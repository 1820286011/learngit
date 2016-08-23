 ///
 /// @file    String_move.cc
 /// @author  wyy
 /// @date    2016-08-09 06:09:35
 ///
 
#include <iostream>
#include <string.h>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
class String
{
	friend std::ostream & operator <<(std::ostream & os,const String &s);
	public:
		String()
		:_pstr(new char[1])
		{
			cout<<"String()"<<endl;
		}
		String(const char*pstr)
		:_pstr(new char[strlen(pstr)+1])
		{
			strcpy(_pstr,pstr);
			cout<<"String(const char * pstr)"<<endl;
		}
		String(const String &s)
		:_pstr(new char[strlen(s._pstr)+1])
		{
			strcpy(_pstr,s._pstr);
			cout<<"String(const String &s)"<<endl;
		}
		String(String && s)
		:_pstr(s._pstr)
		{
			s._pstr=NULL;
			cout<<"String(String &&s)"<<endl;
		}
		String & operator=(const String & rhs)
		{
			if(this!=&rhs)
			{
				delete _pstr;
				_pstr=new char[strlen(rhs._pstr)+1];
				strcpy(_pstr,rhs._pstr);
			}
			cout<<"s1=s2"<<endl;
			return *this;
		}
		String & operator =(String && rhs)
		{
			delete []_pstr;
			_pstr=rhs._pstr;
			rhs._pstr=NULL;
			cout<<"s1=&&s2"<<endl;
			return *this;
		}
		~String()
		{
			cout<<"~String()"<<endl;
			delete []_pstr;
		}


		
	private:
	 char * _pstr;
};

std::ostream & operator <<(std::ostream & os,const String &s)
{
	os<<s._pstr<<endl;
	return os;
}

int main()
{
	String("hello");
	String s("word");
	cout<<s<<endl;
	String s2(std::move(s));
	cout<<s2<<endl;
	//cout<<s;

	String s3("uuu");
	s2=s3;
	cout<<s2<<endl;

	s2="lala";
	cout<<s2<<endl;
	return 0;
}
