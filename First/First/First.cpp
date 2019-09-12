
#include "First.h"
#include "DBservice.h"
#include "DBserviceCtrl.h"
#pragma comment(lib,"DBservice.lib")
First::First(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//ui.webEngineView->load(QUrl(QStringLiteral("https://www.taobao.com")));
	//ui.webEngineView->showMaximized();
	//QString htmlTitle = ui.webEngineView->title();
	//DBserviceCtrl *d = new DBserviceCtrl();
	DBService::createConnection();
}
