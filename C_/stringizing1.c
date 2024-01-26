//working with stringizing
#include<stdio.h>
#include<string.h>
#define CMD(NAME) char NAME##_cmd[10]="";\
	strcpy(NAME##_cmd,#NAME);\
	printf("%s\n",NAME##_cmd);

int main()
{
	CMD(mov)
	
	return 0;
}
