 ///
 /// @file    stack.cc
 /// @author  wyy
 /// @date    2016-07-26 05:42:50
 ///
 
#include <iostream>
using namespace std;
class stack
{
	public:
		stack();
		void push(int);
		void pop();
		int top();
		bool emty();
		bool full();
	private:
		int element[10];
		int topindex;

};

stack :: stack():topindex(-1){cout<<"create a stack!"<<endl;}
void stack :: push(int x)
{
	topindex++;
	if(full()) {cout<<"stack is full!"<<endl;topindex++;}
	else
	{
		element[topindex]=x;
		cout<<"push : "<<x<<endl;
	}
}
void stack :: pop()
{
	if(emty()) cout<<"stack is empty!"<<endl;
	else
	{
		cout<<"pop() : "<<element[topindex]<<endl;
		topindex--;
	}

}

int stack :: top()
{
//	cout<<"the top num is: "<<element[topindex]<<endl;
	return element[topindex];
}

bool stack :: emty()
{
	if(topindex<0)
	{
		cout<<"stack is empty!"<<endl;
		return true;
	}
	return false;
	
}

bool stack :: full()
{
	if(topindex==10) 
	{
		cout<<"stack is full!"<<endl;
		return true;
	}
	return false;
}

int main()
{
	stack *st = new stack();
	st->push(10);
	st->push(12);
	st->push(14);
    cout<<"the top num is: "<<st->top()<<endl;
    st->pop();
	cout<<"the top num is: "<<st->top()<<endl;
}
