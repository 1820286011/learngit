 ///
 /// @file    MutexLock.h
 /// @author  wyy
 /// @date    2016-08-18 07:25:43
 ///
 
#ifndef _WYY_MUTEXLOCK_H_
#define _WYY_MUTEXLOCK_H_
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;
namespace wyy
{
class MutexLock
{
	public:
		MutexLock();
		~MutexLock();

		void lock();
		void unlock();
		pthread_mutex_t * getMutexPtr()
		{
			return &_mutex;
		}
	private:
		pthread_mutex_t _mutex;
};

class MutexLockGuard
{
	public:
		MutexLockGuard(MutexLock & mutex)
		:_mutex(mutex)
		{
			_mutex.lock();
		}
		~MutexLockGuard()
		{
			_mutex.unlock();
		}
	private:
		MutexLock &_mutex;
};


}
#endif
