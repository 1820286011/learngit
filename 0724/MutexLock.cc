 ///
 /// @file    MutexLock.cc
 /// @author  wyy
 /// @date    2016-07-24 18:09:03
 ///
 
#include <iostream>
#include<pthread.h>
using namespace std;
class MutexLock
{
	public:
		MutexLock();
		~MutexLock();

		void lock();
		void unlock();
	private:
		pthread_mutex_t  _lock;

};

MutexLock :: MutexLock()
{
	pthread_mutex_init(&_lock,NULL);
}

MutexLock :: ~MutexLock()
{
	pthread_mutex_destroy(&_lock);
}

void MutexLock :: lock()
{
	pthread_mutex_lock(&_lock);
}

void MutexLock :: unlock()
{
	pthread_mutex_unlock(&_lock);
}


