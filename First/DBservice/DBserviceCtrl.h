#pragma once
#include "DBservice.h"
#include "head.h"
namespace DBService {

		//�������ݿ�
		bool BIL_SHARE createConnection();
		// ��ȡ����,��������
		int BIL_SHARE DBSelect(const std::string& Querystr, QList<QString>& data);
		// ��������,��������
		int BIL_SHARE DBUpdate(const std::string& Querystr, QList<QString> & datafamt, QList<QString> & data);
		//��������,��������
		int BIL_SHARE DBInsert(const std::string& Querystr, QList<QString> & datafamt, QList<QString>& data);
		//ɾ������,��������
		int BIL_SHARE DBDelete(const std::string& Querystr, QList<QString> & data);
		// ��������
		int BIL_SHARE Query(const std::string& Querystr);

		bool BIL_SHARE DBCreateTable(QList<QString> tableList);
		//��ȡ������Ϣ���������
		void BIL_SHARE GetDBErrorInfo(ErrorInfo& errorInfo);
		// ���벢��ȡ�����ID,����Զ�����ID
		//int GetInsertID(const std::string& Querystr);
}
