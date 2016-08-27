 ///
 /// @file    TimerThread.h
 /// @author  wyy
 /// @date    2016-08-21 00:11:01
 ///
 
#include "Timer.h"
#include "thread.h"
using namespace wyy;
class TimerThread
{
	public:
		TimerThread(int initialTime,int intervalTime,Timer::TimerCallback cb);
		void start();
		void stop();

	private:
		Timer time;
		Thread *pth;
				

};

