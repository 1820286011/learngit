 ///
 /// @file    TextQuery.cc
 /// @author  wyy
 /// @date    2016-08-07 04:57:35
 ///
 
#include <iostream>
#include<map>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
#include<vector>
#include<set>
#include<sstream>
using namespace std;

class ProDict
{
	public:
		void readFile(const string filename); 
		void query(const string &word);
		void display();
		void putmap(string stemp);
		map<string,int>& getMap();
	private:
		map<string,int> _mapWordFreq;
};
map<string,int>&ProDict::getMap()
{
	return _mapWordFreq;
}
void ProDict :: query(const string & word)
{
	map<string,int>::iterator iter;
	iter=_mapWordFreq.find(word);
	cout<<"query"<<endl;
	if(iter!=_mapWordFreq.end())
	{
		cout<<word<<"  counts: "<<iter->second<<endl;
	}


}
void ProDict::putmap(string stemp)
{
	map<string,int>::iterator iter;
	map<string,set<int> >::iterator ssiter;
	set<int>::iterator setiter;

	iter=_mapWordFreq.find(stemp);
	if(iter==_mapWordFreq.end())
	{
		_mapWordFreq.insert(pair<string,int>(stemp,1));
	}
	else
	{
			int i = _mapWordFreq[stemp];
			_mapWordFreq[stemp]=++i;
	}
	
}


void ProDict:: readFile(const string filename)
{
		ifstream ifs(filename.c_str());
	if(!ifs.good())
	{ 
		cout<<" open error!"<<endl;
		return;
	}
	string sword;
	string :: iterator siter;
	string lineword;
	while(getline(ifs,lineword))
	{
		
		stringstream ss(lineword);
		while(ss>>sword)
		{
			
			int k=0;string stemp;
			for(siter=sword.begin();siter!=sword.end();siter++)
			{
				char p=*siter;
				if(p<='z'&&p>='a')
				{
					stemp.push_back(p);
				}
				else if(p<='Z'&&p>='A')
				{
					p=p-'A'+'a';
					stemp.push_back(p);
				}
				else
				{
					if(stemp!="")
					{
						putmap(stemp);
					}
					k=0;stemp="";
				
				}
				if(stemp!=""&&siter==(--sword.end()))
				{
						putmap(stemp);
				}
				
		
			}
		}
	}
}


