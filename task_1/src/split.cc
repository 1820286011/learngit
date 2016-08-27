 ///
 /// @file    split.cc
 /// @author  wyy
 /// @date    2016-08-25 18:21:02
 ///
#include<string.h>
#include<string>
#include <iostream>
using namespace std;
int judge(char c);
int main()
{
	string s;
	cin>>s;
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
		cout<<cs<<endl;


	}
}
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
