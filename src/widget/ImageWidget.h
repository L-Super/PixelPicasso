//
// Created by LMR on 2024/4/4.
//

#ifndef IMAGEWIDGET_H
#define IMAGEWIDGET_H

#include <QWidget>


QT_BEGIN_NAMESPACE
namespace Ui {
class ImageWidget;
}
QT_END_NAMESPACE

class ImageWidget : public QWidget {
    Q_OBJECT

public:
    explicit ImageWidget(QWidget* parent = nullptr);
    ~ImageWidget() override;
protected:
    // 当拖放操作进入widget的事件
    void dragEnterEvent(QDragEnterEvent *event) override;
    // 拖放操作完成时发送的事件
    void dropEvent(QDropEvent *event) override;

private:
    Ui::ImageWidget* ui;
};


#endif//IMAGEWIDGET_H
