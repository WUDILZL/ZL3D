#include "Mouse_Key.h"

Mouse_Key::Mouse_Key()
{
	鼠标滚轮 = 0;
	鼠标x = 0;
	鼠标y = 0;
	滚轮事件 = false;
	鼠标事件 = false;
	ctrl检测 = true;
	键盘事件记录 = Wu;
}

Mouse_Key::~Mouse_Key()
{
}

void Mouse_Key::时间线()
{
	if (鼠标x != 0 || 鼠标y != 0 || 鼠标滚轮 != 0)
	{
		滚轮事件 = true;
		鼠标事件 = true;
	}
}

void Mouse_Key::参数刷新(QPoint 鼠标参数)
{
	鼠标x += 鼠标参数.x();
	鼠标y += 鼠标参数.y();
}

void Mouse_Key::参数重置()
{
	鼠标滚轮 = 0;
	鼠标x = 0;
	鼠标y = 0;
	滚轮事件 = false;
	鼠标事件 = false;
}

int Mouse_Key::返回键盘响应信息()
{
	switch (键盘事件记录)
	{
	case Wu:
		return 0;
	case E:
		return 1;
	case T:
		return 2;
	case R:
		return 3;
	case 操控X:
		return 4;
	case 操控Y:
		return 5;
	case 操控Z:
		return 6;
	default:
		return 0;
	}
	
}
