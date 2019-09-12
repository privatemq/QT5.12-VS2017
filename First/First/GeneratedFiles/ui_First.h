/********************************************************************************
** Form generated from reading UI file 'First.ui'
**
** Created by: Qt User Interface Compiler version 5.12.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FIRST_H
#define UI_FIRST_H

#include <QtCore/QVariant>
#include <QtWebEngineWidgets/QWebEngineView>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FirstClass
{
public:
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout;
    QWebEngineView *webEngineView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *FirstClass)
    {
        if (FirstClass->objectName().isEmpty())
            FirstClass->setObjectName(QString::fromUtf8("FirstClass"));
        FirstClass->resize(600, 400);
        centralWidget = new QWidget(FirstClass);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        verticalLayout = new QVBoxLayout(centralWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        webEngineView = new QWebEngineView(centralWidget);
        webEngineView->setObjectName(QString::fromUtf8("webEngineView"));
        webEngineView->setUrl(QUrl(QString::fromUtf8("about:blank")));

        verticalLayout->addWidget(webEngineView);

        FirstClass->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(FirstClass);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 600, 23));
        FirstClass->setMenuBar(menuBar);
        mainToolBar = new QToolBar(FirstClass);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        FirstClass->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(FirstClass);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        FirstClass->setStatusBar(statusBar);

        retranslateUi(FirstClass);

        QMetaObject::connectSlotsByName(FirstClass);
    } // setupUi

    void retranslateUi(QMainWindow *FirstClass)
    {
        FirstClass->setWindowTitle(QApplication::translate("FirstClass", "First", nullptr));
    } // retranslateUi

};

namespace Ui {
    class FirstClass: public Ui_FirstClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FIRST_H
