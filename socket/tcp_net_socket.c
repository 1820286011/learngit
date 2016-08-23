 ///
 /// @file    tcp_net_socket.c
 /// @author  wyy
 /// @date    2016-07-31 07:58:41
 ///
 
#include "tcp_net_socket.h"
int tcp_init(const char*ip,int port)
{
	int sfd=socket(AF_INET,SOCK_STREAM,0);
	if(sfd==-1)
	{
		perror("socket");
		exit(-1);
	}
	struct sockaddr_in serveraddr;
	memset(&serveraddr,0,sizeof(struct sockaddr));
	serveraddr.sin
}
