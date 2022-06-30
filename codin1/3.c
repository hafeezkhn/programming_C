#include<stdio.h>
#include<limits.h>
void main()
{
         unsigned int arr[5]={1,7,6,3,12};
        int i,big1=0,big2=0,big3;
        for(i=0;i<5;i++)
        {
                if(arr[i]>big1)
                {
                        big2=big1;
                        big1=arr[i];
                }
                else if(arr[i]>big2)
                        big2=arr[i];
        }
        big3=big1-big2;
        i=5;
        while(arr[i]!=big1&&i>=0)
        {
                arr[i]=arr[i-1];
                i--;
        }
        arr[i]=big2;
        arr[i+1]=big3;
        printf("%u %u\n",big1,big2);
        for(i=0;i<6;i++)
                printf("%u ",arr[i]);
}
