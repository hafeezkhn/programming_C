#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>

int main()
{
 
	struct addrinfo hints,*server;
	int r,sockfd,clientfd;
	struct soackaddr client_address;
	socklen_t client_len;
	const int buffer_size=1024;
	char buffer[buffer_size];

	/*configure the server to use the localhost,port 8080 tcp*/
	printf("configuring server......");
	memset(&hints,0,sizeof(struct addrinfo));
	
	hints.ai_family = AF_INET; //ipv4
        hints.ai_socktype = SOCK_STREAM ; //TCP streaming

	/*
	 * getaddrinfo 
	 * 
	 * 1st arg : can be string (yahoo.com) or can be ipv4/ipv6 addr
	 * or zero for local system
	 * 
	 * 2nd arg : is a service which can be port number(21)
	 * or service name (FTP) , list of service names are stored in /etc/services
	 * 
	 * 3rd arg : is addr of `addrinfostruct` this struct is initialized to 0 before
	 * its members are assigned this step ensure thr is garbage value after
	 * initialisation members are set to configure the host or client
	 *
	 * 4th arg : struct is filled with info(data which can further be used) about the
	 * connection which is used in subsequent systemcalls,function 
	 * releases memory used by *res struct
	 * 
	 * return value : zero on success or error value on error
         */
	 r = getaddrinfo(0,"8080",&hints,&server);
	return 0;
}

