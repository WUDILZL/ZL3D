#pragma once
#include <QMouseEvent>

enum ���̰��� {
	Wu,
	//ƽ��
	E,
	//����
	T,
	//��ת
	R,
	//��
	�ٿ�X,

	�ٿ�Y,

	�ٿ�Z
};


//�����̼���¼�
class Mouse_Key
{
public:
	Mouse_Key();
	~Mouse_Key();

	float ������;
	float ���x;
	float ���y;
	bool �����¼�;
	bool ����¼�;
	bool ctrl���;

	���̰��� �����¼���¼;
public:
	void ʱ����();
	void ����ˢ��(QPoint ������);
	void ��������();
	int ���ؼ�����Ӧ��Ϣ();
};

