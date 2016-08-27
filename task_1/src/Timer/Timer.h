 ///
 /// @file    Timer.h
 /// @author  wyy
 /// @date    2016-08-20 21:05:27
 ///
#ifndef _WYY_TIMER_H_
#define _WYY_TIMER_H_
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
using std::function;

namespace wyy
{
class Timer
{
	public:
		typedef std::function<void()>TimerCallback;
		Timer(int initialTime,int intervalTime,TimerCallback cb);
		~Timer();
		void start();
		void stop();
	private:
		int _fd;
		int _initialTime;
		int _intervalTime;
		bool _isStarted;
		TimerCallback _cb;
};



}



#endif
