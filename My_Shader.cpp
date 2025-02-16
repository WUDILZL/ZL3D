#include "My_Shader.h"

My_Shader::My_Shader()
{
	ID = -1;
	_Shader = new QOpenGLShaderProgram();
}

//My_Shader::My_Shader(const My_Shader& 数据)
//{
//	ID = 数据.ID;
//	_Shader = 数据._Shader;
//	报错信息 = 数据.报错信息;
//}

My_Shader::~My_Shader()
{
	/*if (_Shader)
	{
		delete _Shader;
		_Shader = nullptr;
	}*/
	
}

void My_Shader::载入着色器(QString 顶点, QString 片段)
{
	bool 状态 = _Shader->addShaderFromSourceFile(QOpenGLShader::Vertex, 顶点);
	if (!状态) 报错信息 = _Shader->log();
	状态 = _Shader->addShaderFromSourceFile(QOpenGLShader::Fragment, 片段);
	if (!状态) 报错信息.append(_Shader->log());

	if (_Shader->link())
	{
		ID = _Shader->programId();
	}
	else
	{
		ID = -1;
	}
}

void My_Shader::销毁着色器() const
{
	if (ID != -1)OPENGL_EXTRA_FUNCTIONS->glDeleteProgram(ID);
}

void My_Shader::use()
{
	OPENGL_FUNCTIONS->glUseProgram(ID);
}

void My_Shader::设置GPU变量(const char* 名字, int 数据) const
{
	OPENGL_FUNCTIONS->glUniform1i(OPENGL_FUNCTIONS->glGetUniformLocation(ID, 名字), 数据);
}

void My_Shader::设置GPU变量(const char* 名字, float 数据)const
{
	OPENGL_FUNCTIONS->glUniform1f(OPENGL_FUNCTIONS->glGetUniformLocation(ID, 名字), 数据);
}

void My_Shader::设置GPU变量(const char* 名字, 向量二维 数据)const
{
	glm::vec2 参数 = glm::vec2(0.0f);
	参数.x = 数据.X;
	参数.y = 数据.Y;
	OPENGL_FUNCTIONS->glUniform2fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, 名字), 1, glm::value_ptr(参数));
}

void My_Shader::设置GPU变量(const char* 名字, 向量三维 数据)const
{
	glm::vec3 参数 = glm::vec3(0.0f);
	参数.x = 数据.X;
	参数.y = 数据.Y;
	参数.z = 数据.Z;

	OPENGL_FUNCTIONS->glUniform3fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, 名字), 1, glm::value_ptr(参数));
}

void My_Shader::设置GPU变量(const char* 名字, YS_RGB 数据)const
{
	glm::vec4 参数 = glm::vec4(0.0f);
	参数.x = 数据.r;
	参数.y = 数据.g;
	参数.z = 数据.b;
	参数.w = 数据.a;
	OPENGL_FUNCTIONS->glUniform4fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, 名字), 1, glm::value_ptr(参数));
}

void My_Shader::设置GPU变量(const char* 名字, 矩阵4X4 数据)const
{
	glm::mat4 参数 = glm::mat4(0.0f);

	/*参数 = glm::mat4(数据.M11, 数据.M21, 数据.M31, 数据.M41,
		数据.M12, 数据.M22, 数据.M32, 数据.M42,
		数据.M13, 数据.M23, 数据.M33, 数据.M43,
		数据.M14, 数据.M24, 数据.M34, 数据.M44);*/
	参数 = glm::mat4(数据.M11, 数据.M12, 数据.M13, 数据.M14,
		数据.M21, 数据.M22, 数据.M23, 数据.M24,
		数据.M31, 数据.M32, 数据.M33, 数据.M34,
		数据.M41, 数据.M42, 数据.M43, 数据.M44);
	// projection * view * model * vec4(aPos, 1.0f); 倒置 vec4(aPos, 1.0f) * model * view * projection;
	OPENGL_FUNCTIONS->glUniformMatrix4fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, 名字), 1, GL_TRUE, glm::value_ptr(参数));
	
}

void My_Shader::设置GPU变量(const char* 名字, glm::mat4 数据) const
{
	OPENGL_FUNCTIONS->glUniformMatrix4fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, 名字), 1, GL_FALSE, glm::value_ptr(数据));
}
