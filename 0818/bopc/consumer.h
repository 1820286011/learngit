 ///
 /// @file    consumer.h
 /// @author  wyy
 /// @date    2016-08-18 06:07:39
 ///
#include "Buffer.h"
#include "thread.h"
#include <iostream>
#include <unistd.h>
using std::cout;
using std::endl;
class Consumer
{
	public:
		Consumer(wyy::Buffer& buff)
		:_buff(buff)
		{
		
		}
		void getnum() 
		{
			while(1)
			{
				cout<<"consume the :"<<_buff.pop()<<endl;
				sleep(5);
			}
		}
	private:
		wyy::Buffer& _buff;

};

