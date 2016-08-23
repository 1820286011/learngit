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

class TextQuery
{
	public:
		void readFile(const string filename); 
		void query(const string &word);
		void display();
		void putmap(string stemp,int line);
	private:
		vector<string>_vecLines;
		map<string,set<int> > _mapWord2Line;
		map<string,int> _mapWordFreq;
};
void TextQuery :: query(const string & word)
{
	map<string,int>::iterator iter;
	map<string,set<int> >::iterator ssiter;
	set<int>::iterator setiter;
	iter=_mapWordFreq.find(word);
	cout<<"query"<<endl;
	if(iter!=_mapWordFreq.end())
	{
		cout<<word<<"  counts: "<<iter->second<<endl;
		ssiter=_mapWord2Line.find(word);
		for(setiter=ssiter->second.begin();setiter!=ssiter->second.end();setiter++)
		{
			cout<<*setiter<<"   "<<_vecLines[*setiter-1]<<endl;
		}
	}


}
void TextQuery::putmap(string stemp,int line)
{
	map<string,int>::iterator iter;
	map<string,set<int> >::iterator ssiter;
	set<int>::iterator setiter;

	iter=_mapWordFreq.find(stemp);
	if(iter==_mapWordFreq.end())
	{
		_mapWordFreq.insert(pair<string,int>(stemp,1));
		set<int> settemp;
			settemp.insert(line);
			_mapWord2Line.insert(pair<string,set<int> >(stemp,settemp));
	}
	else
	{
			int i = _mapWordFreq[stemp];
			_mapWordFreq[stemp]=++i;
			_mapWord2Line[stemp].insert(line);
	}
	
}


void TextQuery :: readFile(const string filename)
{
		ifstream ifs(filename.c_str());
	if(!ifs.good())
	{ 
		cout<<" open error!"<<endl;
		return;
	}
	string lineword;
	string sword;int line=0;int t=0;
	string :: iterator siter;
	while(getline(ifs,lineword))
	{
		
		_vecLines.push_back(lineword);
		stringstream ss(lineword);
		line++;
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
						cout<<stemp<<endl;
						putmap(stemp,line);
					}
					k=0;stemp="";
				
				}
				if(stemp!=""&&siter==(--sword.end()))
				{
						cout<<"end:"<<stemp<<endl;
						putmap(stemp,line);
				}
				
		
			}
		}
	}
}

int main()
{	
	TextQuery* ws = new TextQuery();
	ws->readFile("china_daily.txt");
	string word;
	cin>>word;
	ws->query(word);
	delete ws;
	return 0;

}
