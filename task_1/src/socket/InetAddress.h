 ///
 /// @file    InetAddress.h
 /// @author  wyy
 /// @date    2016-08-23 05:32:48
 ///
#ifndef _WYY_INETADDRESS_H_
#define _WYY_INETADDRESS_H_
#include <netinet/in.h>
#include <string>
using std::string;
namespace wyy
{
class InetAddress
{
	public:
		InetAddress(unsigned short port);
		InetAddress(const string & ip,unsigned short port);
		InetAddress(struct sockaddr_in addr);
		const struct sockaddr_in * getInetAddressPtr()const;
		string ip() const;
		unsigned short port()const;
	private:
		struct sockaddr_in _addr;
};




}




#endif
