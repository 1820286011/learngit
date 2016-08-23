 ///
 /// @file    test_threadpool.cc
 /// @author  wyy
 /// @date    2016-08-20 01:28:24
 ///
#include"Threadpool.h"
#include<time.h>
#include<stdlib.h>
#include<unistd.h>
#include <iostream>


using namespace wyy;
using std::cout;
using std::endl;
void getnum()
{
	srand((unsigned)time(NULL));
	int num=rand()%100;
	cout<<"num= "<<num<<endl;
	sleep(2);
	
}
int main()
{
	Threadpool tp(4,10);
	tp.start();
	int n=6;
	while(n--)
	{
		tp.addTask(std::bind(getnum));
	}
	tp.stop();
	return 0;
}
