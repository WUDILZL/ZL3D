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
    //�����¼�
    virtual void keyPressEvent(QKeyEvent* event) override;
    //�����¼�
    virtual void keyReleaseEvent(QKeyEvent* event) override;

private:
    void ��ʼ��();
    

private:
    ALL_UI* _ui;
};
