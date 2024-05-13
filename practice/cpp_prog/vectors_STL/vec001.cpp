/* c-style array */
#include<iostream>
using namespace std;
int main()
{

	int *cArray = new int[5];
	for (int i=0;i<5;++i){cArray[i]= i+1;}
	for (int i=0;i<5;++i)
	 cout<<cArray[i]<<" ";
	cout<<"\n";
	const int newSize = 7;
	int *newCArray = new int[newSize];


return 0;
}
