 ///
 /// @file    EpollPoller.h
 /// @author  wyy
 /// @date    2016-08-24 00:22:09
 ///
 
#ifndef _WYY_EPOLLPOLLER_H_
#define _WYY_EPOLLPOLLER_H_
#include "TcpConnection.h"
#include<sys/epoll.h>
#include<vector>
#include<map>
using std::vector;
using std::map;

namespace wyy
{
typedef TcpConnection::TcpConnectionCallback TcpConnectionCallback;

class EpollPoller
{
public:
	EpollPoller(int listenfd);

	void loop();
	void unloop();
	void waitEpollfd();

	void setConnectionCallback(TcpConnectionCallback cb);
	void setMessageCallback(TcpConnectionCallback cb);
	void setCloseCallback(TcpConnectionCallback cb);
private:
	void handleConnection();
	void handleMessage(int connfd);
	bool isConnected(int connfd);
private:
	int _efd;
	int _listenfd;
	bool _isLooping;
	vector<struct epoll_event> _events;
	map<int,TcpConnectionPtr> _mapConnections;

	TcpConnectionCallback _onConnectionCb;
	TcpConnectionCallback _onMessageCb;
	TcpConnectionCallback _onCloseCb;
};







}
#endif
