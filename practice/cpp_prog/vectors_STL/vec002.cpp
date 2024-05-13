#include<iostream>
#include<vector>
using namespace std;
int main()
{
	vector<int> stlvector = {1,2,3,4,5};
	for(int val: stlvector){
	cout<<val<<" ";
	}
	cout<<"\n";

	stlvector.resize(7);

	for(int val: stlvector){
	cout<<val<<" ";
	}
	cout<<"\n";

	cout<<stlvector.size()<<endl;


return 0;
}
