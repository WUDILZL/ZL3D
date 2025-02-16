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

void Vertex_buffer::ע�ᶥ�㻺��(std::vector<float> �����б�, std::vector<unsigned int>�����б�)
{
	������С = �����б�.size();
	OPENGL_EXTRA_FUNCTIONS->glGenVertexArrays(1, &VAO);
	OPENGL_EXTRA_FUNCTIONS->glGenBuffers(1, &VBO);//����һ�����㻺�����
	OPENGL_EXTRA_FUNCTIONS->glGenBuffers(1, &EBO);
	//��
	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(VAO);

	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, VBO);//���涥���������� ���㻺��
	OPENGL_EXTRA_FUNCTIONS->glBufferData(GL_ARRAY_BUFFER, �����б�.size() * sizeof(float), �����б�.data(), GL_STATIC_DRAW);//���仺��������
	//OPENGL_XR_JK->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);//����ָ�����ݸ�ʽ�����͵�ǰ����

	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);//���涥���������� ��������
	OPENGL_EXTRA_FUNCTIONS->glBufferData(GL_ELEMENT_ARRAY_BUFFER, �����б�.size() * sizeof(unsigned int), �����б�.data(), GL_STATIC_DRAW);//���仺��������
	OPENGL_EXTRA_FUNCTIONS->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	OPENGL_EXTRA_FUNCTIONS->glEnableVertexAttribArray(0);

	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	
}

void Vertex_buffer::������㻺��()
{
	if (VAO != -1) OPENGL_EXTRA_FUNCTIONS->glDeleteVertexArrays(1, &VAO);
	if (VBO != -1) OPENGL_EXTRA_FUNCTIONS->glDeleteBuffers(1, &VBO);
	if (EBO != -1) OPENGL_EXTRA_FUNCTIONS->glDeleteBuffers(1, &EBO);
}
