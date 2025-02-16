#pragma once
#include <vector>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "计算.h"





class 向量二维
{
public:
	float X, Y;

	向量二维();
	向量二维(float 向量);
	向量二维(float x, float y);

public:
	float 模();
	float 模平方();
	void 转单位向量();
	std::vector<float> 转数组();

	向量二维 operator -();
	向量二维 operator +(向量二维& 向量);
	向量二维 operator -(向量二维& 向量);
	向量二维 operator *(向量二维& 向量);
	向量二维 operator /(向量二维& 向量);
	向量二维 operator +(float& 标量);
	向量二维 operator -(float& 标量);
	向量二维 operator *(float& 标量);
	向量二维 operator /(float& 标量);
	bool operator ==(向量二维& 向量);
	bool operator !=(向量二维& 向量);

public:
	static 向量二维 计算绝对值(向量二维 向量);
	static 向量二维 Barycentric(向量二维 坐标1, 向量二维 坐标2, 向量二维 坐标3, float 权重1, float 权重2);
	static 向量二维 范围限制(向量二维 向量, 向量二维 最小值, 向量二维 最大值);
	static float 计算叉乘(向量二维 向量1, 向量二维 向量2);
	static float 计算点乘(向量二维 向量1, 向量二维 向量2);
	static float 计算距离(向量二维 向量1, 向量二维 向量2);
	static float 计算距离平方(向量二维 向量1, 向量二维 向量2);
	static 向量二维 计算单位向量(向量二维 向量);
	static 向量二维 计算反射向量(向量二维 入射向量, 向量二维 法线);
	static 向量二维 计算线性插值(向量二维 开始向量, 向量二维 结束向量, float 百分比);
	static 向量二维 计算三次插值(向量二维 开始向量, 向量二维 结束向量, float 百分比);
	static 向量二维 计算Hermite插值(向量二维 向量1, 向量二维 切线1, 向量二维 向量2, 向量二维 切线2, float 百分比);
	static 向量二维 计算CatmullRom插值(向量二维 向量1, 向量二维 向量2, 向量二维 向量3, 向量二维 向量4, float 百分比);
	static float 计算夹角(向量二维 向量A, 向量二维 向量B);
	static float 计算顺时针旋转角度(向量二维 向量1, 向量二维 向量2);

};

