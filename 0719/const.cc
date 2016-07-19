 ///
 /// @file    reference.cc
 /// @author  wyy
 /// @date    2016-07-19 05:44:45
 ///
 
#include <iostream>
using namespace std;

int main()
{
  int b,c;
  b=5;
  c=6;
  int * const p=&b;
*p=c;
  
  cout<<"p="<<*p<<endl;
  cout<<"b="<<b<<endl;
  const int *p1=&b;
  p1=&c;
cout<<"p1="<<*p1<<endl;
  b=5;
  int const *p2=&b;
  p2=&c;
  
  cout<<"b="<<b<<endl;
  cout<<"p2="<<*p2<<endl;
}
