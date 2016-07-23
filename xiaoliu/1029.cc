 ///
 /// @file    1029.cc
 /// @author  wyy
 /// @date    2016-07-23 00:58:53
 ///
 
#include <iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main(){  
	string ss1;
	string ss2;
	//char s1[80];
	//char s2[80];
	//char *s1;
	//char *s2;
	bool bad[200];
	getline(cin,ss1);
	getline(cin,ss2);
    const char *s1 = ss1.c_str();
	const char *s2 = ss2.c_str();
	//scanf("%s",s1);
	//scanf("%s",s2);
	for(int i=0;s1[i]!='\0';i++){
		bad[(int)s1[i]]=true;
	}
	for(int i=0;s2[i]!='\0';i++){
		if(bad[(int)s2[i]]){
			bad[(int)s2[i]]=false;
		}
	}
	for(int i=0;s1[i]!='\0';i++){
		if(bad[(int)s1[i]]){
			cout<<s1[i];
            bad[(int)s1[i]]=false;
		}
	}
	cout<<endl;
	cout<<'Z';
	return 0;
}
