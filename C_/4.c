//process block endpointers of each section
#include<stdio.h>
int main()
{
 extern char etext,edata,end;
 printf("%s\n %s\n %s\n",etext,edata,end);
return 0;
}
