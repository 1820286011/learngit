 ///
 /// @file    Buffer.cc
 /// @author  wyy
 /// @date    2016-08-18 05:30:36
 ///
 
#include "Buffer.h"
namespace wyy
{
Buffer::Buffer(size_t size)
:_queSize(size)
,_mutex()
,_notFull(_mutex)
,_notEmpty(_mutex)
{
	cout<<"Buffer(task)"<<endl;
}

bool Buffer::empty()
{
	return _que.size()==0;
}

bool Buffer::full()
{
	return _que.size()==_queSize;
}

void Buffer::push(Task num)
{
	MutexLockGuard guard(_mutex);
	while(full())
		_notFull.wait();
	_que.push(num);
	_notEmpty.notify();
}

Task Buffer::pop()
{
	MutexLockGuard guard(_mutex);
	while(empty())
		_notEmpty.wait();
	Task num=_que.front();
	_que.pop();
	_notFull.notify();
   return num;
}
void Buffer::notifyall()
{
	_notEmpty.notifyall();
}



}
