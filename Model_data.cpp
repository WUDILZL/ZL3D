#include "Model_data.h"

Model_data::Model_data(QWidget* parent)
{
	QVBoxLayout* ��ֱ���� = new QVBoxLayout(this);
	���� = new QLabel();

	ѡȡ״̬ = new QCheckBox();
	ѡȡ״̬->setText(QString::fromLocal8Bit("ѡȡ�ٿ�"));

	�ߴ�x = new ZLSlider();
	�ߴ�y = new ZLSlider();
	�ߴ�z = new ZLSlider();

	�ֶ�x = new ZLSlider();
	�ֶ�y = new ZLSlider();
	�ֶ�z = new ZLSlider();

	��״̬ = new Render_state_data();
	��״̬ = new Render_state_data();
	��״̬ = new Render_state_data();

	�������� = new Coord_data();
	�������� = new Coord_data();
	��ֱ����->addWidget(����);

	��ֱ����->addWidget(ѡȡ״̬);

	��ֱ����->addWidget(�ߴ�x);
	��ֱ����->addWidget(�ߴ�y);
	��ֱ����->addWidget(�ߴ�z);

	��ֱ����->addWidget(�ֶ�x);
	��ֱ����->addWidget(�ֶ�y);
	��ֱ����->addWidget(�ֶ�z);

	��ֱ����->addWidget(��״̬);
	��ֱ����->addWidget(��״̬);
	��ֱ����->addWidget(��״̬);

	��ֱ����->addWidget(��������);
	��ֱ����->addWidget(��������);

	��ֱ����->setSpacing(2);
	��ֱ����->setContentsMargins(0, 0, 0, 0);
}

Model_data::~Model_data()
{
}

void Model_data::��������(ui��ʾ���� ����)
{
	���� = ����;
	����->setText(����.����);
	ѡȡ״̬->setChecked(����.ѡ��״̬);
	�ߴ�x->��������(QString::fromLocal8Bit("�ߴ�X"), ����.�ߴ�.X);
	�ߴ�y->��������(QString::fromLocal8Bit("�ߴ�Y"), ����.�ߴ�.Y);
	�ߴ�z->��������(QString::fromLocal8Bit("�ߴ�Z"), ����.�ߴ�.Z);

	�ֶ�x->��������(QString::fromLocal8Bit("�ֶ�X"), ����.�ֶ�.X);
	�ֶ�y->��������(QString::fromLocal8Bit("�ֶ�Y"), ����.�ֶ�.Y);
	�ֶ�z->��������(QString::fromLocal8Bit("�ֶ�Z"), ����.�ֶ�.Z);

	��״̬->���ݸ���(QString::fromLocal8Bit("��Ⱦ��"), ����.��Ⱦ״̬��);
	��״̬->���ݸ���(QString::fromLocal8Bit("��Ⱦ��"), ����.��Ⱦ״̬��);
	��״̬->���ݸ���(QString::fromLocal8Bit("��Ⱦ��"), ����.��Ⱦ״̬��);

	��������->���ݸ���(QString::fromLocal8Bit("��������"), ����.��������.X, ����.��������.Y, ����.��������.Z);
	��������->���ݸ���(QString::fromLocal8Bit("��������"), ����.��������.X, ����.��������.Y, ����.��������.Z);

}

void Model_data::���ٸ��²���(ui��ʾ���� ����)
{
	��������->ʵʱ����(����.��������.X, ����.��������.Y, ����.��������.Z);
	��������->ʵʱ����(����.��������.X, ����.��������.Y, ����.��������.Z);
}


