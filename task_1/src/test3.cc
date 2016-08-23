 ///
 /// @file    test3.cc
 /// @author  wyy
 /// @date    2016-08-23 04:15:03
 ///
#include "./Threadpool/Threadpool.h"
#include "MyTask.h"
#include <iostream>
using namespace wyy;
using namespace std;
int main()
{
	Mydict::createInstance()->init("../data/source1.txt");
	Threadpool tp(4,5);
	tp.start();
	int i=3;
	vector<MyTask*> v;
	while(1)
	{
		string s;
		cin>>s;
		MyTask*mk=new MyTask(s,1);
		v.push_back(mk);
		tp.addTask(std::bind(&MyTask::queryIndexTable,mk));

	}
    tp.stop();
	vector<MyTask*>::iterator itm;
	for(itm=v.begin();itm!=v.end();itm++)
	{
		delete(*itm);
	}
	return 0;
	

}
