#pragma once
#include <vector>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "����.h"





class ������ά
{
public:
	float X, Y;

	������ά();
	������ά(float ����);
	������ά(float x, float y);

public:
	float ģ();
	float ģƽ��();
	void ת��λ����();
	std::vector<float> ת����();

	������ά operator -();
	������ά operator +(������ά& ����);
	������ά operator -(������ά& ����);
	������ά operator *(������ά& ����);
	������ά operator /(������ά& ����);
	������ά operator +(float& ����);
	������ά operator -(float& ����);
	������ά operator *(float& ����);
	������ά operator /(float& ����);
	bool operator ==(������ά& ����);
	bool operator !=(������ά& ����);

public:
	static ������ά �������ֵ(������ά ����);
	static ������ά Barycentric(������ά ����1, ������ά ����2, ������ά ����3, float Ȩ��1, float Ȩ��2);
	static ������ά ��Χ����(������ά ����, ������ά ��Сֵ, ������ά ���ֵ);
	static float ������(������ά ����1, ������ά ����2);
	static float ������(������ά ����1, ������ά ����2);
	static float �������(������ά ����1, ������ά ����2);
	static float �������ƽ��(������ά ����1, ������ά ����2);
	static ������ά ���㵥λ����(������ά ����);
	static ������ά ���㷴������(������ά ��������, ������ά ����);
	static ������ά �������Բ�ֵ(������ά ��ʼ����, ������ά ��������, float �ٷֱ�);
	static ������ά �������β�ֵ(������ά ��ʼ����, ������ά ��������, float �ٷֱ�);
	static ������ά ����Hermite��ֵ(������ά ����1, ������ά ����1, ������ά ����2, ������ά ����2, float �ٷֱ�);
	static ������ά ����CatmullRom��ֵ(������ά ����1, ������ά ����2, ������ά ����3, ������ά ����4, float �ٷֱ�);
	static float ����н�(������ά ����A, ������ά ����B);
	static float ����˳ʱ����ת�Ƕ�(������ά ����1, ������ά ����2);

};

