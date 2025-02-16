#pragma once
#include "向量三维.h"

//线段集合
class Line_seg
{
public:
	Line_seg();
	Line_seg(std::vector<向量三维> 顶点集合);
	~Line_seg();
	std::vector<向量三维> 顶点坐标集合;
	std::vector<unsigned int> 索引列表;

private:
	bool 闭合 = false;
};

