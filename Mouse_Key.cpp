#include "Mouse_Key.h"

Mouse_Key::Mouse_Key()
{
	������ = 0;
	���x = 0;
	���y = 0;
	�����¼� = false;
	����¼� = false;
	ctrl��� = true;
	�����¼���¼ = Wu;
}

Mouse_Key::~Mouse_Key()
{
}

void Mouse_Key::ʱ����()
{
	if (���x != 0 || ���y != 0 || ������ != 0)
	{
		�����¼� = true;
		����¼� = true;
	}
}

void Mouse_Key::����ˢ��(QPoint ������)
{
	���x += ������.x();
	���y += ������.y();
}

void Mouse_Key::��������()
{
	������ = 0;
	���x = 0;
	���y = 0;
	�����¼� = false;
	����¼� = false;
}

int Mouse_Key::���ؼ�����Ӧ��Ϣ()
{
	switch (�����¼���¼)
	{
	case Wu:
		return 0;
	case E:
		return 1;
	case T:
		return 2;
	case R:
		return 3;
	case �ٿ�X:
		return 4;
	case �ٿ�Y:
		return 5;
	case �ٿ�Z:
		return 6;
	default:
		return 0;
	}
	
}
