 ///
 /// @file    Condition.cc
 /// @author  wyy
 /// @date    2016-07-27 02:52:23
 ///
 
#include <iostream>
#include <pthread.h>

class MutexLock
{
	public:
		MutexLock()
		{
			pthread_mutex_init(&_mutex,NULL);

		}
		~MutexLock()
		{
			pthread_mutex_destroy(&_mutex);
		}

		void lock()
		{
			pthread_mutex_lock(&_mutex);
		}
		void unlock()
		{
			pthread_mutex_unlock(&_mutex);
		}
		pthread_mutex_t * getMutexPtr()
		{
			return &_mutex;
		}
	private:
		pthread_mutex_t  _mutex;
};

class Condtion
{
	public:
		Condtion()
		{
			pthread_cond_init(&cond,NULL);
		}
		~Condtion()
		{
			pthread_cond_destroy(&cond);
		}
		void wait(MutexLock & mutex)
		{
			pthread_cond_wait(&cond,mutex.getMutexPtr());
		}
		void notify()
		{
			pthread_cond_signal(&cond);
		}
		void notifyall()
		{
			pthread_cond_broadcast(&cond);
		}
	private:
		pthread_cond_t cond;

};
