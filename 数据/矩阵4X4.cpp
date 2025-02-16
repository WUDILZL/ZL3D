#include "矩阵4X4.h"

矩阵4X4::矩阵4X4()
{
	M11 = 0, M12 = 0, M13 = 0, M14 = 0;
	M21 = 0, M22 = 0, M23 = 0, M24 = 0;
	M31 = 0, M32 = 0, M33 = 0, M34 = 0;
	M41 = 0, M42 = 0, M43 = 0, M44 = 0;
}

矩阵4X4::矩阵4X4(float z)
{
	M11 = z, M12 = z, M13 = z, M14 = z;
	M21 = z, M22 = z, M23 = z, M24 = z;
	M31 = z, M32 = z, M33 = z, M34 = z;
	M41 = z, M42 = z, M43 = z, M44 = z;
}

矩阵4X4::矩阵4X4(float m11, float m12, float m13, float m14, float m21, float m22, float m23, float m24, float m31, float m32, float m33, float m34, float m41, float m42, float m43, float m44)
{
	M11 = m11, M12 = m12, M13 = m13, M14 = m14;
	M21 = m21, M22 = m22, M23 = m23, M24 = m24;
	M31 = m31, M32 = m32, M33 = m33, M34 = m34;
	M41 = m41, M42 = m42, M43 = m43, M44 = m44;
}

矩阵4X4::矩阵4X4(std::vector<float> 值)
{
	if (值.size() != 16)
	{
		//return ;
	}
	M11 = 值[0];
	M12 = 值[1];
	M13 = 值[2];
	M14 = 值[3];
	M21 = 值[4];
	M22 = 值[5];
	M23 = 值[6];
	M24 = 值[7];
	M31 = 值[8];
	M32 = 值[9];
	M33 = 值[10];
	M34 = 值[11];
	M41 = 值[12];
	M42 = 值[13];
	M43 = 值[14];
	M44 = 值[15];
}

//float& 矩阵4X4::operator[](int index)
//{
//	if (index >= 0 && index <= 15) 
//	{
//		switch (index) {
//		case 0: return M11;
//		case 1: return M12;
//		case 2: return M13;
//		case 3: return M14;
//		case 4: return M21;
//		case 5: return M22;
//		case 6: return M23;
//		case 7: return M24;
//		case 8: return M31;
//		case 9: return M32;
//		case 10: return M33;
//		case 11: return M34;
//		case 12: return M41;
//		case 13: return M42;
//		case 14: return M43;
//		case 15: return M44;
//		}
//	}// TODO: 在此处插入 return 语句
//}

矩阵4X4 矩阵4X4::零()
{
	return 矩阵4X4(0);
}

矩阵4X4 矩阵4X4::单位矩阵()
{
	return 矩阵4X4
	   (1, 0, 0, 0,
		0, 1, 0, 0,
		0, 0, 1, 0,
		0, 0, 0, 1);
}

矩阵4X4 矩阵4X4::计算叉乘(矩阵4X4 左, 矩阵4X4 右)
{
	矩阵4X4 matrix;
	matrix.M11 = 左.M11 * 右.M11 + 左.M12 * 右.M21 + 左.M13 * 右.M31 + 左.M14 * 右.M41;
	matrix.M12 = 左.M11 * 右.M12 + 左.M12 * 右.M22 + 左.M13 * 右.M32 + 左.M14 * 右.M42;
	matrix.M13 = 左.M11 * 右.M13 + 左.M12 * 右.M23 + 左.M13 * 右.M33 + 左.M14 * 右.M43;
	matrix.M14 = 左.M11 * 右.M14 + 左.M12 * 右.M24 + 左.M13 * 右.M34 + 左.M14 * 右.M44;
	matrix.M21 = 左.M21 * 右.M11 + 左.M22 * 右.M21 + 左.M23 * 右.M31 + 左.M24 * 右.M41;
	matrix.M22 = 左.M21 * 右.M12 + 左.M22 * 右.M22 + 左.M23 * 右.M32 + 左.M24 * 右.M42;
	matrix.M23 = 左.M21 * 右.M13 + 左.M22 * 右.M23 + 左.M23 * 右.M33 + 左.M24 * 右.M43;
	matrix.M24 = 左.M21 * 右.M14 + 左.M22 * 右.M24 + 左.M23 * 右.M34 + 左.M24 * 右.M44;
	matrix.M31 = 左.M31 * 右.M11 + 左.M32 * 右.M21 + 左.M33 * 右.M31 + 左.M34 * 右.M41;
	matrix.M32 = 左.M31 * 右.M12 + 左.M32 * 右.M22 + 左.M33 * 右.M32 + 左.M34 * 右.M42;
	matrix.M33 = 左.M31 * 右.M13 + 左.M32 * 右.M23 + 左.M33 * 右.M33 + 左.M34 * 右.M43;
	matrix.M34 = 左.M31 * 右.M14 + 左.M32 * 右.M24 + 左.M33 * 右.M34 + 左.M34 * 右.M44;
	matrix.M41 = 左.M41 * 右.M11 + 左.M42 * 右.M21 + 左.M43 * 右.M31 + 左.M44 * 右.M41;
	matrix.M42 = 左.M41 * 右.M12 + 左.M42 * 右.M22 + 左.M43 * 右.M32 + 左.M44 * 右.M42;
	matrix.M43 = 左.M41 * 右.M13 + 左.M42 * 右.M23 + 左.M43 * 右.M33 + 左.M44 * 右.M43;
	matrix.M44 = 左.M41 * 右.M14 + 左.M42 * 右.M24 + 左.M43 * 右.M34 + 左.M44 * 右.M44;
	return matrix;
}

