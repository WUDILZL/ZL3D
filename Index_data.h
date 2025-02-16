#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <vector>
#include <algorithm>
#include "RGB.h"
#include "Vertex_index.h"

//索引数据
class Index_data
{
public:
	Index_data();
	Index_data(std::vector<Vertex_index> _索引集合);
	~Index_data();
	//每次在索引集合添加数都应该更新索引集合
	std::vector<Vertex_index> 索引集合;
	YS_RGB 统一着色;
	//对应哈希值 
	int 坐标索引和;

	Index_data operator + (int 偏移);

public:
	void 更新索引合集(std::vector<Vertex_index> _索引集合);
	Index_data 索引偏移(int 坐标偏移, int 法线偏移, int UV偏移, int 颜色偏移);
	static Index_data 计算反转索引(Index_data 旧数据);
	void 更新坐标索引和();

	static Index_data 顶点索引转列表(Vertex_index a);
	static Index_data 顶点索引转列表(Vertex_index a, Vertex_index b);
	static Index_data 顶点索引转列表(Vertex_index a, Vertex_index b, Vertex_index c);
	static Index_data 顶点索引转列表(Vertex_index a, Vertex_index b, Vertex_index c, Vertex_index d);
};