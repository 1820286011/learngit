 ///
 /// @file    Threadpool.cc
 /// @author  wyy
 /// @date    2016-08-20 00:26:41
 ///
 
#include "Threadpool.h"
#include "Buffer.h"
#include "thread.h"
#include "../Cache.h"
namespace wyy
{
	Threadpool::Threadpool(size_t threadNum,size_t buffSize)
	:_threadNum(threadNum)
	,_buffSize(buffSize)
	,_isExit(false)
	,_buffer(buffSize)
	,_timethreadcache(10,20,std::bind(&Threadpool::updCache,this))
	,_timethreadfile(20,100,std::bind(&Threadpool::updFile,this))
	{
	}
   Threadpool::~Threadpool()
	{
		cout<<"~Threadpool()"<<endl;
	}
	void Threadpool::start()
	{
		for(size_t i=0;i<_threadNum;i++)
		{
			Cache*pcache=new Cache();
			pcache->readFromFile("Cache_to_out.txt");
			Thread*pthread=new Thread(std::bind(&Threadpool::threadFunc,this,pcache));
			pthread->start();
			_threads.push_back(pthread);
			_caches.push_back(pcache);
		}
		_timethreadcache.start();
		_timethreadfile.start();

	}
	void Threadpool::stop()
	{
		vector<Thread*>::iterator it;
		if(!_isExit)
		{	
			while(!_buffer.empty()){
				sleep(1);				   
			}
			_isExit=true;
			for(it=_threads.begin();it!=_threads.end();it++)
			{//(*it)->join();
			 delete *it;
			}
			
			_buffer.notifyall();
		}

	}
	void Threadpool::addTask(Task task)
	{
		_buffer.push(task);
	}
	Task Threadpool::getTask()
	{
		return _buffer.pop();
	}
	
	void Threadpool::threadFunc(Cache* pcache)
	{
		
		while(!_isExit)
		{
			Task task=getTask();
			if(task)
			task(pcache);
			
		
		}
	}

	void Threadpool::updCache()
	{
		for(int i=0;i<_caches.size();i++)
		{
			_sumcache.update(*_caches[i]);
		}
		for(int i=0;i<_caches.size();i++)
		{
			Cache*p=_caches[i];
			p->update(_sumcache);
		}
		
	}

	void Threadpool::updFile()
	{
		_sumcache.writeToFile("Cache_to_out.txt");
	}










}




