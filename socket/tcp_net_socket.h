 ///
 /// @file    tcp_net_socket.h
 /// @author  wyy
 /// @date    2016-07-31 07:53:48
 //

#ifndef_TCP_NET_SOCKET_H
#define_TCP_NET_SOCKET_H

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<sys/types.h>
#include<netine/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<signal.h>

extern int tcp_init(const char *ip,int port);
extern int tcp_accept(int sfd);
extern int tcp_connect(const char*ip,int port);
extern void signalhandler(void);

#endif
