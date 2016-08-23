 ///
 /// @file    virtual1.cc
 /// @author  wyy
 /// @date    2016-08-14 05:19:25
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Base
{
	public:
		virtual int func(int x)
		{
			cout<<"Base::func(int)"<<endl;
			return x;
		}
};
class sub2:public Base
{
	public:
		int func(int x)
		{
			cout<<"sub2::func(int x)"<<endl;
			return x;
		}
};

class sub1:public Base
{
	public:
		int func(int x)
		{
			cout<<"sub1::func(int x)"<<endl;
			return x;
		}
};

void test(Base &b)
{
	cout<<b.func(3)<<endl;
}
int main()
{
	sub1 s1;
	test(s1);
	sub2 s2;
	test(s2);
	Base b;
	test(b);
	return 0;
}
