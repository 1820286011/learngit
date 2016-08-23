 ///
 /// @file    1039.cc
 /// @author  wyy
 /// @date    2016-07-29 07:31:18
 ///
 
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
using namespace std;
int main()
{
	string sshop,sself;
	bool buy=true;
	int q=0,d=0;
	int rnum=0;
	int cot[130];
	memset(cot,0,sizeof(cot));
	cin>>sshop;
	cin>>sself;
	const char * sp=sshop.c_str();
	const char * sf=sself.c_str();
	for(int i=0;i<sshop.length();i++)
	{
		int tmp=(int)(sp[i]);
		cot[tmp]++;
	}
	for(int i=0;i<sself.length();i++)
	{
		int tmp=(int)(sf[i]);
		cot[tmp]--;
		if(cot[tmp]<0)buy=false;
	}
	
		for(int i=0;i<130;i++)
		{
			if(cot[i]<0)q+=cot[i];
			if(cot[i]>0)d+=cot[i];
			cout<<cot[i]<<endl;

		}
		if(buy)cout<<"Yes "<<d<<endl;
		else cout<<"No "<<-q<<endl;
	


}
