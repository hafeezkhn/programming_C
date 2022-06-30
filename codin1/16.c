#include<stdio.h>
#include<limits.h>
int main()

{ 
	void *ptr;int i;
	void* p=calloc(5,sizeof(void*)); 
	printf("%d\n",sizeof(void *) * CHAR_BIT);
	printf("%d\n",CHAR_BIT);

	for(i=0;i<5;i++)
	{

	*((long long int*)p) = 220;
	

	}
	p--;

	printf("%d\n",*((char*)p));
	printf("%d\n",*((char*)(p-1)));
	



	return 0;
}
