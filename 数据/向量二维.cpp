#include "������ά.h"



������ά::������ά()
{
	X = 0, Y = 0;
}

������ά::������ά(float ����)
{
	X = ����, Y = ����;
}

������ά::������ά(float x, float y)
{
	X = x, Y = y;
}

float ������ά::ģ()
{
	return std::sqrt(X * X + Y * Y);
}

float ������ά::ģƽ��()
{
	return X * X, Y* Y;
}

void ������ά::ת��λ����()
{
	float num = ģ();
	if (!����::����0(num))
	{
		float num2 = 1.0f / num;
		X *= num2;
		Y *= num2;
	}
}

std::vector<float> ������ά::ת����()
{
	return std::vector<float>(X, Y);
}

������ά ������ά::operator-()
{
	return ������ά(-X, -Y);
}

������ά ������ά::operator+(������ά& ����)
{
	������ά data(X, Y);
	return ������ά(data.X + ����.X, data.Y + ����.Y);
}

������ά ������ά::operator-(������ά& ����)
{
	������ά data(X, Y);
	return ������ά(data.X - ����.X, data.Y - ����.Y);
}

������ά ������ά::operator*(������ά& ����)
{
	������ά data(X, Y);
	return ������ά(data.X * ����.X, data.Y * ����.Y);
}

������ά ������ά::operator/(������ά& ����)
{
	������ά data(X, Y);
	return ������ά(data.X / ����.X, data.Y / ����.Y);
}

������ά ������ά::operator+(float& ����)
{
	������ά data(X, Y);
	return ������ά(data.X + ����, data.Y + ����);
}

������ά ������ά::operator-(float& ����)
{
	������ά data(X, Y);
	return ������ά(data.X - ����, data.Y - ����);
}

������ά ������ά::operator*(float& ����)
{
	������ά data(X, Y);
	return ������ά(data.X * ����, data.Y * ����);
}

������ά ������ά::operator/(float& ����)
{
	������ά data(X, Y);
	return ������ά(data.X / ����, data.Y / ����);
}

bool ������ά::operator==(������ά& ����)
{
	������ά data(X, Y);
	return data.X == ����.X && data.Y == ����.Y;
}

bool ������ά::operator!=(������ά& ����)
{
	������ά data(X, Y);
	return data.X != ����.X || data.Y != ����.Y;
}

������ά ������ά::�������ֵ(������ά ����)
{
	return ������ά((����.X > 0.0f) ? ����.X : (0.0f - ����.X), (����.Y > 0.0f) ? ����.Y : (0.0f - ����.Y));;
}

������ά ������ά::Barycentric(������ά ����1, ������ά ����2, ������ά ����3, float Ȩ��1, float Ȩ��2)
{
	return ������ά(����1.X + Ȩ��1 * (����2.X - ����1.X) + Ȩ��2 * (����3.X - ����1.X), ����1.Y + Ȩ��1 * (����2.Y - ����1.Y) + Ȩ��2 * (����3.Y - ����1.Y));
}

������ά ������ά::��Χ����(������ά ����, ������ά ��Сֵ, ������ά ���ֵ)
{
	float x = ����.X;
	x = ((x > ���ֵ.X) ? ���ֵ.X : x);
	x = ((x < ��Сֵ.X) ? ��Сֵ.X : x);
	float y = ����.Y;
	y = ((y > ���ֵ.Y) ? ���ֵ.Y : y);
	y = ((y < ��Сֵ.Y) ? ��Сֵ.Y : y);
	return ������ά(x, y);
}

float ������ά::������(������ά ����1, ������ά ����2)
{
	return ����1.X * ����2.Y - ����1.Y * ����2.X;
}

float ������ά::������(������ά ����1, ������ά ����2)
{
	return ����1.X * ����2.X + ����1.Y * ����2.Y;
}

float ������ά::�������(������ά ����1, ������ά ����2)
{
	float num = ����1.X - ����2.X;
	float num2 = ����1.Y - ����2.Y;
	return std::sqrt(num * num + num2 * num2);
}

float ������ά::�������ƽ��(������ά ����1, ������ά ����2)
{
	float num = ����1.X - ����2.X;
	float num2 = ����1.Y - ����2.Y;
	return num * num + num2 * num2;
}

������ά ������ά::���㵥λ����(������ά ����)
{
	����.ת��λ����();
	return ����;
}

