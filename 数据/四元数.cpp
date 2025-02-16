#include "��Ԫ��.h"

��Ԫ��::��Ԫ��()
{
	X = Y = Z = W = 0;
}

��Ԫ��::��Ԫ��(float ֵ)
{
	X = Y = Z = W = ֵ;
}

��Ԫ��::��Ԫ��(������ά value, float w)
{
	X = value.X;
	Y = value.Y;
	Z = value.Z;
	W = w;
}

��Ԫ��::��Ԫ��(������ά value, float z, float w)
{
	X = value.X;
	Y = value.Y;
	Z = z;
	W = w;
}

��Ԫ��::��Ԫ��(float x, float y, float z, float w)
{
	X = x;
	Y = y;
	Z = z;
	W = w;
}

��Ԫ��::��Ԫ��(std::vector<float> values)
{
	if (values.size() != 4)
	{

	}

	X = values[0];
	Y = values[1];
	Z = values[2];
	W = values[3];
}

��Ԫ�� ��Ԫ��::��()
{
	return ��Ԫ��(0);
}

��Ԫ�� ��Ԫ��::Ҽ()
{
	return ��Ԫ��(1);
}

��Ԫ�� ��Ԫ��::��λ��Ԫ��()
{
	return ��Ԫ��(0, 0, 0, 1);
}

float ��Ԫ��::��ת�Ƕ�(��Ԫ�� ֵ)
{
	if (����::����0(ֵ.X * ֵ.X + ֵ.Y * ֵ.Y + ֵ.Z * ֵ.Z))
	{
		return 0.0f;
	}

	return 2.0f * std::acos(����::��Χ����(W, -1.0f, 1.0f));
}

������ά ��Ԫ��::��ת��(��Ԫ�� ֵ)
{
	float num = ֵ.X * ֵ.X + ֵ.Y * ֵ.Y + ֵ.Z * ֵ.Z;
	if (����::����0(num))
	{
		return ������ά::X��();
	}

	float num2 = 1.0f / std::sqrt(num);
	return  ������ά(X * num2, Y * num2, Z * num2);
}

float ��Ԫ��::����ģ(��Ԫ�� ��Ԫ��)
{
	return std::sqrt(��Ԫ��.X * ��Ԫ��.X + ��Ԫ��.Y * ��Ԫ��.Y + ��Ԫ��.Z * ��Ԫ��.Z + ��Ԫ��.W * ��Ԫ��.W);
}

float ��Ԫ��::����ģƽ��(��Ԫ�� ��Ԫ��)
{
	return ��Ԫ��.X * ��Ԫ��.X + ��Ԫ��.Y * ��Ԫ��.Y + ��Ԫ��.Z * ��Ԫ��.Z + ��Ԫ��.W * ��Ԫ��.W;
}

��Ԫ�� ��Ԫ��::������(��Ԫ�� ��, ��Ԫ�� ��)
{
	��Ԫ�� ��Ԫ��;
	float x = ��.X;
	float y = ��.Y;
	float z = ��.Z;
	float w = ��.W;
	float x2 = ��.X;
	float y2 = ��.Y;
	float z2 = ��.Z;
	float w2 = ��.W;
	float num = y * z2 - z * y2;
	float num2 = z * x2 - x * z2;
	float num3 = x * y2 - y * x2;
	float num4 = x * x2 + y * y2 + z * z2;
	��Ԫ��.X = x * w2 + x2 * w + num;
	��Ԫ��.Y = y * w2 + y2 * w + num2;
	��Ԫ��.Z = z * w2 + z2 * w + num3;
	��Ԫ��.W = w * w2 - num4;
	return ��Ԫ��;
}

��Ԫ�� ��Ԫ��::���㵥λ��Ԫ��(��Ԫ�� ��Ԫ��ֵ)
{
	��Ԫ�� ��λ��Ԫ��;
	float num = ����ģ(��Ԫ��ֵ);
	if (!����::����0(num))
	{
		float num2 = 1.0f / num;
		��λ��Ԫ��.X = ��Ԫ��ֵ.X * num2;
		��λ��Ԫ��.Y = ��Ԫ��ֵ.Y * num2;
		��λ��Ԫ��.Z = ��Ԫ��ֵ.Z * num2;
		��λ��Ԫ��.W = ��Ԫ��ֵ.W * num2;
	}
	return ��λ��Ԫ��;
}

