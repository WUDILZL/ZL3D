#include "ZLSlider.h"

ZLSlider::ZLSlider(QWidget* parent)
{
	QHBoxLayout* 水平布局 = new QHBoxLayout(this);
	拖动条 = new QSlider(Qt::Horizontal);
	//setValue 设置初始值
	拖动条->setRange(1, 10);
	名称 = new QLabel();
	数值显示 = new QLabel();
	水平布局->addWidget(名称, 1);
	水平布局->addWidget(数值显示, 1);
	水平布局->addWidget(拖动条, 3);
	水平布局->setSpacing(2);
	水平布局->setContentsMargins(0, 0, 0, 0);
}

ZLSlider::~ZLSlider()
{
}

void ZLSlider::数据设置(QString 名, int 数值)
{
	名称->setText(名);
	数值显示->setText(QString::number(数值));

    拖动条->setValue(数值);

}
