 ///
 /// @file    test.h
 /// @author  wyy
 /// @date    2016-07-21 19:55:02
 ///
 
#include <iostream>
#include<string.h>
#include<stdio.h>
#include<stdlib.h>
using namespace std;
class A
{
  private:	char*string;
  public:
			A()
			{// string =NULL;
			}
		 void setstring(char *pstring)
		   {//if (string!=NULL)
			   //free(string);
			 // string=(char*)malloc(strlen(pstring));
			 // strcpy(string,pstring);
			  //string=pstring;
			  string=pstring;
		   }
		   void print()
		   {
			   cout<<string<<endl;
		   }
		   ~A()
		   {
			   //free(string);
		   cout<<"~A()"<<endl;
		   }
};

