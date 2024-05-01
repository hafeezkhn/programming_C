#include<iostream>
#include<deque>
using namespace std;

int main()
{
	deque<int> mark;
	mark.push_back(10);
	mark.push_front(20);

//	deque<int>::iterator it;
//	for (it=mark.begin();it!=mark.end();++it)
//	{
//	   cout <<'\t'<<*it;
//	}
//	cout <<'\n';
//
	for (auto i:mark)
	{
	  cout<< i <<'\t';
	}

	cout<<mark.size()<<endl;
	cout<<mark.max_size()<<endl;

	cout<<mark.front()<<endl;
	cout<<mark.back()<<endl;

	cout<<mark.at(1)<<endl;


return 0;
}
