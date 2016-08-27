 ///
 /// @file    TcpConnection.cc
 /// @author  wyy
 /// @date    2016-08-23 07:26:21
 ///
 
#include "TcpConnection.h"
#include<string.h>
#include<sstream>
#include<iostream>
using namespace std;
namespace wyy
{
	TcpConnection::TcpConnection(int connfd)
	:_sock(connfd)
	,_sockIO(connfd)
	,_localAddress(Socket::getLocalAddress(connfd))
	,_peerAddress(Socket::getPeerAddress(connfd))
	,_isShutdownWrite(false)
	{

	}

	TcpConnection::~TcpConnection()
	{
		if(_isShutdownWrite)
		{
			shutdown();
		}
	}

	string TcpConnection::receive()
	{
		char buf[65536];
		memset(buf,0,sizeof(buf));
		_sockIO.readline(buf,sizeof(buf));
		return string(buf);
	}

void TcpConnection::send(const string &msg)
{
	cout<<"qmsg="<<msg<<endl;
	_sockIO.writen(msg.c_str(),msg.size());
	cout<<"hmsg="<<msg<<endl;
}
void TcpConnection::shutdown()
{
	if(_isShutdownWrite)
	{
		_isShutdownWrite=true;
		_sock.shutdownWrite();
	}
}

string TcpConnection::toString()const
{
	std::ostringstream oss;
	oss<<_localAddress.ip()<<":"<<_localAddress.port()
		<<"-->"<<_peerAddress.ip()<<":"<<_peerAddress.port();
	return oss.str();
}

void TcpConnection::setConnectionCallback(TcpConnectionCallback cb)
{
	_onConnectionCb=cb;
}
void TcpConnection::setMessageCallback(TcpConnectionCallback cb)
{
	_onMessageCb=cb;
}
void TcpConnection::setCloseCallback(TcpConnectionCallback cb)
{
	_onCloseCb=cb;
}
void TcpConnection::handleConnectionCallback()
{
	if(_onConnectionCb)
	{
		
		_onConnectionCb(shared_from_this());
	}
}
void TcpConnection::handleMessageCallback()
{
	if(_onMessageCb)
		_onMessageCb(shared_from_this());
}
void TcpConnection::handleCloseCallback()
{
	if(_onCloseCb)
		_onCloseCb(shared_from_this());
}



}
