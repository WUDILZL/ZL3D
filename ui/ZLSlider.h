#pragma once
#include <QtWidgets>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>

//滑块组件
class ZLSlider : public QWidget
{
    Q_OBJECT
public:
    explicit ZLSlider(QWidget* parent = nullptr);
    ~ZLSlider();
    void 数据设置(QString 名,int 数值);
public:
    QLabel* 名称;
    QLabel* 数值显示;
    QSlider* 拖动条;

   
};


