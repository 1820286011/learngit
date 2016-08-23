 ///
 /// @file    1006.cc
 /// @author  wyy
 /// @date    2016-07-30 06:33:07
 ///
 
#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;
int main()
{
	char p[3];
	char result[30]={0};
	
	cin>>p;
	int n=atoi(p);
	
	if(10>n&&n>=0)
	{
		for(int i=1;i<=n;++i)
			result[i-1]='0'+i;

	}
	if(10<=n&&n<100)
	{
		int ge=n%10,ct=0;
		n=(n-ge)/10;
		for(int i=1;i<=n;i++)
		{	result[ct]='S';
			ct++;
			
		}
		//cout<<result<<endl;
		for(int j=1;j<=ge;j++)
		{
			result[ct]='0'+j;
			ct++;
		}

	}
	if(n>=100&&n<1000)
	{
		int ge=n%10;
		int sh=((n-ge)/10)%10;
		int ba=(n-sh*10-ge)/100;
		int ct=0;
		for(int i=1;i<=ba;i++)
		{
			result[ct]='B';ct++;
		}
		for(int i=1;i<=sh;i++)
		{
			result[ct]='S';ct++;
		}
		for(int i=1;i<=ge;i++)
		{
			result[ct]='0'+i;ct++;
		}
	}
	
	cout<<result<<endl;
}
