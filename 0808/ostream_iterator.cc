 ///
 /// @file    ostream_iterator.cc
 /// @author  wyy
 /// @date    2016-08-08 00:08:23
 ///
 
#include <iostream>
#include <iterator>
#include <algorithm>
#include <vector>
using namespace std;
int main()
{
	int a[5]={1,2,3,4,5};
	vector <int> v(a,a+5);
	ostream_iterator<int> osi(cout,"\n");
	copy(v.begin(),v.end(),osi);
	return 0;
}
