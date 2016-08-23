 ///
 /// @file    bind.cc
 /// @author  wyy
 /// @date    2016-08-08 07:32:54
 ///
 
#include <iostream>
#include <functional>
using std::cout;
using std::endl;

int add(int x,int y)
{
	return x+y;
}

class A
{
	public:
		int add(int x,int y)
		{
			return x+y;
		}
		int _ix=9;
};

void f(int n1,int n2,int n3,const int & n4,int n5)
{
	cout<<n1<<"  "<<n2<<"  "<<n3<<"  "<<n4<<"  "<<n5<<endl;
}

int main()
{
	auto ad=std::bind(add,std::placeholders::_2,20);
	cout<<ad(50,10)<<endl;

	A a;
	auto ad2=std::bind(&A::add,&a,std::placeholders::_1,30);
	cout<<ad2(70,20)<<endl;

	auto d=std::bind(&A::_ix,&a);
	cout<<d()<<endl;

}
