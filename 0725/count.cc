 ///
 /// @file    count.cc
 /// @author  wyy
 /// @date    2016-07-25 04:57:35
 ///
 
#include <iostream>
#include<map>
#include<string>
#include<fstream>
#include<stdlib.h>
#include<iomanip>
using namespace std;

class WordStatic
{
	public:
		void read_file(string filename);
		void write_file(string filename);
	private:
		map<string,int> count_map;
		map<string,int>::iterator cm_iter;

};

void WordStatic :: read_file(string filename)
{
	ifstream ifs(filename.c_str());
	if(!ifs.good())
	{ 
		cout<<" open error!"<<endl;
		return;
	}
	string sword;
	while(ifs>>sword)
	{
    	
		if(atoi(sword.c_str())!=0)continue;
		cm_iter=count_map.find(sword);
		if(cm_iter==count_map.end())
		{
			count_map.insert(pair<string,int>(sword,1));
			
		}
		else
		{
			int i = count_map[sword];
			count_map[sword]=++i;
		}
	}


}
void WordStatic :: write_file(string filename)
{
	ofstream ofs(filename.c_str(),ios::app);
	for(cm_iter=count_map.begin();cm_iter!=count_map.end();cm_iter++)
	{
		ofs<<left<<setw(6)<<"word:"<<setw(20)<<cm_iter->first<<left<<setw(7)<<"counts: "<<cm_iter->second<<endl;
	}
}

int main()
{	
	WordStatic* ws = new WordStatic();
	ws->read_file("The_Holy_Bible.txt");
	ws->write_file("counts_result.txt");
	delete ws;
	return 0;

}
