 ///
 /// @file    Derived2.cc
 /// @author  wyy
 /// @date    2016-08-12 07:13:33
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
		Base(int ix)
		{
			cout<<"Base(int)"<<endl;
		}
	private :
		int _ix;
};
class Derived
:public Base
{
	public:
	Derived()
	{
		cout<<"Derived()"<<endl;
	}
};
int main()
{
	Derived d;
}
