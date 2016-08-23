 ///
 /// @file    Point3D.cc
 /// @author  wyy
 /// @date    2016-08-11 18:06:31
 ///
 
#include <iostream>
using std::cout;
using std::endl;

class Point
{
	public:
		Point(int ix,int iy)
		:_ix(ix)
		,_iy(iy)
	{
		cout<<"Point(int,int)"<<endl;
	}
		int getX(){return _ix;}
		int getY(){return _iy;}
		void display()
		{
			cout<<"("<<_ix<<","<<_iy<<")"<<endl;
		}
	private:
		int _ix;
		int _iy;
};

class Point3D
:public Point
{
	public:
		Point3D(int ix,int iy,int iz)
		:Point(ix,iy)
		,_iz(iz)
	{
		cout<<"Point3D(int ,int ,int)"<<endl;
	}
		void display()
		{
			cout<<getX()<<"  "<<getY()<<"  "<<_iz<<endl;
		}
	private:
		int _iz;
};
int main()
{
	Point3D pt(1,2,3);
	pt.display();
}
