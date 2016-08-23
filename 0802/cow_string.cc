 ///
 /// @file    cow_string.cc
 /// @author  wyy
 /// @date    2016-08-02 06:46:48
 ///
 
#include "cow_string.h"

String :: String()
{
	_pstr=NULL;
}
String :: String(const char *p)
:_pstr(new char[strlen(p)]+2)								
{
	strcpy(_pstr,p);
	cout<<"String()"<<endl;
	initRefcount();
}
String :: String(const String &rhs)
:_pstr(rhs._pstr)
{
	increaseRefcount();
}
String :: ~String()
{
	decreaseRefcount();
	if(_pstr[length()+1]==0)delete _pstr;	
}
String & String :: operator=(const String & rhs)
{
	decreaseRefcount();
	if(_pstr[length()+1]==0)delete _pstr;
	_pstr=rhs._pstr;
	increaseRefcount();
}
void String :: initRefcount()
{
	_pstr[length()+1]='1';
}
void String :: increaseRefcount()
{
	++(_pstr[length()+1]);
}
void String :: decreaseRefcount()
{
	--(_pstr[length()+1]);
}
int String :: length() const
{
	return strlen(_pstr);
}

ostream & operator<<(ostream & os,const String & rhs)
{
	os<<rhs._pstr<<"  addr:"<<(void *)rhs._pstr<<"   refc:"<<rhs._pstr[rhs.length()+1]<<endl;
}
int main()
{
	String s="hello";
	String s2="hello2";	cout<<s<<endl;
	cout<<s2<<endl;

	s=s2;
	cout<<s<<endl;
	cout<<s2<<endl;
}
