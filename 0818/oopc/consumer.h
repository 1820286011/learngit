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
:public wyy::Thread
{
	public:
		Consumer(wyy::Buffer& buff)
		:_buff(buff)
		{
			cout<<"Consumer :"<<nums<<endl;
			nums++;
		}
		void run()
		{
			while(1)
			{
				cout<<"consume the :"<<_buff.pop()<<endl;
				sleep(2);
			}
		}
	private:
		wyy::Buffer& _buff;
		static int nums;

};
int Consumer::nums=1;
