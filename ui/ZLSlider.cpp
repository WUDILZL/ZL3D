#include "ZLSlider.h"

ZLSlider::ZLSlider(QWidget* parent)
{
	QHBoxLayout* ˮƽ���� = new QHBoxLayout(this);
	�϶��� = new QSlider(Qt::Horizontal);
	//setValue ���ó�ʼֵ
	�϶���->setRange(1, 10);
	���� = new QLabel();
	��ֵ��ʾ = new QLabel();
	ˮƽ����->addWidget(����, 1);
	ˮƽ����->addWidget(��ֵ��ʾ, 1);
	ˮƽ����->addWidget(�϶���, 3);
	ˮƽ����->setSpacing(2);
	ˮƽ����->setContentsMargins(0, 0, 0, 0);
}

ZLSlider::~ZLSlider()
{
}

void ZLSlider::��������(QString ��, int ��ֵ)
{
	����->setText(��);
	��ֵ��ʾ->setText(QString::number(��ֵ));

    �϶���->setValue(��ֵ);

}
