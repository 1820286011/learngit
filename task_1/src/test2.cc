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
	Mydict::createInstance()->init("../data/source1.txt");
	MyTask *p=new MyTask("phonewyy",1);
	p->queryIndexTable();
	return 0;
}
