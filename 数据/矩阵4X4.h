#pragma once
#include "������ά.h"
#include "������ά.h"

class ����4X4
{
public:
	float M11, M12, M13, M14;
	float M21, M22, M23, M24;
	float M31, M32, M33, M34;
	float M41, M42, M43, M44;

	����4X4();
	����4X4(float z);
	����4X4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44);
	����4X4(std::vector<float> z);
	//float& operator[](int index);
	static ����4X4 ��();
	static ����4X4 ��λ����();

	static ����4X4 ������(����4X4 ��, ����4X4 ��);

	����4X4 operator -();
	����4X4 operator +(����4X4 ����);
	����4X4 operator -(����4X4 ����);
	����4X4 operator *(float ����);
	����4X4 operator *(����4X4 ����);
	������ά operator *(������ά ����);
	//���� ������ά * ����;
	static ������ά ����ƽ��(������ά ����, ����4X4 ����);

public:
	static ������ά ��1(����4X4 jz);
	static ������ά ��2(����4X4 ����);
	static ������ά ��3(����4X4 ����);
	static ������ά ��4(����4X4 ����);
	static ������ά ��1(����4X4 ����);
	static ������ά ��2(����4X4 ����);
	static ������ά ��3(����4X4 ����);
	static ������ά ��4(����4X4 ����);
	static void ��һ(������ά ����, ����4X4& Ŀ��);
	static void �ж�(������ά ����, ����4X4& Ŀ��);
	static void ����(������ά ����, ����4X4& Ŀ��);
	static void ����(������ά ����, ����4X4& Ŀ��);
	static void ��һ(������ά ����, ����4X4& Ŀ��);
	static void �ж�(������ά ����, ����4X4& Ŀ��);
	static void ����(������ά ����, ����4X4& Ŀ��);
	static void ����(������ά ����, ����4X4& Ŀ��);

	static ������ά ƽ��(����4X4 ����);
	static ������ά ����(����4X4 ����);

public:
	static float ��������ʽ(����4X4 ����);
	static ����4X4 ������(����4X4 ��, int ָ��);
	static ����4X4 �������Բ�ֵ(����4X4 ����A, ����4X4 ����B, float �ٷֱ�);
	static ����4X4 ���β�ֵ(����4X4 ����A, ����4X4 ����B, float �ٷֱ�);
	static ����4X4 ����ת�þ���(����4X4 ����);
	static ����4X4 ���������(����4X4 ����);
	static ����4X4 ������������(����4X4 ����);
	static ����4X4 ����������һ������(����4X4 ����);
	static ����4X4 ����Ŀ�����(������ά ���������, ������ά Ŀ������, ������ά �Ϸ�������, ������ά ǰ��������);
	static ����4X4 ������ͼ����(������ά ���������, ������ά Ŀ������, ������ά �Ϸ�������);
	static ����4X4 ��������ͶӰ����(float ����, float ��߱�, float �����޼�, float Զ���޼�);
	static ����4X4 ��������ͶӰ����_�ߴ�(float ���, float �߶�, float �����޼�, float Զ���޼�);
	static ����4X4 �����Զ���͸��ͶӰ����(float ��, float ��, float ��, float ��, float �����޼�, float Զ���޼�);
	static ����4X4 ����͸��ͶӰ����(float ���, float �߶�, float �����޼�, float Զ���޼�);
	static ����4X4 ������Ұ͸��ͶӰ����(float ��׶�Ƕ�, float ��߱�, float �����޼�, float Զ���޼�);
	static ����4X4 �������ž���(������ά ����);
	static ����4X4 �������ž���(float x, float y, float z);
	static ����4X4 �������ž���(float ����);
	static ����4X4 ������ת����X(float ����);
	static ����4X4 ������ת����Y(float ����);
	static ����4X4 ������ת����Z(float ����);
	static ����4X4 ������ת����(������ά ��ת��, float ����);
	static ������ά ��ȡŷ����ת(����4X4 ��ת����);
	static ����4X4 �������߾���(����4X4 �������);
	static ����4X4 ����������ת����(������ά ����1, ������ά ����2);
	static ����4X4 ����ƽ�ƾ���(������ά ƽ��);
	static ����4X4 ����ƽ�ƾ���(float x, float y, float z);
	static ����4X4 �����任����2D(float ����, float ��ת, ������ά ƽ��);
	static ����4X4 ��������任����2D(float ����, ������ά ��ת����, float ��ת, ������ά ƽ��);
	static ����4X4 ��������任����2D(������ά ��������, float ������ת, ������ά ����, ������ά ��ת����, float ��ת, ������ά ƽ��);

};

