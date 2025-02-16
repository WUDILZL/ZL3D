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

YS_RGB YS_RGB::��Χ����(float �ٷֱ�, YS_RGB ���, YS_RGB �յ�)
{
	float r = ����::��Χ����(���.r, �յ�.r, �ٷֱ�);
	float g = ����::��Χ����(���.g, �յ�.g, �ٷֱ�);
	float b = ����::��Χ����(���.b, �յ�.b, �ٷֱ�);
	float a = ����::��Χ����(���.a, �յ�.a, �ٷֱ�);
	return YS_RGB(r, g, b, a);
}

YS_RGB YS_RGB::��()
{
	return YS_RGB(0);
}

YS_RGB YS_RGB::��()
{
	return YS_RGB(1);
}

YS_RGB YS_RGB::͸��()
{
	return YS_RGB(0, 0, 0, 0);
}

YS_RGB YS_RGB::��()
{
	return YS_RGB(0.5f);
}

YS_RGB YS_RGB::ǳ��()
{
	return YS_RGB(0.75f);
}

YS_RGB YS_RGB::���()
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
	YS_RGB ����(r, g, b, a);
	return YS_RGB(����.r - canshu.r, ����.g - canshu.g, ����.b - canshu.b, ����.a);
}

YS_RGB YS_RGB::operator*(YS_RGB& canshu)
{
	YS_RGB ����(r, g, b, a);
	return YS_RGB(����.r * canshu.r, ����.g * canshu.g, ����.b * canshu.b, ����.a);
}

YS_RGB YS_RGB::operator/(YS_RGB& canshu)
{
	YS_RGB ����(r, g, b, a);
	return YS_RGB(����.r / canshu.r, ����.g / canshu.g, ����.b / canshu.b, ����.a);
}

YS_RGB YS_RGB::operator+(float& canshu)
{
	YS_RGB ����(r, g, b, a);
	return YS_RGB(canshu + ����.r, canshu + ����.g, canshu + ����.b, ����.a);
}

YS_RGB YS_RGB::operator-(float& canshu)
{
	YS_RGB ����(r, g, b, a);
	return YS_RGB(canshu - ����.r, canshu - ����.g, canshu - ����.b, ����.a);
}

YS_RGB YS_RGB::operator*(float& canshu)
{
	YS_RGB ����(r, g, b, a);
	return YS_RGB(canshu * ����.r, canshu * ����.g, canshu * ����.b, ����.a);
}

YS_RGB YS_RGB::operator/(float& canshu)
{
	YS_RGB ����(r, g, b, a);
	return YS_RGB(����.r / canshu, ����.g / canshu, ����.b / canshu, ����.a);
}

bool YS_RGB::operator==(YS_RGB& canshu)
{
	YS_RGB ����(r, g, b, a);
	return ����.r == canshu.r && ����.g == canshu.g && ����.b == canshu.b && ����.a == canshu.a;
}

bool YS_RGB::operator!=(YS_RGB& canshu)
{
	YS_RGB ����(r, g, b, a);
	return ����.r != canshu.r || ����.g != canshu.g || ����.b != canshu.b || ����.a != canshu.a;
}

