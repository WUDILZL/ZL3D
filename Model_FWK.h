#pragma once
#include <set>
#include "多重计算.h"
#include "RGB.h"
#include "Line_seg.h"
#include "Index_list.h"
#include "Vertex_buffer.h"

//面顶点数据
class Face_vectex_data
{
public:
	Face_vectex_data() {
		坐标 = 法线 = 向量三维(0.0f);
		UV = 向量二维(0.0f);
		颜色 = YS_RGB(0);
	}
	Face_vectex_data(向量三维 z, 向量三维 f, 向量二维 u, YS_RGB y)
	{
		坐标 = z;
		法线 = f;
		UV = u;
		颜色 = y;
	}
	~Face_vectex_data()
	{

	}
	向量三维 坐标;
	向量三维 法线;
	向量二维 UV;
	YS_RGB 颜色;
};

// 顶点索引 法线
struct Vectex_face {
	Vertex_index 顶点索引;
	向量三维 法线;
};

struct 平滑集合 {
	向量三维 法线;
	int 索引;
};

struct 渲染状态 {
	bool 是否渲染 = true;
	bool 渲染线 = true;
	bool 渲染面 = true;
	bool 渲染点 = true;
};

struct 顶点状态 {
	bool 渲染面顶点注册 = false;
	bool 渲染边顶点注册 = false;
	bool 渲染点顶点注册 = false;
};

//立方体
struct ui显示数据
{
	QString 名称;
	bool 选中状态 = false;
	向量三维 尺寸;
	向量三维 分段;

	bool 渲染状态面 = true;
	bool 渲染状态线 = true;
	bool 渲染状态点 = true;

	向量三维 自身坐标;
	向量三维 世界坐标;

};


//所有绘制均采用顺时针
// 模型架构 ,model framework
class Model_FWK
{
public:
	Model_FWK();
	Model_FWK(std::vector<向量三维> _坐标集合, std::vector<向量三维> _法线集合, std::vector<向量二维> _UV集合, std::vector<YS_RGB> _颜色集合, std::vector<Index_data> _索引面集合, std::vector<Index_data> _索引边集合, std::vector<Index_data> _索引点集合);
	~Model_FWK();

public:
	Vertex_buffer _渲染面;
	Vertex_buffer _渲染边;
	Vertex_buffer _渲染点;

	std::vector<向量三维> 三维坐标集合;
	std::vector<向量三维> 三维法线集合;
	std::vector<向量二维> 三维UV集合;
	std::vector<YS_RGB> 三维颜色集合;
	

	std::vector<Index_data> 索引面集合;
	std::vector<Index_data> 索引边集合;
	std::vector<Index_data> 索引点集合;

	std::vector<float> 索引面坐标集合;
	std::vector<float> 索引边坐标集合;
	std::vector<float> 索引点坐标集合;

	std::vector<unsigned int> 索引面;
	std::vector<unsigned int> 索引边;
	std::vector<unsigned int> 索引点;

public:
	
	void 获取渲染面数据();
	void 获取渲染边数据();
	void 获取渲染点数据();
	void 变换坐标(四元数 四元数);
	void 变换坐标(向量三维 向量);
	void 变换坐标(矩阵4X4 矩阵);

	static std::vector<Index_data> 面提取边(std::vector<Index_data> _面合集);
	static std::vector<Index_data> 面提取点(std::vector<Index_data> _面合集);
	static Model_FWK 创建平面(float 宽度, float 高度, int 宽度分段, int 高度分段);
	static Model_FWK 合并模型(std::vector<Model_FWK> 模型列表);
	static void 平滑着色(Model_FWK& 模型, float 角度);
	static Model_FWK 创建面(std::vector<向量三维> _坐标合集);
	static void 优化顶点模型(Model_FWK& 模型, float 公差 = 0.001f);
	static Model_FWK 创建立方体(float 尺寸x, float 尺寸y, float 尺寸z, int 分段x, int 分段y, int 分段z);
	static Model_FWK 创建圆管(float 半径, float 高度, int 旋转分段, int 高度分段, float 起点角度 = 0.0f, float 终点角度 = 360.0f);
	static Model_FWK 创建球体(float 半径, int 分段);
	static Model_FWK 创建半球体(float 半径, int 分段);
	static Model_FWK 创建金字塔(float 尺寸X, float Y, float Z);
	static Model_FWK 创建圆盘(float 内半径, float 外半径, int 圆盘分段, int 旋转分段, float 起点角度 = 0.01f, float 终点角度 = 360.0f);
	static Model_FWK 创建管道(float 内半径, float 外半径, float 高度, int 旋转分段, int 圆盘分段 = 1, int 高度分段 = 1, float 起点角度 = 0.0f, float 终点角度 = 360.0f);
	static Model_FWK 创建线条(std::vector<向量三维> 坐标列表);
	static Model_FWK 创建线条(std::vector<Line_seg> 坐标列表);
	static Model_FWK 创建箭头线(向量三维 起点, 向量三维 终点, float 箭头尺寸);
	static Model_FWK 创建圆环线(float 半径, int 分段);

	Model_FWK operator *(四元数 四元数);
	Model_FWK operator +(向量三维 向量);
	Model_FWK operator -(向量三维 向量);
	Model_FWK operator +(Model_FWK 模型);
	Model_FWK operator *(矩阵4X4 矩阵);

private:
	std::vector<Index_data> 获取三角面集合();
	static bool 是否包含(std::vector<Vertex_index> 数据, Vertex_index 查找);
	static bool 列表添加并查重(std::vector<平滑集合> 集合, 向量三维 法线);
};




