#include <QApplication>
#include <QDebug>

#include "MainWindow.h"
#include "version.h"

int main(int argc, char* argv[])
{
	QApplication a(argc, argv);

	qDebug()<<QString("The version of this application is v%1").arg(VERSION_STR);
    MainWindow w;
    w.show();

	return QApplication::exec();
}
