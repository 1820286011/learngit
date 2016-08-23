 ///
 /// @file    thread_function.cc
 /// @author  wyy
 /// @date    2016-08-17 07:51:11
 ///
 
#include "thread_function.h"
using namespace std;
namespace wyy
{
	Thread::Thread(ThreadCallBack cd)
	:is_running(false)
	,pthid(0)
	,_cd(cd)
	{}
	Thread::Thread(){}
	Thread::~Thread()
	{
		if(is_running)
		{
			pthread_detach(pthid);
			is_running=false;
		}
	}
	void Thread :: start()
	{
		pthread_create(&pthid,NULL,&Thread::ThreadFunc,this);
		is_running=true;
	}
	void Thread::join()
	{
		pthread_join(pthid,NULL);
	}
#if 1
	void Thread::SetThreadCallBack(Thread::ThreadCallBack  cd)
	{
		_cd=cd;
	}
#endif

	void* Thread::ThreadFunc(void*arg)
	{
			Thread*ppthread=static_cast<Thread*>(arg);
			if(ppthread)
			{ppthread->_cd();}
	}
}
