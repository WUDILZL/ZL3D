#include "Coord_data.h"

Coord_data::Coord_data(QWidget* parent)
{
	QHBoxLayout* 水平布局 = new QHBoxLayout(this);
    名称 = new QLabel();
    x = new QLineEdit();
    y = new QLineEdit();
    z = new QLineEdit();
    x->setReadOnly(true);
    y->setReadOnly(true);
    z->setReadOnly(true);
    水平布局->addWidget(名称, 1);
    水平布局->addWidget(x, 2);
    水平布局->addWidget(y, 2);
    水平布局->addWidget(z, 2);
    水平布局->setSpacing(2);
    水平布局->setContentsMargins(0, 0, 0, 0);
}

Coord_data::~Coord_data()
{
}

void Coord_data::数据更新(QString 名, float _x, float _y, float _z)
{
    名称->setText(名);
    x->setText(QString::number(_x));
    y->setText(QString::number(_y));
    z->setText(QString::number(_z));
}

void Coord_data::实时更新(float _x, float _y, float _z)
{
    x->setText(QString::number(_x));
    y->setText(QString::number(_y));
    z->setText(QString::number(_z));
}