矩阵4X4 矩阵4X4::operator-()
{
	return 矩阵4X4(-M11, -M12, -M13, -M14,
		-M21, -M22, -M23, -M24,
		-M31, -M32, -M33, -M34,
		-M41, -M42, -M43, -M44);
}

矩阵4X4 矩阵4X4::operator+(矩阵4X4 矩阵)
{
	矩阵4X4 变量(M11, M12, M13, M14, M21, M22, M23, M24, M31, M32, M33, M34, M41, M42, M43, M44);
	return 矩阵4X4(变量.M11 + 矩阵.M11, 变量.M12 + 矩阵.M12, 变量.M13 + 矩阵.M13, 变量.M14 + 矩阵.M14,
		变量.M21 + 矩阵.M21, 变量.M22 + 矩阵.M22, 变量.M23 + 矩阵.M23, 变量.M24 + 矩阵.M24,
		变量.M31 + 矩阵.M31, 变量.M32 + 矩阵.M32, 变量.M33 + 矩阵.M33, 变量.M34 + 矩阵.M34,
		变量.M41 + 矩阵.M41, 变量.M42 + 矩阵.M42, 变量.M43 + 矩阵.M43, 变量.M44 + 矩阵.M44);
}

矩阵4X4 矩阵4X4::operator-(矩阵4X4 矩阵)
{
	矩阵4X4 变量(M11, M12, M13, M14, M21, M22, M23, M24, M31, M32, M33, M34, M41, M42, M43, M44);
	return 矩阵4X4(变量.M11 - 矩阵.M11, 变量.M12 - 矩阵.M12, 变量.M13 - 矩阵.M13, 变量.M14 - 矩阵.M14,
		变量.M21 - 矩阵.M21, 变量.M22 - 矩阵.M22, 变量.M23 - 矩阵.M23, 变量.M24 - 矩阵.M24,
		变量.M31 - 矩阵.M31, 变量.M32 - 矩阵.M32, 变量.M33 - 矩阵.M33, 变量.M34 - 矩阵.M34,
		变量.M41 - 矩阵.M41, 变量.M42 - 矩阵.M42, 变量.M43 - 矩阵.M43, 变量.M44 - 矩阵.M44);
}

矩阵4X4 矩阵4X4::operator*(float 矩阵)
{
	矩阵4X4 变量(M11, M12, M13, M14, M21, M22, M23, M24, M31, M32, M33, M34, M41, M42, M43, M44);
	return 矩阵4X4(变量.M11 * 矩阵, 变量.M12 * 矩阵, 变量.M13 * 矩阵, 变量.M14 * 矩阵,
		变量.M21 * 矩阵, 变量.M22 * 矩阵, 变量.M23 * 矩阵, 变量.M24 * 矩阵,
		变量.M31 * 矩阵, 变量.M32 * 矩阵, 变量.M33 * 矩阵, 变量.M34 * 矩阵,
		变量.M41 * 矩阵, 变量.M42 * 矩阵, 变量.M43 * 矩阵, 变量.M44 * 矩阵);
}

矩阵4X4 矩阵4X4::operator*(矩阵4X4 矩阵)
{
	return 矩阵4X4(计算叉乘(矩阵4X4(M11, M12, M13, M14, M21, M22, M23, M24, M31, M32, M33, M34, M41, M42, M43, M44), 矩阵));
}

向量三维 矩阵4X4::operator*(向量三维 向量)
{
	矩阵4X4 变量(M11, M12, M13, M14, M21, M22, M23, M24, M31, M32, M33, M34, M41, M42, M43, M44);
	矩阵4X4 新矩阵 = 创建平移矩阵(向量) * 变量;
	return 新矩阵.平移(新矩阵);
}

向量三维 矩阵4X4::返回平移(向量三维 向量, 矩阵4X4 矩阵)
{
	矩阵4X4 新矩阵 = 创建平移矩阵(向量) * 矩阵;
	return 新矩阵.平移(新矩阵);
}

向量四维 矩阵4X4::行1(矩阵4X4 jz)
{
	return 向量四维(jz.M11, jz.M12, jz.M13, jz.M14);
}

向量四维 矩阵4X4::行2(矩阵4X4 矩阵)
{
	return 向量四维(矩阵.M21, 矩阵.M22, 矩阵.M23, 矩阵.M24);
}

向量四维 矩阵4X4::行3(矩阵4X4 矩阵)
{
	return 向量四维(矩阵.M31, 矩阵.M32, 矩阵.M33, 矩阵.M34);
}

向量四维 矩阵4X4::行4(矩阵4X4 矩阵)
{
	return 向量四维(矩阵.M41, 矩阵.M42, 矩阵.M43, 矩阵.M44);
}

向量四维 矩阵4X4::列1(矩阵4X4 矩阵)
{
	return 向量四维(矩阵.M11, 矩阵.M21, 矩阵.M31, 矩阵.M41);
}

向量四维 矩阵4X4::列2(矩阵4X4 矩阵)
{
	return 向量四维(矩阵.M12, 矩阵.M22, 矩阵.M32, 矩阵.M42);
}

向量四维 矩阵4X4::列3(矩阵4X4 矩阵)
{
	return 向量四维(矩阵.M13, 矩阵.M23, 矩阵.M33, 矩阵.M43);
}

向量四维 矩阵4X4::列4(矩阵4X4 矩阵)
{
	return 向量四维(矩阵.M14, 矩阵.M24, 矩阵.M34, 矩阵.M44);
}

