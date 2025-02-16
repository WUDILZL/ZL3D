#pragma once

#include <QtWidgets/QMainWindow>
#include "ALL_UI.h"

class QtWidgetsApplication2 : public QMainWindow
{
    Q_OBJECT

public:
    QtWidgetsApplication2(QWidget *parent = nullptr);
    ~QtWidgetsApplication2();

protected:
    //按下事件
    virtual void keyPressEvent(QKeyEvent* event) override;
    //弹起事件
    virtual void keyReleaseEvent(QKeyEvent* event) override;

private:
    void 初始化();
    

private:
    ALL_UI* _ui;
};
