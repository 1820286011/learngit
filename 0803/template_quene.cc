 ///
 /// @file    template_quene.cc
 /// @author  wyy
 /// @date    2016-08-02 22:29:22
 ///
 
#include <iostream>
using namespace std;



template <typename T>
class node
{
	
	T value;
	node<T> * next;
	public:
	node()
	{
		next=NULL;
	}
	node(T a)
	{
		value=a;
		next=NULL;
	}
	template<typename T1,int NUM>
	friend class quene;
};
template <typename T ,int NUM>
class quene
{
	public:
		quene()
		{
			currentnum=0;
			head=tail=NULL;
			cout<<"quene()"<<endl;
			
		}
		void push(node<T>& a)
		{
			if(tail==NULL)
			{
				head=&a;
				tail=&a;
				currentnum++;
			}
			else
			{	
				if(!full())
				{	
					tail->next=&a;
					tail=&a;
					currentnum++;
				}
				else
				cout<<"the quene is full!"<<endl;
			}
		}
		void pop()
		{
			if(!empty())
			{	
				node<T>*tmp=head;
				head=head->next;
				cout<<"pop: "<<tmp->value<<endl;
				delete tmp;
				currentnum--;
						}
			else 
				cout<<"the quene is empty!"<<endl;
		}
		bool empty()
		{
			if(head==NULL)return true;
			else return false;
		}
		bool full()
		{
			if(currentnum==NUM)return true;
			else return false;
		}
		T gethead()
		{
			return head->value;
		}
		T gettail()
		{
			return tail->value;
		}

	private:
		node<T>* head;
		node<T>* tail;
		int currentnum;
};
int main()
{
	node<int> *n1=new node<int>(1);
	node<int> *n2=new node<int>(2);
	node<int> *n3=new node<int>(3);
	node<int> *n4=new node<int>(4);
	quene<int,3> que;
	que.push(*n1);
	que.push(*n2);
	que.push(*n3);
	que.push(*n4);
	cout<<"head: "<<que.gethead()<<endl;
	cout<<"tail: "<<que.gettail()<<endl;

	que.pop();
	cout<<"head: "<<que.gethead()<<endl;
	cout<<"tail: "<<que.gettail()<<endl;
	que.pop();
	cout<<"head: "<<que.gethead()<<endl;
	cout<<"tail: "<<que.gettail()<<endl;
	que.pop();
	que.pop();
	return 0;





	
}
