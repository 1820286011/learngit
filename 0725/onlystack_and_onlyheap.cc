 ///
 /// @file    only_stack.cc
 /// @author  wyy
 /// @date    2016-07-25 08:12:02
 ///
 
#include <iostream>
#include<string.h>
using namespace std;
class Ostack
{
	public:
		Ostack():name(new char[strlen("only_stack!")+1])
		{
			strcpy(name,"only_stack!");
			cout<<"Its name is : "<<name<<endl;
			cout<<"Ostack()"<<endl;
		}
		~Ostack()
		{
			delete name;
			cout<<"~Ostack()"<<endl;
		}
	private:
		char *name;
		static void* operator new(size_t nSize);
		static void operator delete(void *pVoid);
};

class Oheap
{
	public:
		Oheap():name(new char[strlen("only_Oheap!")+1])
				{
				   strcpy(name,"only_Oheap!");
				   cout<<"Its name is:"<<name<<endl;
				   cout<<"Oheap()"<<endl;
				}
		void destroy()
		{
		   delete name;
			this->~Oheap();
		   //cout<<" destory()"<<endl;

		}
	private:
		char *name;
		~Oheap()
		{
			cout<<"~Oheap()"<<endl;
		}
};
int main()
{

	Oheap *op = new Oheap;
    op->destroy();
	//Oheap opp;
	Ostack ot;
	//	Ostack *op = new Ostack;



	return 0;
}
