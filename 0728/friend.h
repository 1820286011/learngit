 ///
 /// @file    friend.h
 /// @author  wyy
 /// @date    2016-07-27 20:36:05
 ///
 
#include <iostream>
using namespace std;
class Point
{
	public:
		Point(int x,int y);
		void show();
	private:
		int _x;
		int _y;
}
class line
{
	public:
		dis(Point &p1,Point &p2);
	private:
		Point _p1;
		Point _p2;
}

