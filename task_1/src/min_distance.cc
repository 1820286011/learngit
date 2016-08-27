 ///
 /// @file    min_distance.cc
 /// @author  wyy
 /// @date    2016-08-22 04:27:40
 ///
 
#include <iostream>
#include <string>
#include <vector>
using namespace std;
int Min_Edit_Distance(vector<string> target,vector<string> sourse)
{
	int n=target.size();
	int m=sourse.size();
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
			if(target[i-1]==sourse[j-1])
				substituteCost=0;
			else
				substituteCost=2;
			int c=d[i-1][j-1]+substituteCost;
			d[i][j]=(a<b?a:b)<c?(a<b?a:b):c;
		
			
		}
	return d[n][m];

}
int main()
{
	vector<string> s1;
	vector<string> s2;
	cout<<"苗苗"<<endl;
	cout<<"苗苗猪"<<endl;
	s1.push_back("苗");
	s1.push_back("苗");
	s2.push_back("苗");
	s2.push_back("苗");
	s2.push_back("猪");
    cout<<"result:"<<Min_Edit_Distance(s1,s2)<<endl;
}
