#include<stdio.h>
#pragma pack(1)
struct A{
char a;
int b;
float c;
char d;
short e;
float f;
double g;

}a;
int main()
{
	printf("%lu\n",sizeof(a));
	printf("%lu\n",sizeof(float));
}
