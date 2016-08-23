 ///
 /// @file    test_Eventfd.cc
 /// @author  wyy
 /// @date    2016-08-21 02:23:43
 ///
 
#include "thread.h"
#include "Eventfd.h"
#include <time.h>
#include <stdlib.h>
#include <unistd.h>
using namespace wyy;
using std::cout;
using std::endl;
class Produ
{
	public:
		void getnum()
		{
			srand((unsigned)time(NULL));
			int num=rand()%100;
			cout<<"num= "<<num<<endl;
		}
};
int main()
{
		Produ pro;
		Eventfd *efd=new Eventfd(std::bind(&Produ::getnum,&pro));
		Thread * pth=new Thread(std::bind(&Eventfd::start,efd));
			pth->start();
		int n=5;
		while(n--)
		{
			efd->wakeup();
			sleep(1);
		}
			efd->stop();
		delete pth;
		delete efd;
		return 0;
}
