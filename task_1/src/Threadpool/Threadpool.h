 ///
 /// @file    Threadpool.h
 /// @author  wyy
 /// @date    2016-08-19 08:19:36
 ///
#ifndef  _WYY_THREADPOOL_H_
#define  _WYY_THREADPOOL_H_
#include "../Timer/TimerThread.h"

#include"Buffer.h"
#include "../Cache.h"
#include<unistd.h>
#include <iostream>
#include <vector>

using std::cout;
using std::endl;
using std::vector;

namespace wyy
{
class Thread;
class Threadpool
{
	public:
		Threadpool(size_t threadNum,size_t buffSize);
		~Threadpool();
		void start();
		void stop();
		void addTask(Task task);
		Task getTask();
		void threadFunc(Cache* pcache);
		void updCache();
		void updFile();
	private:
		size_t _threadNum;
		vector<Thread*>_threads;
		size_t _buffSize;
		Buffer _buffer;
		bool _isExit;
		vector<Cache*>_caches;
		Cache _sumcache;
		TimerThread _timethreadcache;
		TimerThread _timethreadfile;
		
};




}



#endif
