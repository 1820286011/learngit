 ///
 /// @file    split_cword.cc
 /// @author  wyy
 /// @date    2016-08-25 20:34:25
 ///
 
#include "cppjieba/Jieba.hpp"
#include "cppjieba/KeywordExtractor.hpp"
#include <iostream>
#include <fstream>
using namespace std;
const char* const DICT_PATH="../include/dict/jieba.dict.utf8";
const char* const HMM_PATH="../include/dict/hmm_model.utf8";
const char* const USER_DICT_PATH="../include/dict/user.dict.utf8";
const char* const IDF_PATH="../include/dict/idf.utf8";
const char* const STOP_WORD_PATH="../include/dict/stop_words.utf8";
const char* const readFile="../data/C3-Art0002.txt";
const char* const writeFile="../data/C3-2out.txt";

int main(int argc,char**argv)
{
	cppjieba::Jieba jieba(DICT_PATH,HMM_PATH,USER_DICT_PATH);
	vector<string> words;
	vector<cppjieba::Word> jiebawords;
	string s;
	string result;
	ifstream ifs;
	ofstream ofs;
	ifs.open(readFile);
	ofs.open(writeFile);
	while(getline(ifs,s))
	{
		jieba.CutAll(s,words);
		ofs<<limonp::Join(words.begin(),words.end()," ")<<endl;
	}


}