void 矩阵4X4::行一(向量四维 数据, 矩阵4X4& 目标)
{
	目标 = 矩阵4X4(数据.X, 数据.Y, 数据.Z, 数据.W,
		目标.M21, 目标.M22, 目标.M23, 目标.M24,
		目标.M31, 目标.M32, 目标.M33, 目标.M34,
		目标.M41, 目标.M42, 目标.M43, 目标.M44);
}

void 矩阵4X4::行二(向量四维 数据, 矩阵4X4& 目标)
{
	目标 = 矩阵4X4(目标.M11, 目标.M12, 目标.M13, 目标.M14,
		 数据.X, 数据.Y, 数据.Z, 数据.W,
		 目标.M31, 目标.M32, 目标.M33, 目标.M34,
		 目标.M41, 目标.M42, 目标.M43, 目标.M44);
}

void 矩阵4X4::行三(向量四维 数据, 矩阵4X4& 目标)
{
	目标 = 矩阵4X4(目标.M11, 目标.M12, 目标.M13, 目标.M14,
		 目标.M21, 目标.M22, 目标.M23, 目标.M24,
		 数据.X, 数据.Y, 数据.Z, 数据.W,
		 目标.M41, 目标.M42, 目标.M43, 目标.M44);
}

void 矩阵4X4::行四(向量四维 数据, 矩阵4X4& 目标)
{
	目标 = 矩阵4X4(目标.M11, 目标.M12, 目标.M13, 目标.M14,
		 目标.M21, 目标.M22, 目标.M23, 目标.M24,
		 目标.M31, 目标.M32, 目标.M33, 目标.M34,
		 数据.X, 数据.Y, 数据.Z, 数据.W );
}

void 矩阵4X4::列一(向量四维 数据, 矩阵4X4& 目标)
{
	目标 = 矩阵4X4(数据.X, 目标.M12, 目标.M13, 目标.M14,
		数据.Y, 目标.M22, 目标.M23, 目标.M24,
		数据.Z, 目标.M32, 目标.M33, 目标.M34,
		数据.W, 目标.M42, 目标.M43, 目标.M44);
}

void 矩阵4X4::列二(向量四维 数据, 矩阵4X4& 目标)
{
	目标 = 矩阵4X4(目标.M11, 数据.X, 目标.M13, 目标.M14,
		目标.M21, 数据.Y, 目标.M23, 目标.M24,
		目标.M31, 数据.Z, 目标.M33, 目标.M34,
		目标.M41, 数据.W, 目标.M43, 目标.M44);
}

void 矩阵4X4::列三(向量四维 数据, 矩阵4X4& 目标)
{
	目标 = 矩阵4X4(目标.M11, 目标.M12, 数据.X, 目标.M14,
		目标.M21, 目标.M22, 数据.Y, 目标.M24,
		目标.M31, 目标.M32, 数据.Z, 目标.M34,
		目标.M41, 目标.M42, 数据.W, 目标.M44);
}

void 矩阵4X4::列四(向量四维 数据, 矩阵4X4& 目标)
{
	目标 = 矩阵4X4(目标.M11, 目标.M12, 目标.M13, 数据.X,
		目标.M21, 目标.M22, 目标.M23, 数据.Y,
		目标.M31, 目标.M32, 目标.M33, 数据.Z,
		目标.M41, 目标.M42, 目标.M43, 数据.W);
}

向量三维 矩阵4X4::平移(矩阵4X4 矩阵)
{
	return 向量三维(矩阵.M41, 矩阵.M42, 矩阵.M43);
}

向量三维 矩阵4X4::缩放(矩阵4X4 矩阵)
{
	return 向量三维(矩阵.M11, 矩阵.M22, 矩阵.M33);
}

float 矩阵4X4::计算行列式(矩阵4X4 矩阵)
{
	float num = 矩阵.M33 * 矩阵.M44 - 矩阵.M34 * 矩阵.M43;
	float num2 = 矩阵.M32 * 矩阵.M44 - 矩阵.M34 * 矩阵.M42;
	float num3 = 矩阵.M32 * 矩阵.M43 - 矩阵.M33 * 矩阵.M42;
	float num4 = 矩阵.M31 * 矩阵.M44 - 矩阵.M34 * 矩阵.M41;
	float num5 = 矩阵.M31 * 矩阵.M43 - 矩阵.M33 * 矩阵.M41;
	float num6 = 矩阵.M31 * 矩阵.M42 - 矩阵.M32 * 矩阵.M41;
	return 矩阵.M11 * (矩阵.M22 * num - 矩阵.M23 * num2 + 矩阵.M24 * num3) - 矩阵.M12 * (矩阵.M21 * num - 矩阵.M23 * num4 + 矩阵.M24 * num5) + 矩阵.M13 * (矩阵.M21 * num2 - 矩阵.M22 * num4 + 矩阵.M24 * num6) - 矩阵.M14 * (矩阵.M21 * num3 - 矩阵.M22 * num5 + 矩阵.M23 * num6);
}

矩阵4X4 矩阵4X4::计算幂(矩阵4X4 左, int 指数)
{
	矩阵4X4 矩阵;
	if (指数 < 0)
	{

	}
	switch (指数)
	{
	case 0:
		矩阵 = 单位矩阵();
		return 矩阵;
	case 1:
		矩阵 = 左;
		return 矩阵;
	}
	矩阵4X4 identity = 单位矩阵();
	矩阵4X4 matrix = 左;
	while (true) {
		bool flag = (指数 & 1) != 0;  // 模拟 C# 中的 ((uint)指数 & (true? 1u : 0u))!=0
		if (flag) {
			identity = identity * matrix;  // 假设乘法运算符已重载
		}
		指数 = 指数 / 2;
		if (指数 <= 0) {
			break;
		}
		matrix = matrix * matrix;
	}
	矩阵 = identity;

	return 矩阵;
}

