#pragma once
#include <cmath>

class ������ά
{
public:
	float X, Y, Z, W;

	������ά();
	������ά(float x, float y, float z, float w);

public:
	float ģ();
	static float ������(������ά ��, ������ά ��);
	static ������ά ���㵥λ����(������ά ����);

	������ά operator *(float& ����);
	������ά operator +(������ά& ����);
	������ά operator -(������ά& ����);
	������ά operator *(������ά& ����);

};
