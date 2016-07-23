 ///
 /// @file    copy.cc
 /// @author  wyy
 /// @date    2016-07-22 05:25:10
 ///
 
#include <iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;
class Point
{
	public:
		Point(const char*name,int x=0,int y=0 )
			:_x(x),
			 _y(y)
			 {	 
				 //_name=(char*)malloc(strlen(name)+1);
				 _name=new char[strlen(name)+1];
				 strcpy(_name,name);
				 cout<<"Point( )"<<endl;
				
			  }
		Point(const Point &prs)
			:_x(prs._x),
			 _y(prs._y)
			{
				//_name=(char*)malloc(strlen(prs._name)+1);
				_name=new char[strlen(prs._name)+1];
				strcpy(_name,prs._name);
				cout<<"copy"<<endl;
			}
#if 0
		Point operator=(Point& prs)
		{	delete []_name;
			_x=prs._x;
			_y=prs._y;
			_name=new char[strlen(prs._name)+1];
			strcpy(_name,prs._name);
			cout<<"===="<<endl;
			return *this;
		}
#endif

	 void	print()
		{
			cout<<_name<<"   x="<<_x<<"  y="<<_y<<endl;
		}
		~Point()
		{
			cout<<"~Point"<<endl;
		//	free(_name);
		   cout<<(void*)_name<<endl;
		    delete []_name;
		}
	private:
		int _x;
		int _y;
		char *_name;
};
int main()
{
	Point p1("p1",2,3);
	p1.print();
    Point p2=p1;
	p2.print();
	Point p3("hi");
	p3=p1;
	p3.print();

}
