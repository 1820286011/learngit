 ///
 /// @file    test4.cc
 /// @author  wyy
 /// @date    2016-08-24 05:19:41
 ///
 
#include "SpellcorrectServer.h"
int main()
{
	SpellCorrectServer *s=new SpellCorrectServer("../data/C3-2out.txt");
	s->start();
	
	return 0;
}