��Ԫ�� ��Ԫ��::operator-()
{
	return ��Ԫ��(-X,-Y,-Z,-W);
}

��Ԫ�� ��Ԫ��::operator+(��Ԫ�� ֵ)
{
	��Ԫ�� ����(X, Y, Z, W);
	return ��Ԫ��(����.X + ֵ.X, ����.Y + ֵ.Y, ����.Z + ֵ.Z, ����.W + ֵ.W);
}

��Ԫ�� ��Ԫ��::operator-(��Ԫ�� ֵ)
{
	��Ԫ�� ����(X, Y, Z, W);
	return ��Ԫ��(����.X - ֵ.X, ����.Y - ֵ.Y, ����.Z - ֵ.Z, ����.W - ֵ.W);
}

��Ԫ�� ��Ԫ��::operator*(��Ԫ�� ֵ)
{
	return ������(��Ԫ��(X, Y, Z, W), ֵ);
}

��Ԫ�� ��Ԫ��::operator*(float ֵ)
{
	��Ԫ�� ����(X, Y, Z, W);
	return ��Ԫ��(����.X * ֵ, ����.Y * ֵ, ����.Z * ֵ, ����.W * ֵ);
}

������ά ��Ԫ��::operator*(������ά ����)
{
	float num = X + X;
	float num2 = Y + Y;
	float num3 = Z + Z;
	float num4 = W * num;
	float num5 = W * num2;
	float num6 = W * num3;
	float num7 = X * num;
	float num8 = X * num2;
	float num9 = X * num3;
	float num10 = Y * num2;
	float num11 = Y * num3;
	float num12 = Z * num3;
	float x = ����.X * (1.0f - num10 - num12) + ����.Y * (num8 - num6) + ����.Z * (num9 + num5);
	float y = ����.X * (num8 + num6) + ����.Y * (1.0f - num7 - num12) + ����.Z * (num11 - num4);
	float z = ����.X * (num9 - num5) + ����.Y * (num11 + num4) + ����.Z * (1.0f - num7 - num10);
	������ά result = ������ά(x, y, z);
	return result;
}

//float& ��Ԫ��::operator[](int index)
//{
//	switch (index) {
//	case 0:
//		return X;
//	case 1:
//		return Y;
//	case 2:
//		return Z;
//	case 3:
//		return W;
//	default:
//		//throw std::invalid_argument("��������");
//	}// TODO: �ڴ˴����� return ���
//}

int ��Ԫ��::ȷ�����ַ���(float zhi)
{
	if (zhi > 0)
	{
		return 1;
	}
	else if (zhi < 0)
	{
		return -1;
	}
	else
	{
		return 0;
	}
	
}

��Ԫ�� ��Ԫ��::������Ȼ����(��Ԫ�� ��Ԫ��ֵ)
{
	��Ԫ�� ��Ȼ����;
	if ((double)std::abs(��Ԫ��ֵ.W) < 1.0)
	{
		float num = std::acos(��Ԫ��ֵ.W);
		float num2 = std::sin(num);
		if (!����::����0(num2))
		{
			float num3 = num / num2;
			��Ȼ����.X = ��Ԫ��ֵ.X * num3;
			��Ȼ����.Y = ��Ԫ��ֵ.Y * num3;
			��Ȼ����.Z = ��Ԫ��ֵ.Z * num3;
		}
		else
		{
			��Ȼ���� = ��Ԫ��ֵ;
		}
	}
	else
	{
		��Ȼ���� = ��Ԫ��ֵ;
	}

	��Ȼ����.W = 0.0f;
	return ��Ԫ��ֵ;
}


������ά ��Ԫ��::��Ԫ������ά����(������ά ����, ��Ԫ�� ��Ԫ��)
{
	float num = ��Ԫ��.X + ��Ԫ��.X;
	float num2 = ��Ԫ��.Y + ��Ԫ��.Y;
	float num3 = ��Ԫ��.Z + ��Ԫ��.Z;
	float num4 = ��Ԫ��.W * num;
	float num5 = ��Ԫ��.W * num2;
	float num6 = ��Ԫ��.W * num3;
	float num7 = ��Ԫ��.X * num;
	float num8 = ��Ԫ��.X * num2;
	float num9 = ��Ԫ��.X * num3;
	float num10 = ��Ԫ��.Y * num2;
	float num11 = ��Ԫ��.Y * num3;
	float num12 = ��Ԫ��.Z * num3;
	float x = ����.X * (1.0f - num10 - num12) + ����.Y * (num8 - num6) + ����.Z * (num9 + num5);
	float y = ����.X * (num8 + num6) + ����.Y * (1.0f - num7 - num12) + ����.Z * (num11 - num4);
	float z = ����.X * (num9 - num5) + ����.Y * (num11 + num4) + ����.Z * (1.0f - num7 - num10);
	������ά result = ������ά(x, y, z);
	return result;
}



