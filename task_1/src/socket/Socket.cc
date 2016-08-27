 ///
 /// @file    Socket.cc
 /// @author  wyy
 /// @date    2016-08-23 06:05:42
 ///
 
#include "Socket.h"
#include "InetAddress.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
namespace wyy
{
int createSocketfd()
{
	int fd = ::socket(AF_INET,SOCK_STREAM,0);
	if(-1==fd)
	{
		perror("socket create error");
	}
	return fd;
}

Socket::Socket()
:_fd(createSocketfd())
{}

Socket::Socket(int fd)
:_fd(fd)
{}

void Socket::shutdownWrite()
{
	::shutdown(_fd,SHUT_WR);
}
int Socket::fd()
{
	return _fd;
}

int Socket::accept()
{
	int connfd=::accept(_fd,NULL,NULL);
	if(connfd==-1)
	{
		perror("accept error");
		close(_fd);
		exit(EXIT_FAILURE);
	}
	return connfd;
}
void Socket::ready(const InetAddress& addr)
{
	setReuseAddr(true);
	setReusePort(true);
	bind(addr);
	listen();
}
void Socket::setReuseAddr(bool on)
{
	int val=on?1:0;
	if(::setsockopt(_fd,SOL_SOCKET,SO_REUSEADDR,
				&val,(socklen_t)sizeof(val))==-1)
	{
		perror("setsocketopt reuseaddr error");
	}
}
void Socket::setReusePort(bool on)
{
	int val=on?1:0;
	if(::setsockopt(_fd,SOL_SOCKET,SO_REUSEPORT,
				&val,(socklen_t)sizeof(val))==-1)
	{
		perror("setsockopt reuseaddr error");
	}
}
void Socket::bind(const InetAddress &addr)
{
	if(::bind(_fd,(struct sockaddr*)addr.getInetAddressPtr(),
				sizeof(struct sockaddr))==-1)
	{
		perror("bind error");
		close(_fd);
		exit(EXIT_FAILURE);
	}
}
void Socket::listen()
{
	if(::listen(_fd,10))
	{
		perror("listen error");
		close(_fd);
		exit(EXIT_FAILURE);
	}
}
InetAddress Socket::getLocalAddress(int fd)
{
	struct sockaddr_in addr;
	socklen_t val;
	memset(&addr,0,sizeof(addr));
	if(::getsockname(fd,(struct sockaddr*)&addr,&val)==-1)
	{
		perror("getsockname error");
	}
	return InetAddress(addr);

}
InetAddress Socket::getPeerAddress(int fd)
{
	struct sockaddr_in addr;
	socklen_t val;
	memset(&addr,0,sizeof(addr));
	if(::getpeername(fd,(struct sockaddr*)&addr,&val)==-1)
	{
		perror("getpeername error");
	}
	return InetAddress(addr);
}










}
