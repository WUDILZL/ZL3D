#include "My_Shader.h"

My_Shader::My_Shader()
{
	ID = -1;
	_Shader = new QOpenGLShaderProgram();
}

//My_Shader::My_Shader(const My_Shader& ����)
//{
//	ID = ����.ID;
//	_Shader = ����._Shader;
//	������Ϣ = ����.������Ϣ;
//}

My_Shader::~My_Shader()
{
	/*if (_Shader)
	{
		delete _Shader;
		_Shader = nullptr;
	}*/
	
}

void My_Shader::������ɫ��(QString ����, QString Ƭ��)
{
	bool ״̬ = _Shader->addShaderFromSourceFile(QOpenGLShader::Vertex, ����);
	if (!״̬) ������Ϣ = _Shader->log();
	״̬ = _Shader->addShaderFromSourceFile(QOpenGLShader::Fragment, Ƭ��);
	if (!״̬) ������Ϣ.append(_Shader->log());

	if (_Shader->link())
	{
		ID = _Shader->programId();
	}
	else
	{
		ID = -1;
	}
}

void My_Shader::������ɫ��() const
{
	if (ID != -1)OPENGL_EXTRA_FUNCTIONS->glDeleteProgram(ID);
}

void My_Shader::use()
{
	OPENGL_FUNCTIONS->glUseProgram(ID);
}

void My_Shader::����GPU����(const char* ����, int ����) const
{
	OPENGL_FUNCTIONS->glUniform1i(OPENGL_FUNCTIONS->glGetUniformLocation(ID, ����), ����);
}

void My_Shader::����GPU����(const char* ����, float ����)const
{
	OPENGL_FUNCTIONS->glUniform1f(OPENGL_FUNCTIONS->glGetUniformLocation(ID, ����), ����);
}

void My_Shader::����GPU����(const char* ����, ������ά ����)const
{
	glm::vec2 ���� = glm::vec2(0.0f);
	����.x = ����.X;
	����.y = ����.Y;
	OPENGL_FUNCTIONS->glUniform2fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, ����), 1, glm::value_ptr(����));
}

void My_Shader::����GPU����(const char* ����, ������ά ����)const
{
	glm::vec3 ���� = glm::vec3(0.0f);
	����.x = ����.X;
	����.y = ����.Y;
	����.z = ����.Z;

	OPENGL_FUNCTIONS->glUniform3fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, ����), 1, glm::value_ptr(����));
}

void My_Shader::����GPU����(const char* ����, YS_RGB ����)const
{
	glm::vec4 ���� = glm::vec4(0.0f);
	����.x = ����.r;
	����.y = ����.g;
	����.z = ����.b;
	����.w = ����.a;
	OPENGL_FUNCTIONS->glUniform4fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, ����), 1, glm::value_ptr(����));
}

void My_Shader::����GPU����(const char* ����, ����4X4 ����)const
{
	glm::mat4 ���� = glm::mat4(0.0f);

	/*���� = glm::mat4(����.M11, ����.M21, ����.M31, ����.M41,
		����.M12, ����.M22, ����.M32, ����.M42,
		����.M13, ����.M23, ����.M33, ����.M43,
		����.M14, ����.M24, ����.M34, ����.M44);*/
	���� = glm::mat4(����.M11, ����.M12, ����.M13, ����.M14,
		����.M21, ����.M22, ����.M23, ����.M24,
		����.M31, ����.M32, ����.M33, ����.M34,
		����.M41, ����.M42, ����.M43, ����.M44);
	// projection * view * model * vec4(aPos, 1.0f); ���� vec4(aPos, 1.0f) * model * view * projection;
	OPENGL_FUNCTIONS->glUniformMatrix4fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, ����), 1, GL_TRUE, glm::value_ptr(����));
	
}

void My_Shader::����GPU����(const char* ����, glm::mat4 ����) const
{
	OPENGL_FUNCTIONS->glUniformMatrix4fv(OPENGL_FUNCTIONS->glGetUniformLocation(ID, ����), 1, GL_FALSE, glm::value_ptr(����));
}
