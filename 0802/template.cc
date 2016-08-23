 ///
 /// @file    template.cc
 /// @author  wyy
 /// @date    2016-08-02 17:36:12
 ///
 
#include <iostream>
using namespace std;

template <typename T>
T max(T a , T b)
{
	return a>b?a:b;
}
int main()
{
	int a=3,b=5;
	cout<<::max(a,b)<<endl;
}
