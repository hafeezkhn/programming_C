#include<iostream>
using namespace std;
class widget{ 
	public:
	int a;
	widget(){
		a=1;
	}

	widget(int b){
                a=b;
        }
};
void func(widget pb){

cout<<pb.a<<endl;
	
}
int main()
{
	widget p={2};
	func(widget{});

	return 0;
}

