 ///
 /// @file    ttt.cc
 /// @author  wyy
 /// @date    2016-08-26 00:30:06
 ///
 
#include "Mydict.h"
using namespace std;
int main()
{
	Mydict::createInstance()->init("../data/C3-2out.txt");
	map<string,set<int> > p=Mydict::createInstance()->getIndexTable();
	map<string,set<int> >::iterator it;
	for(it=p.begin();it!=p.end();it++)
	{
		cout<<"map fisrt:  "<<it->first<<endl;
		cout<<it->second.size()<<endl;
	}
}
