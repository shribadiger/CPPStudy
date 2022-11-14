#include<iostream>
#include<unistd.h>
#include<sys/socket.h>
#include<time.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<string.h>
#include<stdlib.h>
#include<netdb.h>
#define DEST_IP "127.0.0.1"
#define DEST_PORT 4433
#define LINELEN 128

/*
 * Function to connect to server by getting the server address and other useful information
 */
int connectSocket(const char* host, const char* service, const char* transport) {
	printf("\n Entry: ConnectSocket\n");
	struct hostent *pHostEntry;
	struct servent *pSeverInformation;
	struct protoent *pProtocolIformation;
	int socketFD, type;
	struct sockaddr_in socket_address;

	//Intializa the complete socket with Zero
	memset(&socket_address, 0, sizeof(socket_address));

	//Map the service name with port number
	if(pSeverInformation = getservbyname(service, transport)) {
		printf("\n Successful get of Server Information\n");
		socket_address.sin_port  = pSeverInformation->s_port;
	}
	else if((socket_address.sin_port=htons(atoi(service)))==0) {
		printf("\nError: Failed to get the Server Port Information\n");
		perror(" Can not get the server entry");
		exit(-1);
	}

	//Map the host anme to IP address
	if((pHostEntry = gethostbyname(host))) {
		printf("\n Successful to get host information\n");
		memcpy(&socket_address.sin_addr, pHostEntry->h_addr, pHostEntry->h_length);
	}
	else if((socket_address.sin_addr.s_addr=inet_addr(host)) == INADDR_NONE) {
		printf("\n Failed to get the Address\n");
		perror("Failed to get the Address from Host Name\n");
		exit(-1);
	}

	//Map the transport protocol name to Protocol Number to establish the connection
	if((pProtocolIformation=getprotobyname(transport)) == 0) {
		printf("\n Failed to get the transport information\n");
		perror("\n Failed to get the transport information\n");
		exit(-1);
	}

	//use protocol to select type of socket
	if(strcmp(transport,"udp")==0) {
		printf("\n Type: UDP\n");
		type = SOCK_DGRAM;
	}
	else {
		printf("\n Type: TCP\n");
		type=SOCK_STREAM;
	}

        //Now allocate the socket to connect to servera
	printf("\n 1: Create the socket to connect to server\n");
	socketFD = socket(PF_INET, type, pProtocolIformation->p_proto);
	if(socketFD <0) {
		printf("\n Failed to create the client socket\n");
		perror("\n Failed to create the client socket with required information\n");
		exit(-1);
	}

	//connect the socket to server
	printf("\n 2: Trying to connect to Server Socket\n");
	if(connect(socketFD, (struct sockaddr*)&socket_address, sizeof(socket_address)) < 0){
		printf("\n Failed to connect to server socket\n");
		perror("\n Failed to connect to server socket\n");
		exit(-1);
	}

	return socketFD;
}

/*
 * Function to connect to the TCP server 
 */
int connectTCP(const char* host, const char* service) {
	printf("\n Entry: connectTCP\n");
	connectSocket(host,service,"tcp");
	printf("\n Exit: connectTCP\n");
}

/*
 * Function to conenct to UDP server
 */
int connectUDP(const char* host, const char* service) {
	connectSocket(host,service,"udp");
}

//TCP Day Time Functionality
void TCP_Day_Time(const char* host, const char* service) {
	printf("\n Entry: TCP_Day_Time function\n");
	//buffer for one line Text
	char buf[LINELEN];

	int socketFD, n;
	socketFD = connectTCP(host,service);

	while((n=read(socketFD,buf, LINELEN)) > 0){
		printf("\n Reading in while loop\n");
		buf[n]='\0';
		(void)fputs(buf,stdout);
		printf("\n Buffer: %s",buf);
	}
	printf("\n Exit: TCP_Day_Time function\n");
}

/*
 * Main function
 */
int main(int argc, char* argv[]) {\
	printf("\n Clinet Started\n");
	char* host ="localhost";
	char* service ="daytime";
	printf("\n Number of Arguments: %d",argc);
	switch(argc) {
		case 1: host="localhost";
			break;
		case 3: service = argv[2];
			break;
		case 2: host=argv[1];
			break;
		default:fprintf(stderr, "usage: TCP_Day_Time [host [port]]\n");
			exit(1);
	}

	printf("\n Calling the Tcp fucntion\n");
	TCP_Day_Time(host,service);

	exit(0);
}

