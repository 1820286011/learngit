 ///
 /// @file    test.cc
 /// @author  wyy
 /// @date    2016-08-22 18:58:04
 ///

#include "Mydict.h"
using namespace std;
int main()
{
	string s;
		Mydict *m=Mydict::createInstance();
	m->init("../data/source1.txt");
	vector<pair<string,int> > vt=m->getDict();
	map<string,set<int> >& mp=m->getIndexTable();
	map<string,set<int> >::iterator itm;
	cout<<"vector size:"<<vt.size()<<endl;
	cout<<"map size:"<<mp.size()<<endl;
	while(cin>>s){

	itm=mp.find(s);
	set<int> setl=itm->second;
	set<int>::iterator itst;
	cout<<"set.size()"<<setl.size()<<endl;
	
	int i=0;

		for(itst=setl.begin();itst!=setl.end();itst++)
		{cout<<vt[*itst].first<<endl;
			cout<<vt[*itst].second<<endl;
			i++;
		}
		cout<<"n:"<<i<<endl;

	}

}