矩阵4X4 矩阵4X4::计算线性插值(矩阵4X4 矩阵A, 矩阵4X4 矩阵B, float 百分比)
{
	矩阵4X4 向量;
	向量.M11 = 计算::范围采样(矩阵A.M11, 矩阵B.M11, 百分比);
	向量.M12 = 计算::范围采样(矩阵A.M12, 矩阵B.M12, 百分比);
	向量.M13 = 计算::范围采样(矩阵A.M13, 矩阵B.M13, 百分比);
	向量.M14 = 计算::范围采样(矩阵A.M14, 矩阵B.M14, 百分比);
	向量.M21 = 计算::范围采样(矩阵A.M21, 矩阵B.M21, 百分比);
	向量.M22 = 计算::范围采样(矩阵A.M22, 矩阵B.M22, 百分比);
	向量.M23 = 计算::范围采样(矩阵A.M23, 矩阵B.M23, 百分比);
	向量.M24 = 计算::范围采样(矩阵A.M24, 矩阵B.M24, 百分比);
	向量.M31 = 计算::范围采样(矩阵A.M31, 矩阵B.M31, 百分比);
	向量.M32 = 计算::范围采样(矩阵A.M32, 矩阵B.M32, 百分比);
	向量.M33 = 计算::范围采样(矩阵A.M33, 矩阵B.M33, 百分比);
	向量.M34 = 计算::范围采样(矩阵A.M34, 矩阵B.M34, 百分比);
	向量.M41 = 计算::范围采样(矩阵A.M41, 矩阵B.M41, 百分比);
	向量.M42 = 计算::范围采样(矩阵A.M42, 矩阵B.M42, 百分比);
	向量.M43 = 计算::范围采样(矩阵A.M43, 矩阵B.M43, 百分比);
	向量.M44 = 计算::范围采样(矩阵A.M44, 矩阵B.M44, 百分比);
	return 向量;
}

矩阵4X4 矩阵4X4::三次插值(矩阵4X4 矩阵A, 矩阵4X4 矩阵B, float 百分比)
{
	百分比 = 计算::缓动采样(百分比);
	return 计算线性插值(矩阵A, 矩阵B, 百分比);
}

矩阵4X4 矩阵4X4::计算转置矩阵(矩阵4X4 矩阵)
{
	矩阵4X4 转置矩阵;
	转置矩阵.M11 = 矩阵.M11;
	转置矩阵.M12 = 矩阵.M21;
	转置矩阵.M13 = 矩阵.M31;
	转置矩阵.M14 = 矩阵.M41;
	转置矩阵.M21 = 矩阵.M12;
	转置矩阵.M22 = 矩阵.M22;
	转置矩阵.M23 = 矩阵.M32;
	转置矩阵.M24 = 矩阵.M42;
	转置矩阵.M31 = 矩阵.M13;
	转置矩阵.M32 = 矩阵.M23;
	转置矩阵.M33 = 矩阵.M33;
	转置矩阵.M34 = 矩阵.M43;
	转置矩阵.M41 = 矩阵.M14;
	转置矩阵.M42 = 矩阵.M24;
	转置矩阵.M43 = 矩阵.M34;
	转置矩阵.M44 = 矩阵.M44;
	return 转置矩阵;
}

