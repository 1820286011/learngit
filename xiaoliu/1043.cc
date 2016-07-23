 ///
 /// @file    1043.cc
 /// @author  wyy
 /// @date    2016-07-23 01:47:58
 ///
 
#include <iostream>
#include<stdio.h>
#include<malloc.h>
using namespace std;
int w[]={(int)"P",(int)"A",
	     (int)"T",(int)"e",
		 (int)"s",(int)"t"};
int main(){
	char * p = (char*)malloc(10000*sizeof(char));
    int a[200]={0};
	scanf("%s",p);
    for(int i=0;p[i]!='\0';i++){
		cout<<(int)p[i]<<endl;
       a[(int)p[i]]++;   
	}
    bool has = false;
	do{
		has = false;
		for(int i=0;i<6;i++){
			if(a[w[i]]!=0){
              a[w[i]]--;
              has = true;
			  cout<<(char)w[i];
			}
		}
	}while(has);
	cout<<endl;
}
