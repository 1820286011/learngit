 ///
 /// @file    Timer.cc
 /// @author  wyy
 /// @date    2016-08-20 21:12:32
 ///
 
#include "Timer.h"
#include <stdio.h>
#include <unistd.h>
#include <sys/timerfd.h>
#include <poll.h>
namespace wyy
{
int createTimerFd()
{
	int fd=::timerfd_create(CLOCK_REALTIME,0);
	if(-1==fd)
	{
		cout<<"timerfd_create error"<<endl;
	}
	return fd;
}
void setTimerFd(int fd,int initialTime,int intervalTime)
{
	struct itimerspec value;
	value.it_value.tv_sec=initialTime;
	value.it_value.tv_nsec=0;
	value.it_interval.tv_sec=intervalTime;
	value.it_interval.tv_nsec=0;
	int ret=::timerfd_settime(fd,0,&value,NULL);
	if(-1==ret)
	{
		cout<<"timerfd_settime error!"<<endl;
	}
}
void stopTimerFd(int fd)
{
	setTimerFd(fd,0,0);
}
void readTimerFd(int fd)
{
	uint64_t howmany=0;
	int ret = ::read(fd,&howmany,sizeof(howmany));
	if(ret!=sizeof(howmany))
	{
		cout<<"read error!"<<endl;
	}
}
Timer::Timer(int initialTime,int intervalTime,TimerCallback cb)
:_fd(createTimerFd())
,_initialTime(initialTime)
,_intervalTime(intervalTime)
,_cb(cb)
,_isStarted(false)
{

}
Timer::~Timer()
{
	if(_isStarted)
	{
		stop();
	}
}
void Timer::start()
{
	setTimerFd(_fd,_initialTime,_intervalTime);
	_isStarted=true;

	struct pollfd pfd;
	pfd.fd=_fd;
	pfd.events=POLLIN;
	while(_isStarted)
	{
		int ret=::poll(&pfd,1,5000);
		if(ret==0)
		{
			cout<<"poll timeout!"<<endl;
			continue;
		}
		if(ret==-1)
		{
			cout<<"poll error!"<<endl;
			return;
		}
		if(pfd.revents&POLLIN)
		{
			readTimerFd(pfd.fd);
			if(_cb)
				_cb();
		}
	}
}

void Timer::stop()
{
	if(_isStarted)
	{
		stopTimerFd(_fd);
		_isStarted=false;
	}
}


}
