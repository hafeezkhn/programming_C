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
 printf("%c\n",*(char*)((int*)ptr+1));
 printf("%d\n",*(int*)((char*)((int*)ptr+1)+1));
	return 0;
}
