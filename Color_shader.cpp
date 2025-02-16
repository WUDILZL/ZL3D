#include "Color_shader.h"



void Color_shader::渲染面(My_Shader 着色器, Vertex_buffer 顶点缓冲, 矩阵4X4 物体世界矩阵, YS_RGB 颜色, My_Camera 相机, float 深度偏移)
{
	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(顶点缓冲.VAO);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 顶点缓冲.VBO);

	OPENGL_EXTRA_FUNCTIONS->glEnableVertexAttribArray(0);
	OPENGL_EXTRA_FUNCTIONS->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	
	着色器.use();
	着色器.设置GPU变量("migration", 深度偏移);
	着色器.设置GPU变量("view", 相机.视图矩阵);
	着色器.设置GPU变量("model", 物体世界矩阵);
	着色器.设置GPU变量("projection", 相机.投影矩阵);
	着色器.设置GPU变量("Colour", 颜色);
	GLenum error = OPENGL_EXTRA_FUNCTIONS->glGetError();
	//if (error != GL_NO_ERROR) {
	//	std::cout << "glBindVertexArray error: " << error << std::endl;
	//	// 可以根据错误码进行进一步的处理或输出更详细的错误信息
	//}
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 顶点缓冲.EBO);
	OPENGL_EXTRA_FUNCTIONS->glDrawElements(GL_TRIANGLES, 顶点缓冲.索引大小, GL_UNSIGNED_INT, 0);

	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glDisableVertexAttribArray(0);
}

void Color_shader::渲染线(My_Shader 着色器, Vertex_buffer 索引, 矩阵4X4 物体世界矩阵, YS_RGB 颜色, My_Camera 相机, float 线条粗细, float 深度偏移)
{
	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(索引.VAO);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 索引.VBO);
	
	//顶点偏移
	OPENGL_EXTRA_FUNCTIONS->glEnableVertexAttribArray(0);
	OPENGL_EXTRA_FUNCTIONS->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	

	着色器.use();
	着色器.设置GPU变量("migration", 深度偏移);
	着色器.设置GPU变量("view", 相机.视图矩阵);
	着色器.设置GPU变量("model", 物体世界矩阵);
	着色器.设置GPU变量("projection", 相机.投影矩阵);
	着色器.设置GPU变量("Colour", 颜色);

	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 索引.EBO);
	OPENGL_EXTRA_FUNCTIONS->glLineWidth(线条粗细);
	OPENGL_EXTRA_FUNCTIONS->glDrawElements(GL_LINES, 索引.索引大小, GL_UNSIGNED_INT, 0);

	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glDisableVertexAttribArray(0);
}

void Color_shader::渲染点(My_Shader 着色器, Vertex_buffer 索引, 矩阵4X4 物体世界矩阵, YS_RGB 颜色, My_Camera 相机, float 点粗细, float 深度偏移)
{
	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(索引.VAO);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 索引.VBO);
	

	OPENGL_EXTRA_FUNCTIONS->glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
	OPENGL_EXTRA_FUNCTIONS->glEnableVertexAttribArray(0);

	着色器.use();
	着色器.设置GPU变量("migration", 深度偏移);
	着色器.设置GPU变量("view", 相机.视图矩阵);
	着色器.设置GPU变量("model", 物体世界矩阵);
	着色器.设置GPU变量("projection", 相机.投影矩阵);
	着色器.设置GPU变量("Colour", 颜色);
	//glPointSize(点粗细);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 索引.EBO);
	OPENGL_EXTRA_FUNCTIONS->glDrawElements(GL_POINTS, 索引.索引大小, GL_UNSIGNED_INT, 0);

	OPENGL_EXTRA_FUNCTIONS->glBindVertexArray(0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
	OPENGL_EXTRA_FUNCTIONS->glDisableVertexAttribArray(0);
}


