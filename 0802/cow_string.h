 ///
 /// @file    cow_string.h
 /// @author  wyy
 /// @date    2016-08-02 06:58:46
 ///
 
#ifndef _COW_STRING_H_
#define _COW_STRING_H_
#include <iostream>
#include <string.h>
using namespace std;

class String
{
	private:
		class CharProxy
		{
			friend ostream & operator<<(ostream &os,const CharProxy &rhs);
			public:
				CharProxy(String &str,int idx);
				CharProxy & operator=(char ch);
			private:
				int _idx;
				String & _str;
		};
    friend ostream & operator<<(ostream &os,const String & rhs);
	public:
		String();
		String(const char*);
		String(const String &rhs);
		~String();

		String & operator=(const String &rhs);
		char & operator[](int idx)const;

		const char*c_str()const{return _pstr;}
		int length()const;
		int refCount() const;
	private:
		void initRefcount();
		void increaseRefcount();
		void decreaseRefcount();
		char *_pstr;

};
#endif
