#include <QApplication>
#include <QDebug>

#include "version.h"
#include "widget/MainWindow.h"
#include "widget/style/DarkStyle.h"
#include "widget/ImageWidget.h"

int main(int argc, char* argv[])
{
    QApplication a(argc, argv);
    QApplication::setStyle(new DarkStyle());

    qDebug() << QString("The version of this application is v%1").arg(VERSION_STR);

//    pp::ImageResize imageResize;
//    imageResize.resize("F:/Code/CppProjects/PixelPicasso/tests/photo-1.webp", 0.5);
//    MainWindow w;
//    w.show();
    ImageWidget w;
    w.show();
    return QApplication::exec();
}
