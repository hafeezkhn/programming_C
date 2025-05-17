#include<stdio.h>
#include<memory.h>
#include<stdlib.h>
#include<sys/socket.h>
#include<netinet/in.h>
#include<netdb.h>
#include"rpc_common.h"
#include"de_serialise.h"

int multiply_rpc(int a,int b)
{

ser_buff_t *client_send = multiply_client_stub_marshal(a,b);
ser_buff_t *client_rcev = NULL;

init_serialised_buffer ();
rpc_send_recv(client_send,client_buffer);
client_send = NULL;


}


int main()
{
	int a,b;
	printf("Enter first number\n");
	scanf("%d",&a);
	printf("Enter second number\n");
        scanf("%d",&b);
int res=multiply_rpc(a,b);
printf("res=%d\n",res);
return 0;
}	
