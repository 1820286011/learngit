 ///
 /// @file    tcp_server.c
 /// @author  wyy
 /// @date    2016-07-31 03:49:58
 ///
 
#include "func.h"
//socket
int main(int argc,char*argv[])
{
	if(argc!=3)
	{
		printf("error args\n");
		return -1;
	}
	int sfd;
	sfd=socket(AF_INET,SOCK_STREAM,0);              //SOCK_STREAM ->TCP
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
	ret=bind(sfd,(struct sockaddr*)&ser,sizeof(struct sockaddr));
	if(-1==ret)
	{
		perror("bind");
		return -1;
	}
	listen(sfd,10);
	struct sockaddr_in client;
	bzero(&client,sizeof(client));
	int new_fd;
	int addrlen=sizeof(client);
	new_fd=accept(sfd,(struct sockaddr*)&client,&addrlen);
	if(-1==new_fd)
	{
		perror("accept");
		return -1;
	}
	printf("client ip=%s,PORT=%d\n",inet_ntoa(client.sin_addr),ntohs(client.sin_port));
	char buf[128]={0};
	ret=recv(new_fd,buf,sizeof(buf),0);
	if(ret<=0)
	{
		perror("recv");
		return -1;
	}
	printf("client info=%s\n",buf);
	ret=send(new_fd,"i am server",11,0);
	if(ret<=0)
	{
		perror("send");
		return -1;
	}
	close(new_fd);
	close(sfd);
	return 0;


}
