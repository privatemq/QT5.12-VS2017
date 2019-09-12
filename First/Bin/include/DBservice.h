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
	
	// ����MySQL������Ϣ
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

	//����ʽ����ģʽ
	class BIL_SHARE DbService : public QObject
	{
		Q_OBJECT

	public:
		//�������ݿ�
		 bool createConnection();
		 // ��ȡ����,��������
		 int DBSelect(const std::string& Querystr, QList<QString>& data);
		 // ��������,��������
		 int DBUpdate(const std::string& Querystr, QList<QString> & datafamt, QList<QString> & data);
		 //��������,��������
		 int DBInsert(const std::string& Querystr, QList<QString> & datafamt, QList<QString>& data);
		 //ɾ������,��������
		 int DBDelete(const std::string& Querystr, QList<QString> & data);
		 // ��������
		 int Query(const std::string& Querystr);   

		 bool DBCreateTable(QList<QString> tableList);
		 //��ȡ������Ϣ���������
		 void GetDBErrorInfo(ErrorInfo& errorInfo);
		 // ���벢��ȡ�����ID,����Զ�����ID
		 int GetInsertID(const std::string& Querystr);

	public:
		static DbService* Instance();

		//����Java������������
		class GC
		{
		public:
			~GC()
			{
				//�ͷ����Ӻ���Դ
				if (m_dbService != NULL)
				{
					delete m_dbService;
					m_dbService = NULL;
					//�ر����ݿ�
					db.close();
				}
			}
			static GC gc;  // �����ͷŵ���
		};

	private:
		DbService();
		DbService(const DbService &);
		//DBservice& operator=(const DBservice &);

	private:
		static DbService *m_dbService;  
		static QSqlDatabase db;      //���ݿ�������
		static QMutex m_mutex;  // ��

	private:
		MySQLConInfo m_mySqlConInfo;  //���ݿ�������Ϣ
		ErrorInfo m_ErrorInfo;        //������Ϣ
	};
}