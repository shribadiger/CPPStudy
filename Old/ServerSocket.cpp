/*
 * Socket Programming in C++ and Identify the Network fucntionality
 */
#include<iostream>
#include<sys/types.h> //Type used in the socket
#include<netinet/in.h> // Internet Domain structure and Functions
#include<netinet/tcp.h>//Socket Option Macro Definitions and enum values
#include<sys/socket.h> //socket API function Definitions.
#include<netdb.h> //Domain name and Host Name resolutions
#include<sys/select.h> //used by the select() and pselect() functions FD_CLR, FD_RESET, etc
#include<time.h> // time specific function definitions
#include<arpa/inet.h> // Definitions of Internet Opearations like htonl(), inet_addr() etc.
#include<unistd.h> // Definition of Constants and Types
#include<errno.h> //Definition verious Error Handling in Scoket Functinality
#include<string.h>
using namespace std;

#define PORT_NUM 4433
#define BACKLOG 10

int main(int argc, char* argv[] ) {
	
	/* Create the socket handler*/
	int socketHandler;

	/*Create the socket*/
	if((socketHandler = socket(AF_INET,SOCK_STREAM, IPPROTO_IP)) < 0) {
	       	close(socketHandler);
		exit(EXIT_FAILURE);
	}
	else {
		std::cout<<"\n Successfully Created the socket and ID : "<<socketHandler<<"\n";
	}

	/* Prepare the socket and assign the required values */
       struct sockaddr_in socket_addr;
       socket_addr.sin_family = AF_INET;
       socket_addr.sin_addr.s_addr = INADDR_ANY;
       memset(&(socket_addr.sin_zero),0,8);

       if (bind(socketHandler, (struct sockaddr*)&socket_addr,sizeof(struct sockaddr)) == -1) {
	       perror("\n Scoket Failed to Bind to Port\n");
	       exit(-1);
       }
       else {
	       std::cout<<"\n Socket Bind is successful\n";
       }
       /*
	* Server Listening for the client connection with following API 
	* int listen(int socket_fd, int backlog);
	* socket_fd: Indicate the socket descrptor which going to connect to server application
	* backlog  : Number of incomming connection allowed in incoming queue which mentainer by server socket
	* we need to bind to port before listening, otherwise it listen to random port in server
	*/
        if(listen(socketHandler, BACKLOG) == -1) {
		perror("\n Failed to Listen to port\n");
		exit(-1);
	}
	else {
		std::cout<<"\n Server is Listening on port \n Client can connect to server \n";
	}

	/*
	 * Create new socket file descriptor to accept the clinet connection.
	 * accept() API need to be used to accept the connection:
	 * For more info refer: API document
	 * */
	//if we use the interger value for len, error will come for accept() API, so always use socklen_t variable to 
	//hold the length of client socket details.
	socklen_t client_socket_size = sizeof(struct sockaddr_in);
	struct sockaddr_in client_socket;
	int client_socket_fd = accept(socketHandler, (struct sockaddr*)&client_socket, &client_socket_size);

	if(client_socket_fd == -1) {
		perror("\n Failed to accept the new client connections\n");
		exit(-1);
	}
	else {
		std::cout<<"\n ucccessfully Accepted the new connection\n";
	}

	/*
	 * after connection process completed, User can close the open socket descriptor
	 */
	close(client_socket_fd);
	close(socketHandler);
       

	return 0;
}


