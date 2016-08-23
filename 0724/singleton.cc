 ///
 /// @file    singleton.cc
 /// @author  wyy
 /// @date    2016-07-24 06:20:41
 ///
 
#include <iostream>

#include <string>
using namespace std;
class Singleton
{
	public:
	static Singleton * init(int x)
		{
			if(p==NULL)
			{
			   
			p=new Singleton(x);
			return p;
			}else
			{
				return p;
			}
		}
	void destory()
		{
			if(p!=NULL) 
			{
				delete p;
			//	p->~Singleton();
				p=NULL;
				cout<<"destory()"<<endl;
			}


		}
	~Singleton()
	{
	}
		

	private:
		int initx;
		static Singleton * p;
		Singleton(int x):initx(x)
		{
			cout<<" init"<<endl;}

};
 Singleton* Singleton :: p=NULL;
 
 int main()
{
	Singleton *p1 = Singleton::init(2);
	Singleton *p2 = Singleton::init(2);
	cout<<"p1="<<p1<<" p2="<<p2<<endl;
	p1->destory();
	p2->destory();

}
