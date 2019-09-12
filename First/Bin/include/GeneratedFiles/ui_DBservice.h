/********************************************************************************
** Form generated from reading UI file 'DBservice.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DBSERVICE_H
#define UI_DBSERVICE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DBserviceClass
{
public:
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QWidget *centralWidget;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *DBserviceClass)
    {
        if (DBserviceClass->objectName().isEmpty())
            DBserviceClass->setObjectName(QString::fromUtf8("DBserviceClass"));
        DBserviceClass->resize(600, 400);
        menuBar = new QMenuBar(DBserviceClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        DBserviceClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(DBserviceClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        DBserviceClass->addToolBar(mainToolBar);
        centralWidget = new QWidget(DBserviceClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        DBserviceClass->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(DBserviceClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        DBserviceClass->setStatusBar(statusBar);

        retranslateUi(DBserviceClass);

        QMetaObject::connectSlotsByName(DBserviceClass);
    } // setupUi

    void retranslateUi(QMainWindow *DBserviceClass)
    {
        DBserviceClass->setWindowTitle(QApplication::translate("DBserviceClass", "DBservice", nullptr));
    } // retranslateUi

};

namespace Ui {
    class DBserviceClass: public Ui_DBserviceClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DBSERVICE_H
