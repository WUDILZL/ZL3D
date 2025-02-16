#include "射线结构.h"

射线结构::射线结构()
{
}

射线结构::射线结构(向量三维 _坐标, 向量三维 法线)
{
	坐标 = _坐标;
	方向 = 向量三维::计算单位向量(法线);
}

射线结构::~射线结构()
{
}



bool 射线结构::检查三角面碰撞(射线结构 射线, 向量三维 坐标1, 向量三维 坐标2, 向量三维 坐标3, float& 距离)
{
    向量三维 vector = 坐标2 - 坐标1;
    向量三维 vector2 = 坐标3 - 坐标1;
    向量三维 vector3 = 向量三维();
    vector3.X = 射线.方向.Y * vector2.Z - 射线.方向.Z * vector2.Y;
    vector3.Y = 射线.方向.Z * vector2.X - 射线.方向.X * vector2.Z;
    vector3.Z = 射线.方向.X * vector2.Y - 射线.方向.Y * vector2.X;
    float num = vector.X * vector3.X + vector.Y * vector3.Y + vector.Z * vector3.Z;
    if (计算::等于0(num))
    {
        距离 = 0.0f;
        return false;
    }
    float num2 = 1.0f / num;
    向量三维 vector4 = 向量三维();
    vector4.X = 射线.坐标.X - 坐标1.X;
    vector4.Y = 射线.坐标.Y - 坐标1.Y;
    vector4.Z = 射线.坐标.Z - 坐标1.Z;
    float num3 = vector4.X * vector3.X + vector4.Y * vector3.Y + vector4.Z * vector3.Z;
    num3 *= num2;
    if (num3 < 0.0f || num3 > 1.0f)
    {
        距离 = 0.0f;
        return false;
    }

    向量三维 vector5 = 向量三维();
    vector5.X = vector4.Y * vector.Z - vector4.Z * vector.Y;
    vector5.Y = vector4.Z * vector.X - vector4.X * vector.Z;
    vector5.Z = vector4.X * vector.Y - vector4.Y * vector.X;
    float num4 = 射线.方向.X * vector5.X + 射线.方向.Y * vector5.Y + 射线.方向.Z * vector5.Z;
    num4 *= num2;
    if (num4 < 0.0f || num3 + num4 > 1.0f)
    {
        距离 = 0.0f;
        return false;
    }

    float num5 = vector2.X * vector5.X + vector2.Y * vector5.Y + vector2.Z * vector5.Z;
    num5 *= num2;
    if (num5 < 0.0f)
    {
        距离 = 0.0f;
        return false;
    }

    距离 = num5;
    return true;
}

bool 射线结构::检查三角面碰撞(射线结构 射线, 向量三维 坐标1, 向量三维 坐标2, 向量三维 坐标3, 向量三维& 碰撞坐标)
{
    float 距离;
    if (!检查三角面碰撞(射线, 坐标1, 坐标2, 坐标3,距离))
    {
        碰撞坐标 = 向量三维(0);
        return false;
    }
    碰撞坐标 = 射线.坐标 + 射线.方向 * 距离;
    return true;
}

bool 射线结构::检查包围盒碰撞(射线结构 射线, 包围盒 _包围盒)
{
    float 距离;
    return 检查包围盒碰撞(射线, _包围盒, 距离);
}

bool 射线结构::检查包围盒碰撞(射线结构 射线, 包围盒 _包围盒, float& 距离)
{
    距离 = 0.0f;
    float num = FLT_MAX;
    if (计算::等于0(射线.方向.X))
    {
        if (射线.坐标.X < _包围盒.最小值.X || 射线.坐标.X > _包围盒.最大值.X)
        {
            距离 = 0.0f;
            return false;
        }
    }
    else
    {
        float num2 = 1.0f / 射线.方向.X;
        float num3 = (_包围盒.最小值.X - 射线.坐标.X) * num2;
        float num4 = (_包围盒.最大值.X - 射线.坐标.X) * num2;
        if (num3 > num4)
        {
            float num5 = num3;
            num3 = num4;
            num4 = num5;
        }

        距离 = std::max(num3, 距离);
        num = std::min(num4, num);
        if (距离 > num)
        {
            距离 = 0.0f;
            return false;
        }
    }

    if (计算::等于0(射线.方向.Y))
    {
        if (射线.坐标.Y < _包围盒.最小值.Y || 射线.坐标.Y > _包围盒.最大值.Y)
        {
            距离 = 0.0f;
            return false;
        }
    }
    else
    {
        float num6 = 1.0f / 射线.方向.Y;
        float num7 = (_包围盒.最小值.Y - 射线.坐标.Y) * num6;
        float num8 = (_包围盒.最大值.Y - 射线.坐标.Y) * num6;
        if (num7 > num8)
        {
            float num9 = num7;
            num7 = num8;
            num8 = num9;
        }

        距离 = std::max(num7, 距离);
        num = std::min(num8, num);
        if (距离 > num)
        {
            距离 = 0.0f;
            return false;
        }
    }

    if (计算::等于0(射线.方向.Z))
    {
        if (射线.坐标.Z < _包围盒.最小值.Z || 射线.坐标.Z > _包围盒.最大值.Z)
        {
            距离 = 0.0f;
            return false;
        }
    }
    else
    {
        float num10 = 1.0f / 射线.方向.Z;
        float num11 = (_包围盒.最小值.Z - 射线.坐标.Z) * num10;
        float num12 = (_包围盒.最大值.Z - 射线.坐标.Z) * num10;
        if (num11 > num12)
        {
            float num13 = num11;
            num11 = num12;
            num12 = num13;
        }

        距离 = std::max(num11, 距离);
        num = std::min(num12, num);
        if (距离 > num)
        {
            距离 = 0.0f;
            return false;
        }

    }
    return true;
}

