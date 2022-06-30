#include<iostream>
using namespace std;
class A{
	public:
	unsigned char a;
};

class B:public A  {
	public:
	unsigned char b;

};

int main()
{
    class B b;
   class A a={2};
    //class B *pb = pa;

    //cout<<pb->a<<endl;
	return 0;
}
