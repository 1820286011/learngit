 ///
 /// @file    Derived_copy_control.cc
 /// @author  wyy
 /// @date    2016-08-12 08:14:56
 ///
 
#include <iostream>
#include <string.h>
using std::cout;
using std::endl;
class Base
{
	friend std::ostream & operator <<(std::ostream &os,const Base &rhs);
    public:
		Base(const char* pdata)
		:_bpdata(new char[strlen(pdata)+1])
		{
			strcpy(_bpdata,pdata);
			cout<<"Base(const char*pdata)"<<endl;
		}
		Base(int x=0)
		{
			cout<<"Base()"<<endl;
			_bpdata=new char[strlen("aiyo")+1];
			strcpy(_bpdata,"aiyo");
		}
		Base(const Base &rhs)
		{
			if(this!=&rhs)
			{
				_bpdata=new char[strlen(rhs._bpdata)+1];
				strcpy(_bpdata,rhs._bpdata);
				cout<<"Base(const Base &rhs)"<<endl;
			}
		}
		Base & operator=(const Base &rhs)
		{
			if(this!=&rhs)
			{
				delete _bpdata;
				_bpdata=new char[strlen(rhs._bpdata)+1];
				strcpy(_bpdata,rhs._bpdata);
				
			}
			cout<<"Base & operator =(const Base &rhs)"<<endl;
			return *this;
		}
		~Base()
		{
			cout<<"~Base()"<<endl;
		}
	private:
		char * _bpdata;
};
std::ostream &operator <<(std::ostream &os,const Base&rhs)
{
	os<<rhs._bpdata;
	return os;
}
class Derived
:public Base
{
	friend std::ostream &operator<<(std::ostream &os,const Derived&d);
	public:
		Derived(const char*pdata)
		:Base(pdata)
		{
			cout<<"Derived(const char *pdata)"<<endl;
		}
		Derived(const char*pdata1,const char*pdata2)
		:Base(pdata1)
		,_pdata(new char[strlen(pdata2)+1])
		{
			strcpy(_pdata,pdata2);
			cout<<"Derived(const char*pdata1,const char*pdata2)"<<endl;
		}
		Derived(const Derived &d)
		:Base(d)
		,_pdata(new char[strlen(d._pdata)+1])
		{
			strcpy(_pdata,d._pdata);
			cout<<"Derived(const Derived &d)"<<endl;
		}
		Derived & operator=(const Derived &d)
		{
			if(this!=&d)
			{
				delete _pdata;
			    _pdata=new char[strlen(d._pdata)+1];
				strcpy(_pdata,d._pdata);
			}
			return *this;
		}
		~Derived()
		{
			cout<<"~Derived()"<<endl;
		}
		private:
		char * _pdata;

};
std::ostream & operator <<(std::ostream&os,const Derived &d)

{
	os<<(Base)d<<","<<d._pdata<<endl;
	return os;
}
int main()
{
#if 0
		Derived d1("hello");
		cout<<"d1= "<<d1<<endl;
		Derived d2(d1);
		cout<<"d2= "<<d2<<endl;

		Derived d3("world");
		d2=d3;
		cout<<"d2= "<<d2<<endl;
		cout<<endl<<endl<<endl;
#endif

		Derived d4("nihao","wyy");
		cout<<"d4="<<d4<<endl;
		Derived d5=d4;
		cout<<"d5="<<d5<<endl;
		
		return 0;
}

