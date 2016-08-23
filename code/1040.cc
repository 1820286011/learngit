 ///
 /// @file    1040.cc
 /// @author  wyy
 /// @date    2016-08-02 04:52:40
 ///
 
#include <iostream>
#include <string>
#include <string.h>
using namespace std;

int main()
{
	string s;
	int ca=0,ct=0,cp=0;
	cin>>s;
	for(int i=s.length()-1;i>=0;i--)
	{
	  if(s[i]=='T')ct=(ct+1)%1000000007;
	  if(s[i]=='A')ca=(ct+ca)%1000000007;
	  if(s[i]=='P')cp=(ca+cp)%1000000007;
	}
	cout<<cp<<endl;

}