矩阵4X4 矩阵4X4::计算逆矩阵(矩阵4X4 矩阵)
{
	矩阵4X4 逆矩阵;
	float num = 矩阵.M31 * 矩阵.M42 - 矩阵.M32 * 矩阵.M41;
	float num2 = 矩阵.M31 * 矩阵.M43 - 矩阵.M33 * 矩阵.M41;
	float num3 = 矩阵.M34 * 矩阵.M41 - 矩阵.M31 * 矩阵.M44;
	float num4 = 矩阵.M32 * 矩阵.M43 - 矩阵.M33 * 矩阵.M42;
	float num5 = 矩阵.M34 * 矩阵.M42 - 矩阵.M32 * 矩阵.M44;
	float num6 = 矩阵.M33 * 矩阵.M44 - 矩阵.M34 * 矩阵.M43;

	//第一行代数余子式
	float num7 = 矩阵.M22 * num6 + 矩阵.M23 * num5 + 矩阵.M24 * num4;
	float num8 = 矩阵.M21 * num6 + 矩阵.M23 * num3 + 矩阵.M24 * num2;
	float num9 = 矩阵.M21 * (0.0f - num5) + 矩阵.M22 * num3 + 矩阵.M24 * num;
	float num10 = 矩阵.M21 * num4 + 矩阵.M22 * (0.0f - num2) + 矩阵.M23 * num;
	//拉普拉斯行列式展开
	float num11 = 矩阵.M11 * num7 - 矩阵.M12 * num8 + 矩阵.M13 * num9 - 矩阵.M14 * num10;
	if (std::abs(num11) == 0.0f)
	{
		逆矩阵 = 零();
		return 逆矩阵;
	}
	//当矩阵可逆时，计算倒数，及1.0/num11
	num11 = 1.0f / num11;
	float num12 = 矩阵.M11 * 矩阵.M22 - 矩阵.M12 * 矩阵.M21;
	float num13 = 矩阵.M11 * 矩阵.M23 - 矩阵.M13 * 矩阵.M21;
	float num14 = 矩阵.M14 * 矩阵.M21 - 矩阵.M11 * 矩阵.M24;
	float num15 = 矩阵.M12 * 矩阵.M23 - 矩阵.M13 * 矩阵.M22;
	float num16 = 矩阵.M14 * 矩阵.M22 - 矩阵.M12 * 矩阵.M24;
	float num17 = 矩阵.M13 * 矩阵.M24 - 矩阵.M14 * 矩阵.M23;

	float num18 = 矩阵.M12 * num6 + 矩阵.M13 * num5 + 矩阵.M14 * num4;
	float num19 = 矩阵.M11 * num6 + 矩阵.M13 * num3 + 矩阵.M14 * num2;
	float num20 = 矩阵.M11 * (0.0f - num5) + 矩阵.M12 * num3 + 矩阵.M14 * num;
	float num21 = 矩阵.M11 * num4 + 矩阵.M12 * (0.0f - num2) + 矩阵.M13 * num;
	float num22 = 矩阵.M42 * num17 + 矩阵.M43 * num16 + 矩阵.M44 * num15;
	float num23 = 矩阵.M41 * num17 + 矩阵.M43 * num14 + 矩阵.M44 * num13;
	float num24 = 矩阵.M41 * (0.0f - num16) + 矩阵.M42 * num14 + 矩阵.M44 * num12;
	float num25 = 矩阵.M41 * num15 + 矩阵.M42 * (0.0f - num13) + 矩阵.M43 * num12;
	float num26 = 矩阵.M32 * num17 + 矩阵.M33 * num16 + 矩阵.M34 * num15;
	float num27 = 矩阵.M31 * num17 + 矩阵.M33 * num14 + 矩阵.M34 * num13;
	float num28 = 矩阵.M31 * (0.0f - num16) + 矩阵.M32 * num14 + 矩阵.M34 * num12;
	float num29 = 矩阵.M31 * num15 + 矩阵.M32 * (0.0f - num13) + 矩阵.M33 * num12;

	逆矩阵.M11 = num7 * num11;
	逆矩阵.M12 = (0.0f - num18) * num11;
	逆矩阵.M13 = num22 * num11;
	逆矩阵.M14 = (0.0f - num26) * num11;
	逆矩阵.M21 = (0.0f - num8) * num11;
	逆矩阵.M22 = num19 * num11;
	逆矩阵.M23 = (0.0f - num23) * num11;
	逆矩阵.M24 = num27 * num11;
	逆矩阵.M31 = num9 * num11;
	逆矩阵.M32 = (0.0f - num20) * num11;
	逆矩阵.M33 = num24 * num11;
	逆矩阵.M34 = (0.0f - num28) * num11;
	逆矩阵.M41 = (0.0f - num10) * num11;
	逆矩阵.M42 = num21 * num11;
	逆矩阵.M43 = (0.0f - num25) * num11;
	逆矩阵.M44 = num29 * num11;
	return 逆矩阵;
}

矩阵4X4 矩阵4X4::计算正交矩阵(矩阵4X4 矩阵)
{
	矩阵4X4 正交矩阵 = 矩阵;
	float mm = 向量四维::计算点乘(行1(正交矩阵), 行2(正交矩阵)) / 向量四维::计算点乘(行1(正交矩阵), 行1(正交矩阵));
	向量四维 gg = 行1(正交矩阵) * mm;
	正交矩阵.行二((行2(正交矩阵) - gg), 正交矩阵);

	mm = 向量四维::计算点乘(行1(正交矩阵), 行3(正交矩阵)) / 向量四维::计算点乘(行1(正交矩阵), 行1(正交矩阵));
	gg = 行1(正交矩阵) * mm;
	正交矩阵.行三((行3(正交矩阵) - gg), 正交矩阵);

	mm = 向量四维::计算点乘(行2(正交矩阵), 行3(正交矩阵)) / 向量四维::计算点乘(行2(正交矩阵), 行2(正交矩阵));
	gg = 行2(正交矩阵) * mm;
	正交矩阵.行三((行3(正交矩阵) - gg), 正交矩阵);

	mm = 向量四维::计算点乘(行1(正交矩阵), 行4(正交矩阵)) / 向量四维::计算点乘(行1(正交矩阵), 行1(正交矩阵));
	gg = 行1(正交矩阵) * mm;
	正交矩阵.行四((行4(正交矩阵) - gg), 正交矩阵);

	mm = 向量四维::计算点乘(行2(正交矩阵), 行4(正交矩阵)) / 向量四维::计算点乘(行2(正交矩阵), 行2(正交矩阵));
	gg = 行2(正交矩阵) * mm;
	正交矩阵.行四((行4(正交矩阵) - gg), 正交矩阵);

	mm = 向量四维::计算点乘(行3(正交矩阵), 行4(正交矩阵)) / 向量四维::计算点乘(行3(正交矩阵), 行3(正交矩阵));
	gg = 行3(正交矩阵) * mm;
	正交矩阵.行四((行4(正交矩阵) - gg), 正交矩阵);
	return 正交矩阵;
}

