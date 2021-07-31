#include<stdio.h>
#include<stdlib.h>
int main()
{
 int num;
 FILE *fptr;
 fptr = fopen("file1.txt","w");
 if(fptr == NULL)
 {
  printf("ERROR!\n");
  exit(1);
 }
printf("\nEnter num:");
scanf("%d",&num);
fprintf(fptr,"%d",num);
fclose(fptr);
}
