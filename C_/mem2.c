#include<stdio.h>
typedef union{
unsigned short dummy;
unsigned char All;
struct{
	unsigned char PR_bf:3;
	unsigned char res_bf:3;
	unsigned char MK_bf:1;
    volatile unsigned char IF_bf1V:1;
}bit_st;

}gtype;

typedef struct{
	
gtype DMAIC0;	
	
}gtype_IC_st;

gtype_IC_st gICreg;

int main(){
    
unsigned char u18=0;
(&gICreg.DMAIC0)[u18+1].All;
printf("%lu\n",sizeof(gtype));
printf("%lu",sizeof(gtype_IC_st));
}
