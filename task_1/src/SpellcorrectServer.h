 ///
 /// @file    SpellcorrectServer.h
 /// @author  wyy
 /// @date    2016-08-24 04:21:47
 ///
 
#include "MyTask.h"
#include "./Threadpool/Threadpool.h"
#include "./epoll/TcpServer.h" 
using namespace wyy;
using namespace std;
class SpellCorrectServer
{
	public:
		SpellCorrectServer(const string& cgfFileName);
		void start();
		void onConnection(TcpConnectionPtr conn);
		void onMessage(TcpConnectionPtr conn);
		void onClose(TcpConnectionPtr conn);
	private:
		//MyConf _conf;
		TcpServer _tcpServer;
		Threadpool _threadpool;
	//	TimerThread _timer;
};
SpellCorrectServer::SpellCorrectServer(const string& cgfFileName)
:_tcpServer(8886)
,_threadpool(4,5)
{
	
	Mydict::createInstance()->init(cgfFileName.c_str());
	_tcpServer.setConnectionCallback(std::bind(&SpellCorrectServer::onConnection,this,placeholders::_1));
	_tcpServer.setMessageCallback(std::bind(&SpellCorrectServer::onMessage,this,placeholders::_1));
	_tcpServer.setCloseCallback(std::bind(&SpellCorrectServer::onClose,this,placeholders::_1));

	cout<<" construct done"<<endl;
	
}
void SpellCorrectServer::start()
{
	
	_threadpool.start();
	_tcpServer.start();
}
void SpellCorrectServer::onConnection(TcpConnectionPtr conn)
{
	//cout<<conn->toString()<<"has connected"<<endl;
	cout<<"connected"<<endl;
	conn->send("welcome to server!");
	//conn->send("please put the word:");
}

void SpellCorrectServer::onMessage(TcpConnectionPtr conn)
{
	string msg=conn->receive();
	cout << msg << ":" << msg.size() << endl;
	msg.pop_back();
	MyTask *p=new MyTask(msg,conn);
	_threadpool.addTask(std::bind(&MyTask::execute,p,placeholders::_1));
//	conn->send(p.myresult._iFreq);
}
void SpellCorrectServer::onClose(TcpConnectionPtr conn)
{
	cout<<conn->toString()<<"has closed"<<endl;
}
