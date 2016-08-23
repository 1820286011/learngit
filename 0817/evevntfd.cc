 ///
 /// @file    evevntfd.cc
 /// @author  wyy
 /// @date    2016-08-18 23:53:47
 ///
#include<sys/eventfd.h>
#include<
#include <iostream>
#define handle_error(msg) \
	do{perror(msg);exit(EXIT_FAILURE);
	}while(0)
int main(int argc,char**argv)
{
	int efd=eventfd(0,0);
	if(-1==efd)
	{
		handle_error("eventfd");
	}
	switch(fork())
	{
		case 0:
			for(size
		default:
		sleep(2);
		int ret=read(efd,&u,sizeof(u));
		if(sizeof(u)
	}
}