bool 射线结构::检查包围盒碰撞(射线结构 射线, 包围盒 _包围盒, 向量三维& 碰撞坐标)
{
    float 距离;
    if (!检查包围盒碰撞(射线, _包围盒,距离))
    {
        碰撞坐标 = 向量三维(0);
        return false;
    }
    碰撞坐标 = 射线.坐标 + 射线.方向 * 距离;
    return true;
}

bool 射线结构::检查平面碰撞(射线结构 射线, 向量三维 面坐标, 向量三维 面法线, float& 距离, 向量三维& 碰撞点)
{

    float denominator = 向量三维::计算点乘(面法线, 射线.方向);
    if (std::abs(denominator) > 1e-6f)
    {
        距离 = 向量三维::计算点乘(面坐标 - 射线.坐标, 面法线) / denominator;
        碰撞点 = 射线.坐标 + 射线.方向 * 距离;
        if (距离 >= 0)
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    距离 = 0;
    碰撞点 = 0;
    return false;
}

bool 射线结构::检查球碰撞(射线结构 射线, 向量三维 坐标, float 半径)
{
    // 计算射线与点之间的向量
    向量三维 rayToPoint = 坐标 - 射线.坐标;

    // 计算射线方向与射线到点的向量的点积
    float projection = 向量三维::计算点乘(rayToPoint, 射线.方向);

    // 如果投影值小于0，说明点在射线的负方向上，返回点到射线起点的距离
    if (projection < 0)
    {
        return false;
    }

    // 计算射线到点的向量与射线方向的叉积，即点在射线平面内的投影
    向量三维 cross = 向量三维::计算叉乘(rayToPoint, 射线.方向);

    // 计算点投影的模，即是距离
    float distance = cross.模();


    return distance <= 半径;
}

float 射线结构::计算射线与线段距离(射线结构 射线, 向量三维 起点, 向量三维 终点)
{
    // 保证方向向量已经被规范化
    射线.方向 = 向量三维::计算单位向量(射线.方向);
    向量三维 edgeVec = 终点 - 起点;
    edgeVec = 向量三维::计算单位向量(edgeVec);
    向量三维 edgeDir = edgeVec;

    // 计算射线方向和边方向的叉积
    向量三维 crossVec = 向量三维::计算叉乘(射线.方向, edgeDir);

    // 检测射线方向和边方向是否平行
    if (crossVec.模() < 1e-8f)
    {
        // 射线和边平行时计算射线起点到边的直线段的最短距离
        向量三维 rayToEdgeStart = 起点 - 射线.坐标;
        向量三维 projectedPoint = 射线.坐标 + 射线.方向 * 向量三维::计算点乘(rayToEdgeStart, 射线.方向);
        向量三维 closestPoint = 起点 + edgeDir * 向量三维::计算点乘(projectedPoint - 起点, edgeDir);

        if ((closestPoint - 起点).模平方() > edgeVec.模平方() ||
            (closestPoint - 终点).模平方() > edgeVec.模平方())
        {
            // 如果计算出的点不在边上，返回射线起点到最近端点的距离
            float distToStart = (射线.坐标 - 起点).模();
            float distToEnd = (射线.坐标 - 终点).模();
            return std::min(distToStart, distToEnd);
        }

        return (projectedPoint - closestPoint).模();
    }

    // 计算射线起点到边的一个端点的向量
    向量三维 vecBetween = 射线.坐标 - 起点;

    // 计算该向量与射线和边方向叉积向量的点积，从而确定射线和边的距离
    float distance = 向量三维::计算点乘(vecBetween, crossVec) / crossVec.模();

    return std::abs(distance);
}

float 射线结构::计算射线与坐标距离(射线结构 射线, 向量三维 点)
{
    // 计算射线与点之间的向量
    向量三维 rayToPoint = 点 - 射线.坐标;

    // 计算射线方向与射线到点的向量的点积
    float projection = 向量三维::计算点乘(rayToPoint, 射线.方向);

    // 如果投影值小于0，说明点在射线的负方向上，返回点到射线起点的距离
    if (projection < 0)
    {
        return -1;
    }

    // 计算射线到点的向量与射线方向的叉积，即点在射线平面内的投影
    向量三维 cross = 向量三维::计算叉乘(rayToPoint, 射线.方向);

    // 计算点投影的模，即是距离
    float distance = cross.模();


    return distance;
}

射线结构 射线结构::创建射线(向量三维 坐标1, 向量三维 坐标2)
{
    向量三维 方向 = 向量三维::计算单位向量(坐标2 - 坐标1);
    return 射线结构(坐标1, 方向);
}

射线结构 射线结构::operator+(向量三维 _坐标)
{
    return  射线结构(坐标 + _坐标, 方向);
}

射线结构 射线结构::operator-(向量三维 _坐标)
{
	return 射线结构(坐标 - _坐标, 方向);
}

射线结构 射线结构::operator*(四元数 _四元数)
{
    向量三维 向量A = 坐标;
    向量三维 向量B = 坐标 + 方向;
    return 创建射线(_四元数 * 向量A, _四元数 * 向量B);
}

射线结构 射线结构::operator*(矩阵4X4 变换矩阵)
{
    向量三维 向量A = 坐标;
    向量三维 向量B = 坐标 + 方向;
    return 创建射线(变换矩阵 * 向量A, 变换矩阵 * 向量B);
}
