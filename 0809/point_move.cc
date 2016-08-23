 ///
 /// @file    point_move.cc
 /// @author  wyy
 /// @date    2016-08-09 05:57:44
 ///
 
#include <iostream>
using std::cout;
using std::endl;
class Point
{
	friend std::ostream & operator <<(std::ostream & s,const Point &p);
	public:
		Point(int x,int y)
		: _x(x)
		, _y(y)
		{
			cout<<"Point(int x,int y)"<<endl;
		}
	private:
		int _x;
		int _y;

};
std::ostream & operator<<(std::ostream & s,const Point&p)
{
	s<<"point: "<<p._x<<"  "<<p._y<<endl;
}

void fun1(const Point & p)
{
	cout<<p<<endl;
}
void fun2(Point && p)
{
	cout<<p<<endl;
}
int main()
{
	fun1(Point(2,3));
	fun2(Point(4,5));
	Point p(6,7);
	//fun2(p);
	return 0;
}
