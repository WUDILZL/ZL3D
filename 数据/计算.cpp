#include "计算.h"



float 计算::角度转弧度(float 角度)
{
	return 角度 * (计算PI / 180.0f);
}

float 计算::弧度转角度(float 弧度)
{
	return 弧度 * (180.0f / 计算PI);
}

float 计算::范围映射(float 输入值, float 输入下限, float 输入上限, float 输出下限, float 输出上限)
{
	float 百分比 = (输入上限 - 输入值) / (输入上限 - 输入下限);
	float 输出值 = 输出上限 - ((输出上限 - 输出下限) * 百分比);
	return 输出值;
}

float 计算::范围采样(float 起点, float 终点, float 百分比)
{
	return 起点 + ((终点 - 起点) * 百分比);
}

float 计算::范围百分比(float 值, float 起点, float 终点)
{
	if (起点 == 终点)
		return 起点;

	return (值 - 起点) / (终点 - 起点);
}

void 计算::重新分配大小(float& 小值, float& 大值)
{
	if (小值 > 大值)
	{
		float 交换 = 大值;
		大值 = 小值;
		小值 = 交换;
	}
}

float 计算::范围限制(float 输入值, float 下限, float 上限)
{
	if (输入值 < 下限)
		return 下限;
	else if (输入值 > 上限)
		return 上限;
	else
		return 输入值;
}

float 计算::缓动采样(float 百分比)
{
	return 百分比 * 百分比 * 百分比 * (百分比 * (百分比 * 6 - 15) + 10);
}

float 计算::缓动采样(float 百分比, float 起点, float 终点)
{
	float 缓动百分比 = 缓动采样(百分比);
	return 范围采样(起点, 终点, 缓动百分比);
}

bool 计算::等于0(float 值)
{
	return std::abs(值) < 1E-06f;
}

bool 计算::等于1(float 值)
{
	return 等于0(值 - 1.0f);
}

bool 计算::相等(float x1, float x2)
{
	return 等于0(std::abs(x1 - x2));
}

float 计算::弧度()
{
	return 计算PI / 180.0f;
}

float 计算::角度()
{
	return 180.0f / 计算PI;
}

float 计算::角1()
{
	return 计算PI / 180.0f;
}

float 计算::角45()
{
	return 计算PI * 0.25;
}

float 计算::角90()
{
	return 计算PI * 0.5;
}

float 计算::角135()
{
	return (计算PI * 0.5f) + (计算PI * 0.25f);
}

float 计算::角180()
{
	return 计算PI;
}

float 计算::角225()
{
	return 计算PI + (计算PI + 0.25f);
}

float 计算::角270()
{
	return 计算PI * 1.5f;
}

float 计算::角315()
{
	return (计算PI * 1.5f) + (计算PI * 0.25f);
}

float 计算::角360()
{
	return 计算PI * 2;
}
