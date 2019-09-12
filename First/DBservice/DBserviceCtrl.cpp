#include "DBserviceCtrl.h"

namespace DBService {

	//连接数据库
	bool createConnection()
	{
		return DBService::DbService::Instance()->createConnection();
	}
	// 读取数据,返回数量
	int DBSelect(const std::string& Querystr, QList<QString>& data)
	{
		return DBService::DbService::Instance()->DBSelect(Querystr, data);
	}
	// 更新数据,返回数量
	int DBUpdate(const std::string& Querystr, QList<QString> & datafamt, QList<QString> & data)
	{
		return DBService::DbService::Instance()->DBUpdate(Querystr, datafamt, data);
	}
	//插入数据,返回数量
	int DBInsert(const std::string& Querystr, QList<QString> & datafamt, QList<QString>& data)
	{
		return DBService::DbService::Instance()->DBInsert(Querystr, datafamt, data);
	}
	//删除数据,返回数量
	int DBDelete(const std::string& Querystr, QList<QString> & data)
	{
		return DBService::DbService::Instance()->DBDelete(Querystr, data);
	}
	// 其他操作
	int Query(const std::string& Querystr)
	{
		return DBService::DbService::Instance()->Query(Querystr);
	}

	bool DBCreateTable(QList<QString> tableList)
	{
		return DBService::DbService::Instance()->DBCreateTable(tableList);
	}
	//获取返回信息，错误码等
	void GetDBErrorInfo(ErrorInfo& errorInfo)
	{
		DBService::DbService::Instance()->GetDBErrorInfo(errorInfo);
	}
	// 插入并获取插入的ID,针对自动递增ID
	//int DBserviceCtrl::GetInsertID(const std::string& Querystr)
	//{
	//	return m_dbService->GetInsertID(Querystr);
	//}
}
