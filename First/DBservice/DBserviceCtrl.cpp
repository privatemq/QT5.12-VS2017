#include "DBserviceCtrl.h"

namespace DBService {

	//�������ݿ�
	bool createConnection()
	{
		return DBService::DbService::Instance()->createConnection();
	}
	// ��ȡ����,��������
	int DBSelect(const std::string& Querystr, QList<QString>& data)
	{
		return DBService::DbService::Instance()->DBSelect(Querystr, data);
	}
	// ��������,��������
	int DBUpdate(const std::string& Querystr, QList<QString> & datafamt, QList<QString> & data)
	{
		return DBService::DbService::Instance()->DBUpdate(Querystr, datafamt, data);
	}
	//��������,��������
	int DBInsert(const std::string& Querystr, QList<QString> & datafamt, QList<QString>& data)
	{
		return DBService::DbService::Instance()->DBInsert(Querystr, datafamt, data);
	}
	//ɾ������,��������
	int DBDelete(const std::string& Querystr, QList<QString> & data)
	{
		return DBService::DbService::Instance()->DBDelete(Querystr, data);
	}
	// ��������
	int Query(const std::string& Querystr)
	{
		return DBService::DbService::Instance()->Query(Querystr);
	}

	bool DBCreateTable(QList<QString> tableList)
	{
		return DBService::DbService::Instance()->DBCreateTable(tableList);
	}
	//��ȡ������Ϣ���������
	void GetDBErrorInfo(ErrorInfo& errorInfo)
	{
		DBService::DbService::Instance()->GetDBErrorInfo(errorInfo);
	}
	// ���벢��ȡ�����ID,����Զ�����ID
	//int DBserviceCtrl::GetInsertID(const std::string& Querystr)
	//{
	//	return m_dbService->GetInsertID(Querystr);
	//}
}
