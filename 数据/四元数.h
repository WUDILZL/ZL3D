#pragma once

#include "矩阵4X4.h"

class 四元数
{
public:
	float X, Y, Z, W;

	四元数();
	四元数(float 值);
	四元数(向量三维 value, float w);
	四元数(向量二维 value, float z, float w);
	四元数(float x, float y, float z, float w);
	四元数(std::vector<float> values);

	static 四元数 零();
	static 四元数 壹();
	static 四元数 单位四元数();

	float 旋转角度(四元数 值);
	向量三维 旋转轴(四元数 值);

	static float 计算模(四元数 四元数);
	static float 计算模平方(四元数 四元数);
	static 四元数 计算叉乘(四元数 左, 四元数 右);
	static 四元数 计算单位四元数(四元数 四元数值);

	四元数 operator -();
	四元数 operator + (四元数 值);
	四元数 operator - (四元数 值);
	四元数 operator * (四元数 值);
	四元数 operator * (float 值);
	向量三维 operator * (向量三维 向量);
	//float& operator[](int index);

	static int 确定数字符号(float zhi);
	static 四元数 计算自然对数(四元数 四元数);
public:
	static 向量三维 四元数乘三维向量(向量三维 向量, 四元数 四元数);
	static float 计算点乘(四元数 左, 四元数 右);
	static 四元数 计算共轭(四元数 值);
	static 四元数 计算指数函数(四元数 四元数值);
	static 四元数 计算逆(四元数 四元数值);
	static 四元数 线性插值(四元数 四元数1, 四元数 四元数2, float 百分比);
	static 四元数 计算球面线性插值(四元数 四元数1, 四元数 四元数2, float 百分比);
	static 四元数 计算球面线性插值(四元数 四元数1, 四元数 四元数2, 四元数 四元数3, 四元数 四元数4, float 百分比);
	static 四元数 计算三点球面线性插值(四元数 四元数1, 四元数 四元数2, 四元数 四元数3, float 百分比1, float 百分比2);
	static std::vector<四元数> 计算球形四边形插值(四元数 四元数1, 四元数 四元数2, 四元数 四元数3, 四元数 四元数4);
	static 四元数 创建轴角旋转(向量三维 旋转轴, float 弧度);

	static 四元数 创建矩阵旋转(矩阵4X4 矩阵);
	static 四元数 创建目标旋转(向量三维 起点, 向量三维 目标点, 向量三维 上行向量, 向量三维 前方向量);
	static 四元数 创建目标旋转(向量三维 起点, 向量三维 目标点, 向量三维 上行向量);
	static 四元数 创建向量旋转(向量三维 向量1, 向量三维 向量2);
	static 四元数 创建欧拉角旋转(float X轴, float Y轴, float Z轴);
	static 四元数 创建欧拉角旋转(向量三维 欧拉旋转);
	static 向量三维 四元数转欧拉角(四元数 四元数);


};
