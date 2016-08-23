 ///
 /// @file    Mydict.h
 /// @author  wyy
 /// @date    2016-08-22 07:05:15
 ///
#include "Produce_Dict.h"
#include <iostream>
using namespace std;
class Mydict
{
	public:
		static Mydict*createInstance();
		void init(const char *dictEnPath,const char*dictCnPath=NULL);
		vector<pair<string,int> >& getDict();
		map<string,set<int> >& getIndexTable();
	private:
		Mydict(){}
		vector<pair<string,int> >_dict;
		map<string,set<int> >_index_table;
		ProDict _prodt;
		static Mydict*pmy;
};
Mydict* Mydict::pmy=NULL;
Mydict * Mydict::createInstance()
{
	if(pmy==NULL)
	{
		pmy=new Mydict();
	}
	return pmy;
}
vector<pair<string,int> >& Mydict::getDict()
{
	return _dict;
}
map<string,set<int> >& Mydict::getIndexTable()
{
	return _index_table;
}
void Mydict::init(const char *dictEnPath,const char*dictCnPath)
{
	map<string,int>::iterator itm;
	map<string,int> DicMap;
	map<string,set<int> >::iterator its;
	_prodt.readFile(dictEnPath);
	DicMap=_prodt.getMap();
	int index=0;
	for(itm=DicMap.begin();itm!=DicMap.end();itm++)
	{
		
		_dict.push_back(*itm);
		for(int i=0;i<(itm->first).size();i++)
		{
			
			stringstream stream;
			string str;
			set<int> setp;
			stream<<(itm->first)[i];
			str=stream.str();
			its=_index_table.find(str);
			

			if(its==_index_table.end())
			{
				setp.insert(index);
				_index_table.insert(pair<string,set<int> >(str,setp));

			}
			else
			{
				_index_table[str].insert(index);
			}

					
		}
		index++;
		
	}

}
