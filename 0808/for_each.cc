 ///
 /// @file    for_each.cc
 /// @author  wyy
 /// @date    2016-08-08 01:27:09
 ///
 
#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>
using std::cout;
using std::vector;
using std::endl;
using std::string;
using std::pair;
using std::map;
void func(string& st)
{
	st.append(" wyy");
}
void funcmap(pair<string,int>& p)
{
	(p.second)++;
}
int main()
{
	string s[3]={"hello","nihao","hihi"};
	vector<string>vs(s,s+3);
	map<string,int>msi;
	map<string,int>::iterator it;
	std::for_each(vs.begin(),vs.end(),func);
	for(int i=0;i<vs.size();i++)
	{
		msi.insert(pair<string,int>(vs[i],i+1));

	}
	std::for_each(msi.begin(),msi.end(),funcmap);
	for(auto & elem:vs)
	{
		cout<<elem<<endl;
	}
	for(it=msi.begin();it!=msi.end();it++)
	{
		cout<<it->first<<"  "<<it->second<<endl;
	}
   return 0;

}
