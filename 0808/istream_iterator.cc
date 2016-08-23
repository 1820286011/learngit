 ///
 /// @file    istream_iterator.cc
 /// @author  wyy
 /// @date    2016-08-08 00:38:58
 ///
 
#include <iostream>
#include <istream>
#include <ostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <string>
#include<sstream>
using namespace std;
int main()
{
	stringstream ss(string("hello"));
	vector<char>vs;
	istream_iterator<char> isi(ss);
	copy(isi,istream_iterator<char>(),back_inserter(vs));

	ostream_iterator<char> osi(cout,"\n");
	copy(vs.begin(),vs.end(),osi);
	cout<<endl;
	return 0;
	

}