//������Ԫ���ĵ�˽��Խ�ӽ�1����ʾ���ǵķ�����ӽӽ�����룻�����Խ�ӽ�-1����ʾ���ǵķ����෴�����Ϊ0��ʾ���Ǵ�ֱ������
float ��Ԫ��::������(��Ԫ�� ��, ��Ԫ�� ��)
{
	return ��.X * ��.X + ��.Y * ��.Y + ��.Z * ��.Z + ��.W * ��.W;
}

//ģ��Ϊ1����Ԫ�����乲��������棬��������������������Ԫ�����桢��ת�����ת�õ�
��Ԫ�� ��Ԫ��::���㹲��(��Ԫ�� ֵ)
{
	��Ԫ�� ������Ԫ��;
	������Ԫ��.X = 0.0f - ֵ.X;
	������Ԫ��.Y = 0.0f - ֵ.Y;
	������Ԫ��.Z = 0.0f - ֵ.Z;
	������Ԫ��.W = ֵ.W;
	return ������Ԫ��;
}

��Ԫ�� ��Ԫ��::����ָ������(��Ԫ�� ��Ԫ��ֵ)
{
	��Ԫ�� ָ������;
	float num = std::sqrt(��Ԫ��ֵ.X * ��Ԫ��ֵ.X + ��Ԫ��ֵ.Y * ��Ԫ��ֵ.Y + ��Ԫ��ֵ.Z * ��Ԫ��ֵ.Z);
	float num2 = std::sin(num);
	if (!����::����0(num2))
	{
		float num3 = num2 / num;
		ָ������.X = num3 * ��Ԫ��ֵ.X;
		ָ������.Y = num3 * ��Ԫ��ֵ.Y;
		ָ������.Z = num3 * ��Ԫ��ֵ.Z;
		return ָ������;
	}
	else
	{
		ָ������ = ��Ԫ��ֵ;
		return ָ������;
	}

	ָ������.W = std::cos(num);
	return ָ������;
}

��Ԫ�� ��Ԫ��::������(��Ԫ�� ��Ԫ��ֵ)
{
	��Ԫ�� ��Ԫ����;
	float lengthSquared = ����ģƽ��(��Ԫ��ֵ);
	if (lengthSquared == 0)
	{
		//std::cout << "�޷������㳤����Ԫ�����档"<<std::endl;
	}
	float inverseLengthSquared = 1 / lengthSquared;
	return ��Ԫ���� = ��Ԫ��(
		��Ԫ��ֵ.X * -inverseLengthSquared,
		��Ԫ��ֵ.Y * -inverseLengthSquared,
		��Ԫ��ֵ.Z * -inverseLengthSquared,
		��Ԫ��ֵ.W * inverseLengthSquared);
}

��Ԫ�� ��Ԫ��::���Բ�ֵ(��Ԫ�� ��Ԫ��1, ��Ԫ�� ��Ԫ��2, float �ٷֱ�)
{
	��Ԫ�� ��Ԫ��ֵ;
	float num = 1.0f - �ٷֱ�;
	if (������(��Ԫ��1, ��Ԫ��2) >= 0.0f)
	{
		��Ԫ��ֵ.X = num * ��Ԫ��1.X + �ٷֱ� * ��Ԫ��2.X;
		��Ԫ��ֵ.Y = num * ��Ԫ��1.Y + �ٷֱ� * ��Ԫ��2.Y;
		��Ԫ��ֵ.Z = num * ��Ԫ��1.Z + �ٷֱ� * ��Ԫ��2.Z;
		��Ԫ��ֵ.W = num * ��Ԫ��1.W + �ٷֱ� * ��Ԫ��2.W;
	}
	else
	{
		��Ԫ��ֵ.X = num * ��Ԫ��1.X - �ٷֱ� * ��Ԫ��2.X;
		��Ԫ��ֵ.Y = num * ��Ԫ��1.Y - �ٷֱ� * ��Ԫ��2.Y;
		��Ԫ��ֵ.Z = num * ��Ԫ��1.Z - �ٷֱ� * ��Ԫ��2.Z;
		��Ԫ��ֵ.W = num * ��Ԫ��1.W - �ٷֱ� * ��Ԫ��2.W;
	}
	return ��Ԫ��ֵ = ���㵥λ��Ԫ��(��Ԫ��ֵ);
}

