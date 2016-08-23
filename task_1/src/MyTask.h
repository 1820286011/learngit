 ///
 /// @file    MyTask.h
 /// @author  wyy
 /// @date    2016-08-23 00:41:47
 ///
#include "Mydict.h"
#include <iostream>
#include <vector>
#include <set>
#define _dict Mydict::createInstance() 
class MyTask
{
	public:
		MyTask(const string& queryWord,int peerfd);
		//void execute(Cache &cache);
	
		void queryIndexTable();
		void statistic(set<int> &iset);
		int distance(const string& rhs);
		//void response(Cache &cache);
	private:
		string _queryWord;
		int _peerfd;
	//	Priority _queue<MyResult,vector<MyResult>,MyCompare> _resultQue;
		
};
MyTask::MyTask(const string&queryWord,int peerfd)
{
	_queryWord=queryWord;
}
void MyTask::queryIndexTable()
{
	set<int> rset,tpset;
	set<int>::iterator itset;
	map<string,set<int> >IndexTable=_dict->getIndexTable();
	for(int i=0;i<_queryWord.size();i++)
	{
		
		stringstream stream;
		stream<<_queryWord[i];
		tpset=IndexTable[stream.str()];
		for(itset=tpset.begin();itset!=tpset.end();itset++)
		{
			rset.insert(*itset);
		}
	}
	statistic(rset);
}
void MyTask::statistic(set<int> &iset)
{
	vector<pair<string,int> > dict=_dict->getDict();
	set<int>::iterator itst;
	int min=-1,tmin;
	string smin;
	for(itst=iset.begin();itst!=iset.end();itst++)
	{
		
	//	cout<<dict[*itst].first;
		int tmin=distance(dict[*itst].first);
	//	cout<<"  distance: "<<tmin<<endl;
		if(min<0)
		{
			min=tmin;
			smin=dict[*itst].first;
		}
		else 
		{
			if(tmin<min)
			{
				min=tmin;
				smin=dict[*itst].first;
			}

		}
	    
	}
	cout<<"min_distance : "<<min<<"  word:  "<<smin<<endl;
}
int MyTask::distance(const string &rhs)
{
	int n=rhs.size();
	int m=_queryWord.size();
	int d[n+1][m+1];
	int insertCost=1,deleteCost=1,substituteCost;
	d[0][0]=0;
	for(int i=0;i<n+1;i++)
		d[i][0]=i;
	for(int i=0;i<m+1;i++)
		d[0][i]=i;
	for(int i=1;i<n+1;i++)
		for(int j=1;j<m+1;j++)
		{
			int a=d[i-1][j]+insertCost;
			int b=d[i][j-1]+deleteCost;
			if(rhs[i-1]==_queryWord[j-1])
				substituteCost=0;
			else
				substituteCost=2;
			int c=d[i-1][j-1]+substituteCost;
			d[i][j]=(a<b?a:b)<c?(a<b?a:b):c;
		}
	return d[n][m];

}

