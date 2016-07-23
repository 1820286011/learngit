 ///
 /// @file    main.cc
 /// @author  wyy
 /// @date    2016-07-21 07:26:04
 ///
 
#include "computer.h"
int main()
{
	Computer *a=new Computer();
	a->SetBrand("zzz");
	a->SetPrice(1000);
	a->print();
	delete a;
}
