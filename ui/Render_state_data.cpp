#include "Render_state_data.h"

Render_state_data::Render_state_data(QWidget* parent)
{
	QHBoxLayout* ˮƽ���� = new QHBoxLayout(this);
	���� = new QLabel(this);
	״̬ = new QCheckBox(this);
	��ɫ�� = new QPushButton(this);
	��ɫ��->setText(QString::fromLocal8Bit("��ɫ��"));
	ˮƽ����->addWidget(����);
	ˮƽ����->addWidget(״̬);
	ˮƽ����->addWidget(��ɫ��);
	ˮƽ����->setSpacing(2);
	ˮƽ����->setContentsMargins(0, 0, 0, 0);
	
	connect(��ɫ��, &QPushButton::clicked, [&]() {
		if (!��ɫ��״̬) return;
		��ɫ�崰�� = new Color_widget(this);
		��ɫ��״̬ = false;
		connect(��ɫ�崰��->��ɫ��, &QColorDialog::currentColorChanged, [=](const QColor& color) {
			�����ɫ = color;
			setcolor(�����ɫ);
			});
		connect(��ɫ�崰��, &Color_widget::destroy, [&]() {
			��ɫ��״̬ = true;
			});
		});

	

}

Render_state_data::~Render_state_data()
{
}

void Render_state_data::���ݸ���(QString ��, bool _״̬)
{
	����->setText(��);
	״̬->setChecked(_״̬);
}
