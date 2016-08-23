 ///
 /// @file    tcp_client.c
 /// @author  wyy
 /// @date    2016-07-31 04:37:10
 ///
 
#include "func.h"
int main(int argc,char*argv[])
{
	if(argc!=3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);
	if(-1==sfd)
	{
		perror("socket");
		return -1;
	}
	struct sockaddr_in ser;
	memset(&ser,0,sizeof(ser));
	ser.sin_family=AF_INET;
	ser.sin_port=htons(atoi(argv[2]));
	ser.sin_addr.s_addr=inet_addr(argv[1]);
	int ret;
	ret=connect(sfd,(struct sockaddr*)&ser,sizeof(ser));
	if(-1==ret)
	{
		perror("connect");
		return -1;
	}
	ret=send(sfd,"i am client",11,0);
	if(ret<=0)
	{
		perror("send");
		return -1;
	}
	char buf[128]={0};
	ret=recv(sfd,buf,sizeof(buf),0);
	if(ret<=0)
	{
		perror("recv");
		return -1;

	}
	printf("client rec=%s\n",buf);
	close(sfd);
	return 0;

}
