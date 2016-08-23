 ///
 /// @file    template_stack.cc
 /// @author  wyy
 /// @date    2016-08-02 20:10:29
 ///
 
#include <iostream>
using namespace std;

template <typename T,int NUM>
class stack
{
	public:
		stack();
		void push(const T a);
		void pop();
		bool empty();
		bool full();
		T top();
		
	private:
		int _top;
		T array[NUM];
};
template<typename T,int NUM>
stack<T,NUM>::stack():_top(-1)
{
	cout<<"stack()"<<endl;
}
template<typename T,int NUM>
T stack<T,NUM>::top()
{
	return array[_top];
	
}
template<typename T,int NUM>
void stack<T,NUM> :: push(const T a)
{
	if(!full())
	{
		_top++;
		array[_top]=a;
	}
}
template<typename T,int NUM>
void stack<T,NUM> :: pop()
{
	if(!empty())
		_top--;
}
template<typename T,int NUM>
bool stack<T,NUM>::empty()
{
	if(_top==-1)return true;
	else return false;
}
template<typename T,int NUM>
bool stack<T,NUM>::full()
{
	if(_top==NUM-1)return true;
	else return false;
}
int main()
{
	stack<int,10>s1;
	s1.push(5);
	s1.push(7);
	s1.pop();
	
	cout<<s1.top()<<endl;
}
