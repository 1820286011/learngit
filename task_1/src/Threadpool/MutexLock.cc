 ///
 /// @file    MutexLock.cc
 /// @author  wyy
 /// @date    2016-08-18 07:30:17
 ///
 
#include "MutexLock.h"
namespace wyy
{
MutexLock::MutexLock()
{
	pthread_mutex_init(&_mutex,NULL);
}
MutexLock::~MutexLock()
{
	pthread_mutex_destroy(&_mutex);
}
void MutexLock::lock()
{
	pthread_mutex_lock(&_mutex);
}
void MutexLock::unlock()
{
	pthread_mutex_unlock(&_mutex);
}


}

