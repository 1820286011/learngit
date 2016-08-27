 ///
 /// @file    TcpConnection.h
 /// @author  wyy
 /// @date    2016-08-23 06:55:21
 ///
 
#ifndef _WYY_TCPCONNECTION_H_
#define _WYY_TCPCONNECTION_H_
#include"InetAddress.h"
#include"Socket.h"
#include"SocketIO.h"
#include<string>
using std::string;
namespace wyy
{
class TcpConnection
{
	public:
		TcpConnection(int connfd);
		~TcpConnection();

		string receive();
		void send(const string & msg);
		void shutdown();

		string toString()const;
	private:
		Socket _sock;
		SocketIO _sockIO;
		InetAddress _localAddress;
		InetAddress _peerAddress;
		bool _isShutdownWrite;
};




}


#endif
