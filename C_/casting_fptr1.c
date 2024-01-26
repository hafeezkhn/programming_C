//casting func_pointer
#include<stdio.h>
unsigned short add(void)
{
        return 0xeeff;
}

int main()
{
 char a,b;

unsigned char (*const func)(void) = (unsigned char (*)(void))add;

a=(*func)();
printf("%x\n",a);


return 0;
}
