#pragma once
#include <iostream>

#include "RGB.h"
#include "����4X4.h"
#include "Vertex_buffer.h"
#include "My_Shader.h"
#include "My_Camera.h"


class Color_shader
{
public:


public:
	static void ��Ⱦ��(My_Shader ��ɫ��,Vertex_buffer ����, ����4X4 �����������, YS_RGB ��ɫ, My_Camera ���, float ���ƫ�� = 0.0f);
	static void ��Ⱦ��(My_Shader ��ɫ��, Vertex_buffer ����, ����4X4 �����������, YS_RGB ��ɫ, My_Camera ���, float ������ϸ = 0.01f, float ���ƫ�� = 0.0f);
	static void ��Ⱦ��(My_Shader ��ɫ��, Vertex_buffer ����, ����4X4 �����������, YS_RGB ��ɫ, My_Camera ���, float ���ϸ = 0.01f, float ���ƫ�� = 0.0f);

	

};

