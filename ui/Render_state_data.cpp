#include "Render_state_data.h"

Render_state_data::Render_state_data(QWidget* parent)
{
	QHBoxLayout* 水平布局 = new QHBoxLayout(this);
	名称 = new QLabel(this);
	状态 = new QCheckBox(this);
	调色板 = new QPushButton(this);
	调色板->setText(QString::fromLocal8Bit("调色板"));
	水平布局->addWidget(名称);
	水平布局->addWidget(状态);
	水平布局->addWidget(调色板);
	水平布局->setSpacing(2);
	水平布局->setContentsMargins(0, 0, 0, 0);
	
	connect(调色板, &QPushButton::clicked, [&]() {
		if (!调色板状态) return;
		调色板窗口 = new Color_widget(this);
		调色板状态 = false;
		connect(调色板窗口->调色板, &QColorDialog::currentColorChanged, [=](const QColor& color) {
			面板颜色 = color;
			setcolor(面板颜色);
			});
		connect(调色板窗口, &Color_widget::destroy, [&]() {
			调色板状态 = true;
			});
		});

	

}

Render_state_data::~Render_state_data()
{
}

void Render_state_data::数据更新(QString 名, bool _状态)
{
	名称->setText(名);
	状态->setChecked(_状态);
}
