#pragma once
#include "Working_plane.h"
#include "Cube.h"

struct ģ�Ͷ��� {
	std::vector<Working_plane> ����ƽ�����;
	std::vector<My_Camera> ͸���������;
	std::vector<Cube> ���������;
};


class Queue
{
public:

	static void ����ע�����(ģ�Ͷ���& ע���б�);
	static void �������ٶ���(ģ�Ͷ���& ����);
	static void ��Ⱦ����(ģ�Ͷ���& ��Ⱦ, My_Shader ��ɫ��);
	static void ���ݸ��¶���(ģ�Ͷ���& ģ��);

};

