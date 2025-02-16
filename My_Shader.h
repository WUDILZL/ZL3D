#pragma once
#include <QOpenGLShaderProgram>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "OPenGL_Link.h"
#include "��Ԫ��.h"
#include "RGB.h"

class My_Shader 
{
public:
	My_Shader();
	/*My_Shader(const My_Shader& ����);*/
	~My_Shader();
	//Ψһ����
	GLuint ID;
	QString ������Ϣ;

public:
	void ������ɫ��(QString ����, QString Ƭ��);
	void ������ɫ��()const;
	//������ɫ��
	void use();
	void ����GPU����(const char* ����, int ����)const;
	void ����GPU����(const char* ����, float ����)const;
	void ����GPU����(const char* ����, ������ά ����)const;
	void ����GPU����(const char* ����, ������ά ����)const;
	void ����GPU����(const char* ����, YS_RGB ����)const;
	void ����GPU����(const char* ����, ����4X4 ����)const;
	void ����GPU����(const char* ����, glm::mat4 ����)const;

private:
	//��ɫ��
	QOpenGLShaderProgram* _Shader;
};

