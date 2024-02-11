//#include <libexplain/socket.h>
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
 const char *hello = "Hello client!\nusentme: ";//response
 const int buffer_size = 1024;
 char buffer[buffer_size];

 /*config the server to use localhost, port 8080 TCP*/
 memset(&hints,0,sizeof(struct addrinfo));
 hints.ai_family = AF_INET;
 hints.ai_socktype = SOCK_STREAM;
 r = getaddrinfo(0,"8080",&hints,&server);
 if(r!=0)
 {
	 perror("failed");
	 exit(1);
 }
 /*create socket to use for communications*/
 sockfd = socket(server->ai_family,server->ai_socktype,server->ai_protocol);
if (sockfd < 0)
{
  //  fprintf(stderr, "%s\n", explain_socket(server->ai_family,server->ai_socktype,server->ai_protocol));
    exit(1);
}
 /*bind the server to socket*/
r = bind(sockfd,server->ai_addr,server->ai_addrlen);
if(r == -1)
{
 perror("failed");
 exit(1);
}
/*listen for incomming connections*/
r = listen(sockfd,1);
if(r==-1)
{
 perror("failed");
 exit(1);
}


/*accept new connection*/
client_len = sizeof(client_address);
clientfd = accept(sockfd,&client_address,&client_len);
if(clientfd = -1)
{
 perror("failed");
 exit(1);
}
/*client is now connected*/
/*recive a chunk of text from client*/
r = recv(clientfd,buffer,buffer_size,0);
/*zero == disconnected,so process any incomming text*/
if(r > 0)
{
 buffer[r]='\0';/*terminate the incomming string*/
 /*error checking isnt done here*/
 send(clientfd,hello,strlen(hello),0);/*send the hello string*/
 send(clientfd,buffer,strlen(buffer),0);/*send back the client string*/
}

/*closeup*/
freeaddrinfo(server);
close(clientfd);
close(sockfd);
return 0;

}
