 ///
 /// @file    1021.cc
 /// @author  wyy
 /// @date    2016-07-23 01:36:24
 ///
 
#include <iostream>
#include <malloc.h>

using namespace std;
int main(){
  char * s =(char *)malloc(1000*sizeof(char));
  scanf("%s",s);
  int a[10]= {0};
  for(int i=0;s[i]!='\0';i++){
	  a[(int)s[i]-48]++;
  }
  for(int i=0;i<10;i++){
	  if(a[i]!=0){
		  cout<<i<<":"<<a[i]<<endl;
	  }
  }
}
