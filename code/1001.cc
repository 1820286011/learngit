 ///
 /// @file    1001.cc
 /// @author  wyy
 /// @date    2016-07-26 01:35:08
 ///
 
#include <iostream>
using namespace std;
int main()
{
	int x;int count=0;
	cin>>x;
	while(x!=1)
	{
		if(x%2==0)
		{
			x=x/2;
		}
		else
		{
			int y=3*x+1;
			x=y/2;
		}
		count++;
	}
	cout<<count<<endl;

}
