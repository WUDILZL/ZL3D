#pragma once
#include <iostream>

#include "RGB.h"
#include "矩阵4X4.h"
#include "Vertex_buffer.h"
#include "My_Shader.h"
#include "My_Camera.h"


class Color_shader
{
public:


public:
	static void 渲染面(My_Shader 着色器,Vertex_buffer 索引, 矩阵4X4 物体世界矩阵, YS_RGB 颜色, My_Camera 相机, float 深度偏移 = 0.0f);
	static void 渲染线(My_Shader 着色器, Vertex_buffer 索引, 矩阵4X4 物体世界矩阵, YS_RGB 颜色, My_Camera 相机, float 线条粗细 = 0.01f, float 深度偏移 = 0.0f);
	static void 渲染点(My_Shader 着色器, Vertex_buffer 索引, 矩阵4X4 物体世界矩阵, YS_RGB 颜色, My_Camera 相机, float 点粗细 = 0.01f, float 深度偏移 = 0.0f);

	

};

