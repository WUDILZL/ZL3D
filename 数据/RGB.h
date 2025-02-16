#pragma once
#include "计算.h"
class YS_RGB
{
public:
	float a, r, g, b;
	
	YS_RGB();
	YS_RGB(float ys);
	YS_RGB(float R, float G, float B);
	YS_RGB(float R, float G, float B, float A);

public:
	static YS_RGB 范围采样(float 百分比, YS_RGB 起点, YS_RGB 终点);
	//static std::vector<unsigned char> convertToByteArray();
	static YS_RGB 黑();
	static YS_RGB 白();
	static YS_RGB 透明();
	static YS_RGB 灰();
	static YS_RGB 浅灰();
	static YS_RGB 深灰();
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