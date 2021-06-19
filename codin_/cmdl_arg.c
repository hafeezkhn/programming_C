#include<stdio.h>
/* The first argument, int argc, indicates how
 * many command-line arguments there are. The second argument, char *argv[], is an
 * array of pointers to the command-line arguments, */
int main(int argc ,char *argv[])
{
int j;
for(j=0;j<argc;j++)
	printf("arg[%d]=%s\n",j,argv[j]);
	return 0;
}
