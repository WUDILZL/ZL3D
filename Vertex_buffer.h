#pragma once
#include "OPenGL_Link.h"

//opengl���㻺��
class Vertex_buffer
{
public:
	Vertex_buffer();
	~Vertex_buffer();

	void ע�ᶥ�㻺��(std::vector<float> �����б�,std::vector<unsigned int>�����б�);
	void ������㻺��();
public:
	GLuint VAO, VBO, EBO;
	int ������С = 0;
};

