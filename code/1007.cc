 ///
 /// @file    1007.cc
 /// @author  wyy
 /// @date    2016-07-30 07:46:57
 ///
 
#include <iostream>
#include <math.h>
using namespace std;
bool prime(int i)
{
	for(int j=2;j<=sqrt(i);j++)
	{
		if(i%j==0)return false;
	}
	return true;

}

int main()
{
	int n,left=0,right=0,num=0,init=true;
	cin>>n;

	for(int i=3;i<=n;i++)
	{
		if(prime(i))
		{
			//cout<<i<<endl;
			if(init)
			{
			  if(!left)left=i;
			  else{ right=i;init=false;}
			  if((right-left)==2)num++;
			}
			else
			{
				left=right;
				right=i;
				if((right-left)==2)num++;
			}
		}
	}
	cout<<num<<endl;
}


