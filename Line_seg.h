#pragma once
#include "������ά.h"

//�߶μ���
class Line_seg
{
public:
	Line_seg();
	Line_seg(std::vector<������ά> ���㼯��);
	~Line_seg();
	std::vector<������ά> �������꼯��;
	std::vector<unsigned int> �����б�;

private:
	bool �պ� = false;
};

