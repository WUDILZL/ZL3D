#pragma once
#include <qwidget.h>
#include <QCloseEvent>
#include <QColorDialog>
#include <QVBoxLayout>

//调色板窗口
class Color_widget :
    public QWidget
{
    Q_OBJECT
public:

    explicit Color_widget(QWidget* parent = nullptr);
    ~Color_widget();

    QColorDialog* 调色板;

protected:
    void closeEvent(QCloseEvent* event) override {
        destroy();
        event->accept();
    }

signals:
    //销毁信号
    void destroy();

};

