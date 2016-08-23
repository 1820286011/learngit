 ///
 /// @file    oversee.cc
 /// @author  wyy
 /// @date    2016-08-14 06:04:10
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Base
{
	public:
		Base()
		{
			cout<<"Base()"<<endl;
		}
		virtual int func(int x)
		{
			cout<<"Base::func(int)"<<endl;
			return x;
		}
};
class sub
:public Base
{
	public:
		virtual int func(float x)
		{
			cout<<"sub::func(float)"<<endl;
			return x;
		}
};
void test(Base &b)
{
	cout<<b.func(3)<<endl;
}
int main()
{
	Base b;
	sub s;
	test(s);
	cout<<s.func(5)<<endl;
	Base &ref=s;
	cout<<ref.func(8)<<endl;
	return 0;
}