矩阵4X4 矩阵4X4::计算正交归一化矩阵(矩阵4X4 矩阵)
{
	矩阵4X4 正交归一化矩阵 = 矩阵;
	正交归一化矩阵.行一(向量四维::计算单位向量(行1(正交归一化矩阵)), 正交归一化矩阵);


	float mm = 向量四维::计算点乘(行1(正交归一化矩阵), 行2(正交归一化矩阵));
	向量四维 gg = 行1(正交归一化矩阵)* mm;
	正交归一化矩阵.行二((行2(正交归一化矩阵) - gg), 正交归一化矩阵);
	正交归一化矩阵.行二(向量四维::计算单位向量(行2(正交归一化矩阵)), 正交归一化矩阵);


	mm = 向量四维::计算点乘(行1(正交归一化矩阵), 行3(正交归一化矩阵));
	gg = 行1(正交归一化矩阵) * mm;
	正交归一化矩阵.行三((行3(正交归一化矩阵) - gg), 正交归一化矩阵);
	mm = 向量四维::计算点乘(行2(正交归一化矩阵), 行3(正交归一化矩阵));
	gg = 行2(正交归一化矩阵) * mm;
	正交归一化矩阵.行三((行3(正交归一化矩阵) - gg), 正交归一化矩阵);
	正交归一化矩阵.行三(向量四维::计算单位向量(行3(正交归一化矩阵)), 正交归一化矩阵);


	mm = 向量四维::计算点乘(行1(正交归一化矩阵), 行4(正交归一化矩阵));
	gg = 行1(正交归一化矩阵) * mm;
	正交归一化矩阵.行四((行4(正交归一化矩阵) - gg), 正交归一化矩阵);
	mm = 向量四维::计算点乘(行2(正交归一化矩阵), 行4(正交归一化矩阵));
	gg = 行2(正交归一化矩阵) * mm;
	正交归一化矩阵.行四((行4(正交归一化矩阵) - gg), 正交归一化矩阵);
	mm = 向量四维::计算点乘(行3(正交归一化矩阵), 行4(正交归一化矩阵));
	gg = 行3(正交归一化矩阵) * mm;
	正交归一化矩阵.行四((行4(正交归一化矩阵) - gg), 正交归一化矩阵);
	正交归一化矩阵.行四(向量四维::计算单位向量(行4(正交归一化矩阵)), 正交归一化矩阵);

	return 正交归一化矩阵;
}

矩阵4X4 矩阵4X4::创建目标矩阵(向量三维 摄像机坐标, 向量三维 目标坐标, 向量三维 上方向向量, 向量三维 前方向向量)
{
	向量三维 right = 目标坐标 - 摄像机坐标;
	向量三维 result2, result3;
	float num = right.模平方();
	if (计算::等于0(num))
	{
		right = -前方向向量;
	}
	else
	{
		float m = 1.0f / std::sqrt(num);
		right = right * m;
	}

	result2 = 向量三维::计算叉乘(上方向向量, right);
	result2.转单位向量();
	result3 = 向量三维::计算叉乘(right, result2);
	矩阵4X4 目标矩阵;
	目标矩阵.M11 = result2.X;
	目标矩阵.M12 = result2.Y;
	目标矩阵.M13 = result2.Z;
	目标矩阵.M14 = 0.0f;
	目标矩阵.M21 = result3.X;
	目标矩阵.M22 = result3.Y;
	目标矩阵.M23 = result3.Z;
	目标矩阵.M24 = 0.0f;
	目标矩阵.M31 = right.X;
	目标矩阵.M32 = right.Y;
	目标矩阵.M33 = right.Z;
	目标矩阵.M34 = 0.0f;
	目标矩阵.M41 = 摄像机坐标.X;
	目标矩阵.M42 = 摄像机坐标.Y;
	目标矩阵.M43 = 摄像机坐标.Z;
	目标矩阵.M44 = 1.0f;

	return 目标矩阵;
}

矩阵4X4 矩阵4X4::创建视图矩阵(向量三维 摄像机坐标, 向量三维 目标坐标, 向量三维 上方向向量)
{
	向量三维 result2 = 目标坐标 - 摄像机坐标;
	向量三维 result3, result4;
	result2.转单位向量();
	result3 = 向量三维::计算叉乘(上方向向量, result2);
	result3.转单位向量();
	result3 = 向量三维::计算叉乘(result2, result3);
	矩阵4X4 视图矩阵 = 单位矩阵();
	视图矩阵.M11 = result3.X;
	视图矩阵.M21 = result3.Y;
	视图矩阵.M31 = result3.Z;
	视图矩阵.M12 = result4.X;
	视图矩阵.M22 = result4.Y;
	视图矩阵.M32 = result4.Z;
	视图矩阵.M13 = result2.X;
	视图矩阵.M23 = result2.Y;
	视图矩阵.M33 = result2.Z;
	视图矩阵.M41 = 向量三维::计算点乘(result3, 摄像机坐标);
	视图矩阵.M42 = 向量三维::计算点乘(result4, 摄像机坐标);
	视图矩阵.M43 = 向量三维::计算点乘(result2, 摄像机坐标);
	视图矩阵.M41 = -视图矩阵.M41;
	视图矩阵.M42 = -视图矩阵.M42;
	视图矩阵.M43 = -视图矩阵.M43;
	return 视图矩阵;
}

矩阵4X4 矩阵4X4::创建正交投影矩阵(float 缩放, float 宽高比, float 近端修剪, float 远端修剪)
{
	float 宽度 = 缩放;
	float 高度 = 缩放 / 宽高比;
	float 左 = -宽度 * 0.5f;
	float 右 = 宽度 * 0.5f;
	float 上 = -高度 * 0.5f;
	float 下 = 高度 * 0.5f;
	float num = 1.0f / (远端修剪 - 近端修剪);
	矩阵4X4 正交投影矩阵 = 单位矩阵();
	正交投影矩阵.M11 = 2.0f / (右 - 左);
	正交投影矩阵.M22 = 2.0f / (上 - 下);
	正交投影矩阵.M33 = num;
	正交投影矩阵.M41 = (左 + 右) / (左 - 右);
	正交投影矩阵.M42 = (上 + 下) / (下 - 上);
	正交投影矩阵.M43 = (0.0f - 近端修剪) * num;
	return 正交投影矩阵;
}

