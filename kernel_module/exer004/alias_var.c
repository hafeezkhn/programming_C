#include<stdio.h>
int oldname = 5;

extern int newname __attribute__((alias("oldname")));//if u remove extern it will become definition hence its a declaration

int main()
{

printf("Value of new name is %d\n",newname);
return 0;
}
