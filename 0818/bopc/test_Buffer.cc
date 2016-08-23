 ///
 /// @file    test_Buffer.cc
 /// @author  wyy
 /// @date    2016-08-18 07:04:04
 ///
#include "Buffer.h"
#include "producer.h"
#include "consumer.h"
#include "thread.h"
#include <iostream>
#include <functional>
using namespace wyy;
using std::bind;
using std::function;

int main()
{
	Buffer* buff=new Buffer(10);

	Producer pro(*buff);
	Consumer con(*buff);
	Thread * pthread=new Thread(bind(&Producer::pushnum,&pro));
	Thread * cthread=new Thread(bind(&Consumer::getnum,&con));
	pthread->start();
	cthread->start();
	cthread->join();
	pthread->join();
	
	
	return 0;
}
