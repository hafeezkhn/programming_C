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
	struct sockaddr client_address;
	socklen_t client_len;
	const int buffer_size=1024;
	char buffer[buffer_size];
	/*http is port and protocol the network service bieng accessed in this code
	 *here,http_data contains http header and abriviated html doc 
	 */
	const char* http_data = 
		"HTTP/1.1 200 OK\r\n"
		"Connection: close\r\n"
		"Content-Type: text/html\r\n\r\n"
		"<h1>Hello from server!</h1>";

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
	 if(r!=0)
	 {
	  perror("failed");
	  exit(1);
	 }
	 puts("done");


	/* create socket for communications
	 *
	 *
	 */
         printf("Assign a socket...");
	 sockfd = socket(
			 server->ai_family,//domain,ipv4/6
			 server->ai_socktype,//type stream(TCP) or datagram(UDP)
			 server->ai_protocol //protocol `/etc/protocol`
			 );

	 if(sockfd == -1)
	 {
	  perror("failed");
	  exit(1);
	 }
	 puts("done");

        /*Bind the server to socket
	 *1st arg: socket file discriptor
	 *2nd arg: servers addr retrieved from the getaddrinfo()
	 *3rd arg: servers addr length(IPv4 or IPv6)
	 */
	 printf("Binding Socket...");
         r = bind(sockfd,server->ai_addr,server->ai_addrlen);

	 if(r == -1)
	 {
	  perror("failed");
	  exit(1);
	 }
	 puts("done");

        /*listen for incomming connection
	 * 1st arg: server socket file descriptor
	 * 2nd arg: Number of pending connections to wait in queue
	 */
        printf("listening...");
	r = listen(sockfd,1);
	if(r == -1)
	{
	 perror("failed");
	 exit(1);
	}
	puts("done");

        /*accept a new connection
	 *1st arg: servers socket fd
	 *2nd arg: connecting client addr
	 *3rd arg: length of sockaddr structure
	 */
         printf("Accepting new connection...");
	 client_len = sizeof(client_address);
	 clientfd = accept(sockfd,&client_address,&client_len); 
	 /*accept() is a Blocking call -> holds the program until 
	  * connection arrives and then accepted.
	  */ 

	 if(clientfd == -1)
	 {
	  perror("failed");
	  exit(1);
	 }
	 printf("on file discriptor %d\n",clientfd);
	 /*client is now connected*/

	 /*recieve data
	  * 1st arg: socket fd
	  * 2nd arg: data to send
	  * 3rd arg: buffer size
	  * 4th arg: settings/option
	  */
          r = recv(clientfd,buffer,buffer_size,0);
	  if(r>0)
	  {
	   printf("Recieved %d bytes:\n---\n",r);
	   for(int i=0;i<r;i++)
		   putchar(buffer[i]); //outputs 
	  
	  }

	  /*send the response*/
	  r = send(clientfd,http_data,strlen(http_data),0);
	  if(r<1)
	  {
	   perror("Send failed!");
	   exit(1);
	  }

	  /*close the client socket*/
	  close(clientfd);

	  /*free allocated memory*/
	  freeaddrinfo(server);
	  /*close the socket*/
	  close(sockfd);
	  puts("Socket closed, done\n");

	return 0;
}

