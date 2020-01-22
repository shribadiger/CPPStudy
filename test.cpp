#include<stdio.h>
#include<unistd.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/types.h>
#include<netinet/in.h>
#include<stdlib.h>
#include<arpa/inet.h>
#include<errno.h>
#include<string.h>
#include<time.h>

/*
 * Function create a passive sever socket
 */
u_short portbase = 0;
int passive_socket(const char* service, const char* transport, int qLen) {
	
	struct servent *serverEntry;
	struct protoent *ProtoEntry;
	struct sockaddr_in sin;

	int socketFD, type;

	//Initialize the socket address to Zero
	memset(&sin,0,sizeof(sin));

	//Set the socket inforamtion
	sin.sin_family =AF_INET;
	sin.sin_addr.s_addr = INADDR_ANY;

	//Map the service name to port number
	if(serverEntry=getservbyname(service, transport)) {
		sin.sin_port = htons(ntohs((u_short)serverEntry->s_port)+portbase);
	}
	else if((sin.sin_port=htons((u_short)atoi(service))) == 0) {
		printf("\nError: Failed to get port number\n");
		perror("\nFailed to get port number\n");
		exit(-1);
	}

	//Map the protocol name to Protocol Number
	if ((ProtoEntry=getprotobyname(transport)) ==0) {
		printf("\nError: Failed to get the Protocol Numnber\n");
		perror("\nFailed to get the Protocol Number\n");
		exit(-1);
	}

	//Set the Protocol Type
	if( strcmp(transport,"tcp") == 0) {
		type=SOCK_STREAM;
	}
	else {
		type=SOCK_DGRAM;
	}

	socketFD = socket(PF_INET, type, ProtoEntry->p_proto);
	if(socketFD<0) {
		printf("\nError: Failed to create the socket\n");
		perror("\nFailed to create the socket\n");
		exit(-1);
	}

	//Now going to bind to perticular port to serve the client
	if(bind(socketFD, (struct sockaddr*)&sin, sizeof(sin)) <0) {
		printf("\nError: Failed to Bind to socket address\n");
		perror("\n Failed to bind to server socket\n");
		exit(-1);
	}

	if(type ==SOCK_STREAM && listen(socketFD, qLen) < 0) {
		printf("\nEror: Failed to listen on Port\n");
		perror("\nFaield to listen on port\n");
		exit(-1);
	}

	return socketFD;
}

int passiveUDP(const char* service) {
	return passive_socket(service,"udp",0);
}

int passiveTCP(const char* service, int qLen) {
	return passive_socket(service,"tcp",qLen);
}

int TCP_Day_Time(int fd) {
	char* ptr;
	time_t now;
	char* ctime();
	time(&now);
	printf("\n Server %s",ctime(&now));
	write(fd, ptr,strlen(ptr));
	return 0;
}

int main(int argc, char* argv[]) {
	struct sockaddr_in fsin;
	char* service="daytime";
	int msock,sscok;
	socklen_t alen;

	msock = passiveTCP(service,5);
	while(1) {
		sscok = accept(msock, (struct sockaddr*)&fsin, &alen);
		if(sscok < 0){
			printf("\nError: Failed to accept the conenction\n");
			perror("\nFailed to accpet the connection\n");
			exit(-1);
		}

		TCP_Day_Time(sscok);
		close(sscok);
	}
	return 0;
}

