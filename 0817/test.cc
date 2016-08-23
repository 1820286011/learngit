 ///
 /// @file    test.cc
 /// @author  wyy
 /// @date    2016-08-17 05:27:58
 ///
 
#include"thread.h"
#include<stdlib.h>
#include<time.h>
#include<unistd.h>
class Derived
:public wyy::Thread
{
	public:
	void run()
	{
		srand(time(NULL));
		while(1)
		{
			int num=rand()%100;
			cout<<"num="<<num<<endl;
			sleep(1);
		}
	}
};
int main()
{
	Derived *pthread=new Derived();
//	wyy::Thread *pthread=new Derived();
	pthread->start();
	pthread->join();
	delete pthread;
	return 0;

}
