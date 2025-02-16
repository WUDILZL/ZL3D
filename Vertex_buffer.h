#pragma once
#include "OPenGL_Link.h"

//opengl顶点缓冲
class Vertex_buffer
{
public:
	Vertex_buffer();
	~Vertex_buffer();

	void 注册顶点缓冲(std::vector<float> 顶点列表,std::vector<unsigned int>索引列表);
	void 清除顶点缓冲();
public:
	GLuint VAO, VBO, EBO;
	int 索引大小 = 0;
};