矩阵4X4 矩阵4X4::创建正交投影矩阵_尺寸(float 宽度, float 高度, float 近端修剪, float 远端修剪)
{
	float num3 = 宽度 * 0.5f;
	float num2 = 高度 * 0.5f;
	float 左 = 0 - num3;
	float 右 = num3;
	float 上 = 0 - num2;
	float 下 = num2;
	float num = 1.0f / (远端修剪 - 近端修剪);
	矩阵4X4 正交投影矩阵 = 单位矩阵();
	正交投影矩阵.M11 = 2.0f / (右 - 左);
	正交投影矩阵.M22 = 2.0f / (上 - 下);
	正交投影矩阵.M33 = num;
	正交投影矩阵.M41 = (左 + 右) / (左 - 右);
	正交投影矩阵.M42 = (上 + 下) / (下 - 上);
	正交投影矩阵.M43 = (0.0f - 近端修剪) * num;
	return 正交投影矩阵;
}

矩阵4X4 矩阵4X4::创建自定义透视投影矩阵(float 左, float 右, float 下, float 上, float 近端修剪, float 远端修剪)
{
	float num = 远端修剪 / (远端修剪 - 近端修剪);
	矩阵4X4 透视投影矩阵;
	透视投影矩阵.M11 = 2.0f * 近端修剪 / (右 - 左);
	透视投影矩阵.M22 = 2.0f * 近端修剪 / (上 - 下);
	透视投影矩阵.M31 = (左 + 右) / (左 - 右);
	透视投影矩阵.M32 = (上 + 下) / (下 - 上);
	透视投影矩阵.M33 = num;
	透视投影矩阵.M34 = 1.0f;
	透视投影矩阵.M43 = (0.0f - 近端修剪) * num;
	return 透视投影矩阵;
}

矩阵4X4 矩阵4X4::创建透视投影矩阵(float 宽度, float 高度, float 近端修剪, float 远端修剪)
{
	float num = 宽度 * 0.5f;
	float num2 = 高度 * 0.5f;
	return 创建自定义透视投影矩阵(0.0f - num, num, 0.0f - num2, num2, 近端修剪, 远端修剪);
}

矩阵4X4 矩阵4X4::创建视野透视投影矩阵(float 视锥角度, float 宽高比, float 近端修剪, float 远端修剪)
{
	float num = 1.0f / std::tan(视锥角度 * 0.5f);//视锥角度，相机垂直角度范围
	float num2 = 远端修剪 / (远端修剪 - 近端修剪);//深度映射
	矩阵4X4 透视矩阵;
	透视矩阵.M11 = num / 宽高比;//水平缩放
	透视矩阵.M22 = num;//垂直缩放
	透视矩阵.M33 = num2;//深度映射
	透视矩阵.M34 = 1.0f;//透视除法
	透视矩阵.M43 = (0.0f - num2) * 近端修剪;//深度映射
	return 透视矩阵;
}

矩阵4X4 矩阵4X4::创建缩放矩阵(float x, float y, float z)
{
	矩阵4X4 缩放矩阵 = 单位矩阵();
	缩放矩阵.M11 = x;
	缩放矩阵.M22 = y;
	缩放矩阵.M33 = z;
	return 缩放矩阵;
}

矩阵4X4 矩阵4X4::创建缩放矩阵(向量三维 缩放)
{
	矩阵4X4 缩放矩阵 = 单位矩阵();
	缩放矩阵 = 创建缩放矩阵(缩放.X, 缩放.Y, 缩放.Z);
	return 缩放矩阵;
}

矩阵4X4 矩阵4X4::创建缩放矩阵(float 缩放)
{
	矩阵4X4 缩放矩阵 = 单位矩阵();
	缩放矩阵.M11 = 缩放;
	缩放矩阵.M22 = 缩放;
	缩放矩阵.M33 = 缩放;
	return 缩放矩阵;
}

矩阵4X4 矩阵4X4::创建旋转矩阵X(float 弧度)
{
	矩阵4X4 旋转矩阵;
	float num = std::cos(弧度);
	float num2 = std::sin(弧度);
	旋转矩阵 = 单位矩阵();
	旋转矩阵.M22 = num;
	旋转矩阵.M23 = num2;
	旋转矩阵.M32 = 0.0f - num2;
	旋转矩阵.M33 = num;
	return 旋转矩阵;
}

矩阵4X4 矩阵4X4::创建旋转矩阵Y(float 弧度)
{
	矩阵4X4 旋转矩阵;
	float num = std::cos(弧度);
	float num2 = std::sin(弧度);
	旋转矩阵 = 单位矩阵();
	旋转矩阵.M11 = num;
	旋转矩阵.M13 = 0.0f - num2;
	旋转矩阵.M31 = num2;
	旋转矩阵.M33 = num;
	return 旋转矩阵;
}

矩阵4X4 矩阵4X4::创建旋转矩阵Z(float 弧度)
{
	矩阵4X4 旋转矩阵;
	float num = std::cos(弧度);
	float num2 = std::sin(弧度);
	旋转矩阵 = 单位矩阵();
	旋转矩阵.M11 = num;
	旋转矩阵.M12 = num2;
	旋转矩阵.M21 = 0.0f - num2;
	旋转矩阵.M22 = num;
	return 旋转矩阵;
}


//轴脚旋转


