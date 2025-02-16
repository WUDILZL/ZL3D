#pragma once
#include <cmath>

class 向量四维
{
public:
	float X, Y, Z, W;

	向量四维();
	向量四维(float x, float y, float z, float w);

public:
	float 模();
	static float 计算点乘(向量四维 左, 向量四维 右);
	static 向量四维 计算单位向量(向量四维 向量);

	向量四维 operator *(float& 标量);
	向量四维 operator +(向量四维& 向量);
	向量四维 operator -(向量四维& 向量);
	向量四维 operator *(向量四维& 向量);

};
