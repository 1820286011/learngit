 ///
 /// @file    insert_iterator.cc
 /// @author  wyy
 /// @date    2016-08-08 05:44:49
 ///
 
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
using std::cout;
using std::endl;
using std::vector;
using std::list;
using std::iterator;
using std::back_insert_iterator;
using std::front_insert_iterator;
using std::insert_iterator;

template <typename Container>
void display(Container & c)
{
	typename Container::iterator it;
	for(it=c.begin();it!=c.end();it++)
	{
		cout<<*it<<"  ";
	}
	cout<<endl;
}
int main()
{
	vector<int> vc={1,2,3};
	list<int> listint;
	copy(vc.begin(),vc.end(),back_insert_iterator<list<int> >(listint));
	display(listint);
	
	copy(vc.begin(),vc.end(),front_insert_iterator<list<int> >(listint));
	display(listint);

	copy(vc.begin(),vc.end(),insert_iterator<list<int> >(listint,++listint.begin()));
	display(listint);


	return 0;
}
