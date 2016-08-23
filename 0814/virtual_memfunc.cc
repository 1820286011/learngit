 ///
 /// @file    virtual_memfunc.cc
 /// @author  wyy
 /// @date    2016-08-14 06:50:14
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Base
{
	public:
		virtual void display()
		{
			cout<<"Base::display()"<<endl;
		}
		void call_base1()
		{
			this->display();
		}
		void call_base2()
		{
			this->display();
		}
};
class Child
:public Base
{
	public:
		void display()
		{
			cout<<"Child::display()"<<endl;
		}
		virtual void print()
		{
			cout<<"Child::print()"<<endl;
		}
		void call_child1()
		{
			display();
		}
};
int main()
{
	Base base;
	Child child;
	base.call_base1();
	child.call_child1();
	cout<<endl;

	Base*pb=&base;
	pb->call_base1();
	pb->call_base2();

	pb=&child;
	pb->call_base1();
	pb->call_base2();
	pb->display();


	return 0;
}

