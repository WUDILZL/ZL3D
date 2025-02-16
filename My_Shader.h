#pragma once
#include <QOpenGLShaderProgram>
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>

#include "OPenGL_Link.h"
#include "四元数.h"
#include "RGB.h"

class My_Shader 
{
public:
	My_Shader();
	/*My_Shader(const My_Shader& 数据);*/
	~My_Shader();
	//唯一索引
	GLuint ID;
	QString 报错信息;

public:
	void 载入着色器(QString 顶点, QString 片段);
	void 销毁着色器()const;
	//激活着色器
	void use();
	void 设置GPU变量(const char* 名字, int 数据)const;
	void 设置GPU变量(const char* 名字, float 数据)const;
	void 设置GPU变量(const char* 名字, 向量二维 数据)const;
	void 设置GPU变量(const char* 名字, 向量三维 数据)const;
	void 设置GPU变量(const char* 名字, YS_RGB 数据)const;
	void 设置GPU变量(const char* 名字, 矩阵4X4 数据)const;
	void 设置GPU变量(const char* 名字, glm::mat4 数据)const;

private:
	//着色器
	QOpenGLShaderProgram* _Shader;
};

