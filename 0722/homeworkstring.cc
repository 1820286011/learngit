 ///
 /// @file    homeworkstring.cc
 /// @author  wyy
 /// @date    2016-07-22 21:44:56
 ///
 
#include <iostream>
#include<string.h>
using namespace std;
class String
{
	public:
		String();
		String(const char*pstr);
		String(const String & rhs);
		String & operator = (const String & rhs);
		~String();
		void print();
	private:
		char * _pstr;
};

String :: String()
{
	_pstr = new char [strlen(" default string ")+1];
	strcpy(_pstr," default string ");
}

String :: String(const char * pstr)
{
	_pstr = new char [strlen(pstr)+1];
	strcpy(_pstr,pstr);
}

String :: String(const String & rhs)
{	
	_pstr = new char [strlen(rhs._pstr)+1];
	strcpy(_pstr,rhs._pstr);
}
String & String :: operator = (const String & rhs)
{
	delete _pstr;
	_pstr = new char [strlen(rhs._pstr)+1];
	strcpy(_pstr,rhs._pstr);
}

void String :: print()
{
	cout<<"_pstr : "<<_pstr<<endl;
}

String :: ~String()
{
	delete _pstr;
	cout<<"~String"<<endl;
}

int main(void)
{
	String str1;
	str1.print();

	String str2 = "Hello,world";
	String str3 = "wangdao";

	str2.print();
	str3.print();
	str2 = str3;
	str2.print();

	String str4 = str3;
	str4.print();
	return 0;
}
