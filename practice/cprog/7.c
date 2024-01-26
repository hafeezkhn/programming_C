#include<stdio.h>

int main(){

enum a{ A=-4294967295 ,B,C};

enum a c= B;

printf("size-%d\n value- %d\n",sizeof(c),c);

return 0;
}


