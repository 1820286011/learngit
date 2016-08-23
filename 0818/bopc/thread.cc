 ///
 /// @file    thread.cc
 /// @author  wyy
 /// @date    2016-08-18 06:45:16
 ///
 
#include "thread.h"
namespace wyy
{
	Thread::Thread(ThreadCallBack cb)
	:pthid(0)
	,is_running(false)
	,_cb(cb)
	{	
	}
	Thread::~Thread()
	{
		if(is_running)
		pthread_detach(pthid);
	}
	void Thread::start()
	{
		pthread_create(&pthid,NULL,&Thread::ThreadFunc,this);
		is_running=true;
	}
	void Thread::join()
	{
		if(is_running)
		{
			pthread_join(pthid,NULL);
			is_running=false;
		}
	}
	void Thread::SetThreadCallBack(ThreadCallBack cb)
	{
		_cb=cb;
	}
	void*Thread::ThreadFunc(void*arg)
	{
		Thread*pthread=static_cast<Thread*>(arg);
		if(pthread)
			pthread->_cb();
		return NULL;
	}


}
