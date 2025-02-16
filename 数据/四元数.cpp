#include "四元数.h"

四元数::四元数()
{
	X = Y = Z = W = 0;
}

四元数::四元数(float 值)
{
	X = Y = Z = W = 值;
}

四元数::四元数(向量三维 value, float w)
{
	X = value.X;
	Y = value.Y;
	Z = value.Z;
	W = w;
}

四元数::四元数(向量二维 value, float z, float w)
{
	X = value.X;
	Y = value.Y;
	Z = z;
	W = w;
}

四元数::四元数(float x, float y, float z, float w)
{
	X = x;
	Y = y;
	Z = z;
	W = w;
}

四元数::四元数(std::vector<float> values)
{
	if (values.size() != 4)
	{

	}

	X = values[0];
	Y = values[1];
	Z = values[2];
	W = values[3];
}

四元数 四元数::零()
{
	return 四元数(0);
}

四元数 四元数::壹()
{
	return 四元数(1);
}

四元数 四元数::单位四元数()
{
	return 四元数(0, 0, 0, 1);
}

float 四元数::旋转角度(四元数 值)
{
	if (计算::等于0(值.X * 值.X + 值.Y * 值.Y + 值.Z * 值.Z))
	{
		return 0.0f;
	}

	return 2.0f * std::acos(计算::范围限制(W, -1.0f, 1.0f));
}

向量三维 四元数::旋转轴(四元数 值)
{
	float num = 值.X * 值.X + 值.Y * 值.Y + 值.Z * 值.Z;
	if (计算::等于0(num))
	{
		return 向量三维::X轴();
	}

	float num2 = 1.0f / std::sqrt(num);
	return  向量三维(X * num2, Y * num2, Z * num2);
}

float 四元数::计算模(四元数 四元数)
{
	return std::sqrt(四元数.X * 四元数.X + 四元数.Y * 四元数.Y + 四元数.Z * 四元数.Z + 四元数.W * 四元数.W);
}

float 四元数::计算模平方(四元数 四元数)
{
	return 四元数.X * 四元数.X + 四元数.Y * 四元数.Y + 四元数.Z * 四元数.Z + 四元数.W * 四元数.W;
}

四元数 四元数::计算叉乘(四元数 左, 四元数 右)
{
	四元数 四元数;
	float x = 左.X;
	float y = 左.Y;
	float z = 左.Z;
	float w = 左.W;
	float x2 = 右.X;
	float y2 = 右.Y;
	float z2 = 右.Z;
	float w2 = 右.W;
	float num = y * z2 - z * y2;
	float num2 = z * x2 - x * z2;
	float num3 = x * y2 - y * x2;
	float num4 = x * x2 + y * y2 + z * z2;
	四元数.X = x * w2 + x2 * w + num;
	四元数.Y = y * w2 + y2 * w + num2;
	四元数.Z = z * w2 + z2 * w + num3;
	四元数.W = w * w2 - num4;
	return 四元数;
}

四元数 四元数::计算单位四元数(四元数 四元数值)
{
	四元数 单位四元数;
	float num = 计算模(四元数值);
	if (!计算::等于0(num))
	{
		float num2 = 1.0f / num;
		单位四元数.X = 四元数值.X * num2;
		单位四元数.Y = 四元数值.Y * num2;
		单位四元数.Z = 四元数值.Z * num2;
		单位四元数.W = 四元数值.W * num2;
	}
	return 单位四元数;
}

四元数 四元数::operator-()
{
	return 四元数(-X,-Y,-Z,-W);
}

四元数 四元数::operator+(四元数 值)
{
	四元数 变量(X, Y, Z, W);
	return 四元数(变量.X + 值.X, 变量.Y + 值.Y, 变量.Z + 值.Z, 变量.W + 值.W);
}

四元数 四元数::operator-(四元数 值)
{
	四元数 变量(X, Y, Z, W);
	return 四元数(变量.X - 值.X, 变量.Y - 值.Y, 变量.Z - 值.Z, 变量.W - 值.W);
}

四元数 四元数::operator*(四元数 值)
{
	return 计算叉乘(四元数(X, Y, Z, W), 值);
}

