#include "Working_plane.h"

Working_plane::Working_plane()
{
	选中 = false;
	是否渲染 = true;
	队列索引 = 0;
	名称 = QString::fromLocal8Bit("工作平面");
	std::vector<Line_seg> 线集合;
	int 尺寸A = 5;
	for (int i = -尺寸A; i <= 尺寸A; i++)
	{
		std::vector<向量三维> 线段;
		线段.push_back(向量三维(i, 0, -尺寸A));
		线段.push_back(向量三维(i, 0, 尺寸A));

		线集合.push_back(Line_seg(线段));
		线段.clear();

		线段.push_back(向量三维(-尺寸A, 0, i));
		线段.push_back(向量三维(尺寸A, 0, i));

		线集合.push_back(Line_seg(线段));
	}
	网络模型A = Model_FWK::创建线条(线集合);
	线集合.clear();

	尺寸A = 50;
	for (int i = -尺寸A; i <= 尺寸A; i++)
	{
		std::vector<向量三维> 线段;
		线段.push_back(向量三维(i, 0, -尺寸A));
		线段.push_back(向量三维(i, 0, 尺寸A));

		线集合.push_back(Line_seg(线段));
		线段.clear();

		线段.push_back(向量三维(-尺寸A, 0, i));
		线段.push_back(向量三维(尺寸A, 0, i));

		线集合.push_back(Line_seg(线段));
	}
	网络模型B = Model_FWK::创建线条(线集合);
	线集合.clear();

	float 尺寸2 = 5.0f;
	float 箭头尺寸 = 0.1f;
	X轴模型 = Model_FWK::创建箭头线(向量三维(-尺寸2, 0, 0), 向量三维(尺寸2, 0, 0), 箭头尺寸);

	std::vector<向量三维> 列表数据;
	列表数据.push_back(向量三维(0, 尺寸2, 0));
	列表数据.push_back(向量三维(0, -尺寸2, 0));
	线集合.push_back(列表数据);
	列表数据.clear();

	列表数据.push_back(向量三维(0, 尺寸2, 0));
	列表数据.push_back(向量三维(箭头尺寸, 尺寸2 - 箭头尺寸, 0));
	线集合.push_back(列表数据);
	列表数据.clear();

	列表数据.push_back(向量三维(0, 尺寸2, 0));
	列表数据.push_back(向量三维(-箭头尺寸, 尺寸2 - 箭头尺寸, 0));
	线集合.push_back(列表数据);
	列表数据.clear();

	Y轴模型 = Model_FWK::创建线条(线集合);
	线集合.clear();

	列表数据.push_back(向量三维(0, 0, 尺寸2));
	列表数据.push_back(向量三维(0, 0, -尺寸2));
	线集合.push_back(列表数据);
	列表数据.clear();

	列表数据.push_back(向量三维(0, 0, 尺寸2));
	列表数据.push_back(向量三维(箭头尺寸, 0, 尺寸2 - 箭头尺寸));
	线集合.push_back(列表数据);
	列表数据.clear();

	列表数据.push_back(向量三维(0, 0, 尺寸2));
	列表数据.push_back(向量三维(-箭头尺寸, 0, 尺寸2 - 箭头尺寸));
	线集合.push_back(列表数据);
	列表数据.clear();

	Z轴模型 = Model_FWK::创建线条(线集合);

	网络模型A.获取渲染边数据();
	网络模型B.获取渲染边数据();
	X轴模型.获取渲染边数据();
	Y轴模型.获取渲染边数据();
	Z轴模型.获取渲染边数据();
}

Working_plane::~Working_plane()
{
}

void Working_plane::注册顶点缓冲()
{
	网络模型A._渲染边.注册顶点缓冲(网络模型A.索引边坐标集合, 网络模型A.索引边);
	网络模型B._渲染边.注册顶点缓冲(网络模型B.索引边坐标集合, 网络模型B.索引边);
	X轴模型._渲染边.注册顶点缓冲(X轴模型.索引边坐标集合, X轴模型.索引边);
	Y轴模型._渲染边.注册顶点缓冲(Y轴模型.索引边坐标集合, Y轴模型.索引边);
	Z轴模型._渲染边.注册顶点缓冲(Z轴模型.索引边坐标集合, Z轴模型.索引边);
}

void Working_plane::渲染(My_Shader 着色器, My_Camera 相机)
{
	if (是否渲染)
	{
		Color_shader::渲染线(着色器, 网络模型A._渲染边, 矩阵4X4::创建缩放矩阵(缩放 * 10) * 世界矩阵, YS_RGB(1, 1, 1, 0.5f), 相机, 1.0f, 0.1f);
		Color_shader::渲染线(着色器, 网络模型B._渲染边, 矩阵4X4::创建缩放矩阵(缩放 * 1) * 世界矩阵, YS_RGB(1, 1, 1, 0.3f), 相机, 1.0f, 0.1f);
		Color_shader::渲染线(着色器, X轴模型._渲染边, 矩阵4X4::单位矩阵(), YS_RGB(1, 0, 0), 相机, 1.0f);
		Color_shader::渲染线(着色器, Y轴模型._渲染边, 矩阵4X4::单位矩阵(), YS_RGB(0, 1, 0), 相机, 1.0f);
		Color_shader::渲染线(着色器, Z轴模型._渲染边, 矩阵4X4::单位矩阵(), YS_RGB(0, 0, 1), 相机, 1.0f);
	}
}

void Working_plane::销毁顶点缓冲()
{
	网络模型A._渲染边.清除顶点缓冲();
	网络模型B._渲染边.清除顶点缓冲();
	X轴模型._渲染边.清除顶点缓冲();
	Y轴模型._渲染边.清除顶点缓冲();
	Z轴模型._渲染边.清除顶点缓冲();
}


