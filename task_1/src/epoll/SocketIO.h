 ///
 /// @file    SocketIO.h
 /// @author  wyy
 /// @date    2016-08-23 06:33:58
 ///
 
#ifndef _WYY_SOCKETIO_H_
#define _WYY_SOCKETIO_H_
#include<stdio.h>
namespace wyy
{
class SocketIO
{
	public:
		SocketIO(int fd);
		size_t readn(char* buf,size_t count);
		size_t writen(const char*buf,size_t count);
		size_t readline(char*buf,size_t maxlen);
	private:
		size_t recvPeek(char*buf,size_t count);
	private:
		int _fd;
};



}





#endif

