#include "Color_shader.h"



void Color_shader::��Ⱦ��(My_Shader ��ɫ��, Vertex_buffer ���㻺��, ����4X4 �����������, YS_RGB ��ɫ, My_Camera ���, float ���ƫ��)
{
	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(���㻺��.VAO);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, ���㻺��.VBO);

	OPENGL_EXTRA_FUNCTIONS->glEnableVertexAttribArray(0);
	OPENGL_EXTRA_FUNCTIONS->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	
	��ɫ��.use();
	��ɫ��.����GPU����("migration", ���ƫ��);
	��ɫ��.����GPU����("view", ���.��ͼ����);
	��ɫ��.����GPU����("model", �����������);
	��ɫ��.����GPU����("projection", ���.ͶӰ����);
	��ɫ��.����GPU����("Colour", ��ɫ);
	GLenum error = OPENGL_EXTRA_FUNCTIONS->glGetError();
	//if (error != GL_NO_ERROR) {
	//	std::cout << "glBindVertexArray error: " << error << std::endl;
	//	// ���Ը��ݴ�������н�һ���Ĵ�����������ϸ�Ĵ�����Ϣ
	//}
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ���㻺��.EBO);
	OPENGL_EXTRA_FUNCTIONS->glDrawElements(GL_TRIANGLES, ���㻺��.������С, GL_UNSIGNED_INT, 0);

	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glDisableVertexAttribArray(0);
}

void Color_shader::��Ⱦ��(My_Shader ��ɫ��, Vertex_buffer ����, ����4X4 �����������, YS_RGB ��ɫ, My_Camera ���, float ������ϸ, float ���ƫ��)
{
	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(����.VAO);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, ����.VBO);
	
	//����ƫ��
	OPENGL_EXTRA_FUNCTIONS->glEnableVertexAttribArray(0);
	OPENGL_EXTRA_FUNCTIONS->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	

	��ɫ��.use();
	��ɫ��.����GPU����("migration", ���ƫ��);
	��ɫ��.����GPU����("view", ���.��ͼ����);
	��ɫ��.����GPU����("model", �����������);
	��ɫ��.����GPU����("projection", ���.ͶӰ����);
	��ɫ��.����GPU����("Colour", ��ɫ);

	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ����.EBO);
	OPENGL_EXTRA_FUNCTIONS->glLineWidth(������ϸ);
	OPENGL_EXTRA_FUNCTIONS->glDrawElements(GL_LINES, ����.������С, GL_UNSIGNED_INT, 0);

	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glDisableVertexAttribArray(0);
}

void Color_shader::��Ⱦ��(My_Shader ��ɫ��, Vertex_buffer ����, ����4X4 �����������, YS_RGB ��ɫ, My_Camera ���, float ���ϸ, float ���ƫ��)
{
	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(����.VAO);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, ����.VBO);
	

	OPENGL_EXTRA_FUNCTIONS->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	OPENGL_EXTRA_FUNCTIONS->glEnableVertexAttribArray(0);

	��ɫ��.use();
	��ɫ��.����GPU����("migration", ���ƫ��);
	��ɫ��.����GPU����("view", ���.��ͼ����);
	��ɫ��.����GPU����("model", �����������);
	��ɫ��.����GPU����("projection", ���.ͶӰ����);
	��ɫ��.����GPU����("Colour", ��ɫ);
	//glPointSize(���ϸ);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, ����.EBO);
	OPENGL_EXTRA_FUNCTIONS->glDrawElements(GL_POINTS, ����.������С, GL_UNSIGNED_INT, 0);

	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glDisableVertexAttribArray(0);
}


