 ///
 /// @file    1005.cc
 /// @author  wyy
 /// @date    2016-07-30 05:17:57
 ///
 
#include <iostream>
#include <map>
using namespace std;
int main()
{
	map<int,bool> rmap;
	map<int,bool>::iterator it;
	map<int,bool>::iterator fit;
	int num;
	cin>>num;
	for(int i=0;i<num;i++)
	{
		int n;
		cin>>n;
		rmap.insert(pair<int,bool>(n,true));
	}
	for(it=rmap.begin();it!=rmap.end();it++)
	{
		int n=it->first;
		while(n!=1&&it->second==true)
		{		
			if(n%2==0)
			{
				n=n/2;
			}
			else
			{
				n=(3*n+1)/2;
			}
			fit=rmap.find(n);
			if(fit!=rmap.end())
			{
			   rmap[n]=false;
			}
		}
	
	}
		int k=0;
		for(fit=rmap.end();fit!=rmap.begin();fit--)
		{

			if(fit->second==1&&k>0)cout<<" "<<fit->first;
			if(fit->second==1&&k==0)
			{cout<<fit->first;
				k++;
			}
		}
		if(rmap.begin()->second)cout<<" "<<fit->first;

}
