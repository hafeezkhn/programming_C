//another eg:1.c
#include<stdio.h>
#pragma pack(1)
struct A{
	int a;
	char b;
	int c;
};
int main()
{
 struct A k={18,'j',6};
 void *ptr=&k;

 printf("%d\n",*(int*)ptr);
 ptr = (int*)ptr+1;
 printf("%c\n",*(char*)ptr);
 ptr = (char*)ptr+1;
 printf("%d\n",*(int*)ptr);
 return 0;
}

