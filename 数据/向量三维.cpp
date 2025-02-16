#include "向量三维.h"

向量三维::向量三维()
{
	X = 0, Y = 0, Z = 0;
}

向量三维::向量三维(float z)
{
	X = z, Y = z, Z = z;
}

向量三维::向量三维(float x, float y, float z)
{
	X = x, Y = y, Z = z;
}

向量三维::向量三维(向量二维 xy, float z)
{
	X = xy.X, Y = xy.Y, Z = z;
}

向量三维::~向量三维()
{
}

向量三维 向量三维::X轴()
{
	return 向量三维(1, 0, 0);
}

向量三维 向量三维::Y轴()
{
	return 向量三维(0, 1, 0);
}

向量三维 向量三维::Z轴()
{
	return 向量三维(0, 0, 1);
}

向量三维 向量三维::负X轴()
{
	return 向量三维(-1, 0, 0);
}

向量三维 向量三维::负Y轴()
{
	return 向量三维(0, -1, 0);
}

向量三维 向量三维::负Z轴()
{
	return 向量三维(0, 0, -1);
}

向量三维 向量三维::零()
{
	return 向量三维(0);
}

向量三维 向量三维::壹()
{
	return 向量三维(1);
}

向量三维 向量三维::operator-()
{
	return 向量三维(-X, -Y, -Z);
}

向量三维 向量三维::operator+(向量三维 向量)
{
	向量三维 temp(X, Y, Z);
	return 向量三维(temp.X + 向量.X, temp.Y + 向量.Y, temp.Z + 向量.Z);
}

向量三维 向量三维::operator-(向量三维 向量)
{
	向量三维 temp(X, Y, Z);
	return 向量三维(temp.X - 向量.X, temp.Y - 向量.Y, temp.Z - 向量.Z);
}

向量三维 向量三维::operator*(向量三维 向量)
{
	向量三维 temp(X, Y, Z);
	return 向量三维(temp.X * 向量.X, temp.Y * 向量.Y, temp.Z * 向量.Z);
}

向量三维 向量三维::operator/(向量三维 向量)
{
	向量三维 temp(X, Y, Z);
	return 向量三维(temp.X / 向量.X, temp.Y / 向量.Y, temp.Z / 向量.Z);
}

向量三维 向量三维::operator+(float 向量)
{
	向量三维 temp(X, Y, Z);
	return 向量三维(temp.X + 向量, temp.Y + 向量, temp.Z + 向量);
}

向量三维 向量三维::operator-(float 向量)
{
	向量三维 temp(X, Y, Z);
	return 向量三维(temp.X - 向量, temp.Y - 向量, temp.Z - 向量);
}

向量三维 向量三维::operator*(float 向量)
{
	向量三维 temp(X, Y, Z);
	return 向量三维(temp.X * 向量, temp.Y * 向量, temp.Z * 向量);
}

向量三维 向量三维::operator/(float 向量)
{
	向量三维 temp(X, Y, Z);
	return 向量三维(temp.X / 向量, temp.Y / 向量, temp.Z / 向量);
}

bool 向量三维::operator==(向量三维& 向量)
{
	向量三维 temp(X, Y, Z);
	return temp.X == 向量.X && temp.Y == 向量.Y && temp.Z == 向量.Z;
}

bool 向量三维::operator!=(向量三维& 向量)
{
	向量三维 temp(X, Y, Z);
	return temp.X != 向量.X || temp.Y != 向量.Y || temp.Z != 向量.Z;
}

float 向量三维::模()
{
	return std::sqrt(X * X + Y * Y + Z * Z);
}

float 向量三维::模平方()
{
	return X * X + Y * Y + Z * Z;
}

void 向量三维::转单位向量()
{
	float num = 模();
	if (!计算::等于0(num))
	{
		float num2 = 1.0f / num;
		X *= num2;
		Y *= num2;
		Z *= num2;
	}
}

