 ///
 /// @file    test_function.cc
 /// @author  wyy
 /// @date    2016-08-17 08:14:35
 ///
 
#include "thread_function.h"
#include <time.h>
#include <unistd.h>
using std::cout;
using std::endl;
class Derived
{
	public:
	void func(int num)
	{
		while(1)
		{
			cout<<"nihao yoyo: "<<num<<endl;
			num++;
			sleep(1);
		}

	}
};
int main()
{
	Derived *d=new Derived;
	wyy::Thread* p=new wyy::Thread(std::bind(&Derived::func,d,1));
	p->start();
	p->join();
	delete p;
	return 0;

}
