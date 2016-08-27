 ///
 /// @file    Socket.h
 /// @author  wyy
 /// @date    2016-08-23 05:59:41
 ///
 
#ifndef _WYY_SOCKET_H_
#define _WYY_SOCKET_H_
namespace wyy
{
class InetAddress;
class Socket
{
	public:
		Socket();
		explicit Socket(int fd);
		void ready(const InetAddress & addr);
		int accept();
		void shutdownWrite();
		int fd();
		
		static InetAddress getLocalAddress(int fd);
		static InetAddress getPeerAddress(int fd);
	private:
		void setReuseAddr(bool on);
		void setReusePort(bool on);
		void bind(const InetAddress &addr);
		void listen();
	private:
		int _fd;
};





}




#endif
