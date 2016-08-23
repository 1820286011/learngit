 ///
 /// @file    thread_function.h
 /// @author  wyy
 /// @date    2016-08-17 07:40:08
 ///
 
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
		Thread();
		Thread(ThreadCallBack cd);
		~Thread();
		void start();
		void join();
		static void* ThreadFunc(void*);
		void SetThreadCallBack(ThreadCallBack cd);
//		{	_cd = cd;	}
	private:
		bool is_running;
		pthread_t pthid;
		ThreadCallBack _cd;
};






}