矩阵4X4 矩阵4X4::创建旋转矩阵(向量三维 旋转轴, float 弧度)
{
	矩阵4X4 旋转矩阵;
	float x = 旋转轴.X;
	float y = 旋转轴.Y;
	float z = 旋转轴.Z;
	float num = std::cos(弧度);
	float num2 = std::sin(弧度);
	float num3 = x * x;
	float num4 = y * y;
	float num5 = z * z;
	float num6 = x * y;
	float num7 = x * z;
	float num8 = y * z;
	旋转矩阵 = 单位矩阵();
	旋转矩阵.M11 = num3 + num * (1.0f - num3);
	旋转矩阵.M12 = num6 - num * num6 + num2 * z;
	旋转矩阵.M13 = num7 - num * num7 - num2 * y;
	旋转矩阵.M21 = num6 - num * num6 - num2 * z;
	旋转矩阵.M22 = num4 + num * (1.0f - num4);
	旋转矩阵.M23 = num8 - num * num8 + num2 * x;
	旋转矩阵.M31 = num7 - num * num7 + num2 * y;
	旋转矩阵.M32 = num8 - num * num8 - num2 * x;
	旋转矩阵.M33 = num5 + num * (1.0f - num5);
	return 旋转矩阵;
}

向量三维 矩阵4X4::提取欧拉旋转(矩阵4X4 旋转矩阵)
{
	float pitch, yaw, roll;
	// 提取yaw（偏航角）
	yaw = std::atan2(旋转矩阵.M13, 旋转矩阵.M33);

	// 提取pitch（俯仰角）
	float sinPitch = -旋转矩阵.M23;
	pitch = std::asin(sinPitch);

	// 提取roll（翻滚角）
	float cosPitch = std::cos(pitch);
	//float cosYaw = MathF.Cos(yaw);
	roll = std::atan2(旋转矩阵.M21 / cosPitch, 旋转矩阵.M22 / cosPitch);
	return 向量三维(-pitch, -yaw, -roll);
}

矩阵4X4 矩阵4X4::创建法线矩阵(矩阵4X4 世界矩阵)
{
	矩阵4X4 逆矩阵 = 矩阵4X4::计算逆矩阵(世界矩阵);
	矩阵4X4 转置矩阵 = 矩阵4X4::计算转置矩阵(逆矩阵);
	return 转置矩阵;
}

矩阵4X4 矩阵4X4::创建向量旋转矩阵(向量三维 向量1, 向量三维 向量2)
{
	矩阵4X4 旋转矩阵;
	if (向量三维::计算点乘(向量1, 向量2) >= 1)
	{
		旋转矩阵 = 矩阵4X4::单位矩阵();
	}
	else
	{
		向量三维 originalVector = 向量2;
		float angle = std::acos(向量三维::计算点乘(originalVector, 向量1) / (originalVector.模() * 向量1.模()));
		向量三维 axis = 向量三维::计算单位向量(向量三维::计算叉乘(originalVector, 向量1));
		旋转矩阵 = 矩阵4X4::创建旋转矩阵(axis, angle);
	}
	return 旋转矩阵;
}

矩阵4X4 矩阵4X4::创建平移矩阵(float x, float y, float z)
{
	矩阵4X4 矩阵;
	矩阵 = 单位矩阵();
	矩阵.M41 = x;
	矩阵.M42 = y;
	矩阵.M43 = z;
	return 矩阵;
}

矩阵4X4 矩阵4X4::创建平移矩阵(向量三维 平移)
{
	矩阵4X4 矩阵 = 创建平移矩阵(平移.X, 平移.Y, 平移.Z);
	return 矩阵;
}

矩阵4X4 矩阵4X4::创建变换矩阵2D(float 缩放, float 旋转, 向量二维 平移)
{
	矩阵4X4 矩阵;
	矩阵4X4 m1 = 创建缩放矩阵(缩放, 缩放, 1.0f);
	矩阵4X4 m2 = 创建旋转矩阵Z(旋转);
	矩阵4X4 m3 = 创建平移矩阵(向量三维(平移, 0));
	矩阵 = m1 * m2 * m3;
	return 矩阵;
}

矩阵4X4 矩阵4X4::创建仿射变换矩阵2D(float 缩放, 向量二维 旋转中心, float 旋转, 向量二维 平移)
{
	矩阵4X4 矩阵;
	矩阵4X4 m1, m2, m3, m4, m5;
	m1 = 创建缩放矩阵(缩放, 缩放, 1.0f);
	m2 = 创建平移矩阵(向量三维(-旋转中心, 0));
	m3 = 创建旋转矩阵Z(旋转);
	m4 = 创建平移矩阵(向量三维(旋转中心, 0));
	m5 = 创建平移矩阵(向量三维(平移, 0));
	矩阵 = m1 * m2 * m3 * m4 * m5;
	return 矩阵;
}

矩阵4X4 矩阵4X4::创建仿射变换矩阵2D(向量二维 缩放中心, float 缩放旋转, 向量二维 缩放, 向量二维 旋转中心, float 旋转, 向量二维 平移)
{
	矩阵4X4 矩阵;
	矩阵4X4 m1, m2, m3, m4, m5, m6, m7, m8, m9;
	m1 = 创建平移矩阵(向量三维(-缩放中心, 0));
	m2 = 创建旋转矩阵Z(0.0f - 缩放旋转);
	m3 = 创建缩放矩阵(向量三维(缩放, 0));
	m4 = 创建旋转矩阵Z(缩放旋转);
	m5 = 创建平移矩阵(向量三维(缩放中心, 0));
	m6 = 创建平移矩阵(向量三维(-旋转中心, 0));
	m7 = 创建旋转矩阵Z(旋转);
	m8 = 创建平移矩阵(向量三维(旋转中心, 0));
	m9 = 创建平移矩阵(向量三维(平移, 0));
	矩阵 = m1 * m2 * m3 * m4 * m5 * m6 * m7 * m8 * m9;
	矩阵.M33 = 1.0f;
	矩阵.M44 = 1.0f;
	return 矩阵;
}








