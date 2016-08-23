 ///
 /// @file    producer.h
 /// @author  wyy
 /// @date    2016-08-18 05:50:23
 ///
#include "Buffer.h"
#include "thread.h"
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
using std::cout;
using std::endl;
class Producer
{
	public:
		Producer(wyy::Buffer&buff)
		:_buff(buff)
		{
			
		}
		void pushnum()
		{
			srand(time(NULL));
			while(1)
			{
				int n=rand()%100;
				cout<<" produce:"<<n<<endl;
				_buff.push(n);
				sleep(1);
				
			}
		}
	private:
		wyy::Buffer & _buff;
	
};

