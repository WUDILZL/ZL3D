#include "���߽ṹ.h"

���߽ṹ::���߽ṹ()
{
}

���߽ṹ::���߽ṹ(������ά _����, ������ά ����)
{
	���� = _����;
	���� = ������ά::���㵥λ����(����);
}

���߽ṹ::~���߽ṹ()
{
}



bool ���߽ṹ::�����������ײ(���߽ṹ ����, ������ά ����1, ������ά ����2, ������ά ����3, float& ����)
{
    ������ά vector = ����2 - ����1;
    ������ά vector2 = ����3 - ����1;
    ������ά vector3 = ������ά();
    vector3.X = ����.����.Y * vector2.Z - ����.����.Z * vector2.Y;
    vector3.Y = ����.����.Z * vector2.X - ����.����.X * vector2.Z;
    vector3.Z = ����.����.X * vector2.Y - ����.����.Y * vector2.X;
    float num = vector.X * vector3.X + vector.Y * vector3.Y + vector.Z * vector3.Z;
    if (����::����0(num))
    {
        ���� = 0.0f;
        return false;
    }
    float num2 = 1.0f / num;
    ������ά vector4 = ������ά();
    vector4.X = ����.����.X - ����1.X;
    vector4.Y = ����.����.Y - ����1.Y;
    vector4.Z = ����.����.Z - ����1.Z;
    float num3 = vector4.X * vector3.X + vector4.Y * vector3.Y + vector4.Z * vector3.Z;
    num3 *= num2;
    if (num3 < 0.0f || num3 > 1.0f)
    {
        ���� = 0.0f;
        return false;
    }

    ������ά vector5 = ������ά();
    vector5.X = vector4.Y * vector.Z - vector4.Z * vector.Y;
    vector5.Y = vector4.Z * vector.X - vector4.X * vector.Z;
    vector5.Z = vector4.X * vector.Y - vector4.Y * vector.X;
    float num4 = ����.����.X * vector5.X + ����.����.Y * vector5.Y + ����.����.Z * vector5.Z;
    num4 *= num2;
    if (num4 < 0.0f || num3 + num4 > 1.0f)
    {
        ���� = 0.0f;
        return false;
    }

    float num5 = vector2.X * vector5.X + vector2.Y * vector5.Y + vector2.Z * vector5.Z;
    num5 *= num2;
    if (num5 < 0.0f)
    {
        ���� = 0.0f;
        return false;
    }

    ���� = num5;
    return true;
}

bool ���߽ṹ::�����������ײ(���߽ṹ ����, ������ά ����1, ������ά ����2, ������ά ����3, ������ά& ��ײ����)
{
    float ����;
    if (!�����������ײ(����, ����1, ����2, ����3,����))
    {
        ��ײ���� = ������ά(0);
        return false;
    }
    ��ײ���� = ����.���� + ����.���� * ����;
    return true;
}

bool ���߽ṹ::����Χ����ײ(���߽ṹ ����, ��Χ�� _��Χ��)
{
    float ����;
    return ����Χ����ײ(����, _��Χ��, ����);
}

bool ���߽ṹ::����Χ����ײ(���߽ṹ ����, ��Χ�� _��Χ��, float& ����)
{
    ���� = 0.0f;
    float num = FLT_MAX;
    if (����::����0(����.����.X))
    {
        if (����.����.X < _��Χ��.��Сֵ.X || ����.����.X > _��Χ��.���ֵ.X)
        {
            ���� = 0.0f;
            return false;
        }
    }
    else
    {
        float num2 = 1.0f / ����.����.X;
        float num3 = (_��Χ��.��Сֵ.X - ����.����.X) * num2;
        float num4 = (_��Χ��.���ֵ.X - ����.����.X) * num2;
        if (num3 > num4)
        {
            float num5 = num3;
            num3 = num4;
            num4 = num5;
        }

        ���� = std::max(num3, ����);
        num = std::min(num4, num);
        if (���� > num)
        {
            ���� = 0.0f;
            return false;
        }
    }

    if (����::����0(����.����.Y))
    {
        if (����.����.Y < _��Χ��.��Сֵ.Y || ����.����.Y > _��Χ��.���ֵ.Y)
        {
            ���� = 0.0f;
            return false;
        }
    }
    else
    {
        float num6 = 1.0f / ����.����.Y;
        float num7 = (_��Χ��.��Сֵ.Y - ����.����.Y) * num6;
        float num8 = (_��Χ��.���ֵ.Y - ����.����.Y) * num6;
        if (num7 > num8)
        {
            float num9 = num7;
            num7 = num8;
            num8 = num9;
        }

        ���� = std::max(num7, ����);
        num = std::min(num8, num);
        if (���� > num)
        {
            ���� = 0.0f;
            return false;
        }
    }

    if (����::����0(����.����.Z))
    {
        if (����.����.Z < _��Χ��.��Сֵ.Z || ����.����.Z > _��Χ��.���ֵ.Z)
        {
            ���� = 0.0f;
            return false;
        }
    }
    else
    {
        float num10 = 1.0f / ����.����.Z;
        float num11 = (_��Χ��.��Сֵ.Z - ����.����.Z) * num10;
        float num12 = (_��Χ��.���ֵ.Z - ����.����.Z) * num10;
        if (num11 > num12)
        {
            float num13 = num11;
            num11 = num12;
            num12 = num13;
        }

        ���� = std::max(num11, ����);
        num = std::min(num12, num);
        if (���� > num)
        {
            ���� = 0.0f;
            return false;
        }

    }
    return true;
}

