#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_First.h"

class First : public QMainWindow
{
	Q_OBJECT

public:
	First(QWidget *parent = Q_NULLPTR);

private:
	Ui::FirstClass ui;
};
