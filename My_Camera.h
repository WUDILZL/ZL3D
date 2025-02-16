#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <QString>
#include "Camera_base.h"

//透视相机
class My_Camera : public Camera_base
{
public:
	My_Camera();
	~My_Camera();
	
	
public:
	float 焦距;
	float 视锥角度;
	float 游标距离;
	向量三维 游标坐标;
	QString 名称;

	int 队列索引;

protected:
	virtual void 事件_更新投影矩阵()override;

public:
	void 通知投影矩阵改变();
	void 设置变量_焦距(float value);
	void 设置变量_视锥角度(float value);
	void 设置变量_游标距离(float value);

	static float 焦距转视野角度(float 焦距数据, float 传感器尺寸);
	static float 视野角度转焦距(float 视野角度数据, float 传感器尺寸);

	void 获取鼠标数据(float 滚动值, float x, float y);

private:
	float _焦距;
	float _视锥角度;
	float _游标距离;
};

