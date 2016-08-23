 ///
 /// @file    thread.h
 /// @author  wyy
 /// @date    2016-08-18 06:39:22
 ///
#ifndef _WYY_THREAD_H_
#define _WYY_THREAD_H_
#include <pthread.h>
#include <iostream>
#include <functional>
using std::cout;
using std::endl;
namespace wyy
{
	class Thread
	{
		public:
			typedef std::function<void()> ThreadCallBack;
			Thread(ThreadCallBack cb);
			virtual ~Thread();
			void SetThreadCallBack(ThreadCallBack cb);
			void start();
			void join();

			static void*ThreadFunc(void*arg);
		private:
			pthread_t pthid;
			bool is_running;
			ThreadCallBack _cb;

	};




}







#endif
