#include "ALL_UI.h"

ALL_UI::ALL_UI(QWidget* parent)
{
	//��ǰ���沼��
	QHBoxLayout* buju = new QHBoxLayout(this);
	QWidget* ����1 = new QWidget();

	//������ʾ����
	_opengl��ʾ���� = new MyOpenGLWidegets(this);

	//ˮƽ�Ϸ�����
	��״ͼ�νڵ���ʾ = new Tree_list(this);
	//�Ҳ಼��
	QVBoxLayout* ˮƽ = new QVBoxLayout(����1);

	//�л�����
	ҳ��ֲ� = new QStackedWidget(this);
	//���ݵڶ�ҳ ����������
	������������ʾ���� = new Model_data(this);
	//���ݵ�һҳ �հ�
	QWidget* �����ݴ��� = new QWidget(this);

	ҳ��ֲ�->addWidget(�����ݴ���);//0
	ҳ��ֲ�->addWidget(������������ʾ����);//1

	//�Ҳ಼��
	ˮƽ->addWidget(��״ͼ�νڵ���ʾ, 5);
	ˮƽ->addWidget(ҳ��ֲ�, 5);
	ˮƽ->setSpacing(2);
	ˮƽ->setContentsMargins(0, 0, 0, 0);

	//�ܲ���
	buju->addWidget(_opengl��ʾ����, 4);
	buju->addWidget(����1, 1);
	buju->setSpacing(2);//����ÿ���ؼ����
	buju->setContentsMargins(0, 0, 0, 0);//�������¼�϶
	

	//������ʾ����->��������(_opengl��ʾ����->��ά����.������.������);
	��ȡ���нڵ�����(_opengl��ʾ����->��ά����.ȫ��ģ��);
	�����б��źŽ���();
	ģ���ź�();
	
}

ALL_UI::~ALL_UI()
{
}

void ALL_UI::�����б��źŽ���()
{
	connect(��״ͼ�νڵ���ʾ->���νڵ�, &QTreeView::clicked, [&](const QModelIndex& index) {
		���ݸ���ǰ��ģ��ѡȡȡ��();
		��ǰ�ڵ����� = index.data(Qt::UserRole).toInt();
		��ǰ�ڵ����� = index.data(Qt::UserRole + 1).toInt();
		����uiģ������();
		_opengl��ʾ����->��ά����.��ȡ��ǰ��ѡģ��(��ǰ�ڵ�����, ��ǰ�ڵ�����);
		});
	
	connect(��״ͼ�νڵ���ʾ->���νڵ�, &ZL_TreeView::destroy, [&]() {
		��������(��״ͼ�νڵ���ʾ->���νڵ�->����, ��״ͼ�νڵ���ʾ->���νڵ�->����);
		��ǰ�ڵ����� = -1;
		��ǰ�ڵ����� = -1;
		_opengl��ʾ����->��ά����.��ȡ��ǰ��ѡģ��(��ǰ�ڵ�����, ��ǰ�ڵ�����);
		});
}

void ALL_UI::ģ���ź�()
{
	������ģ���ź�();
}

void ALL_UI::���ģ��(int ����)
{
	if (���� == 0)
	{

	}
	else if (���� == 1)
	{

	}
	else if (���� == 2)
	{
		if (_opengl��ʾ����->��ά����.ȫ��ģ��.���������.empty())
		{
			_opengl��ʾ����->��ά����.ȫ��ģ��.���������.push_back(Cube());
			��״ͼ�νڵ���ʾ->����ӽڵ�(_opengl��ʾ����->��ά����.ȫ��ģ��.���������[0].����, 2, _opengl��ʾ����->��ά����.ȫ��ģ��.���������[0].��������);
			_opengl��ʾ����->��ά����.���ģ��������ģ��();
		}
		else
		{
			int ĩβ���� = _opengl��ʾ����->��ά����.ȫ��ģ��.���������.size() - 1;
			int ��ȡ���� = _opengl��ʾ����->��ά����.ȫ��ģ��.���������[ĩβ����].�������� + 1;
			Cube ������ = Cube();
			������.����.append(QString::number(ĩβ���� + 1));
			������.�������� = ��ȡ����;
			_opengl��ʾ����->��ά����.ȫ��ģ��.���������.push_back(������);
			��״ͼ�νڵ���ʾ->����ӽڵ�(������.����, 2, ��ȡ����);
			_opengl��ʾ����->��ά����.���ģ��������ģ��();
		}
	}
}