bool ���߽ṹ::����Χ����ײ(���߽ṹ ����, ��Χ�� _��Χ��, ������ά& ��ײ����)
{
    float ����;
    if (!����Χ����ײ(����, _��Χ��,����))
    {
        ��ײ���� = ������ά(0);
        return false;
    }
    ��ײ���� = ����.���� + ����.���� * ����;
    return true;
}

bool ���߽ṹ::���ƽ����ײ(���߽ṹ ����, ������ά ������, ������ά �淨��, float& ����, ������ά& ��ײ��)
{

    float denominator = ������ά::������(�淨��, ����.����);
    if (std::abs(denominator) > 1e-6f)
    {
        ���� = ������ά::������(������ - ����.����, �淨��) / denominator;
        ��ײ�� = ����.���� + ����.���� * ����;
        if (���� >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    ���� = 0;
    ��ײ�� = 0;
    return false;
}

bool ���߽ṹ::�������ײ(���߽ṹ ����, ������ά ����, float �뾶)
{
    // �����������֮�������
    ������ά rayToPoint = ���� - ����.����;

    // �������߷��������ߵ���������ĵ��
    float projection = ������ά::������(rayToPoint, ����.����);

    // ���ͶӰֵС��0��˵���������ߵĸ������ϣ����ص㵽�������ľ���
    if (projection < 0)
    {
        return false;
    }

    // �������ߵ�������������߷���Ĳ��������������ƽ���ڵ�ͶӰ
    ������ά cross = ������ά::������(rayToPoint, ����.����);

    // �����ͶӰ��ģ�����Ǿ���
    float distance = cross.ģ();


    return distance <= �뾶;
}

float ���߽ṹ::�����������߶ξ���(���߽ṹ ����, ������ά ���, ������ά �յ�)
{
    // ��֤���������Ѿ����淶��
    ����.���� = ������ά::���㵥λ����(����.����);
    ������ά edgeVec = �յ� - ���;
    edgeVec = ������ά::���㵥λ����(edgeVec);
    ������ά edgeDir = edgeVec;

    // �������߷���ͱ߷���Ĳ��
    ������ά crossVec = ������ά::������(����.����, edgeDir);

    // ������߷���ͱ߷����Ƿ�ƽ��
    if (crossVec.ģ() < 1e-8f)
    {
        // ���ߺͱ�ƽ��ʱ����������㵽�ߵ�ֱ�߶ε���̾���
        ������ά rayToEdgeStart = ��� - ����.����;
        ������ά projectedPoint = ����.���� + ����.���� * ������ά::������(rayToEdgeStart, ����.����);
        ������ά closestPoint = ��� + edgeDir * ������ά::������(projectedPoint - ���, edgeDir);

        if ((closestPoint - ���).ģƽ��() > edgeVec.ģƽ��() ||
            (closestPoint - �յ�).ģƽ��() > edgeVec.ģƽ��())
        {
            // ���������ĵ㲻�ڱ��ϣ�����������㵽����˵�ľ���
            float distToStart = (����.���� - ���).ģ();
            float distToEnd = (����.���� - �յ�).ģ();
            return std::min(distToStart, distToEnd);
        }

        return (projectedPoint - closestPoint).ģ();
    }

    // ����������㵽�ߵ�һ���˵������
    ������ά vecBetween = ����.���� - ���;

    // ��������������ߺͱ߷����������ĵ�����Ӷ�ȷ�����ߺͱߵľ���
    float distance = ������ά::������(vecBetween, crossVec) / crossVec.ģ();

    return std::abs(distance);
}

float ���߽ṹ::�����������������(���߽ṹ ����, ������ά ��)
{
    // �����������֮�������
    ������ά rayToPoint = �� - ����.����;

    // �������߷��������ߵ���������ĵ��
    float projection = ������ά::������(rayToPoint, ����.����);

    // ���ͶӰֵС��0��˵���������ߵĸ������ϣ����ص㵽�������ľ���
    if (projection < 0)
    {
        return -1;
    }

    // �������ߵ�������������߷���Ĳ��������������ƽ���ڵ�ͶӰ
    ������ά cross = ������ά::������(rayToPoint, ����.����);

    // �����ͶӰ��ģ�����Ǿ���
    float distance = cross.ģ();


    return distance;
}

���߽ṹ ���߽ṹ::��������(������ά ����1, ������ά ����2)
{
    ������ά ���� = ������ά::���㵥λ����(����2 - ����1);
    return ���߽ṹ(����1, ����);
}

���߽ṹ ���߽ṹ::operator+(������ά _����)
{
    return  ���߽ṹ(���� + _����, ����);
}

���߽ṹ ���߽ṹ::operator-(������ά _����)
{
	return ���߽ṹ(���� - _����, ����);
}

���߽ṹ ���߽ṹ::operator*(��Ԫ�� _��Ԫ��)
{
    ������ά ����A = ����;
    ������ά ����B = ���� + ����;
    return ��������(_��Ԫ�� * ����A, _��Ԫ�� * ����B);
}

���߽ṹ ���߽ṹ::operator*(����4X4 �任����)
{
    ������ά ����A = ����;
    ������ά ����B = ���� + ����;
    return ��������(�任���� * ����A, �任���� * ����B);
}
