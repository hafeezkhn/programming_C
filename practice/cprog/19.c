



#include <stdio.h>

//Output – MERCEDESBENZ

int main()
{
    char arr[] = "M$$er##ce!desb$en$@z";
    
 //   char output[] = "MERCEDESBENZ";
    
    
    for(int i=0;i<sizeof(arr);i++)
    {
        if ( (arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
        {
            int static temp =0;
            
            
            arr[temp++] = arr[i];
                    
        }
            
        
        
    }
    
    printf("%s\n",arr);
    


    return 0;
}
