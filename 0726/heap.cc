 ///
 /// @file    heap.cc
 /// @author  wyy
 /// @date    2016-07-26 06:10:29
 ///
 
#include <iostream>
#define n 3         
using namespace std;
class quene
{
	public:
		quene();
		void push(int x);
		void pop();
		int front();
		int back();
		bool emty();
		bool full();
	private:
		int element[n];
		int frontindex;
		int backindex;
		bool jempty;
		bool init;
		

};

quene :: quene()
	:frontindex(-1),
	 backindex(-1),
	 jempty(false),
	 init(true)
{
	cout<<"create a quene!"<<endl;

}
void quene :: push(int x)
{
	if(frontindex<0)
	{
		frontindex=0;backindex=0;
		element[backindex]=element[frontindex]=x;
		cout<<"push : "<<x<<endl;
	}
	else
	{	
		backindex=(backindex+1)%n;
		if(full())
		{
			backindex=(backindex+n-1)%n;
		}
		else
		{
			element[backindex]=x;
			cout<<"push : "<<x<<endl;
		}
	}
}

void quene :: pop()
{
	if(frontindex<0)
	{
		cout<<"the heap is empty!"<<endl;
	}
	else
	{
		
		if(!emty())
		{
			cout<<"pop : "<<element[frontindex]<<endl;
			frontindex=(frontindex+1)%n;		
		}

	}
}

bool quene :: emty()
{
	if(frontindex==((backindex+1)%n) && jempty==true)
	{
		frontindex=(frontindex+n-1)%n;
		cout<<"the quene is empty!"<<endl;
		return true;

	}
	if(frontindex==backindex && jempty==false)
	{
		jempty=true;
		return false;
	}
	if(jempty==false)
		return false;
}

bool quene :: full()
{
	if(init) 
	{
		init = false;
		return false;
	
	}

	if(frontindex==backindex)
	{
		cout<<"the quene is full!"<<endl;
		return true;
	}
	else
	{
		jempty=false;
		return false;
	}
}

int quene :: front()
{
	return element[frontindex];
}

int quene :: back()
{
	return element[backindex];
}

int main()
{
	quene * q = new quene();
	q->push(1);
	q->push(2);
	q->push(3);
	q->push(4);
	q->pop();
	q->push(5);
    q->pop();
	q->push(6);
	q->pop();
	q->push(7);
	q->pop();
	
    delete q;
}
