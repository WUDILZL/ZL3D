#pragma once
#include <vector>

#include "矩阵4X4.h"
class 包围盒
{
public:
	包围盒(); 
	包围盒(std::vector<向量三维> 顶点集合);
	包围盒(向量三维 _最大值, 向量三维 _最小值);
	~包围盒();
	向量三维 最大值, 最小值, 尺寸, 中点;

public:
	std::vector<向量三维> 获取顶点();
	static std::vector<包围盒> 拆分包围盒(包围盒 _包围盒);
	static 包围盒 修改包围盒(包围盒 _包围盒, 向量三维 修改值);
	static bool 判断点在包围盒中(包围盒 _包围盒, 向量三维 顶点);
	static bool 判断点集合包围盒中(包围盒 _包围盒, std::vector<向量三维> 顶点集合);

	包围盒 operator +(向量三维 向量);
	包围盒 operator *(向量三维 向量);
	包围盒 operator *(矩阵4X4 向量);
};

