#include "向量二维.h"



向量二维::向量二维()
{
	X = 0, Y = 0;
}

向量二维::向量二维(float 向量)
{
	X = 向量, Y = 向量;
}

向量二维::向量二维(float x, float y)
{
	X = x, Y = y;
}

float 向量二维::模()
{
	return std::sqrt(X * X + Y * Y);
}

float 向量二维::模平方()
{
	return X * X, Y* Y;
}

void 向量二维::转单位向量()
{
	float num = 模();
	if (!计算::等于0(num))
	{
		float num2 = 1.0f / num;
		X *= num2;
		Y *= num2;
	}
}

std::vector<float> 向量二维::转数组()
{
	return std::vector<float>(X, Y);
}

向量二维 向量二维::operator-()
{
	return 向量二维(-X, -Y);
}

向量二维 向量二维::operator+(向量二维& 向量)
{
	向量二维 data(X, Y);
	return 向量二维(data.X + 向量.X, data.Y + 向量.Y);
}

向量二维 向量二维::operator-(向量二维& 向量)
{
	向量二维 data(X, Y);
	return 向量二维(data.X - 向量.X, data.Y - 向量.Y);
}

向量二维 向量二维::operator*(向量二维& 向量)
{
	向量二维 data(X, Y);
	return 向量二维(data.X * 向量.X, data.Y * 向量.Y);
}

向量二维 向量二维::operator/(向量二维& 向量)
{
	向量二维 data(X, Y);
	return 向量二维(data.X / 向量.X, data.Y / 向量.Y);
}

向量二维 向量二维::operator+(float& 标量)
{
	向量二维 data(X, Y);
	return 向量二维(data.X + 标量, data.Y + 标量);
}

向量二维 向量二维::operator-(float& 标量)
{
	向量二维 data(X, Y);
	return 向量二维(data.X - 标量, data.Y - 标量);
}

向量二维 向量二维::operator*(float& 标量)
{
	向量二维 data(X, Y);
	return 向量二维(data.X * 标量, data.Y * 标量);
}

向量二维 向量二维::operator/(float& 标量)
{
	向量二维 data(X, Y);
	return 向量二维(data.X / 标量, data.Y / 标量);
}

bool 向量二维::operator==(向量二维& 向量)
{
	向量二维 data(X, Y);
	return data.X == 向量.X && data.Y == 向量.Y;
}

bool 向量二维::operator!=(向量二维& 向量)
{
	向量二维 data(X, Y);
	return data.X != 向量.X || data.Y != 向量.Y;
}

向量二维 向量二维::计算绝对值(向量二维 向量)
{
	return 向量二维((向量.X > 0.0f) ? 向量.X : (0.0f - 向量.X), (向量.Y > 0.0f) ? 向量.Y : (0.0f - 向量.Y));;
}

向量二维 向量二维::Barycentric(向量二维 坐标1, 向量二维 坐标2, 向量二维 坐标3, float 权重1, float 权重2)
{
	return 向量二维(坐标1.X + 权重1 * (坐标2.X - 坐标1.X) + 权重2 * (坐标3.X - 坐标1.X), 坐标1.Y + 权重1 * (坐标2.Y - 坐标1.Y) + 权重2 * (坐标3.Y - 坐标1.Y));
}

向量二维 向量二维::范围限制(向量二维 向量, 向量二维 最小值, 向量二维 最大值)
{
	float x = 向量.X;
	x = ((x > 最大值.X) ? 最大值.X : x);
	x = ((x < 最小值.X) ? 最小值.X : x);
	float y = 向量.Y;
	y = ((y > 最大值.Y) ? 最大值.Y : y);
	y = ((y < 最小值.Y) ? 最小值.Y : y);
	return 向量二维(x, y);
}

float 向量二维::计算叉乘(向量二维 向量1, 向量二维 向量2)
{
	return 向量1.X * 向量2.Y - 向量1.Y * 向量2.X;
}

float 向量二维::计算点乘(向量二维 向量1, 向量二维 向量2)
{
	return 向量1.X * 向量2.X + 向量1.Y * 向量2.Y;
}

float 向量二维::计算距离(向量二维 向量1, 向量二维 向量2)
{
	float num = 向量1.X - 向量2.X;
	float num2 = 向量1.Y - 向量2.Y;
	return std::sqrt(num * num + num2 * num2);
}

float 向量二维::计算距离平方(向量二维 向量1, 向量二维 向量2)
{
	float num = 向量1.X - 向量2.X;
	float num2 = 向量1.Y - 向量2.Y;
	return num * num + num2 * num2;
}

向量二维 向量二维::计算单位向量(向量二维 向量)
{
	向量.转单位向量();
	return 向量;
}