������ά ������ά::���㷴������(������ά ��������, ������ά ����)
{
	������ά ��������;
	float num = ��������.X * ����.X + ��������.Y * ����.Y;
	��������.X = ��������.X - 2.0f * num * ����.X;
	��������.Y = ��������.Y - 2.0f * num * ����.Y;
	return ��������;
}

������ά ������ά::�������Բ�ֵ(������ά ��ʼ����, ������ά ��������, float �ٷֱ�)
{
	������ά ���Բ�ֵ;
	���Բ�ֵ.X = ����::��Χ����(��ʼ����.X, ��������.X, �ٷֱ�);
	���Բ�ֵ.Y = ����::��Χ����(��ʼ����.Y, ��������.Y, �ٷֱ�);
	return ���Բ�ֵ;
}

������ά ������ά::�������β�ֵ(������ά ��ʼ����, ������ά ��������, float �ٷֱ�)
{
	�ٷֱ� = ����::��������(�ٷֱ�);
	return �������Բ�ֵ(��ʼ����, ��������, �ٷֱ�);
}

������ά ������ά::����Hermite��ֵ(������ά ����1, ������ά ����1, ������ά ����2, ������ά ����2, float �ٷֱ�)
{
	������ά Hermite��ֵ;
	float num = �ٷֱ� * �ٷֱ�;
	float num2 = �ٷֱ� * num;
	float num3 = 2.0f * num2 - 3.0f * num + 1.0f;
	float num4 = -2.0f * num2 + 3.0f * num;
	float num5 = num2 - 2.0f * num + �ٷֱ�;
	float num6 = num2 - num;
	Hermite��ֵ.X = ����1.X * num3 + ����2.X * num4 + ����1.X * num5 + ����2.X * num6;
	Hermite��ֵ.Y = ����1.Y * num3 + ����2.Y * num4 + ����1.Y * num5 + ����2.Y * num6;
	return Hermite��ֵ;
}

������ά ������ά::����CatmullRom��ֵ(������ά ����1, ������ά ����2, ������ά ����3, ������ά ����4, float �ٷֱ�)
{
	������ά CatmullRom��ֵ;
	float num = �ٷֱ� * �ٷֱ�;
	float num2 = �ٷֱ� * num;
	CatmullRom��ֵ.X = 0.5f * (2.0f * ����2.X + (0.0f - ����1.X + ����3.X) * �ٷֱ� + (2.0f * ����1.X - 5.0f * ����2.X + 4.0f * ����3.X - ����4.X) * num + (0.0f - ����1.X + 3.0f * ����2.X - 3.0f * ����3.X + ����4.X) * num2);
	CatmullRom��ֵ.Y = 0.5f * (2.0f * ����2.Y + (0.0f - ����1.Y + ����3.Y) * �ٷֱ� + (2.0f * ����1.Y - 5.0f * ����2.Y + 4.0f * ����3.Y - ����4.Y) * num + (0.0f - ����1.Y + 3.0f * ����2.Y - 3.0f * ����3.Y + ����4.Y) * num2);
	return CatmullRom��ֵ;
}

float ������ά::����н�(������ά ����A, ������ά ����B)
{
	float dotProduct = ������ά::������(����A, ����B);
	float magnitudeProduct = ����A.ģ() * ����B.ģ();

	float angle = std::acos(dotProduct / magnitudeProduct);
	//float angleInDegrees = MathHelper.ToDegrees(angle);

	// �ж�������
	float crossProduct = ����A.X * ����B.Y - ����A.Y * ����B.X;
	if (crossProduct < 0)
	{
		angle = -angle;
	}

	if (isnan(angle))
	{
		return 0;
	}

	//return angleInDegrees;
	//float dot = ����A.X * ����B.X + ����A.Y * ����B.Y;
	//float det = ����A.X * ����B.Y - ����A.Y * ����B.X;
	//float angle = MathF.Atan2(det, dot);
	//float crossProduct = (����A.X * ����B.Y) - (����A.Y * ����B.X);
	//if (crossProduct < 0)
	//    angle = -angle;
	return angle;
}

float ������ά::����˳ʱ����ת�Ƕ�(������ά ����1, ������ά ����2)
{
	float PI = 3.1415926;
	float dotProduct = ������ά::������(����2, ����1);
	float magnitudeProduct = ����2.ģ() * ����1.ģ();
	float angle = std::acos(dotProduct / magnitudeProduct);
	float Բ�� = PI + PI;
	// �ж�������
	float crossProduct = ����2.X * ����1.Y - ����2.Y * ����1.X;
	if (crossProduct < 0)
		angle = -angle + Բ��;

	if (isnan(angle))
		return 0;

	return angle;
}




