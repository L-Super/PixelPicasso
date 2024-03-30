#include <QApplication>
#include <QDebug>

#include "version.h"
#include "widget/MainWindow.h"
#include "logic/ImageConvertor.h"
#include "logic/ImageResize.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);

    qDebug() << QString("The version of this application is v%1").arg(VERSION_STR);

    pp::ImageResize imageResize;
    imageResize.resize("F:/Code/CppProjects/PixelPicasso/resources/test.png", 0.5);
//    MainWindow w;
//    w.show();

    return QApplication::exec();
}
