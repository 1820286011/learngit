 ///
 /// @file    test_Timer.cc
 /// @author  wyy
 /// @date    2016-08-20 23:42:40
 ///
 
#include "TimerThread.h"
#include "thread.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace wyy;
using std::cout;
using std::endl;
class Produ
{
	public:
		void getnum()
		{
			srand((unsigned)time(NULL));
			int num=rand()%100;
			cout<<"num= "<<num<<endl;
		}
};
int main()
{
	Produ pro;
	TimerThread timethread(2,1,std::bind(&Produ::getnum,&pro));
//	Thread * pth=new Thread(std::bind(&Timer::start,&time));
	timethread.start();
	sleep(10);
	timethread.stop();
	return 0;
}
