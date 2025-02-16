#include "向量四维.h"

向量四维::向量四维()
{
	X = 0, Y = 0, Z = 0, W = 0;
}

向量四维::向量四维(float x, float y, float z, float w)
{
	X = x, Y = y, Z = z, W = w;
}

float 向量四维::模()
{
	return std::sqrt(X * X + Y * Y + Z * Z + W * W);
}

float 向量四维::计算点乘(向量四维 左, 向量四维 右)
{
	return 左.X * 右.X + 左.Y * 右.Y + 左.Z * 右.Z + 左.W * 右.W;
}

向量四维 向量四维::计算单位向量(向量四维 向量)
{
	float length = 向量.模();
	return 向量四维(向量.X / length, 向量.Y / length, 向量.Z / length, 向量.W / length);
}

向量四维 向量四维::operator*(float& 标量)
{
	向量四维 变量(X, Y, Z, W);
	return 向量四维(变量.X * 标量, 变量.Y * 标量, 变量.Z * 标量, 变量.W * 标量);
}

向量四维 向量四维::operator+(向量四维& 向量)
{
	向量四维 变量(X, Y, Z, W);
	return 向量四维(变量.X + 向量.X, 变量.Y + 向量.Y, 变量.Z + 向量.Z, 变量.W + 向量.W);
}

向量四维 向量四维::operator-(向量四维& 向量)
{
	向量四维 变量(X, Y, Z, W);
	return 向量四维(变量.X - 向量.X, 变量.Y - 向量.Y, 变量.Z - 向量.Z, 变量.W - 向量.W);
}

向量四维 向量四维::operator*(向量四维& 向量)
{
	向量四维 变量(X, Y, Z, W);
	return 向量四维(变量.X * 向量.X, 变量.Y * 向量.Y, 变量.Z * 向量.Z, 变量.W * 向量.W);
}
