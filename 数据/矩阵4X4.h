#pragma once
#include "向量三维.h"
#include "向量四维.h"

class 矩阵4X4
{
public:
	float M11, M12, M13, M14;
	float M21, M22, M23, M24;
	float M31, M32, M33, M34;
	float M41, M42, M43, M44;

	矩阵4X4();
	矩阵4X4(float z);
	矩阵4X4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
	矩阵4X4(std::vector<float> z);
	//float& operator[](int index);
	static 矩阵4X4 零();
	static 矩阵4X4 单位矩阵();

	static 矩阵4X4 计算叉乘(矩阵4X4 左, 矩阵4X4 右);

	矩阵4X4 operator -();
	矩阵4X4 operator +(矩阵4X4 矩阵);
	矩阵4X4 operator -(矩阵4X4 矩阵);
	矩阵4X4 operator *(float 矩阵);
	矩阵4X4 operator *(矩阵4X4 矩阵);
	向量三维 operator *(向量三维 向量);
	//方法 向量三维 * 矩阵;
	static 向量三维 返回平移(向量三维 向量, 矩阵4X4 矩阵);

public:
	static 向量四维 行1(矩阵4X4 jz);
	static 向量四维 行2(矩阵4X4 矩阵);
	static 向量四维 行3(矩阵4X4 矩阵);
	static 向量四维 行4(矩阵4X4 矩阵);
	static 向量四维 列1(矩阵4X4 矩阵);
	static 向量四维 列2(矩阵4X4 矩阵);
	static 向量四维 列3(矩阵4X4 矩阵);
	static 向量四维 列4(矩阵4X4 矩阵);
	static void 行一(向量四维 数据, 矩阵4X4& 目标);
	static void 行二(向量四维 数据, 矩阵4X4& 目标);
	static void 行三(向量四维 数据, 矩阵4X4& 目标);
	static void 行四(向量四维 数据, 矩阵4X4& 目标);
	static void 列一(向量四维 数据, 矩阵4X4& 目标);
	static void 列二(向量四维 数据, 矩阵4X4& 目标);
	static void 列三(向量四维 数据, 矩阵4X4& 目标);
	static void 列四(向量四维 数据, 矩阵4X4& 目标);

	static 向量三维 平移(矩阵4X4 矩阵);
	static 向量三维 缩放(矩阵4X4 矩阵);

public:
	static float 计算行列式(矩阵4X4 矩阵);
	static 矩阵4X4 计算幂(矩阵4X4 左, int 指数);
	static 矩阵4X4 计算线性插值(矩阵4X4 矩阵A, 矩阵4X4 矩阵B, float 百分比);
	static 矩阵4X4 三次插值(矩阵4X4 矩阵A, 矩阵4X4 矩阵B, float 百分比);
	static 矩阵4X4 计算转置矩阵(矩阵4X4 矩阵);
	static 矩阵4X4 计算逆矩阵(矩阵4X4 矩阵);
	static 矩阵4X4 计算正交矩阵(矩阵4X4 矩阵);
	static 矩阵4X4 计算正交归一化矩阵(矩阵4X4 矩阵);
	static 矩阵4X4 创建目标矩阵(向量三维 摄像机坐标, 向量三维 目标坐标, 向量三维 上方向向量, 向量三维 前方向向量);
	static 矩阵4X4 创建视图矩阵(向量三维 摄像机坐标, 向量三维 目标坐标, 向量三维 上方向向量);
	static 矩阵4X4 创建正交投影矩阵(float 缩放, float 宽高比, float 近端修剪, float 远端修剪);
	static 矩阵4X4 创建正交投影矩阵_尺寸(float 宽度, float 高度, float 近端修剪, float 远端修剪);
	static 矩阵4X4 创建自定义透视投影矩阵(float 左, float 右, float 下, float 上, float 近端修剪, float 远端修剪);
	static 矩阵4X4 创建透视投影矩阵(float 宽度, float 高度, float 近端修剪, float 远端修剪);
	static 矩阵4X4 创建视野透视投影矩阵(float 视锥角度, float 宽高比, float 近端修剪, float 远端修剪);
	static 矩阵4X4 创建缩放矩阵(向量三维 缩放);
	static 矩阵4X4 创建缩放矩阵(float x, float y, float z);
	static 矩阵4X4 创建缩放矩阵(float 缩放);
	static 矩阵4X4 创建旋转矩阵X(float 弧度);
	static 矩阵4X4 创建旋转矩阵Y(float 弧度);
	static 矩阵4X4 创建旋转矩阵Z(float 弧度);
	static 矩阵4X4 创建旋转矩阵(向量三维 旋转轴, float 弧度);
	static 向量三维 提取欧拉旋转(矩阵4X4 旋转矩阵);
	static 矩阵4X4 创建法线矩阵(矩阵4X4 世界矩阵);
	static 矩阵4X4 创建向量旋转矩阵(向量三维 向量1, 向量三维 向量2);
	static 矩阵4X4 创建平移矩阵(向量三维 平移);
	static 矩阵4X4 创建平移矩阵(float x, float y, float z);
	static 矩阵4X4 创建变换矩阵2D(float 缩放, float 旋转, 向量二维 平移);
	static 矩阵4X4 创建仿射变换矩阵2D(float 缩放, 向量二维 旋转中心, float 旋转, 向量二维 平移);
	static 矩阵4X4 创建仿射变换矩阵2D(向量二维 缩放中心, float 缩放旋转, 向量二维 缩放, 向量二维 旋转中心, float 旋转, 向量二维 平移);

};

