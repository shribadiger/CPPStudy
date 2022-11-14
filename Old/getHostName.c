/*
 * Program to Illustrate about the gethostname functionality
 */
#include<stdio.h>
#include<unistd.h>
#include<string.h>
#include<netinet/in.h>
#include<sys/types.h>
#include<sys/socket.h>
#include<netdb.h>
#include<arpa/inet.h>
#include<error.h>
#include<stdlib.h>

int main(int argc, char* argv[]) {
	printf("\n ----- GETHOSTNAME ILLUSTRATION ------\n");
	
	char* host_buffer[256];
	char* IP_Address;
	struct hostent* host_entry;
	int host_name;

	//Retreive the host name by using the API
	host_name = gethostname(host_buffer,sizeof(host_buffer));
	if(host_name == -1) {
		perror("\n Failed to get host name\n");
		exit(-1);
	}

	host_entry = gethostbyname(host_buffer);
	if(host_entry == NULL) {
		perror("\n Failed to get the host entry\n");
		exit(-1);
	}

	IP_Address = inet_ntoa(*((struct in_addr*)host_entry->h_addr_list[0]));

	printf("\n Host Name : %s\n", host_buffer);
	printf("\n Host IP   : %s\n", IP_Address);

	printf("\n --------- E N D  ---------\n");
	return 0;
}
