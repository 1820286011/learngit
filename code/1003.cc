 ///
 /// @file    1003.cc
 /// @author  wyy
 /// @date    2016-07-26 02:20:54
 ///
 
#include <iostream>
#include <string.h>
using namespace std;
int main()
{
	int n;
	cin>>n;
	string *str = new string[n];
	string *result = new string[n];
	for(int i=0;i<n;i++)
	{
		int ca1=0,ca2=0,ca3=0,cp=0,ct=0;
		cin>>str[i];
		const char*p=str[i].c_str();
		for(int j=0;j<strlen(p);j++)
		{
			if(p[j]!='A'&&p[j]!='P'&&p[j]!='T')
			{
				result[i]="NO";
				break;
			}
			if(p[j]=='P')
			{
				if(cp==0&&ct==0)cp=1;
				else
				{
					result[i]="No";
					break;
				}

			}
			if(p[j]=='T')
			{
				if(ct==0&&cp==1)ct=1;
				else
				{
					result[i]="No";
					break;
				}
			}
			if(p[j]=='A')
			{
				if(cp==0)ca1++;
				if(cp==1&&ct==0)ca2++;
				if(cp==1&&ct==1)ca3++;
			}
		}
		
			
		if(ca2==0)result[i]="NO";
		else
		{	if(ct==0||cp==0) {result[i]="NO";}
		else{	if(ca2==1){result[i]="YES";continue;}
			if(ca2>1)
			{
				if(ca1==0&&ca3==0)result[i]="YES";
				else{	int b=ca3-ca1*(ca2-1);
				if(b>0)result[i]="YES";
				else result[i]="NO";}
			}
			else if(ct==1&&cp==1&&ca2>0){
			result[i]="YES";}
		}
		}

	}
	for(int i=0;i<n;i++)
	{
		cout<<result[i]<<endl;
	}
}
