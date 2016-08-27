 ///
 /// @file    MyTask.h
 /// @author  wyy
 /// @date    2016-08-23 00:41:47
 ///
#include "Mydict.h"
#include "./epoll/TcpServer.h"
#include "Cache.h"
#include <iostream>
#include <vector>
#include <set>
#define _dict Mydict::createInstance() 
using namespace wyy;
struct MyResult
{
	string _word;
	int _iFreq;
	int _iDist;
};
int judge(char c)
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
void getSword(const string &s,vector<string>& vs)
{
	
	const char* pchar=s.c_str();
	for(int i=0;i<strlen(pchar);i++)
	{
		string cs;
		cs.push_back(pchar[i]);
		int j=judge(pchar[i]);
		if(j)
		{
			int k;
			for( k=i+1;k<i+j;k++)
				cs.push_back(pchar[k]);
			i+=j-1;
		}
		vs.push_back(cs);
	}
	

}

class MyTask
{
	public:
		MyTask(const string& queryWord,TcpConnectionPtr conn);
		
		void execute(Cache *pcache);
	
		void queryIndexTable();
		void statistic(set<int> &iset);
		int distance(const string& rhs);
		//void response(Cache &cache);
			MyResult myresult;
		

	private:
		string _queryWord;
		//int _peerfd;
		TcpConnectionPtr _conn;
		Cache *_pcache;
		unordered_map<string,string> *cmap;
		
		//	Priority _queue<MyResult,vector<MyResult>,MyCompare> _resultQue;
		
};
void MyTask::execute(Cache *pcache)
{
	_pcache=pcache;
	cmap= &_pcache->getmap();
	unordered_map<string,string>::iterator itm;
	itm=cmap->find(_queryWord);
	if(itm==cmap->end())
	{
		cout<<"query"<<endl;
		queryIndexTable();
	}
	else
	{
		cout<<"map:"<<endl;
		_conn->send((*cmap)[_queryWord]);
	}
}
MyTask::MyTask(const string&queryWord,TcpConnectionPtr conn)
{
	_conn=conn;
	_queryWord=queryWord;
	
}

void MyTask::queryIndexTable()
{
	set<int> rset,tpset;
	set<int>::iterator itset;
	map<string,set<int> >IndexTable=_dict->getIndexTable();
	vector<string> vq;
	getSword(_queryWord,vq);
	for(int i=0;i<vq.size();i++)
	{
		
		
		tpset=IndexTable[vq[i]];
		for(itset=tpset.begin();itset!=tpset.end();itset++)
		{
			rset.insert(*itset);
		}
	}
	if(rset.size()==0)
		_conn->send("NULL");
	else
	{
	statistic(rset);
	_conn->send(myresult._word);
	cmap->insert(pair<string,string>(_queryWord,myresult._word));
	}
	
	
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
	myresult._word=smin;
	myresult._iDist=min;
}
int MyTask::distance(const string &rhs)
{
	vector<string>  vqueryWord;
	getSword(_queryWord,vqueryWord);
	vector<string>  vrhs;
	getSword(rhs,vrhs);
	int n=vrhs.size();
	int m=vqueryWord.size();
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
			if(vrhs[i-1]==vqueryWord[j-1])
				substituteCost=0;
			else
				substituteCost=2;
			int c=d[i-1][j-1]+substituteCost;
			d[i][j]=(a<b?a:b)<c?(a<b?a:b):c;
			
		}
	return d[n][m];

}

