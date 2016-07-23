 ///
 /// @file    test.cc
 /// @author  wyy
 /// @date    2016-07-22 04:18:36
 ///
 
#include"test.h"
int main()
{
	A* a=new A();
	char *hh="zhu";
	a->setstring(hh);
	
	a->print();
   // a->setstring("lala");
//	a->print();
	delete a;
}
