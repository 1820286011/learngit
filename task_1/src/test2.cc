 ///
 /// @file    test2.cc
 /// @author  wyy
 /// @date    2016-08-23 01:37:04
 ///
#include"MyTask.h"
#include <iostream>
using namespace std;
int main()
{
	Mydict::createInstance()->init("../data/C3-Art0002.txt");
	MyTask *p=new MyTask("中国",1);
	p->queryIndexTable();
	return 0;
}