向量三维 向量三维::计算单位向量(向量三维 向量)
{
	float length = 向量.模();
	return 向量三维(向量.X / length, 向量.Y / length, 向量.Z / length);
}


向量三维 向量三维::计算绝对值(向量三维 向量)
{
	return 向量三维((向量.X > 0.0f) ? 向量.X : (0.0f - 向量.X), (向量.Y > 0.0f) ? 向量.Y : (0.0f - 向量.Y), (向量.Z > 0.0f) ? 向量.Z : (0.0f - 向量.Z));
}

向量三维 向量三维::计算三角形重心权重坐标(向量三维 点1, 向量三维 点2, 向量三维 点3, float 百分比1, float 百分比2)
{
	return 向量三维(点1.X + 百分比1 * (点2.X - 点1.X) + 百分比2 * (点3.X - 点1.X), 点1.Y + 百分比1 * (点2.Y - 点1.Y) + 百分比2 * (点3.Y - 点1.Y), 点1.Z + 百分比1 * (点2.Z - 点1.Z) + 百分比2 * (点3.Z - 点1.Z));
}

向量三维 向量三维::范围限制(向量三维 向量, 向量三维 最小值, 向量三维 最大值)
{
	float x = 向量.X;
	x = ((x > 最大值.X) ? 最大值.X : x);
	x = ((x < 最小值.X) ? 最小值.X : x);
	float y = 向量.Y;
	y = ((y > 最大值.Y) ? 最大值.Y : y);
	y = ((y < 最小值.Y) ? 最小值.Y : y);
	float z = 向量.Z;
	z = ((z > 最大值.Z) ? 最大值.Z : z);
	z = ((z < 最小值.Z) ? 最小值.Z : z);
	return 向量三维(x, y, z);
}

向量三维 向量三维::计算叉乘(向量三维 左, 向量三维 右)
{
	return 向量三维(左.Y * 右.Z - 左.Z * 右.Y, 左.Z * 右.X - 左.X * 右.Z, 左.X * 右.Y - 左.Y * 右.X);
}

float 向量三维::计算距离(向量三维 坐标1, 向量三维 坐标2)
{
	float num = 坐标1.X - 坐标2.X;
	float num2 = 坐标1.Y - 坐标2.Y;
	float num3 = 坐标1.Z - 坐标2.Z;
	return std::sqrt(num * num + num2 * num2 + num3 * num3);
}

float 向量三维::计算距离平方(向量三维 坐标1, 向量三维 坐标2)
{
	float num = 坐标1.X - 坐标2.X;
	float num2 = 坐标1.Y - 坐标2.Y;
	float num3 = 坐标1.Z - 坐标2.Z;
	return num * num + num2 * num2 + num3 * num3;
}

float 向量三维::计算点乘(向量三维 左, 向量三维 右)
{
	return 左.X * 右.X + 左.Y * 右.Y + 左.Z * 右.Z;
}

向量三维 向量三维::计算中点(向量三维 坐标A, std::vector<向量三维> 坐标集合)
{
	向量三维 和 = 坐标A;
	for (int i = 0; i < 坐标集合.size(); i++)
	{
		向量三维 m = 坐标集合[i];
		和 = 和 + m;
	}
	float mm = 坐标集合.size() + 1;
	return  和 / mm;
}

向量三维 向量三维::计算重心(std::vector<向量三维> 坐标集合)
{
	向量三维 和;
	for (int i = 0; i < 坐标集合.size(); i++)
	{
		向量三维 m = 坐标集合[i];
		和 = 和 + m;
	}
	float mm = 坐标集合.size();
	return  和 / mm;
}

向量三维 向量三维::计算偏移(向量三维 起始向量, 向量三维 终点向量, float 百分比)
{
	向量三维 方向 = 终点向量 - 起始向量;
	向量三维 mm = 方向 * 百分比;
	return 起始向量 + mm;
}

向量三维 向量三维::计算点投影坐标(向量三维 点, 向量三维 面法线)
{
	float 点乘 = 向量三维::计算点乘(点, 面法线);
	向量三维 mm = 面法线 * 点乘;
	向量三维 投影坐标 = 点 - mm;
	return 投影坐标;
}

