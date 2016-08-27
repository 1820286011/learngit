 ///
 /// @file    Cache.h
 /// @author  wyy
 /// @date    2016-08-25 00:40:58
 ///
#ifndef _WYY_CACHE_H_
#define _WYY_CACHE_H_
#include<unordered_map>
#include<string>
#include<iostream>
#include<fstream>
#include<sstream>
using namespace std;

class Cache
{
	public:
		Cache(int num=10);
		Cache(const Cache& cache);
		void addElement(const string & key,const string & value);
		void readFromFile(const string& filename);
		void writeToFile(const string& filename);
		void update(const Cache& rhs);
		unordered_map<string,string> &getmap();
	private:
		unordered_map<string,string> _hashMap;
};

#endif
