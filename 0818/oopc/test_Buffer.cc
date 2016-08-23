 ///
 /// @file    test_Buffer.cc
 /// @author  wyy
 /// @date    2016-08-18 07:04:04
 ///
#include "Buffer.h"
#include "producer.h"
#include "consumer.h"
#include <iostream>
using namespace wyy;
int main()
{
	Buffer* buff=new Buffer(10);
	Producer* pro=new Producer(*buff);
	Consumer* con=new Consumer(*buff);
	pro->start();
	con->start();
	pro->join();
	pro->join();
	delete pro;
	delete con;
	return 0;
}