向量三维 向量三维::计算点投影坐标(向量三维 点, 向量三维 面法线, 向量三维 面坐标)
{
	float 点乘 = 向量三维::计算点乘(点 - 面坐标, 面法线);
	向量三维 mm = 面法线 * 点乘;
	向量三维 投影坐标 = 点 - mm;
	return 投影坐标;
}

float 向量三维::计算夹角(向量三维 向量1, 向量三维 向量2)
{
	float dotProduct = 计算点乘(向量1, 向量2);
	float magnitudeProduct = 向量1.模() * 向量2.模();
	return std::acos(dotProduct / magnitudeProduct);
}

向量三维 向量三维::计算面法线(std::vector<向量三维> 顶点集合)
{
	向量三维 A = 顶点集合[0];
	向量三维 B = 顶点集合[1];
	向量三维 C = 顶点集合[2];
	向量三维 叉乘 = 计算叉乘(B - A, C - A);
	return 计算单位向量(叉乘);
}

向量二维 向量三维::计算经纬度(向量三维 坐标)
{
	// 计算经度
	float 经度 = std::atan2(坐标.Y, 坐标.X);
	// 计算纬度
	float hyp = std::sqrt(坐标.X * 坐标.X + 坐标.Y * 坐标.Y);
	float 纬度 = std::atan2(坐标.Z, hyp);

	return 向量二维(经度, 纬度);
}

向量三维 向量三维::计算线性插值(向量三维 坐标1, 向量三维 坐标2, float 百分比)
{
	向量三维 结果;
	结果.X = 计算::范围采样(坐标1.X, 坐标2.X, 百分比);
	结果.Y = 计算::范围采样(坐标1.Y, 坐标2.Y, 百分比);
	结果.Z = 计算::范围采样(坐标1.Z, 坐标2.Z, 百分比);
	return 结果;
}

向量三维 向量三维::计算三次插值(向量三维 起点向量, 向量三维 终点向量, float 百分比)
{
	百分比 = 计算::缓动采样(百分比);
	return 计算线性插值(起点向量, 终点向量, 百分比);
}

向量三维 向量三维::计算Hermite插值(向量三维 向量1, 向量三维 tangent1, 向量三维 向量2, 向量三维 tangent2, float amount)
{
	向量三维 result;
	float num = amount * amount;
	float num2 = amount * num;
	float num3 = 2.0f * num2 - 3.0f * num + 1.0f;
	float num4 = -2.0f * num2 + 3.0f * num;
	float num5 = num2 - 2.0f * num + amount;
	float num6 = num2 - num;
	result.X = 向量1.X * num3 + 向量2.X * num4 + tangent1.X * num5 + tangent2.X * num6;
	result.Y = 向量1.Y * num3 + 向量2.Y * num4 + tangent1.Y * num5 + tangent2.Y * num6;
	result.Z = 向量1.Z * num3 + 向量2.Z * num4 + tangent1.Z * num5 + tangent2.Z * num6;
	return result;
}

向量三维 向量三维::计算CatmullRom插值(向量三维 向量1, 向量三维 向量2, 向量三维 向量3, 向量三维 向量4, float amount)
{
	向量三维 result;
	float num = amount * amount;
	float num2 = amount * num;
	result.X = 0.5f * (2.0f * 向量2.X + (0.0f - 向量1.X + 向量3.X) * amount + (2.0f * 向量1.X - 5.0f * 向量2.X + 4.0f * 向量3.X - 向量4.X) * num + (0.0f - 向量1.X + 3.0f * 向量2.X - 3.0f * 向量3.X + 向量4.X) * num2);
	result.Y = 0.5f * (2.0f * 向量2.Y + (0.0f - 向量1.Y + 向量3.Y) * amount + (2.0f * 向量1.Y - 5.0f * 向量2.Y + 4.0f * 向量3.Y - 向量4.Y) * num + (0.0f - 向量1.Y + 3.0f * 向量2.Y - 3.0f * 向量3.Y + 向量4.Y) * num2);
	result.Z = 0.5f * (2.0f * 向量2.Z + (0.0f - 向量1.Z + 向量3.Z) * amount + (2.0f * 向量1.Z - 5.0f * 向量2.Z + 4.0f * 向量3.Z - 向量4.Z) * num + (0.0f - 向量1.Z + 3.0f * 向量2.Z - 3.0f * 向量3.Z + 向量4.Z) * num2);
	return result;
}

