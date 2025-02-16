#include "RGB.h"


YS_RGB::YS_RGB()
{
	a = 1, r = 1, g = 1, b = 1;
}

YS_RGB::YS_RGB(float ys)
{
	a = 1, r = ys, g = ys, b = ys;
}

YS_RGB::YS_RGB(float R, float G, float B)
{
	a = 1, r = R, g = G, b = B;
}

YS_RGB::YS_RGB(float R, float G, float B, float A)
{
	a = A, r = R, g = G, b = B;
}

YS_RGB YS_RGB::范围采样(float 百分比, YS_RGB 起点, YS_RGB 终点)
{
	float r = 计算::范围采样(起点.r, 终点.r, 百分比);
	float g = 计算::范围采样(起点.g, 终点.g, 百分比);
	float b = 计算::范围采样(起点.b, 终点.b, 百分比);
	float a = 计算::范围采样(起点.a, 终点.a, 百分比);
	return YS_RGB(r, g, b, a);
}

YS_RGB YS_RGB::黑()
{
	return YS_RGB(0);
}

YS_RGB YS_RGB::白()
{
	return YS_RGB(1);
}

YS_RGB YS_RGB::透明()
{
	return YS_RGB(0, 0, 0, 0);
}

YS_RGB YS_RGB::灰()
{
	return YS_RGB(0.5f);
}

YS_RGB YS_RGB::浅灰()
{
	return YS_RGB(0.75f);
}

YS_RGB YS_RGB::深灰()
{
	return YS_RGB(0.25f);
}

YS_RGB YS_RGB::operator+(YS_RGB& canshu)
{
	return YS_RGB(r + canshu.r, g + canshu.g, b + canshu.b, a);
}

//std::vector<unsigned char> YS_RGB::convertToByteArray()
//{
//	std::vector<unsigned char> byteArray;
//	byteArray.push_back(static_cast<unsigned char>(r * 255));
//	byteArray.push_back(static_cast<unsigned char>(g * 255));
//	byteArray.push_back(static_cast<unsigned char>(b * 255));
//	byteArray.push_back(static_cast<unsigned char>(a * 255));
//	return byteArray;
//}

YS_RGB YS_RGB::operator-(YS_RGB& canshu)
{
	YS_RGB 数据(r, g, b, a);
	return YS_RGB(数据.r - canshu.r, 数据.g - canshu.g, 数据.b - canshu.b, 数据.a);
}

YS_RGB YS_RGB::operator*(YS_RGB& canshu)
{
	YS_RGB 数据(r, g, b, a);
	return YS_RGB(数据.r * canshu.r, 数据.g * canshu.g, 数据.b * canshu.b, 数据.a);
}

YS_RGB YS_RGB::operator/(YS_RGB& canshu)
{
	YS_RGB 数据(r, g, b, a);
	return YS_RGB(数据.r / canshu.r, 数据.g / canshu.g, 数据.b / canshu.b, 数据.a);
}

YS_RGB YS_RGB::operator+(float& canshu)
{
	YS_RGB 数据(r, g, b, a);
	return YS_RGB(canshu + 数据.r, canshu + 数据.g, canshu + 数据.b, 数据.a);
}

YS_RGB YS_RGB::operator-(float& canshu)
{
	YS_RGB 数据(r, g, b, a);
	return YS_RGB(canshu - 数据.r, canshu - 数据.g, canshu - 数据.b, 数据.a);
}

YS_RGB YS_RGB::operator*(float& canshu)
{
	YS_RGB 数据(r, g, b, a);
	return YS_RGB(canshu * 数据.r, canshu * 数据.g, canshu * 数据.b, 数据.a);
}

YS_RGB YS_RGB::operator/(float& canshu)
{
	YS_RGB 数据(r, g, b, a);
	return YS_RGB(数据.r / canshu, 数据.g / canshu, 数据.b / canshu, 数据.a);
}

bool YS_RGB::operator==(YS_RGB& canshu)
{
	YS_RGB 数据(r, g, b, a);
	return 数据.r == canshu.r && 数据.g == canshu.g && 数据.b == canshu.b && 数据.a == canshu.a;
}

bool YS_RGB::operator!=(YS_RGB& canshu)
{
	YS_RGB 数据(r, g, b, a);
	return 数据.r != canshu.r || 数据.g != canshu.g || 数据.b != canshu.b || 数据.a != canshu.a;
}

