#include "����.h"



float ����::�Ƕ�ת����(float �Ƕ�)
{
	return �Ƕ� * (����PI / 180.0f);
}

float ����::����ת�Ƕ�(float ����)
{
	return ���� * (180.0f / ����PI);
}

float ����::��Χӳ��(float ����ֵ, float ��������, float ��������, float �������, float �������)
{
	float �ٷֱ� = (�������� - ����ֵ) / (�������� - ��������);
	float ���ֵ = ������� - ((������� - �������) * �ٷֱ�);
	return ���ֵ;
}

float ����::��Χ����(float ���, float �յ�, float �ٷֱ�)
{
	return ��� + ((�յ� - ���) * �ٷֱ�);
}

float ����::��Χ�ٷֱ�(float ֵ, float ���, float �յ�)
{
	if (��� == �յ�)
		return ���;

	return (ֵ - ���) / (�յ� - ���);
}

void ����::���·����С(float& Сֵ, float& ��ֵ)
{
	if (Сֵ > ��ֵ)
	{
		float ���� = ��ֵ;
		��ֵ = Сֵ;
		Сֵ = ����;
	}
}

float ����::��Χ����(float ����ֵ, float ����, float ����)
{
	if (����ֵ < ����)
		return ����;
	else if (����ֵ > ����)
		return ����;
	else
		return ����ֵ;
}

float ����::��������(float �ٷֱ�)
{
	return �ٷֱ� * �ٷֱ� * �ٷֱ� * (�ٷֱ� * (�ٷֱ� * 6 - 15) + 10);
}

float ����::��������(float �ٷֱ�, float ���, float �յ�)
{
	float �����ٷֱ� = ��������(�ٷֱ�);
	return ��Χ����(���, �յ�, �����ٷֱ�);
}

bool ����::����0(float ֵ)
{
	return std::abs(ֵ) < 1E-06f;
}

bool ����::����1(float ֵ)
{
	return ����0(ֵ - 1.0f);
}

bool ����::���(float x1, float x2)
{
	return ����0(std::abs(x1 - x2));
}

float ����::����()
{
	return ����PI / 180.0f;
}

float ����::�Ƕ�()
{
	return 180.0f / ����PI;
}

float ����::��1()
{
	return ����PI / 180.0f;
}

float ����::��45()
{
	return ����PI * 0.25;
}

float ����::��90()
{
	return ����PI * 0.5;
}

float ����::��135()
{
	return (����PI * 0.5f) + (����PI * 0.25f);
}

float ����::��180()
{
	return ����PI;
}

float ����::��225()
{
	return ����PI + (����PI + 0.25f);
}

float ����::��270()
{
	return ����PI * 1.5f;
}

float ����::��315()
{
	return (����PI * 1.5f) + (����PI * 0.25f);
}

float ����::��360()
{
	return ����PI * 2;
}
