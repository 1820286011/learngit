 ///
 /// @file    template_singleton.cc
 /// @author  wyy
 /// @date    2016-08-03 05:54:58
 ///
 
#include <iostream>
#include <stdlib.h>
using namespace std;
template <typename T>
class Singleton
{
	public:
		static T *getInstance();
		static void destroy();
	private:
	    Singleton();
		~Singleton();
		int refcount;
		static T * p;
};
template<typename T>
T* Singleton<T>::p=NULL;

template<typename T>
void Singleton<T>::destroy()
{
	//~Singleton();
	delete p;
}
template<typename T>
T *Singleton<T> :: getInstance()
{

	if(p)return p;
	::atexit(Singleton<T>::destroy);
	p=new T;
	return p;
}
template<typename T>
Singleton<T> :: Singleton()
{
	refcount=0;
}
template<typename T>
Singleton<T> ::~Singleton()
{
	cout<<"~Singleton()"<<endl;
}
class A
{
	public:
		A()
		{
			cout<<"A()"<<endl;
		}
	   ~A()
	   {
		   cout<<"~A()"<<endl;
	   }
};
int main()
{
	A*p1=Singleton<A>::getInstance();
	A*p2=Singleton<A>::getInstance();
	cout<<p1<<"  "<<p2<<endl;
	

}
