#include<iostream>
using namespace std;
class widget{ 
	public:
	int a;
	int b;

};
void func(widget pb){

cout<<pb.a<<endl;
cout<<pb.b<<endl;
	
}
int main()
{
	widget p={.b=3};
	func(p);

	return 0;
}


