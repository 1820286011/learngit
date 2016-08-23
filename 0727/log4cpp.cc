 ///
 /// @file    log4cpp.cc
 /// @author  wyy
 /// @date    2016-07-27 06:00:41
 ///
 
#include <iostream>
#include <string.h>
#include<log4cpp/PatternLayout.hh>
#include <log4cpp/Category.hh>
#include <log4cpp/BasicLayout.hh>
#include <log4cpp/OstreamAppender.hh>
#include <log4cpp/Priority.hh>
#include <log4cpp/FileAppender.hh>
using namespace std;
using namespace log4cpp;

class Mylog
{
	public:
		static Mylog * getInstance(const char * apdname)
		{
			if(!ml)	ml = new Mylog(apdname);
			return ml;
		}
		void destroy()
		{
			if(ml!=NULL) this->~Mylog();
		}
		~Mylog()
		{
			//delete ml;
			ml=NULL;
			delete _msg;
			Category::shutdown();
			cout<<"~Mylog"<<endl;
			
		}
		void warn(const char * msg)
		{
			if(!_msg)delete _msg;
			_msg = new char[strlen(msg)+1];
			strcpy(_msg,msg);
			coutcat.warn(_msg);
			Cat.warn(_msg);

		}
		void error(const char * msg)
		{
			if(!_msg)delete _msg;
			_msg = new char[strlen(msg)+1];
			strcpy(_msg,msg);
			coutcat.error(_msg);
			Cat.error(_msg);


		}
		void debug(const char * msg)
		{
			if(!_msg)delete _msg;
			_msg = new char[strlen(msg)+1];
			strcpy(_msg,msg);
			coutcat.debug(_msg);
			Cat.debug(_msg);

		}
		void info(const char * msg)
		{
			if(!_msg)delete _msg;
			_msg = new char[strlen(msg)+1];
			strcpy(_msg,msg);
			coutcat.info(_msg);
			Cat.debug(_msg);

		}
	private:
		Mylog(const char * apdname)
			:_apdname(new char[strlen(apdname)+1]),
			 coutcat(Category::getRoot().getInstance("debugcat")),
			 Cat(Category::getRoot().getInstance("Cat")),
			 _msg(NULL)
		{
			strcpy(_apdname,apdname);
			
			ptnLayout = new PatternLayout();
			ptnLayout->setConversionPattern("%d:%p %c %x:%m%n");

			pOstreamAppender = new OstreamAppender(_apdname,&cout);
			pOstreamAppender->setLayout(ptnLayout);
			coutcat.addAppender(pOstreamAppender);
			coutcat.setPriority(Priority::DEBUG);

			ptnLayout2 = new PatternLayout();
			ptnLayout2->setConversionPattern("%d:%p %c %x:%m%n");

			pFileAppender = new FileAppender("fileAppender","note.log");
			pFileAppender->setLayout(ptnLayout2);
			Cat.addAppender(pFileAppender);
			Cat.setPriority(Priority::DEBUG);
			

						
			
		}
	   static Mylog * ml;
	   char * _msg;
	   char * _apdname;
		PatternLayout * ptnLayout;
		PatternLayout * ptnLayout2;
		OstreamAppender * pOstreamAppender;
		Category &coutcat;
		Category &Cat;
		FileAppender * pFileAppender;


		
};

Mylog * Mylog :: ml=NULL;

int main()
{
	Mylog *mg1 = Mylog :: getInstance("osappender1");
	cout<<"hello world"<<endl;
	mg1->warn("this is a warn");
	Mylog *mg2 = Mylog :: getInstance("osapender2");
	mg2->error("this is a error!");
	Mylog *mg3 = Mylog :: getInstance("osappender3");
	mg3->info("this is a info!");
	Mylog *mg4 = Mylog :: getInstance("osappender4");
	mg4->debug("this is a debug!");


	cout<<"mg1="<<mg1<<endl;
	cout<<"mg2="<<mg2<<endl;
	cout<<"mg3="<<mg3<<endl;
	cout<<"mg4="<<mg4<<endl;

	mg1->destroy();


}

