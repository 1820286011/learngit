 ///
 /// @file    TimerThread.cc
 /// @author  wyy
 /// @date    2016-08-21 00:35:52
 ///
 

#include "TimerThread.h"


TimerThread::TimerThread(int initialTime,int intervalTime,Timer::TimerCallback cb)
:time(initialTime,intervalTime,cb)
{

}
void TimerThread::start()
{
	pth=new Thread(std::bind(&Timer::start,&time));
	pth->start();
}
void TimerThread::stop()
{
	time.stop();
	delete pth;
}


