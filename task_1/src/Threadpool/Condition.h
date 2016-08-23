 ///
 /// @file    Condition.h
 /// @author  wyy
 /// @date    2016-08-18 07:39:39
 ///
 
#ifndef _WYY_CONDITION_H_
#define _WYY_CONDITION_H_
#include <pthread.h>
#include <iostream>
using std::cout;
using std::endl;
namespace wyy
{
class MutexLock;
class Condition
{
	public:
		Condition(MutexLock &mutex);
		~Condition();

		void wait();
		void notify();
		void notifyall();
	private:
		pthread_cond_t _cond;
		MutexLock & _mutex;
};
	
}


#endif
