 ///
 /// @file    memory.c
 /// @author  wyy
 /// @date    2016-07-21 05:06:41
 ///
#include<stdio.h> 
#include <iostream>
using namespace std;
int a=0;
int*p1;

int main()
{
	int b;
	char s[]="123456";
	int*p2;
	 char*const p3="123456";
	static int c=0;

	p1 = new int(10);
	p2 = new int(5);//	strcpy(p1,"123456");
    cout<<"&a="<<&a<<endl;
	cout<<"p1="<<p1<<endl;
	cout<<"&p1="<<&p1<<endl;
	cout<<"p2="<<p2<<endl;
	cout<<"&p2="<<&p2<<endl;
	cout<<"p3="<<p3<<endl;
	cout<<"&p3="<<&p3<<endl;
	cout<<"&c="<<&c<<endl;
	cout<<"&s="<<&s<<endl;


}
