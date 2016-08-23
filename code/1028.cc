 ///
 /// @file    1028.cc
 /// @author  wyy
 /// @date    2016-07-30 20:45:32
 ///
 
#include <iostream>
#include <string.h>
#include <string>
#include <stdlib.h>
#include <sstream>
using namespace std;
bool datelegal(int sum)
{
	if(sum>=18140906&&sum<=20140906)return true;
	return false;
}
int main()
{
	int n,num=0,min=0,max=0,year,month,day,minyear,minmonth,minday,maxyear,maxmonth,maxday,maxsum,minsum;
	string minp,maxp;
	string ssdate;
	cin>>n;
	
    stringstream sw;
		string *sname=new string[n];int init=1;
	for(int i=0;i<n;i++)
	{

		cin>>sname[i];
		cin>>year;
		cin.ignore();
		cin>>month;
		cin.ignore();
		cin>>day;
	//cout<<year<<month<<day<<endl;
	int sum=year*10000+month*100+day;

	if(datelegal(sum))
	{	if(init){minsum=maxsum=sum;init=0;minp=sname[i];maxp=sname[i];}

		num++;
		if(sum<minsum){minsum=sum;minp=sname[i];}
		if(sum>maxsum){maxsum=sum;maxp=sname[i];}		
	}

	}
	if(num>0)
	cout<<num<<" "<<minp<<" "<<maxp<<endl;
	else
		cout<<num;

}
