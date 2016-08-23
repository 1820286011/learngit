 ///
 /// @file    vector_list_dequene.cc
 /// @author  wyy
 /// @date    2016-08-04 06:29:57
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <deque>
using namespace std;

class A
{
	int _x;
	public:
		A(const A& a):_x(a._x)
		{
			cout<<"A(a)"<<_x<<endl;
		}
		A(int x=0)
		{
			_x=x;
			cout<<"A()"<<_x<<endl;

		}
		~A()
		{
			cout<<"~A()"<<endl;
		}
		void print()
		{
			cout<<_x<<endl;
		}
};
int main()
{
//	A a[5]={A(1),A(2),A(3),A(4),A(5)};
	//vector<A> vt(a,a+5);
	vector<A> v(5);
	cout<<"size(): "<<v.size()<<endl;
	cout<<"capatity(): "<<v.capacity()<<endl;
	v.push_back(A(6));
	cout<<"size(): "<<v.size()<<endl;
	cout<<"capatity(): "<<v.capacity()<<endl;
	//vector<int> vi(5);
	int i=0;
	vector<A>::iterator it;
	//for(auto & em:vt)em.print();
	for(it=v.begin();it!=v.end();++it)
	{
	//	v.push_back(A(i));
	//	i++;
	//o	(*it).print();
	it->print();
		
	}
	return 0;
}
