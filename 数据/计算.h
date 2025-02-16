#pragma once
#include <cmath>
#include <vector>

#define 计算PI 3.1415926f

class 计算
{
public:
	//float PI = 3.1415926;

	static float 角度转弧度(float 角度);
	static float 弧度转角度(float 弧度);
	static float 范围映射(float 输入值, float 输入下限, float 输入上限, float 输出下限, float 输出上限);
	static float 范围采样(float 起点, float 终点, float 百分比);
	static float 范围百分比(float 值, float 起点, float 终点);
	static void 重新分配大小(float& 小值, float& 大值);
	static float 范围限制(float 输入值, float 下限 = 0.0f, float 上限 = 1.0f);
	static float 缓动采样(float 百分比);
	static float 缓动采样(float 百分比, float 起点, float 终点);
	static bool 等于0(float 值);
	static bool 等于1(float 值);
	static bool 相等(float x1, float x2);

	static float 弧度();
	static float 角度();
	static float 角1();
	static float 角45();
	static float 角90();
	static float 角135();
	static float 角180();
	static float 角225();
	static float 角270();
	static float 角315();
	static float 角360();
};

