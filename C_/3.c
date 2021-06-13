#include <stdio.h>


int check(unsigned int**);

int func(unsigned int *num)
{
  int ret;
  unsigned int* addr=0;
  unsigned int size=10;
  ret = check(&addr);
 
  if(size >=10)
  {
    size = 10;
    
  //  while(size >0)
    {
      (*num) = (*(int*)addr) ;
      printf("%d\n",(*num));
      num++;
      addr++;
      size--;
    }
  }
}
void main()
{
  unsigned int variable;
  func(&variable);
  
}


int check(unsigned int **n)
{
  static int var =20;
  *n = &var;
  
  return 0;
}
