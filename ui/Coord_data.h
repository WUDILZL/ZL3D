#pragma once
#include <qwidget.h>
#include <QLineEdit>
#include <QLabel>
#include <QVBoxLayout>


//坐标数据显示
class Coord_data :
    public QWidget
{
    Q_OBJECT
public:
    explicit Coord_data(QWidget* parent = nullptr);
    ~Coord_data();
    void 数据更新(QString 名, float _x, float _y, float _z);
    void 实时更新(float _x, float _y, float _z);
public:
    QLabel* 名称;
    QLineEdit* x;
    QLineEdit* y;
    QLineEdit* z;
};

