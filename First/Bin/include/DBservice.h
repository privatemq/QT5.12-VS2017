#pragma once

#include <QtWidgets/QMainWindow>
#include "head.h"
#include <QSqlDatabase>
#include <QMessageBox>
#include <QSqlQuery>
#include <QSqlError>
#include <QList>
#include <string>
#include <QMutex>
#include <QVariant>

namespace DBService 
{
	
	// 定义MySQL连接信息
	typedef struct
	{
		QString server;
		QString user;
		QString password;
		QString database;
		int port;
	}MySQLConInfo;

	enum SQL_ERROR
	{
		IUIT_FAIL,
		IUIT_SUCCES
	};

	typedef struct
	{
		SQL_ERROR Error_Info;
		QSqlError Error_Code;
	}ErrorInfo;

	//饿汉式单例模式
	class BIL_SHARE DbService : public QObject
	{
		Q_OBJECT

	public:
		//连接数据库
		 bool createConnection();
		 // 读取数据,返回数量
		 int DBSelect(const std::string& Querystr, QList<QString>& data);
		 // 更新数据,返回数量
		 int DBUpdate(const std::string& Querystr, QList<QString> & datafamt, QList<QString> & data);
		 //插入数据,返回数量
		 int DBInsert(const std::string& Querystr, QList<QString> & datafamt, QList<QString>& data);
		 //删除数据,返回数量
		 int DBDelete(const std::string& Querystr, QList<QString> & data);
		 // 其他操作
		 int Query(const std::string& Querystr);   

		 bool DBCreateTable(QList<QString> tableList);
		 //获取返回信息，错误码等
		 void GetDBErrorInfo(ErrorInfo& errorInfo);
		 // 插入并获取插入的ID,针对自动递增ID
		 int GetInsertID(const std::string& Querystr);

	public:
		static DbService* Instance();

		//类似Java的垃圾回收器
		class GC
		{
		public:
			~GC()
			{
				//释放连接和资源
				if (m_dbService != NULL)
				{
					delete m_dbService;
					m_dbService = NULL;
					//关闭数据库
					db.close();
				}
			}
			static GC gc;  // 用于释放单例
		};

	private:
		DbService();
		DbService(const DbService &);
		//DBservice& operator=(const DBservice &);

	private:
		static DbService *m_dbService;  
		static QSqlDatabase db;      //数据库连接类
		static QMutex m_mutex;  // 锁

	private:
		MySQLConInfo m_mySqlConInfo;  //数据库连接信息
		ErrorInfo m_ErrorInfo;        //错误信息
	};
}