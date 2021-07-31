#include<sys/stat.h>
#include<fcntl.h>
#include <sys/types.h>  /* Type definitions used by many programs */
#include <stdio.h>      /* Standard I/O functions */
#include <stdlib.h>     /* Prototypes of commonly used library functions,
			                              plus EXIT_SUCCESS and EXIT_FAILURE constants */
#include <unistd.h>     /* Prototypes for many system calls */
#include <errno.h>      /* Declares errno and defines error constants */
#include <string.h>     /* Commonly used string-handling functions */
#include <stdbool.h>    /* 'bool' type plus 'true' and 'false' constants */

#ifndef BUF_SIZE
#define BUF_SIZE 1024
#endif
int main(int argc,char *argv[])
{
int Inputfd,Outputfd;ssize_t num;
char buf[BUF_SIZE];
Inputfd = open(argv[1],O_RDONLY);
Outputfd = open(argv[2],O_CREAT|O_WRONLY|O_TRUNC,00700);
num = read(Inputfd,buf,BUF_SIZE);
write(Outputfd,buf,num);

close(Inputfd);
close(Outputfd);

return 0;
}
