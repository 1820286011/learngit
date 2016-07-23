 ///
 /// @file    computer.h
 /// @author  wyy
 /// @date    2016-07-21 07:01:48
 ///
#ifndef _C_H
#define _C_H
 
#include <iostream>
#include<string.h>
using namespace std;
class Computer
{
	public:
		void print();
		void SetBrand(const char*sz);
		void SetPrice(float pr);
Computer():brand(c
	private:
		char brand[20];
		float price;
};
#endif