四元数 四元数::operator*(float 值)
{
	四元数 变量(X, Y, Z, W);
	return 四元数(变量.X * 值, 变量.Y * 值, 变量.Z * 值, 变量.W * 值);
}

向量三维 四元数::operator*(向量三维 向量)
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
	float x = 向量.X * (1.0f - num10 - num12) + 向量.Y * (num8 - num6) + 向量.Z * (num9 + num5);
	float y = 向量.X * (num8 + num6) + 向量.Y * (1.0f - num7 - num12) + 向量.Z * (num11 - num4);
	float z = 向量.X * (num9 - num5) + 向量.Y * (num11 + num4) + 向量.Z * (1.0f - num7 - num10);
	向量三维 result = 向量三维(x, y, z);
	return result;
}

//float& 四元数::operator[](int index)
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
//		//throw std::invalid_argument("超出索引");
//	}// TODO: 在此处插入 return 语句
//}

int 四元数::确定数字符号(float zhi)
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

四元数 四元数::计算自然对数(四元数 四元数值)
{
	四元数 自然对数;
	if ((double)std::abs(四元数值.W) < 1.0)
	{
		float num = std::acos(四元数值.W);
		float num2 = std::sin(num);
		if (!计算::等于0(num2))
		{
			float num3 = num / num2;
			自然对数.X = 四元数值.X * num3;
			自然对数.Y = 四元数值.Y * num3;
			自然对数.Z = 四元数值.Z * num3;
		}
		else
		{
			自然对数 = 四元数值;
		}
	}
	else
	{
		自然对数 = 四元数值;
	}

	自然对数.W = 0.0f;
	return 四元数值;
}


向量三维 四元数::四元数乘三维向量(向量三维 向量, 四元数 四元数)
{
	float num = 四元数.X + 四元数.X;
	float num2 = 四元数.Y + 四元数.Y;
	float num3 = 四元数.Z + 四元数.Z;
	float num4 = 四元数.W * num;
	float num5 = 四元数.W * num2;
	float num6 = 四元数.W * num3;
	float num7 = 四元数.X * num;
	float num8 = 四元数.X * num2;
	float num9 = 四元数.X * num3;
	float num10 = 四元数.Y * num2;
	float num11 = 四元数.Y * num3;
	float num12 = 四元数.Z * num3;
	float x = 向量.X * (1.0f - num10 - num12) + 向量.Y * (num8 - num6) + 向量.Z * (num9 + num5);
	float y = 向量.X * (num8 + num6) + 向量.Y * (1.0f - num7 - num12) + 向量.Z * (num11 - num4);
	float z = 向量.X * (num9 - num5) + 向量.Y * (num11 + num4) + 向量.Z * (1.0f - num7 - num10);
	向量三维 result = 向量三维(x, y, z);
	return result;
}



//两个四元数的点乘结果越接近1，表示它们的方向更加接近或对齐；而结果越接近-1，表示它们的方向相反；结果为0表示它们垂直或正交
float 四元数::计算点乘(四元数 左, 四元数 右)
{
	return 左.X * 右.X + 左.Y * 右.Y + 左.Z * 右.Z + 左.W * 右.W;
}

//模长为1的四元数，其共轭就是其逆，共轭操作可以用于求解四元数的逆、旋转矩阵的转置等
四元数 四元数::计算共轭(四元数 值)
{
	四元数 共轭四元数;
	共轭四元数.X = 0.0f - 值.X;
	共轭四元数.Y = 0.0f - 值.Y;
	共轭四元数.Z = 0.0f - 值.Z;
	共轭四元数.W = 值.W;
	return 共轭四元数;
}

四元数 四元数::计算指数函数(四元数 四元数值)
{
	四元数 指数函数;
	float num = std::sqrt(四元数值.X * 四元数值.X + 四元数值.Y * 四元数值.Y + 四元数值.Z * 四元数值.Z);
	float num2 = std::sin(num);
	if (!计算::等于0(num2))
	{
		float num3 = num2 / num;
		指数函数.X = num3 * 四元数值.X;
		指数函数.Y = num3 * 四元数值.Y;
		指数函数.Z = num3 * 四元数值.Z;
		return 指数函数;
	}
	else
	{
		指数函数 = 四元数值;
		return 指数函数;
	}

	指数函数.W = std::cos(num);
	return 指数函数;
}

