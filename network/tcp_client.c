#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<unistd.h>
#include<sys/socket.h>
#include<netdb.h>

int main()
{
 struct addrinfo hints,*host;
 int r,sockfd;
 const char *hello = "Howdy,TCP server!\n";//sends to server
 const int buffer_size = 1024;
 char buffer[buffer_size];

 /*config the to use localhost, port 8080 TCP*/
 memset(&hints,0,sizeof(struct addrinfo));
 hints.ai_family = AF_INET;
 hints.ai_socktype = SOCK_STREAM;
 r = getaddrinfo("127.0.0.1","8080",&hints,&host);
 if(r!=0)
 {
	 perror("TCP client");
	 exit(1);
 }
 /*create socket to use for communications*/
 sockfd = socket(host->ai_family,host->ai_socktype,host->ai_protocol);
 if(sockfd = -1)
 {
  perror("TCP client!");
  exit(1);
 }

 /*connect and get the info*/
r = connect(sockfd,host->ai_addr,host->ai_addrlen);
if(r == -1)
{
 perror("TCP client");
 exit(1);
}
/*send something to say hello*/
r = send(sockfd,hello,strlen(hello),0);
if(r==-1)
{
 perror("TCP client");
 exit(1);
}

r = recv(sockfd,buffer,buffer_size,0);
buffer[r]='\0';
printf("%s\n",buffer);

/*closeup*/
freeaddrinfo(host);
close(sockfd);
return 0;

}

