#pragma once
#include "向量二维.h"

class 向量三维     //: public 向量二维
{
public:
	float X, Y, Z;

	向量三维();
	向量三维(float z);
	向量三维(float x, float y, float z);
	向量三维(向量二维 xy, float z);
	~向量三维();

	static 向量三维 X轴();
	static 向量三维 Y轴();
	static 向量三维 Z轴();
	static 向量三维 负X轴();
	static 向量三维 负Y轴();
	static 向量三维 负Z轴();
	static 向量三维 零();
	static 向量三维 壹();

	向量三维 operator -();
	向量三维 operator +(向量三维 向量);
	向量三维 operator -(向量三维 向量);
	向量三维 operator *(向量三维 向量);
	向量三维 operator /(向量三维 向量);
	向量三维 operator +(float 向量);
	向量三维 operator -(float 向量);
	向量三维 operator *(float 向量);
	向量三维 operator /(float 向量);

	bool operator == (向量三维& 向量);
	bool operator != (向量三维& 向量);


public:
	float 模();
	float 模平方();
	void 转单位向量();
	static 向量三维 计算单位向量(向量三维 向量);
	static 向量三维 计算绝对值(向量三维 向量);
	static 向量三维 计算三角形重心权重坐标(向量三维 点1, 向量三维 点2, 向量三维 点3, float 百分比1, float 百分比2);
	static 向量三维 范围限制(向量三维 向量, 向量三维 最小值, 向量三维 最大值);
	static 向量三维 计算叉乘(向量三维 左, 向量三维 右);
	static float 计算距离(向量三维 坐标1, 向量三维 坐标2);
	static float 计算距离平方(向量三维 坐标1, 向量三维 坐标2);
	static float 计算点乘(向量三维 左, 向量三维 右);
	static 向量三维 计算中点(向量三维 坐标A, std::vector<向量三维> 坐标集合);
	//static 向量三维 计算中点(std::vector<向量三维> 坐标集合A, std::vector<向量三维> 坐标集合B);
	//static 向量三维 计算中点(向量三维 坐标A, std::vector<向量三维> 坐标集合A, std::vector<向量三维> 坐标集合B);
	static 向量三维 计算重心(std::vector<向量三维> 坐标集合);
	static 向量三维 计算偏移(向量三维 起始向量, 向量三维 终点向量, float 百分比);
	static 向量三维 计算点投影坐标(向量三维 点, 向量三维 面法线);
	static 向量三维 计算点投影坐标(向量三维 点, 向量三维 面法线, 向量三维 面坐标);
	static float 计算夹角(向量三维 向量1, 向量三维 向量2);
	static 向量三维 计算面法线(std::vector<向量三维> 顶点集合);
	static 向量二维 计算经纬度(向量三维 坐标);
	static 向量三维 计算线性插值(向量三维 坐标1, 向量三维 坐标2, float 百分比);
	static 向量三维 计算三次插值(向量三维 起点向量, 向量三维 终点向量, float 百分比);
	static 向量三维 计算Hermite插值(向量三维 向量1, 向量三维 tangent1, 向量三维 向量2, 向量三维 tangent2, float amount);
	static 向量三维 计算CatmullRom插值(向量三维 向量1, 向量三维 向量2, 向量三维 向量3, 向量三维 向量4, float amount);
	static 向量三维 计算最大值(向量三维 左, 向量三维 右);
	static 向量三维 计算最小值(向量三维 左, 向量三维 右);
	static 向量三维 计算三角形质心坐标(向量三维 向量1, 向量三维 向量2, 向量三维 向量3, 向量三维 交点坐标);
	static 向量三维 计算三角权重(向量三维 交点, 向量三维 顶点1, 向量三维 顶点2, 向量三维 顶点3);
	static 向量三维 计算三角顶点法线插值(向量三维 三角权重, 向量三维 法线1, 向量三维 法线2, 向量三维 法线3);
	static bool 检查为空(向量三维 向量);


};