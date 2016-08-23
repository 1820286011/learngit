 ///
 /// @file    String.cc
 /// @author  wyy
 /// @date    2016-07-28 04:58:35
 ///
 
#include <iostream>
#include <string.h>
#include <stddef.h>
#define num 3
using namespace std;
class String
{
	public:
		String();
		String(const char *);
		String(const String&);
		~String();
		String &operator=(const String &);
		String &operator=(const char*);

		String &operator+=(const String &);
		String &operator+=(const char *);

		char &operator[](std::size_t index);
		const char &operator[](std::size_t index) const;

		std::size_t size() const;
		const char* c_str() const;

		friend bool operator==(const String &,const String &);
		friend bool operator!=(const String &,const String &);

		friend bool operator<(const String &,const String &);
		friend bool operator>(const String &,const String &);
		friend bool operator<=(const String &,const String &);
		friend bool operator>=(const String &,const String &);

		friend std::ostream &operator<<(std::ostream &os,const String &s);
		friend std::istream &operator>>(std::istream &is,String &s);

	private:
		char*_pstr;
};
String :: String()
{
	_pstr=NULL;
	cout<<"String()"<<endl;
}
String :: String (const char *pchar):_pstr(new char[strlen(pchar)+1])
{
    strcpy(_pstr,pchar);
	cout<<"String(const char*)"<<endl;
}
String :: String (const String&str):_pstr(new char[strlen(str._pstr)+1])
{
	strcpy(_pstr,str._pstr);
	cout<<"String(const String&)"<<endl;
}
String :: ~String()
{
	cout<<"~String()"<<endl;
	delete _pstr;
}
String & String ::  operator=(const String &s)
{
	if(_pstr)delete _pstr;
	_pstr = new char[strlen(s._pstr)+1];
	strcpy(_pstr,s._pstr);
	return *this;
}
String &  String :: operator=(const char *pch)
{
	if(_pstr)delete _pstr;
	_pstr = new char[strlen(pch)+1];
	strcpy(_pstr,pch);
	return *this;
}

String & String :: operator+=(const String & s)
{
	char * temp =new char[strlen(_pstr)+strlen(s._pstr)+1];
	strcpy(temp,_pstr);
	strcpy(temp+strlen(_pstr),s._pstr);
	if(_pstr)delete _pstr;
	_pstr=temp;
	return *this;
}
String & String :: operator+=(const char * pch)
{
	char * temp=new char[strlen(_pstr)+strlen(pch)+1];
	strcpy(temp,_pstr);
	strcpy(temp+strlen(_pstr),pch);
	if(_pstr)delete _pstr;
	_pstr=temp;
	return *this;
}

char & String :: operator[](std::size_t index)
{
	return _pstr[index];
}
const char &String :: operator[](std::size_t index) const
{
	return _pstr[index];
}

std::size_t String :: size() const
{
	return strlen(_pstr);
}
const char * String :: c_str() const
{
	return _pstr;
}

bool operator==(const String &s1,const String &s2)
{
	if(strlen(s1._pstr)!=strlen(s2._pstr))return false;
	for(int i=0;i<strlen(s1._pstr);i++)
		{
			if(s1._pstr[i]!=s2._pstr[i])
				return false;
		}
	return true;

}
bool operator!=(const String &s1,const String &s2)
{
	if(s1==s2)return false;
	else return true;
}

bool operator<(const String &s1,const String &s2)
{
	if(strcmp(s1._pstr,s2._pstr)<0)return true;
	else return false;
}
bool operator>(const String &s1,const String &s2)
{	
	if(strcmp(s1._pstr,s2._pstr)>0)return true;
	else return false;

}
bool operator<=(const String &s1,const String &s2)
{
	if(strcmp(s1._pstr,s2._pstr)<=0)return true;
	else return false;
}
bool operator>=(const String &s1,const String &s2)
{
	if(strcmp(s1._pstr,s2._pstr)>=0)return true;
	else return false;
}


String operator+(const String &s1,const String &s2)
{
	String tmp(s1);
	tmp+=s2;
	return tmp;//strange
}
String operator+(const String &s1,const char* pch)//wen leiwai s1._pstr
{
   String tmp(pch);
   tmp+=s1;
   return tmp;
}
#if 0
String operator+(const char*pch1,const char *pch2)
{
	String s1(pch1);
	String s2(pch2);
	s1+=s2;
	return s1;
}
#endif

String operator+(const char * pch,const String & s)
{
	String tmp(pch);
	tmp+=s;
	return tmp;
}

std::ostream &operator<<(std::ostream &os,const String &s)
{
	os<<s._pstr;
	return os;
}
std::istream &operator>>(std::istream &is,String &s)
{  

	char *buffer=new char[num];
	is.get(buffer,num);
	s=buffer;
	while(strlen(buffer)==num-1)
	{
		is.get(buffer,num);
			s+=buffer;
	}
	delete []buffer;
	return is;

}

int main()
{
	String s1;
	String s2("this is s2!");
	String s3("this is s3!");

	s1=s2;
	cout<<"s1=s2   s1:"<<s1<<endl;
	s1="this is s1!";
	cout<<"s1=this is s1   s1:"<<s1<<endl;

	s1+=s2;
	cout<<"s1+=s2  s1:"<<s1<<endl;
	s1+="  world!";
	cout<<"s1+=world  s1:"<<s1<<endl;

	cout<<"s1[5]: "<<s1[5]<<endl;
	char p1=s1[5];
	cout<<"p1=s1[5] p1: "<<p1<<endl;

	cout<<"s1(size) : "<<s1.size()<<endl;
	const char * p2=s1.c_str();
	cout<<"char*p2=s1.c_str   p2:"<<p2<<endl;

	cout<<"s1==s2  "<<(s1==s2)<<endl;
	cout<<"s1!=s2  "<<(s1!=s2)<<endl;

	cout<<"s1<s2   "<<(s1<s2)<<endl;
	cout<<"s1>s2   "<<(s1>s2)<<endl;
	cout<<"s1>=s2   "<<(s1>=s2)<<endl;
	cout<<"s1<=s2   "<<(s1<=s2)<<endl;

	s2=s1+s3;
	cout<<"s2=s1+s3  s2: "<<s2<<endl;

	s3=s1+"his3";
	cout<<"s3=s1+'his3' "<<s3<<endl;

	s3="add"+s1;
	cout<<"s3='add'+s1  "<<s3<<endl;





}



















