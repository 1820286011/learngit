 ///
 /// @file    Threadpool.cc
 /// @author  wyy
 /// @date    2016-08-20 00:26:41
 ///
 
#include "Threadpool.h"
#include "Buffer.h"
#include "thread.h"
namespace wyy
{
	Threadpool::Threadpool(size_t threadNum,size_t buffSize)
	:_threadNum(threadNum)
	,_buffSize(buffSize)
	,_isExit(false)
	,_buffer(buffSize)
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
			Thread*pthread=new Thread(std::bind(&Threadpool::threadFunc,this));
			pthread->start();
			_threads.push_back(pthread);
		}
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
	
	void Threadpool::threadFunc()
	{
		while(!_isExit)
		{
			Task task=getTask();
			if(task)
			task();
		}
	}










}