��Ԫ�� ��Ԫ��::�����������Բ�ֵ(��Ԫ�� ��Ԫ��1, ��Ԫ�� ��Ԫ��2, float �ٷֱ�)
{
	��Ԫ�� ��Ԫ��ֵ;
	float value = ������(��Ԫ��1, ��Ԫ��2);
	float num;
	float num2;
	if (std::abs(value) > 0.999999f)
	{
		num = 1.0f - �ٷֱ�;
		num2 = �ٷֱ� * ȷ�����ַ���(value);
	}
	else
	{
		float num3 = std::acos(std::abs(value));
		float num4 = 1.0f /std::sin(num3);
		num = std::sin((1.0f - �ٷֱ�) * num3) * num4;
		num2 = std::sin(�ٷֱ� * num3) * num4 * ȷ�����ַ���(value);
	}

	��Ԫ��ֵ.X = num * ��Ԫ��1.X + num2 * ��Ԫ��2.X;
	��Ԫ��ֵ.Y = num * ��Ԫ��1.Y + num2 * ��Ԫ��2.Y;
	��Ԫ��ֵ.Z = num * ��Ԫ��1.Z + num2 * ��Ԫ��2.Z;
	��Ԫ��ֵ.W = num * ��Ԫ��1.W + num2 * ��Ԫ��2.W;
	return ��Ԫ��ֵ;
}

��Ԫ�� ��Ԫ��::�����������Բ�ֵ(��Ԫ�� ��Ԫ��1, ��Ԫ�� ��Ԫ��2, ��Ԫ�� ��Ԫ��3, ��Ԫ�� ��Ԫ��4, float �ٷֱ�)
{
	��Ԫ�� result2, result3, ��Ԫ��ֵ;
	result2 = �����������Բ�ֵ(��Ԫ��1, ��Ԫ��4, �ٷֱ�);
	result3 = �����������Բ�ֵ(��Ԫ��2, ��Ԫ��3, �ٷֱ�);
	��Ԫ��ֵ = �����������Բ�ֵ(result2, result3, 2.0f * �ٷֱ� * (1.0f - �ٷֱ�));
	return ��Ԫ��ֵ;
}

��Ԫ�� ��Ԫ��::���������������Բ�ֵ(��Ԫ�� ��Ԫ��1, ��Ԫ�� ��Ԫ��2, ��Ԫ�� ��Ԫ��3, float �ٷֱ�1, float �ٷֱ�2)
{
	��Ԫ�� result2, result3, ��Ԫ��ֵ;
	result2 = �����������Բ�ֵ( ��Ԫ��1,  ��Ԫ��2, �ٷֱ�1 + �ٷֱ�2);
	result3 = �����������Բ�ֵ( ��Ԫ��1,  ��Ԫ��3, �ٷֱ�1 + �ٷֱ�2);
	��Ԫ��ֵ = �����������Բ�ֵ( result2,  result3, �ٷֱ�2 / (�ٷֱ�1 + �ٷֱ�2));
	return ��Ԫ��ֵ;
}

