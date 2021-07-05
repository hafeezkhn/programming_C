#include<stdio.h>
void* ptr;

void add(void){
	printf("in add\n");
}
void add1(void){
	
	printf("in add1\n");
}

typedef struct{
	void* addrfunc;
	unsigned char udata;
}A_st;
int main()
{
A_st arr[]={{(void*)add,0x01},{(void*)add1,0x02}},*Aptr;
Aptr =arr;

typedef void(*fptr)(void);
ptr=Aptr->addrfunc;
//casting of generic pointer then hence invoked
(*(fptr)(ptr))();



	printf("in main\n");

	return 0;
}
