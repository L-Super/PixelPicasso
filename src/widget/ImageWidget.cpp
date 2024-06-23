//
// Created by LMR on 2024/4/4.
//

// You may need to build the project (run Qt uic code generator) to get "ui_ImageWidget.h" resolved

#include "ImageWidget.h"
#include "ui_ImageWidget.h"

#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>
#include <QDebug>

ImageWidget::ImageWidget(QWidget* parent) : QWidget(parent), ui(new Ui::ImageWidget)
{
    ui->setupUi(this);
    // 为窗口设置拖拽进入事件的处理函数
    setAcceptDrops(true);
}

ImageWidget::~ImageWidget()
{
    delete ui;
}
void ImageWidget::dragEnterEvent(QDragEnterEvent* event)
{
    if (event->mimeData()->hasUrls()) {
        event->acceptProposedAction();
    }
}
void ImageWidget::dropEvent(QDropEvent* event)
{
    // 获取拖拽的文件URL
    QList<QUrl> urls = event->mimeData()->urls();
    qDebug()<<"urls"<<urls;
    if (!urls.isEmpty()) {
        QString filePath = urls.first().toLocalFile();

        QImage image(filePath);
        auto h = image.height();
        auto w = image.width();
        qDebug()<<"file path:"<<filePath<<"size:"<<w<<h;
        if (!image.isNull()) {
            // 如果图片加载成功，显示图片
            auto size = ui->imageLabel->size();
            ui->imageLabel->setPixmap(QPixmap::fromImage(image).scaled(size,Qt::KeepAspectRatio,
                                                                       Qt::SmoothTransformation));
        }
    }
    // 将放置操作设置为建议的操作
    event->acceptProposedAction();
}
