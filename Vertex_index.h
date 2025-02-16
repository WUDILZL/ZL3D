#pragma once

//顶点索引
class Vertex_index
{
public:
	Vertex_index();
	Vertex_index(unsigned int 索引);
	Vertex_index(unsigned int _坐标索引, unsigned int _法线索引, unsigned int _UV索引, unsigned int _颜色索引);
	~Vertex_index();

	unsigned int 坐标索引, 法线索引, UV索引, 颜色索引;
public:
	bool operator ==(Vertex_index 右);
	bool operator !=(Vertex_index 右);

public:
	Vertex_index 偏移(unsigned int 坐标偏移, unsigned int 法线偏移, unsigned int UV偏移, unsigned int 颜色偏移);

};