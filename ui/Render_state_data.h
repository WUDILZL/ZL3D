#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

#include "Color_widget.h"

//��Ⱦ״̬��ʾ
class Render_state_data :
    public QWidget
{
    Q_OBJECT
public:
    explicit Render_state_data(QWidget* parent = nullptr);
    ~Render_state_data();
    void ���ݸ���(QString ��,bool _״̬);
public:
    QLabel* ����;
    QCheckBox* ״̬;
    QPushButton* ��ɫ��;
    Color_widget* ��ɫ�崰��;
    bool ��ɫ��״̬ = true;
    QColor �����ɫ;

signals:
    //��ɫ�����ź�
    void setcolor(QColor color);
};

