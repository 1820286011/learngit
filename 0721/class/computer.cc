 ///
 /// @file    computer.cc
 /// @author  wyy
 /// @date    2016-07-21 06:56:37
 ///
 
#include"computer.h"
void Computer::print()
{
	cout<<"brand:"<<brand<<endl;
	cout<<"price:"<<price<<endl;
}
void Computer::SetBrand(const char *sz)
{
   strcpy(this->brand,sz);
}
void Computer::SetPrice(float pr)
{
	this->price=pr;
}


