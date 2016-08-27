 ///
 /// @file    Cache.cc
 /// @author  wyy
 /// @date    2016-08-25 01:31:37
 ///
 
#include "Cache.h"
using namespace std;
Cache::Cache(int num)
{
}
Cache::Cache(const Cache& cache)
{
	_hashMap.clear();
	_hashMap=cache._hashMap;
}
void Cache::addElement(const string& key,const string& value)
{
	_hashMap.insert(pair<string,string>(key,value));
}
void Cache::readFromFile(const string& filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{
		cout<<"open error!"<<endl;
		return;
	}
	string smap;
	string sword;
	while(getline(ifs,smap))
	{
		stringstream ss(smap);
		string key,value;
		ss>>key>>value;
		_hashMap.insert(pair<string,string>(key,value));	
	}
}
void Cache:: writeToFile(const string& filename)
{
	unordered_map<string,string>::iterator itmap;
	ofstream ofs(filename.c_str());
	if(ofs.is_open())
	{
		for(itmap=_hashMap.begin();itmap!=_hashMap.end();itmap++)
		{
			ofs<<itmap->first<<"     "<<itmap->second<<endl;
		}
	}
}

void Cache::update(const Cache& rhs)
{
	 unordered_map<string,string>::const_iterator itm;
	for(itm=rhs._hashMap.begin();itm!=rhs._hashMap.end();itm++)
	{
		_hashMap.insert(pair<string,string>(itm->first,itm->second));
	}
}
unordered_map<string,string> &Cache::getmap()
{
	cout<<"&_hamap"<<&_hashMap<<endl;
	return _hashMap;
}

