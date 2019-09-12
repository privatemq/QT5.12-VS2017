#pragma once
#include "DBservice.h"
#include "head.h"
namespace DBService {

		//连接数据库
		bool BIL_SHARE createConnection();
		// 读取数据,返回数量
		int BIL_SHARE DBSelect(const std::string& Querystr, QList<QString>& data);
		// 更新数据,返回数量
		int BIL_SHARE DBUpdate(const std::string& Querystr, QList<QString> & datafamt, QList<QString> & data);
		//插入数据,返回数量
		int BIL_SHARE DBInsert(const std::string& Querystr, QList<QString> & datafamt, QList<QString>& data);
		//删除数据,返回数量
		int BIL_SHARE DBDelete(const std::string& Querystr, QList<QString> & data);
		// 其他操作
		int BIL_SHARE Query(const std::string& Querystr);

		bool BIL_SHARE DBCreateTable(QList<QString> tableList);
		//获取返回信息，错误码等
		void BIL_SHARE GetDBErrorInfo(ErrorInfo& errorInfo);
		// 插入并获取插入的ID,针对自动递增ID
		//int GetInsertID(const std::string& Querystr);
}