void ALL_UI::��ȡ���нڵ�����(ģ�Ͷ��� ģ��)
{
	if (!ģ��.����ƽ�����.empty())
	{
		for (int i = 0; i < ģ��.����ƽ�����.size(); i++)
		{
			��״ͼ�νڵ���ʾ->����ӽڵ�(ģ��.����ƽ�����[i].����, 1, ģ��.����ƽ�����[i].��������);
		}
	}
	if (!ģ��.͸���������.empty())
	{
		for (int i = 0; i < ģ��.͸���������.size(); i++)
		{
			��״ͼ�νڵ���ʾ->����ӽڵ�(ģ��.͸���������[i].����, 0, ģ��.͸���������[i].��������);
		}
	}
	if (!ģ��.���������.empty())
	{
		for (int i = 0; i < ģ��.���������.size(); i++)
		{
			��״ͼ�νڵ���ʾ->����ӽڵ�(ģ��.���������[i].����, 2, ģ��.���������[i].��������);
		}
	}

}

void ALL_UI::���ݸ���ǰ��ģ��ѡȡȡ��()
{
	ģ�Ͳ���״̬.������ = false;
	if (��ǰ�ڵ����� == 0)
	{

	}
	if (��ǰ�ڵ����� == 1)
	{

	}
	if (��ǰ�ڵ����� == 2)
	{
		for (int i = 0; i < _opengl��ʾ����->��ά����.ȫ��ģ��.���������.size(); i++)
		{
			if (_opengl��ʾ����->��ά����.ȫ��ģ��.���������[i].ѡ��״̬) _opengl��ʾ����->��ά����.ȫ��ģ��.���������[i].ѡ��״̬ = false;
		}
		
	}
}

void ALL_UI::����uiģ������()
{
	if (��ǰ�ڵ����� == 0)
	{

	}
	if (��ǰ�ڵ����� == 1)
	{
		
	}
	if (��ǰ�ڵ����� == 2)
	{
		ҳ��ֲ�->setCurrentIndex(1);
		for (int i = 0; i < _opengl��ʾ����->��ά����.ȫ��ģ��.���������.size(); i++)
		{
			if (_opengl��ʾ����->��ά����.ȫ��ģ��.���������[i].�������� == ��ǰ�ڵ�����)
			{
				_opengl��ʾ����->��ά����.ȫ��ģ��.���������[i].ѡ��״̬ = true;
				_opengl��ʾ����->��ά����.ȫ��ģ��.���������[i].��������();
				������������ʾ����->��������(_opengl��ʾ����->��ά����.ȫ��ģ��.���������[i].������);
				��ǰѡ������ = ��ǰ�ڵ�����;
				��ǰѡ������ = i;
				ģ�Ͳ���״̬.������ = true;
				return;
			}
		}
		
	}
}

