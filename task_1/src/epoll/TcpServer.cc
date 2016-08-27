 ///
 /// @file    TcpServer.cc
 /// @author  wyy
 /// @date    2016-08-24 01:28:27
 ///
 
#include "TcpServer.h"
#include <iostream>
using std::cout;
using std::endl;
namespace wyy
{
TcpServer::TcpServer(unsigned short port)
:_addr(port)
,_serverSock()
,_epollPoller(_serverSock.fd())
{}

TcpServer::TcpServer(const string &ip,unsigned short port)
:_addr(ip,port)
,_serverSock()
,_epollPoller(_serverSock.fd())
{}

void TcpServer::start()
{
	_serverSock.ready(_addr);
	_epollPoller.setConnectionCallback(_onConnectionCb);
	_epollPoller.setMessageCallback(_onMessageCb);
	_epollPoller.setCloseCallback(_onCloseCb);

	_epollPoller.loop();
}
void TcpServer::stop()
{
	_epollPoller.unloop();
}




}
