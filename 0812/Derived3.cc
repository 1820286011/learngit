 ///
 /// @file    Derived3.cc
 /// @author  wyy
 /// @date    2016-08-12 07:25:19
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
		Base(int x)
		{
			cout<<"Base(int x) "<<x<<endl;
		}
};
class Derived:public Base
{
	public:
		Derived(int x,int y)
		:Base(x)
		{
			cout<<"Derived(int x,int y)"<<endl;
		}
		Derived(int x)
		{
			cout<<"Derived(int x)"<<endl;
		}

};
int main()
{
	Derived d(2);
	Derived d2(4,5);
	return 0;
}
