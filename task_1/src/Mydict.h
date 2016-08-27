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
		int judge(char c);
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
			
		
			string str;
			set<int> setp;
			if((itm->first)[i] > 0)
			 str.push_back(itm->first[i]);
			
			else
			{
				
				str.push_back(itm->first[i]);
				int j=judge(itm->first[i]);
				if(j)
				{
				int k;
				for( k=i+1;k<i+j;k++)
				str.push_back(itm->first[k]);
				i+=j-1;
				}
				
			}
			
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
int Mydict::judge(char c)
{
    char result[8]={0};
	int num=0;
	for(int i=0;i<8;i++)
	   {	
		   result[i]=c&(0x80>>i);
		   if(result[i])
				num++;
		   else
			   return num;
	   }

}
