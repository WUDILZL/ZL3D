#pragma once
#include <qwidget.h>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>


//����������ʾ
class Coord_data :
    public QWidget
{
    Q_OBJECT
public:
    explicit Coord_data(QWidget* parent = nullptr);
    ~Coord_data();
    void ���ݸ���(QString ��, float _x, float _y, float _z);
    void ʵʱ����(float _x, float _y, float _z);
public:
    QLabel* ����;
    QLineEdit* x;
    QLineEdit* y;
    QLineEdit* z;
};

