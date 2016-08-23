 ///
 /// @file    Buffer.h
 /// @author  wyy
 /// @date    2016-08-18 05:21:29
 ///
#ifndef WYY_BUFFER_H
#define WYY_BUFFER_H
#include "MutexLock.h"
#include "Condition.h"
#include <iostream>
#include <queue>
using std::cout;
using std::endl;
using std::queue;
namespace wyy
{

class Buffer
{
	public:
		Buffer(size_t size);
		bool empty();
		bool full();
		void push(int elem);
		int pop();
	private:
		size_t _queSize;
		queue<int>_que;
		wyy::MutexLock _mutex;
		wyy::Condition _notFull;
		wyy::Condition _notEmpty;

};

}


#endif
