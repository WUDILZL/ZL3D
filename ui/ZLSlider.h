#pragma once
#include <QtWidgets>
#include <QSlider>
#include <QVBoxLayout>
#include <QLabel>

//�������
class ZLSlider : public QWidget
{
    Q_OBJECT
public:
    explicit ZLSlider(QWidget* parent = nullptr);
    ~ZLSlider();
    void ��������(QString ��,int ��ֵ);
public:
    QLabel* ����;
    QLabel* ��ֵ��ʾ;
    QSlider* �϶���;

   
};


