 ///
 /// @file    TcpServer.h
 /// @author  wyy
 /// @date    2016-08-24 01:20:59
 ///
 
#ifndef _WYY_TCPSERVER_H_
#define _WYY_TCPSERVER_H_

#include "InetAddress.h"
#include "Socket.h"
#include "EpollPoller.h"
#include <iostream>

namespace wyy
{
class TcpServer
{
	typedef TcpConnection::TcpConnectionCallback TcpServerCallback;
	public:
	TcpServer(unsigned short port);
	TcpServer(const string &ip,unsigned short port);

	void start();
	void stop();

	void setConnectionCallback(TcpServerCallback cb)
	{
		_onConnectionCb=cb;
	}
	void setMessageCallback(TcpServerCallback cb)
	{
		_onMessageCb=cb;
	}
	void setCloseCallback(TcpServerCallback cb)
	{
		_onCloseCb=cb;
	}
	private:
		InetAddress _addr;
		Socket _serverSock;
		EpollPoller _epollPoller;

		TcpServerCallback _onConnectionCb;
		TcpServerCallback _onMessageCb;
		TcpServerCallback _onCloseCb;


};






}

#endif
