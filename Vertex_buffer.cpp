#include "Vertex_buffer.h"

Vertex_buffer::Vertex_buffer()
{
	VAO = VBO = EBO = -1;

}

Vertex_buffer::~Vertex_buffer()
{
	/*if (VAO != -1) OPENGL_EXTRA_FUNCTIONS->glDeleteVertexArrays(1, &VAO);
	if (VBO != -1) OPENGL_EXTRA_FUNCTIONS->glDeleteBuffers(1, &VBO);
	if (EBO != -1) OPENGL_EXTRA_FUNCTIONS->glDeleteBuffers(1, &EBO);*/
}

void Vertex_buffer::注册顶点缓冲(std::vector<float> 顶点列表, std::vector<unsigned int>索引列表)
{
	索引大小 = 索引列表.size();
	OPENGL_EXTRA_FUNCTIONS->glGenVertexArrays(1, &VAO);
	OPENGL_EXTRA_FUNCTIONS->glGenBuffers(1, &VBO);//创建一个顶点缓冲对象
	OPENGL_EXTRA_FUNCTIONS->glGenBuffers(1, &EBO);
	//绑定
	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(VAO);

	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, VBO);//储存顶点数据类型 顶点缓冲
	OPENGL_EXTRA_FUNCTIONS->glBufferData(GL_ARRAY_BUFFER, 顶点列表.size() * sizeof(float), 顶点列表.data(), GL_STATIC_DRAW);//分配缓冲区对象
	//OPENGL_XR_JK->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//根据指定数据格式，解释当前数据

	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);//储存顶点数据类型 索引缓冲
	OPENGL_EXTRA_FUNCTIONS->glBufferData(GL_ELEMENT_ARRAY_BUFFER, 索引列表.size() * sizeof(unsigned int), 索引列表.data(), GL_STATIC_DRAW);//分配缓冲区对象
	OPENGL_EXTRA_FUNCTIONS->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	OPENGL_EXTRA_FUNCTIONS->glEnableVertexAttribArray(0);

	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
}

void Vertex_buffer::清除顶点缓冲()
{
	if (VAO != -1) OPENGL_EXTRA_FUNCTIONS->glDeleteVertexArrays(1, &VAO);
	if (VBO != -1) OPENGL_EXTRA_FUNCTIONS->glDeleteBuffers(1, &VBO);
	if (EBO != -1) OPENGL_EXTRA_FUNCTIONS->glDeleteBuffers(1, &EBO);
}
