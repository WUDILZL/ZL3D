#pragma once
#include "Working_plane.h"
#include "Cube.h"

struct 模型队列 {
	std::vector<Working_plane> 工作平面队列;
	std::vector<My_Camera> 透视相机队列;
	std::vector<Cube> 立方体队列;
};


class Queue
{
public:

	static void 顶点注册队列(模型队列& 注册列表);
	static void 数据销毁队列(模型队列& 销毁);
	static void 渲染队列(模型队列& 渲染, My_Shader 着色器);
	static void 数据更新队列(模型队列& 模型);

};