void ALL_UI::������ģ���ź�()
{
	connect(������������ʾ����->ѡȡ״̬, &QCheckBox::toggled, [&](bool checked) {
		if (!ģ�Ͳ���״̬.������) return;
		if (checked) _opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].ѡ��״̬ = true;
		else _opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].ѡ��״̬ = false;
		});
	
	connect(������������ʾ����->�ߴ�x->�϶���, &QSlider::valueChanged, [=](int value) {
		if (!ģ�Ͳ���״̬.������) return;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�ߴ�x = value;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�޸�ģ��();
		������������ʾ����->�ߴ�x->��ֵ��ʾ->setText(QString::number(value));
		});

	connect(������������ʾ����->�ߴ�y->�϶���, &QSlider::valueChanged, [=](int value) {
		if (!ģ�Ͳ���״̬.������) return;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�ߴ�y = value;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�޸�ģ��();
		������������ʾ����->�ߴ�y->��ֵ��ʾ->setText(QString::number(value));
		});

	connect(������������ʾ����->�ߴ�z->�϶���, &QSlider::valueChanged, [=](int value) {
		if (!ģ�Ͳ���״̬.������) return;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�ߴ�z = value;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�޸�ģ��();
		������������ʾ����->�ߴ�z->��ֵ��ʾ->setText(QString::number(value));
		});


	connect(������������ʾ����->�ֶ�x->�϶���, &QSlider::valueChanged, [=](int value) {
		if (!ģ�Ͳ���״̬.������) return;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�ֶ�x = value;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�޸�ģ��();
		������������ʾ����->�ֶ�x->��ֵ��ʾ->setText(QString::number(value));
		});
	connect(������������ʾ����->�ֶ�y->�϶���, &QSlider::valueChanged, [=](int value) {
		if (!ģ�Ͳ���״̬.������) return;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�ֶ�y = value;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�޸�ģ��();
		������������ʾ����->�ֶ�y->��ֵ��ʾ->setText(QString::number(value));
		});
	connect(������������ʾ����->�ֶ�z->�϶���, &QSlider::valueChanged, [=](int value) {
		if (!ģ�Ͳ���״̬.������) return;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�ֶ�z = value;
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].�޸�ģ��();
		������������ʾ����->�ֶ�z->��ֵ��ʾ->setText(QString::number(value));
		});

	connect(������������ʾ����->��״̬->״̬, &QCheckBox::toggled, [&](bool checked) {
		if (!ģ�Ͳ���״̬.������) return;
		if (checked) _opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].��Ⱦ����.��Ⱦ�� = true;
		else _opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].��Ⱦ����.��Ⱦ�� = false;
		});

	connect(������������ʾ����->��״̬->״̬, &QCheckBox::toggled, [&](bool checked) {
		if (!ģ�Ͳ���״̬.������) return;
		if (checked) _opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].��Ⱦ����.��Ⱦ�� = true;
		else _opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].��Ⱦ����.��Ⱦ�� = false;
		});

	connect(������������ʾ����->��״̬->״̬, &QCheckBox::toggled, [&](bool checked) {
		if (!ģ�Ͳ���״̬.������) return;
		if (checked) _opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].��Ⱦ����.��Ⱦ�� = true;
		else _opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].��Ⱦ����.��Ⱦ�� = false;
		});

	connect(������������ʾ����->��״̬, &Render_state_data::setcolor, [=](QColor color) {
		if (!ģ�Ͳ���״̬.������) return;
		int red = color.red();
		int green = color.green();
		int blue = color.blue();
		int alpha = color.alpha();
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].������ɫ.�� = YS_RGB((float)red / 255.0f, (float)green / 255.0f, (float)blue / 255.0f, (float)alpha / 255.0f);
		});

	connect(������������ʾ����->��״̬, &Render_state_data::setcolor, [=](QColor color) {
		if (!ģ�Ͳ���״̬.������) return;
		int red = color.red();
		int green = color.green();
		int blue = color.blue();
		int alpha = color.alpha();
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].������ɫ.�� = YS_RGB((float)red / 255.0f, (float)green / 255.0f, (float)blue / 255.0f, (float)alpha / 255.0f);
		});

	connect(������������ʾ����->��״̬, &Render_state_data::setcolor, [=](QColor color) {
		if (!ģ�Ͳ���״̬.������) return;
		int red = color.red();
		int green = color.green();
		int blue = color.blue();
		int alpha = color.alpha();
		_opengl��ʾ����->��ά����.ȫ��ģ��.���������[��ǰѡ������].������ɫ.�� = YS_RGB((float)red / 255.0f, (float)green / 255.0f, (float)blue / 255.0f, (float)alpha / 255.0f);
		});
	
}

void ALL_UI::��������(int ����, int ����)
{
	
	_opengl��ʾ����->��ά����.��ӵ����ٶ���(����, ����);
}
