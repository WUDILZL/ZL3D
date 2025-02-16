#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <vector>
#include <algorithm>
#include "RGB.h"
#include "Vertex_index.h"

//��������
class Index_data
{
public:
	Index_data();
	Index_data(std::vector<Vertex_index> _��������);
	~Index_data();
	//ÿ�������������������Ӧ�ø�����������
	std::vector<Vertex_index> ��������;
	YS_RGB ͳһ��ɫ;
	//��Ӧ��ϣֵ 
	int ����������;

	Index_data operator + (int ƫ��);

public:
	void ���������ϼ�(std::vector<Vertex_index> _��������);
	Index_data ����ƫ��(int ����ƫ��, int ����ƫ��, int UVƫ��, int ��ɫƫ��);
	static Index_data ���㷴ת����(Index_data ������);
	void ��������������();

	static Index_data ��������ת�б�(Vertex_index a);
	static Index_data ��������ת�б�(Vertex_index a, Vertex_index b);
	static Index_data ��������ת�б�(Vertex_index a, Vertex_index b, Vertex_index c);
	static Index_data ��������ת�б�(Vertex_index a, Vertex_index b, Vertex_index c, Vertex_index d);
};