 ///
 /// @file    Derived1.cc
 /// @author  wyy
 /// @date    2016-08-12 06:53:34
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

};
class Derived
:public Base
{
	public:
		Derived()
		{
			cout<<"Derived()"<<endl;
		}
		Derived(int ix)
		{
			cout<<"Derived(int ix)"<<endl;
		}
};
int main()
{
	Derived d1;
	Derived d2(2);
}
