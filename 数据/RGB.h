#pragma once
#include "����.h"
class YS_RGB
{
public:
	float a, r, g, b;
	
	YS_RGB();
	YS_RGB(float ys);
	YS_RGB(float R, float G, float B);
	YS_RGB(float R, float G, float B, float A);

public:
	static YS_RGB ��Χ����(float �ٷֱ�, YS_RGB ���, YS_RGB �յ�);
	//static std::vector<unsigned char> convertToByteArray();
	static YS_RGB ��();
	static YS_RGB ��();
	static YS_RGB ͸��();
	static YS_RGB ��();
	static YS_RGB ǳ��();
	static YS_RGB ���();
	YS_RGB operator+(YS_RGB& canshu);
	YS_RGB operator-(YS_RGB& canshu);
	YS_RGB operator*(YS_RGB& canshu);
	YS_RGB operator/(YS_RGB& canshu);
	YS_RGB operator+(float& canshu);
	YS_RGB operator-(float& canshu);
	YS_RGB operator*(float& canshu);
	YS_RGB operator/(float& canshu);
	bool operator==(YS_RGB& canshu);
	bool operator!=(YS_RGB& canshu);

};