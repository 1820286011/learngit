 ///
 /// @file    test_socket.cc
 /// @author  wyy
 /// @date    2016-08-23 07:47:07
 ///
#include "InetAddress.h"
#include "Socket.h"
#include "TcpConnection.h"
#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <string>
#include <iostream>
using namespace wyy;
using namespace std;

int main()
{
	InetAddress inetAddr(8888);
	Socket socket;
	socket.ready(inetAddr);

	int connfd=socket.accept();
	TcpConnection conn(connfd);
	cout<<conn.toString()<<endl;
	conn.send("wleconme serber");
	while(1)
	{
		string msg=conn.receive();
		cout<<msg<<endl;
		conn.send(msg);
	}
	return 0;
}