std::vector<��Ԫ��> ��Ԫ��::���������ı��β�ֵ(��Ԫ�� ��Ԫ��1, ��Ԫ�� ��Ԫ��2, ��Ԫ�� ��Ԫ��3, ��Ԫ�� ��Ԫ��4)
{
	��Ԫ�� result, result2, m1, m2;
	��Ԫ�� quaternion = ((����ģƽ��(��Ԫ��1 + ��Ԫ��2) < ����ģƽ��(��Ԫ��1 - ��Ԫ��2)) ? (-��Ԫ��1) : ��Ԫ��1);
	��Ԫ�� value5 = ((����ģƽ��(��Ԫ��2 + ��Ԫ��3) < ����ģƽ��(��Ԫ��2 - ��Ԫ��3)) ? (-��Ԫ��3) : ��Ԫ��3);
	��Ԫ�� quaternion2 = ((����ģƽ��(��Ԫ��3 + ��Ԫ��4) < ����ģƽ��(��Ԫ��3 - ��Ԫ��4)) ? (-��Ԫ��4) : ��Ԫ��4);
	��Ԫ�� value6 = ��Ԫ��2;
	result = ����ָ������(value6);
	result2 = ����ָ������(value5);
	m1 = value6* ����ָ������((������Ȼ����(result * value5) * -0.25f + ������Ȼ����(result * quaternion)));
	m2 = value5* ����ָ������((������Ȼ����(result2 * quaternion2) * -0.25f + ������Ȼ����(result2 * value6)));
	std::vector<��Ԫ��> ֵ(3);
	ֵ[0] = m1;
	ֵ[1] = m2;
	ֵ[2] = value5;
	return ֵ;
}

��Ԫ�� ��Ԫ��::���������ת(������ά ��ת��, float ����)
{
	��Ԫ�� ��Ԫ��ֵ;
	������ά result2;
	result2 = ������ά::���㵥λ����(��ת��);
	float num = ���� * 0.5f;
	float num2 = std::sin(num);
	float w = std::cos(num);
	��Ԫ��ֵ.X = result2.X * num2;
	��Ԫ��ֵ.Y = result2.Y * num2;
	��Ԫ��ֵ.Z = result2.Z * num2;
	��Ԫ��ֵ.W = w;
	return ��Ԫ��ֵ;
}

��Ԫ�� ��Ԫ��::����������ת(����4X4 ��ת����)
{
	��Ԫ�� ��Ԫ��ֵ;
	float num = ��ת����.M11 + ��ת����.M22 + ��ת����.M33;
	if (num > 0.0f)
	{
		float num2 = std::sqrt(num + 1.0f);
		��Ԫ��ֵ.W = num2 * 0.5f;
		num2 = 0.5f / num2;
		��Ԫ��ֵ.X = (��ת����.M23 - ��ת����.M32) * num2;
		��Ԫ��ֵ.Y = (��ת����.M31 - ��ת����.M13) * num2;
		��Ԫ��ֵ.Z = (��ת����.M12 - ��ת����.M21) * num2;
	}
	else if (��ת����.M11 >= ��ת����.M22 && ��ת����.M11 >= ��ת����.M33)
	{
		float num2 = std::sqrt(1.0f + ��ת����.M11 - ��ת����.M22 - ��ת����.M33);
		float num3 = 0.5f / num2;
		��Ԫ��ֵ.X = 0.5f * num2;
		��Ԫ��ֵ.Y = (��ת����.M12 + ��ת����.M21) * num3;
		��Ԫ��ֵ.Z = (��ת����.M13 + ��ת����.M31) * num3;
		��Ԫ��ֵ.W = (��ת����.M23 - ��ת����.M32) * num3;
	}
	else if (��ת����.M22 > ��ת����.M33)
	{
		float num2 = std::sqrt(1.0f + ��ת����.M22 - ��ת����.M11 - ��ת����.M33);
		float num3 = 0.5f / num2;
		��Ԫ��ֵ.X = (��ת����.M21 + ��ת����.M12) * num3;
		��Ԫ��ֵ.Y = 0.5f * num2;
		��Ԫ��ֵ.Z = (��ת����.M32 + ��ת����.M23) * num3;
		��Ԫ��ֵ.W = (��ת����.M31 - ��ת����.M13) * num3;
	}
	else
	{
		float num2 = std::sqrt(1.0f + ��ת����.M33 - ��ת����.M11 - ��ת����.M22);
		float num3 = 0.5f / num2;
		��Ԫ��ֵ.X = (��ת����.M31 + ��ת����.M13) * num3;
		��Ԫ��ֵ.Y = (��ת����.M32 + ��ת����.M23) * num3;
		��Ԫ��ֵ.Z = 0.5f * num2;
		��Ԫ��ֵ.W = (��ת����.M12 - ��ת����.M21) * num3;
	}
	return ��Ԫ��ֵ;
}

