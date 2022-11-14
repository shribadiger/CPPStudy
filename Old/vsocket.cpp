/* Define the vSocket for communication */
int socketFD;
int af_VMCI = VMCISock_GetAFValue();// To get the VMCI Address family.

#define BUFFSIZE 1024
int serverConnection() {
    int af_VMCI;
    int socketFD;
    int numOfBytes;
    char buffer[BUFFSIZE];
    long number_of_bytes_sent;
    unsigned int buffer_size;
    socklen_t length;

    struct sockaddr_vm server_address = {0}; // initializing the server address to Zeros
    //Step  1: obtain the VMCI Address 
    af_VMCI = VMCISock_GetAFValue();
    init_sockaddr(af_VMCI,& server_address);

    strcpy(buffer,"-- Server connection initialize--");

    //creating the vsocket for connection
    socketFD = socket(af_VMCI,SOCK_STREAM,0);
    if(socketFD  == -1) {
        error("Failed to create socket");
    }

    // connecting the server based on the connection
    if((connect(socketFD,(struct sockaddr*)&server_address,size_of(server_address))) == -1) {
        error("Failed to connect to server");
    }

    //geting the socket options
    if(getsockopt(socketFD,af_VMCI,SO_VMCI_BUFFER_SIZE,(void*)&buffer_size,0) == -1){
        error("Failed to get the socket options");
    }

    printf("\n Buffer Length : %lld",buffer_size);
    getchar(); // reading data from console

    printf("\n Transfering clinet data to server");

    while(1) {
        if((numOfBytes = send(socketFD,buffer,BUFFSIZE,0) == -1)){
            break;
        }
        number_of_bytes_sent=number_of_bytes_sent+numOfBytes;
        printf("\n[Log]: Bytes transmitted : %lld",number_of_bytes_sent);
    }

    printf("\n[log]: Closing the vsocket connection");
    close(socketFD);

    return 0;
}


void startServer() {
    int listenFD, clientFD, nfds;
    uint64_t buf_size, t;
    socklen_t size;
    struct sockaddr_vm my_addr = {0}, their_addr;
    int vmci_address_family;
    fd_set read_fds;
    unsigned int cid;
    uint8_t buf[BUFSIZE];

    socket_startup();

    if ((vmci_address_family = VMCISock_GetAFValue()) < 0)
    {
        fprintf(stderr, "VMCISock_GetAFValue failed: %d. You probably need root privileges\n", vmci_address_family);
        goto cleanup;
    }

    if ((listenFD = socket(vmci_address_family, SOCK_STREAM, 0)) == -1)
    {
        perror("socket");
        goto cleanup;
    }

    /*
     * SO_VMCI_BUFFER_SIZE – Default size of communicating buffers; 65536 bytes if not set.
     * SO_VMCI_BUFFER_MIN_SIZE – Minimum size of communicating buffers; defaults to 128 bytes.
     * SO_VMCI_BUFFER_MAX_SIZE – Maximum size of communicating buffers; defaults to 262144 bytes.
     */

    buf_size = 32768;
    /* reduce buffer to above size and check */
    if (setsockopt(listenFD, vmci_address_family, SO_VMCI_BUFFER_SIZE, (void *)&buf_size, sizeof(buf_size)) == -1)
    {
        perror("setsockopt");
        goto close;
    }

    size = sizeof(t);
    if (getsockopt(listenFD, vmci_address_family, SO_VMCI_BUFFER_SIZE, (void *)&t, &size) == -1)
    {
        perror("getsockopt");
        goto close;
    }
    if (t != buf_size)
    {
        fprintf(stderr, "SO_VMCI_BUFFER_SIZE not set to size requested.\n");
        goto close;
    }

    my_addr.svm_family = vmci_address_family;
    my_addr.svm_cid = VMADDR_CID_ANY;
    my_addr.svm_port = VMADDR_PORT_ANY;
    if (bind(listenFD, (struct sockaddr *)&my_addr, sizeof(my_addr)) == -1)
    {
        perror("bind");
        goto close;
    }

    if ((cid = VMCISock_GetLocalCID()) == (unsigned int)-1)
    {
        fprintf(stderr, "VMCISock_GetLocalCID failed\n");
    }
    else
    {
        fprintf(stderr, "server cid: %u\n", cid);
    }

    size = sizeof(my_addr);
    if (getsockname(listenFD, (struct sockaddr *)&my_addr, &size) == -1)
    {
        perror("getsockname");
        goto close;
    }

    fprintf(stderr, "server (cid, port): %u:%u\n", my_addr.svm_cid, my_addr.svm_port);

    for (;;)
    {
        if (listen(listenFD, CONNECTION_BACKLOG) == -1)
        {
            perror("listen");
            goto close;
        }

        size = sizeof(their_addr);
        if ((clientFD = accept(listenFD, (struct sockaddr *)&their_addr, &size)) == -1)
        {
            perror("accept");
            goto close;
        }
        fprintf(stderr, "client connected\n");

        FD_ZERO(&read_fds);
        FD_SET(clientFD, &read_fds);
        nfds = clientFD + 1;
        if (select(nfds, &read_fds, NULL, NULL, NULL) == -1)
        {
            perror("select");
            goto close;
        }
        if (FD_ISSET(clientFD, &read_fds))
        {
            ssize_t s;
            if ((s = recv(clientFD, (void *)buf, sizeof(buf), 0)) < 0)
            {
                fprintf(stderr, "recv failed: %s\n", strerror(errno));
            }
            else
            {
                int i;
                fprintf(stderr, "recved %lld bytes\n", (long long int)s);
                for (i = 0; i < s; i++)
                {
                    putc(buf[i], stderr);
                }
                putc('\n', stderr);
            }
        }
        close(clientFD);
    }
close:
    socket_close(listenFD);
cleanup:
    socket_cleanup();
    return 0;
}