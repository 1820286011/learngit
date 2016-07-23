 ///
 /// @file    1002.cc
 /// @author  wyy
 /// @date    2016-07-23 00:03:47
 ///
#include<stdio.h>
#include <iostream>
#include<malloc.h>
#include <string>
using std::string;
using std::endl;
using std::cout;
using std::cin;
const char * words[]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};

int main(){
	int i=0;
	int sum = 0;
    //char *n = new char[100];	
	char * n = (char *)malloc(100);
	//gets(n);
	scanf("%s",n);
	for(;n[i]!='\0';i++){
		sum +=(int)n[i]-48;
	}
	//cout<<sum<<endl;
	int a[8];
	int p=0;
	while(sum>10){
		a[p] = sum % 10;
		sum =(int)((double) (sum-a[p])/10);
		p++;
	}
	a[p]=sum;
	for(;p>0;p--){
		cout<<words[a[p]]<<" ";
	}
	cout<<words[a[0]]<<endl;
}
