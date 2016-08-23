 ///
 /// @file    Eventfd.cc
 /// @author  wyy
 /// @date    2016-08-21 01:55:03
 ///
 
#include "Eventfd.h"
#include<unistd.h>
using std::cout;
using std::endl;
namespace wyy
{
int createEventfd()
{
	int fd=::eventfd(0,0);
	if(fd==-1)
	{
		cout<<"createfd error!"<<endl;
	}
	return fd;
}
Eventfd::Eventfd(EventfdCallback cb)
:_fd(createEventfd())
,_isStarted(false)
,_cb(cb)
{

}
Eventfd::~Eventfd()
{
	if(_isStarted)
	{
		stop();
		_isStarted=false;
	}
}
void Eventfd::start()
{
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
			handleRead();
			if(_cb)
				_cb();
		}
	}
}

void Eventfd::stop()
{
	if(_isStarted)
	{
		_isStarted=false;
	}
}
void Eventfd::handleRead()
{
	uint64_t u=0;
	int ret=::read(_fd,&u,sizeof(u));
	if(sizeof(u)!=ret)
	{
		cout<<"read error"<<endl;
	}
}
void Eventfd::wakeup()
{
	uint64_t u=1;
	int ret=::write(_fd,&u,sizeof(u));
	if(ret!=sizeof(u))
	{
		cout<<"write error"<<endl;
	}
}



}