��Ԫ�� ��Ԫ��::����Ŀ����ת(������ά ���, ������ά Ŀ���, ������ά ��������, ������ά ǰ������)
{
	��Ԫ�� ��Ԫ��ֵ;
	����4X4 ��ͼ���� = ����4X4::����Ŀ�����(���, Ŀ���, ��������, ǰ������);
	��Ԫ��ֵ = ��Ԫ��::����������ת(��ͼ����);
	return ��Ԫ��ֵ;
}

��Ԫ�� ��Ԫ��::����Ŀ����ת(������ά ���, ������ά Ŀ���, ������ά ��������)
{
	��Ԫ�� ��Ԫ��ֵ;
	����4X4 ��ͼ���� = ����4X4::������ͼ����(���, Ŀ���, ��������);
	��Ԫ��ֵ = ��Ԫ��::����������ת(��ͼ����);
	return ��Ԫ��ֵ;
}

��Ԫ�� ��Ԫ��::����������ת(������ά ����1, ������ά ����2)
{
	float PI = 3.1415926;
	������ά vec1 = ������ά::���㵥λ����(����1);
	������ά vec2 = ������ά::���㵥λ����(����2);

	float dot = ������ά::������(vec1, vec2);
	��Ԫ�� lei;
	if (dot >= 1.0f)
	{
		// ����������ͬ�����ص�λ��ת
		return lei.��λ��Ԫ��();
	}
	else if (dot <= -1.0f)
	{
		// ���������෴���ҵ�һ��������������������ת180��
		������ά ��ת�� = ������ά::������(vec1, ������ά(1, 0, 0));
		if (��ת��.ģƽ��() < 0.01)
			��ת�� = ������ά::������(vec1,������ά(0, 1, 0));
		return ��Ԫ��::���������ת(������ά::���㵥λ����(��ת��), PI);
	}

	float rotAngle = std::acos(dot);
	������ά rotateAxis = ������ά::������(vec1, vec2);
	return ��Ԫ��::���������ת(������ά::���㵥λ����(rotateAxis), rotAngle);
}

��Ԫ�� ��Ԫ��::����ŷ������ת(float X��, float Y��, float Z��)
{
	float PI = 3.1415926;
	X�� *= PI / 180.0f;
	Y�� *= PI / 180.0f;
	Z�� *= PI / 180.0f;
	float cy = std::cos(Z�� * 0.5f);
	float sy = std::sin(Z�� * 0.5f);
	float cp = std::cos(Y�� * 0.5f);
	float sp = std::sin(Y�� * 0.5f);
	float cr = std::cos(X�� * 0.5f);
	float sr = std::sin(X�� * 0.5f);

	float x = cy * cp * sr - sy * sp * cr;
	float y = sy * cp * sr + cy * sp * cr;
	float z = sy * cp * cr - cy * sp * sr;
	float w = cy * cp * cr + sy * sp * sr;
	return ��Ԫ��(x, y, z, w);
}

��Ԫ�� ��Ԫ��::����ŷ������ת(������ά ŷ����ת)
{
	return ��Ԫ��(����ŷ������ת(ŷ����ת.X, ŷ����ת.Y, ŷ����ת.Z));
}

������ά ��Ԫ��::��Ԫ��תŷ����(��Ԫ�� ��Ԫ��)
{
	float PI = 3.1415926;
	float Y��;
	float Z��;
	float X��;

	float sinr_cosp = 2 * (��Ԫ��.W * ��Ԫ��.X + ��Ԫ��.Y * ��Ԫ��.Z);
	float cosr_cosp = 1 - 2 * (��Ԫ��.X * ��Ԫ��.X + ��Ԫ��.Y * ��Ԫ��.Y);
	X�� = std::atan2(sinr_cosp, cosr_cosp);

	float sinp = 2 * (��Ԫ��.W * ��Ԫ��.Y - ��Ԫ��.Z * ��Ԫ��.X);
	if (std::abs(sinp) >= 1)
	{
		Y�� = std::copysign(PI / 2, sinp);
	}
	else
	{
		Y�� = std::asin(sinp);
	}
	float siny_cosp = 2 * (��Ԫ��.W * ��Ԫ��.Z + ��Ԫ��.X * ��Ԫ��.Y);
	float cosy_cosp = 1 - 2 * (��Ԫ��.Y * ��Ԫ��.Y + ��Ԫ��.Z * ��Ԫ��.Z);
	Z�� = std::atan2(siny_cosp, cosy_cosp);
	return ������ά(X��, Y��, Z��);
}