向量二维 向量二维::计算反射向量(向量二维 入射向量, 向量二维 法线)
{
	向量二维 反射向量;
	float num = 入射向量.X * 法线.X + 入射向量.Y * 法线.Y;
	反射向量.X = 入射向量.X - 2.0f * num * 法线.X;
	反射向量.Y = 入射向量.Y - 2.0f * num * 法线.Y;
	return 反射向量;
}

向量二维 向量二维::计算线性插值(向量二维 开始向量, 向量二维 结束向量, float 百分比)
{
	向量二维 线性插值;
	线性插值.X = 计算::范围采样(开始向量.X, 结束向量.X, 百分比);
	线性插值.Y = 计算::范围采样(开始向量.Y, 结束向量.Y, 百分比);
	return 线性插值;
}

向量二维 向量二维::计算三次插值(向量二维 开始向量, 向量二维 结束向量, float 百分比)
{
	百分比 = 计算::缓动采样(百分比);
	return 计算线性插值(开始向量, 结束向量, 百分比);
}

向量二维 向量二维::计算Hermite插值(向量二维 向量1, 向量二维 切线1, 向量二维 向量2, 向量二维 切线2, float 百分比)
{
	向量二维 Hermite插值;
	float num = 百分比 * 百分比;
	float num2 = 百分比 * num;
	float num3 = 2.0f * num2 - 3.0f * num + 1.0f;
	float num4 = -2.0f * num2 + 3.0f * num;
	float num5 = num2 - 2.0f * num + 百分比;
	float num6 = num2 - num;
	Hermite插值.X = 向量1.X * num3 + 向量2.X * num4 + 切线1.X * num5 + 切线2.X * num6;
	Hermite插值.Y = 向量1.Y * num3 + 向量2.Y * num4 + 切线1.Y * num5 + 切线2.Y * num6;
	return Hermite插值;
}

向量二维 向量二维::计算CatmullRom插值(向量二维 向量1, 向量二维 向量2, 向量二维 向量3, 向量二维 向量4, float 百分比)
{
	向量二维 CatmullRom插值;
	float num = 百分比 * 百分比;
	float num2 = 百分比 * num;
	CatmullRom插值.X = 0.5f * (2.0f * 向量2.X + (0.0f - 向量1.X + 向量3.X) * 百分比 + (2.0f * 向量1.X - 5.0f * 向量2.X + 4.0f * 向量3.X - 向量4.X) * num + (0.0f - 向量1.X + 3.0f * 向量2.X - 3.0f * 向量3.X + 向量4.X) * num2);
	CatmullRom插值.Y = 0.5f * (2.0f * 向量2.Y + (0.0f - 向量1.Y + 向量3.Y) * 百分比 + (2.0f * 向量1.Y - 5.0f * 向量2.Y + 4.0f * 向量3.Y - 向量4.Y) * num + (0.0f - 向量1.Y + 3.0f * 向量2.Y - 3.0f * 向量3.Y + 向量4.Y) * num2);
	return CatmullRom插值;
}

float 向量二维::计算夹角(向量二维 向量A, 向量二维 向量B)
{
	float dotProduct = 向量二维::计算点乘(向量A, 向量B);
	float magnitudeProduct = 向量A.模() * 向量B.模();

	float angle = std::acos(dotProduct / magnitudeProduct);
	//float angleInDegrees = MathHelper.ToDegrees(angle);

	// 判断正负性
	float crossProduct = 向量A.X * 向量B.Y - 向量A.Y * 向量B.X;
	if (crossProduct < 0)
	{
		angle = -angle;
	}

	if (isnan(angle))
	{
		return 0;
	}

	//return angleInDegrees;
	//float dot = 向量A.X * 向量B.X + 向量A.Y * 向量B.Y;
	//float det = 向量A.X * 向量B.Y - 向量A.Y * 向量B.X;
	//float angle = MathF.Atan2(det, dot);
	//float crossProduct = (向量A.X * 向量B.Y) - (向量A.Y * 向量B.X);
	//if (crossProduct < 0)
	//    angle = -angle;
	return angle;
}

float 向量二维::计算顺时针旋转角度(向量二维 向量1, 向量二维 向量2)
{
	float PI = 3.1415926;
	float dotProduct = 向量二维::计算点乘(向量2, 向量1);
	float magnitudeProduct = 向量2.模() * 向量1.模();
	float angle = std::acos(dotProduct / magnitudeProduct);
	float 圆角 = PI + PI;
	// 判断正负性
	float crossProduct = 向量2.X * 向量1.Y - 向量2.Y * 向量1.X;
	if (crossProduct < 0)
		angle = -angle + 圆角;

	if (isnan(angle))
		return 0;

	return angle;
}




