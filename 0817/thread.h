 ///
 /// @file    thread.h
 /// @author  wyy
 /// @date    2016-08-17 02:13:35
 ///
#ifndef _WYY_THREAD_H
#define _WYY_THREAD_H
#include <iostream>
#include <pthread.h>
#include <functional>
using std::cout;
using std::endl;

namespace wyy
{
class Thread
{
	public:
		typedef function<void()> ThreadCallBack;
		Thread(ThreadCallBack cb);
		virtual ~Thread();
		//virtual void run()=0;

		void start();
		void join();
		static void *ThreadFunc(void *pArg);
		void SetThreadCallBack(ThreadCallBack cb);

	private:
		pthread_t pthid;
		bool is_running;
		ThreadCallBack _cb;

};






}



#endif


