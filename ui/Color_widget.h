#pragma once
#include <qwidget.h>
#include <QCloseEvent>
#include <QColorDialog>
#include <QVBoxLayout>

//��ɫ�崰��
class Color_widget :
    public QWidget
{
    Q_OBJECT
public:

    explicit Color_widget(QWidget* parent = nullptr);
    ~Color_widget();

    QColorDialog* ��ɫ��;

protected:
    void closeEvent(QCloseEvent* event) override {
        destroy();
        event->accept();
    }

signals:
    //�����ź�
    void destroy();

};

