#include "Coord_data.h"

Coord_data::Coord_data(QWidget* parent)
{
	QHBoxLayout* ˮƽ���� = new QHBoxLayout(this);
    ���� = new QLabel();
    x = new QLineEdit();
    y = new QLineEdit();
    z = new QLineEdit();
    x->setReadOnly(true);
    y->setReadOnly(true);
    z->setReadOnly(true);
    ˮƽ����->addWidget(����, 1);
    ˮƽ����->addWidget(x, 2);
    ˮƽ����->addWidget(y, 2);
    ˮƽ����->addWidget(z, 2);
    ˮƽ����->setSpacing(2);
    ˮƽ����->setContentsMargins(0, 0, 0, 0);
}

Coord_data::~Coord_data()
{
}

void Coord_data::���ݸ���(QString ��, float _x, float _y, float _z)
{
    ����->setText(��);
    x->setText(QString::number(_x));
    y->setText(QString::number(_y));
    z->setText(QString::number(_z));
}

void Coord_data::ʵʱ����(float _x, float _y, float _z)
{
    x->setText(QString::number(_x));
    y->setText(QString::number(_y));
    z->setText(QString::number(_z));
}