四元数 四元数::计算逆(四元数 四元数值)
{
	四元数 四元数逆;
	float lengthSquared = 计算模平方(四元数值);
	if (lengthSquared == 0)
	{
		//std::cout << "无法计算零长度四元数的逆。"<<std::endl;
	}
	float inverseLengthSquared = 1 / lengthSquared;
	return 四元数逆 = 四元数(
		四元数值.X * -inverseLengthSquared,
		四元数值.Y * -inverseLengthSquared,
		四元数值.Z * -inverseLengthSquared,
		四元数值.W * inverseLengthSquared);
}

四元数 四元数::线性插值(四元数 四元数1, 四元数 四元数2, float 百分比)
{
	四元数 四元数值;
	float num = 1.0f - 百分比;
	if (计算点乘(四元数1, 四元数2) >= 0.0f)
	{
		四元数值.X = num * 四元数1.X + 百分比 * 四元数2.X;
		四元数值.Y = num * 四元数1.Y + 百分比 * 四元数2.Y;
		四元数值.Z = num * 四元数1.Z + 百分比 * 四元数2.Z;
		四元数值.W = num * 四元数1.W + 百分比 * 四元数2.W;
	}
	else
	{
		四元数值.X = num * 四元数1.X - 百分比 * 四元数2.X;
		四元数值.Y = num * 四元数1.Y - 百分比 * 四元数2.Y;
		四元数值.Z = num * 四元数1.Z - 百分比 * 四元数2.Z;
		四元数值.W = num * 四元数1.W - 百分比 * 四元数2.W;
	}
	return 四元数值 = 计算单位四元数(四元数值);
}

四元数 四元数::计算球面线性插值(四元数 四元数1, 四元数 四元数2, float 百分比)
{
	四元数 四元数值;
	float value = 计算点乘(四元数1, 四元数2);
	float num;
	float num2;
	if (std::abs(value) > 0.999999f)
	{
		num = 1.0f - 百分比;
		num2 = 百分比 * 确定数字符号(value);
	}
	else
	{
		float num3 = std::acos(std::abs(value));
		float num4 = 1.0f /std::sin(num3);
		num = std::sin((1.0f - 百分比) * num3) * num4;
		num2 = std::sin(百分比 * num3) * num4 * 确定数字符号(value);
	}

	四元数值.X = num * 四元数1.X + num2 * 四元数2.X;
	四元数值.Y = num * 四元数1.Y + num2 * 四元数2.Y;
	四元数值.Z = num * 四元数1.Z + num2 * 四元数2.Z;
	四元数值.W = num * 四元数1.W + num2 * 四元数2.W;
	return 四元数值;
}

四元数 四元数::计算球面线性插值(四元数 四元数1, 四元数 四元数2, 四元数 四元数3, 四元数 四元数4, float 百分比)
{
	四元数 result2, result3, 四元数值;
	result2 = 计算球面线性插值(四元数1, 四元数4, 百分比);
	result3 = 计算球面线性插值(四元数2, 四元数3, 百分比);
	四元数值 = 计算球面线性插值(result2, result3, 2.0f * 百分比 * (1.0f - 百分比));
	return 四元数值;
}

四元数 四元数::计算三点球面线性插值(四元数 四元数1, 四元数 四元数2, 四元数 四元数3, float 百分比1, float 百分比2)
{
	四元数 result2, result3, 四元数值;
	result2 = 计算球面线性插值( 四元数1,  四元数2, 百分比1 + 百分比2);
	result3 = 计算球面线性插值( 四元数1,  四元数3, 百分比1 + 百分比2);
	四元数值 = 计算球面线性插值( result2,  result3, 百分比2 / (百分比1 + 百分比2));
	return 四元数值;
}

