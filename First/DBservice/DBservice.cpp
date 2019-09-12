#include "DBservice.h"
namespace DBService 
{
	DbService* DbService::m_dbService = NULL;
	QSqlDatabase DbService::db;      //数据库连接类
	QMutex DbService::m_mutex;  // 锁
	DbService::GC DbService::GC::gc; // 重要

	DbService::DbService()
	{

	}

	DbService* DbService::Instance()
	{
		//保证多线程安全，加锁
		m_mutex.lock();
		if (m_dbService == NULL)
		{
			m_mutex.lock();
			if (m_dbService == NULL)
			{
				m_dbService = new DbService();
			}
			m_mutex.lock();
		}
		m_mutex.unlock();
		return m_dbService;
	}

	bool DbService::createConnection()
	{
		db = QSqlDatabase::addDatabase("QMYSQL");
		db.setHostName("localhost");
		db.setDatabaseName("mqtest");       //这里输入你的数据库名
		db.setUserName("root");
		db.setPassword("mengqi");   //这里输入你的密码
		if (!db.open()) {
			QMessageBox::critical(0, QObject::tr("无法打开数据库"), db.lastError().databaseText(), QMessageBox::Cancel);
			m_ErrorInfo.Error_Code = db.lastError();
			m_ErrorInfo.Error_Info = IUIT_FAIL;
			return false;
		} //

		return true;
	}

	//创建表
	bool DbService::DBCreateTable(QList<QString> tableList)
	{
		QString qslname;
		for (int i = 1; i < tableList.count() - 1; i++)
			qslname += (tableList.at(i) + " VARCHAR(40),");
		QString sql = tr("create table %1(" "id INT NOT NULL AUTO_INCREMENT,%2PRIMARY KEY (id));").arg(tableList.at(0)).arg(qslname);
		QSqlQuery query(db);
		if (!query.exec(sql))
		{
			m_ErrorInfo.Error_Code = query.lastError();
			m_ErrorInfo.Error_Info = IUIT_FAIL;
			return false;
		}
		return true;
	}

	// 读取数据,返回数量
	int DbService::DBSelect(const std::string& Querystr, QList<QString>& data)
	{
		QString sql = tr("select * from '%1'").arg(tr("表名"));
		int count = 0;
		QSqlQuery query(db);
		memset(&m_ErrorInfo, 0, sizeof(m_ErrorInfo));
		// 使数据库支持中文
		query.exec("SET NAMES 'UTF8'");
		if (!query.exec(sql))
		{
			m_ErrorInfo.Error_Code = query.lastError();
			m_ErrorInfo.Error_Info = IUIT_FAIL;
			return count;
		}

		while (query.next())
		{
			data.push_back(query.value(count++).toString());
		}

		return count;
	}
	// 更新数据,返回数量  修改列名，修改内容
	int DbService::DBUpdate(const std::string& Querystr, QList<QString> & datafamt, QList<QString> & data)
	{
		int count = 0;
		QString sqlset;
		for (int i = 0; i < data.count(); i++)
			sqlset += "" + datafamt.at(i) + " ='" + data.at(i) + "',";
		sqlset = sqlset.left(sqlset.length() - 1);

		QString sql = tr("update %1 set ").arg("id") + sqlset + tr(" where id = %1").arg(sqlset);
		QSqlQuery query(db);
		memset(&m_ErrorInfo, 0, sizeof(m_ErrorInfo));
		// 使数据库支持中文
		query.exec("SET NAMES 'UTF8'");
		if (!query.exec(sql))
		{
			m_ErrorInfo.Error_Code = query.lastError();
			m_ErrorInfo.Error_Info = IUIT_FAIL;
			return count;
		}
		count = query.size();
		return count;
	}
	//插入数据,返回数量
	int DbService::DBInsert(const std::string& Querystr, QList<QString> & datafamt, QList<QString> & data)
	{
		int count = 0;
		QString sqlDataFamt,sqlData;
		for (int i = 0; i < datafamt.count(); i++)
		{
			sqlDataFamt += "" + datafamt.at(i) + ",";
			sqlData += "" + datafamt.at(i) + ",";
		}

		QString sql = tr("update INTO %1 (%2) VALUES (%3) ").arg("表名").arg(sqlDataFamt).arg(sqlData);
		QSqlQuery query(db);
		memset(&m_ErrorInfo, 0, sizeof(m_ErrorInfo));
		// 使数据库支持中文
		query.exec("SET NAMES 'UTF8'");
		if (!query.exec(sql))
		{
			m_ErrorInfo.Error_Code = query.lastError();
			m_ErrorInfo.Error_Info = IUIT_FAIL;
			return count;
		}
		count = query.size();
		return count;
	}
	//删除数据,返回数量
	int DbService::DBDelete(const std::string& Querystr, QList<QString> & data)
	{
		int count = 0;
		QSqlQuery query(db);
		QString sql = QString("delete from %2 where id=%1").arg(data[0]).arg("表名");
		memset(&m_ErrorInfo, 0, sizeof(m_ErrorInfo));
		// 使数据库支持中文
		query.exec("SET NAMES 'UTF8'");
		if (!query.exec(sql))
		{
			m_ErrorInfo.Error_Code = query.lastError();
			m_ErrorInfo.Error_Info = IUIT_FAIL;
			return count;
		}
		count = query.size();
		return count;
	}
	// 其他操作
	int DbService::Query(const std::string& Querystr)
	{
		int count = 0;
		return count;
	}

	//获取返回信息，错误码等
	void DbService::GetDBErrorInfo(ErrorInfo& errorInfo)
	{
		errorInfo.Error_Code = m_ErrorInfo.Error_Code;
		errorInfo.Error_Info = m_ErrorInfo.Error_Info;
	}
}