#pragma once
#include <QMouseEvent>

enum 键盘按键 {
	Wu,
	//平移
	E,
	//缩放
	T,
	//旋转
	R,
	//轴
	操控X,

	操控Y,

	操控Z
};


//鼠标键盘检测事件
class Mouse_Key
{
public:
	Mouse_Key();
	~Mouse_Key();

	float 鼠标滚轮;
	float 鼠标x;
	float 鼠标y;
	bool 滚轮事件;
	bool 鼠标事件;
	bool ctrl检测;

	键盘按键 键盘事件记录;
public:
	void 时间线();
	void 参数刷新(QPoint 鼠标参数);
	void 参数重置();
	int 返回键盘响应信息();
};