std::vector<四元数> 四元数::计算球形四边形插值(四元数 四元数1, 四元数 四元数2, 四元数 四元数3, 四元数 四元数4)
{
	四元数 result, result2, m1, m2;
	四元数 quaternion = ((计算模平方(四元数1 + 四元数2) < 计算模平方(四元数1 - 四元数2)) ? (-四元数1) : 四元数1);
	四元数 value5 = ((计算模平方(四元数2 + 四元数3) < 计算模平方(四元数2 - 四元数3)) ? (-四元数3) : 四元数3);
	四元数 quaternion2 = ((计算模平方(四元数3 + 四元数4) < 计算模平方(四元数3 - 四元数4)) ? (-四元数4) : 四元数4);
	四元数 value6 = 四元数2;
	result = 计算指数函数(value6);
	result2 = 计算指数函数(value5);
	m1 = value6* 计算指数函数((计算自然对数(result * value5) * -0.25f + 计算自然对数(result * quaternion)));
	m2 = value5* 计算指数函数((计算自然对数(result2 * quaternion2) * -0.25f + 计算自然对数(result2 * value6)));
	std::vector<四元数> 值(3);
	值[0] = m1;
	值[1] = m2;
	值[2] = value5;
	return 值;
}

四元数 四元数::创建轴角旋转(向量三维 旋转轴, float 弧度)
{
	四元数 四元数值;
	向量三维 result2;
	result2 = 向量三维::计算单位向量(旋转轴);
	float num = 弧度 * 0.5f;
	float num2 = std::sin(num);
	float w = std::cos(num);
	四元数值.X = result2.X * num2;
	四元数值.Y = result2.Y * num2;
	四元数值.Z = result2.Z * num2;
	四元数值.W = w;
	return 四元数值;
}

四元数 四元数::创建矩阵旋转(矩阵4X4 旋转矩阵)
{
	四元数 四元数值;
	float num = 旋转矩阵.M11 + 旋转矩阵.M22 + 旋转矩阵.M33;
	if (num > 0.0f)
	{
		float num2 = std::sqrt(num + 1.0f);
		四元数值.W = num2 * 0.5f;
		num2 = 0.5f / num2;
		四元数值.X = (旋转矩阵.M23 - 旋转矩阵.M32) * num2;
		四元数值.Y = (旋转矩阵.M31 - 旋转矩阵.M13) * num2;
		四元数值.Z = (旋转矩阵.M12 - 旋转矩阵.M21) * num2;
	}
	else if (旋转矩阵.M11 >= 旋转矩阵.M22 && 旋转矩阵.M11 >= 旋转矩阵.M33)
	{
		float num2 = std::sqrt(1.0f + 旋转矩阵.M11 - 旋转矩阵.M22 - 旋转矩阵.M33);
		float num3 = 0.5f / num2;
		四元数值.X = 0.5f * num2;
		四元数值.Y = (旋转矩阵.M12 + 旋转矩阵.M21) * num3;
		四元数值.Z = (旋转矩阵.M13 + 旋转矩阵.M31) * num3;
		四元数值.W = (旋转矩阵.M23 - 旋转矩阵.M32) * num3;
	}
	else if (旋转矩阵.M22 > 旋转矩阵.M33)
	{
		float num2 = std::sqrt(1.0f + 旋转矩阵.M22 - 旋转矩阵.M11 - 旋转矩阵.M33);
		float num3 = 0.5f / num2;
		四元数值.X = (旋转矩阵.M21 + 旋转矩阵.M12) * num3;
		四元数值.Y = 0.5f * num2;
		四元数值.Z = (旋转矩阵.M32 + 旋转矩阵.M23) * num3;
		四元数值.W = (旋转矩阵.M31 - 旋转矩阵.M13) * num3;
	}
	else
	{
		float num2 = std::sqrt(1.0f + 旋转矩阵.M33 - 旋转矩阵.M11 - 旋转矩阵.M22);
		float num3 = 0.5f / num2;
		四元数值.X = (旋转矩阵.M31 + 旋转矩阵.M13) * num3;
		四元数值.Y = (旋转矩阵.M32 + 旋转矩阵.M23) * num3;
		四元数值.Z = 0.5f * num2;
		四元数值.W = (旋转矩阵.M12 - 旋转矩阵.M21) * num3;
	}
	return 四元数值;
}