向量三维 向量三维::计算最大值(向量三维 左, 向量三维 右)
{
	向量三维 最大值;
	最大值.X = ((左.X > 右.X) ? 左.X : 右.X);
	最大值.Y = ((左.Y > 右.Y) ? 左.Y : 右.Y);
	最大值.Z = ((左.Z > 右.Z) ? 左.Z : 右.Z);
	return 最大值;
}

向量三维 向量三维::计算最小值(向量三维 左, 向量三维 右)
{
	向量三维 最小值;
	最小值.X = ((左.X < 右.X) ? 左.X : 右.X);
	最小值.Y = ((左.Y < 右.Y) ? 左.Y : 右.Y);
	最小值.Z = ((左.Z < 右.Z) ? 左.Z : 右.Z);
	return 最小值;
}

向量三维 向量三维::计算三角形质心坐标(向量三维 向量1, 向量三维 向量2, 向量三维 向量3, 向量三维 交点坐标)
{
	// 计算三角形的面积
	float area = 向量三维::计算叉乘(向量2 - 向量1, 向量3 - 向量1).模() / 2;

	// 计算点与顶点组成的子三角形的面积
	float area0 = 向量三维::计算叉乘(向量2 - 交点坐标, 向量3 - 交点坐标).模() / 2;
	float area1 = 向量三维::计算叉乘(向量3 - 交点坐标, 向量1 - 交点坐标).模() / 2;
	float area2 = 向量三维::计算叉乘(向量1 - 交点坐标, 向量2 - 交点坐标).模() / 2;

	// 计算质心坐标（权重）
	float w0 = area0 / area;
	float w1 = area1 / area;
	float w2 = area2 / area;

	return 向量三维(w0, w1, w2);
}

向量三维 向量三维::计算三角权重(向量三维 交点, 向量三维 顶点1, 向量三维 顶点2, 向量三维 顶点3)
{
	向量三维 edge0 = 顶点2 - 顶点1;
	向量三维 edge1 = 顶点3 - 顶点1;
	向量三维 edge2 = 交点 - 顶点1;

	float dot00 = 向量三维::计算点乘(edge0, edge0);
	float dot01 = 向量三维::计算点乘(edge0, edge1);
	float dot02 = 向量三维::计算点乘(edge0, edge2);
	float dot11 = 向量三维::计算点乘(edge1, edge1);
	float dot12 = 向量三维::计算点乘(edge1, edge2);

	float invDenom = 1.0f / (dot00 * dot11 - dot01 * dot01);
	float u = (dot11 * dot02 - dot01 * dot12) * invDenom;
	float v = (dot00 * dot12 - dot01 * dot02) * invDenom;
	float w = 1.0f - u - v;

	return  向量三维(u, v, w);
}

向量三维 向量三维::计算三角顶点法线插值(向量三维 三角权重, 向量三维 法线1, 向量三维 法线2, 向量三维 法线3)
{
	向量三维 mm = 法线1 * 三角权重.X;
	向量三维 mm2 = 法线2 * 三角权重.Y;
	向量三维 mm3 = 法线3 * 三角权重.Z;
	向量三维 interpolatedNormal = mm + mm2 + mm3;
	return 计算单位向量(interpolatedNormal);
}

bool 向量三维::检查为空(向量三维 向量)
{
	if (isnan(向量.X) || isnan(向量.Y) || isnan(向量.Z))
	{
		return true;
	}
	return false;
}