四元数 四元数::创建目标旋转(向量三维 起点, 向量三维 目标点, 向量三维 上行向量, 向量三维 前方向量)
{
	四元数 四元数值;
	矩阵4X4 视图矩阵 = 矩阵4X4::创建目标矩阵(起点, 目标点, 上行向量, 前方向量);
	四元数值 = 四元数::创建矩阵旋转(视图矩阵);
	return 四元数值;
}

四元数 四元数::创建目标旋转(向量三维 起点, 向量三维 目标点, 向量三维 上行向量)
{
	四元数 四元数值;
	矩阵4X4 视图矩阵 = 矩阵4X4::创建视图矩阵(起点, 目标点, 上行向量);
	四元数值 = 四元数::创建矩阵旋转(视图矩阵);
	return 四元数值;
}

四元数 四元数::创建向量旋转(向量三维 向量1, 向量三维 向量2)
{
	float PI = 3.1415926;
	向量三维 vec1 = 向量三维::计算单位向量(向量1);
	向量三维 vec2 = 向量三维::计算单位向量(向量2);

	float dot = 向量三维::计算点乘(vec1, vec2);
	四元数 lei;
	if (dot >= 1.0f)
	{
		// 向量方向相同，返回单位旋转
		return lei.单位四元数();
	}
	else if (dot <= -1.0f)
	{
		// 向量方向相反，找到一个正交向量，并绕它旋转180度
		向量三维 旋转轴 = 向量三维::计算叉乘(vec1, 向量三维(1, 0, 0));
		if (旋转轴.模平方() < 0.01)
			旋转轴 = 向量三维::计算叉乘(vec1,向量三维(0, 1, 0));
		return 四元数::创建轴角旋转(向量三维::计算单位向量(旋转轴), PI);
	}

	float rotAngle = std::acos(dot);
	向量三维 rotateAxis = 向量三维::计算叉乘(vec1, vec2);
	return 四元数::创建轴角旋转(向量三维::计算单位向量(rotateAxis), rotAngle);
}

四元数 四元数::创建欧拉角旋转(float X轴, float Y轴, float Z轴)
{
	float PI = 3.1415926;
	X轴 *= PI / 180.0f;
	Y轴 *= PI / 180.0f;
	Z轴 *= PI / 180.0f;
	float cy = std::cos(Z轴 * 0.5f);
	float sy = std::sin(Z轴 * 0.5f);
	float cp = std::cos(Y轴 * 0.5f);
	float sp = std::sin(Y轴 * 0.5f);
	float cr = std::cos(X轴 * 0.5f);
	float sr = std::sin(X轴 * 0.5f);

	float x = cy * cp * sr - sy * sp * cr;
	float y = sy * cp * sr + cy * sp * cr;
	float z = sy * cp * cr - cy * sp * sr;
	float w = cy * cp * cr + sy * sp * sr;
	return 四元数(x, y, z, w);
}

四元数 四元数::创建欧拉角旋转(向量三维 欧拉旋转)
{
	return 四元数(创建欧拉角旋转(欧拉旋转.X, 欧拉旋转.Y, 欧拉旋转.Z));
}

向量三维 四元数::四元数转欧拉角(四元数 四元数)
{
	float PI = 3.1415926;
	float Y轴;
	float Z轴;
	float X轴;

	float sinr_cosp = 2 * (四元数.W * 四元数.X + 四元数.Y * 四元数.Z);
	float cosr_cosp = 1 - 2 * (四元数.X * 四元数.X + 四元数.Y * 四元数.Y);
	X轴 = std::atan2(sinr_cosp, cosr_cosp);

	float sinp = 2 * (四元数.W * 四元数.Y - 四元数.Z * 四元数.X);
	if (std::abs(sinp) >= 1)
	{
		Y轴 = std::copysign(PI / 2, sinp);
	}
	else
	{
		Y轴 = std::asin(sinp);
	}
	float siny_cosp = 2 * (四元数.W * 四元数.Z + 四元数.X * 四元数.Y);
	float cosy_cosp = 1 - 2 * (四元数.Y * 四元数.Y + 四元数.Z * 四元数.Z);
	Z轴 = std::atan2(siny_cosp, cosy_cosp);
	return 向量三维(X轴, Y轴, Z轴);
}




