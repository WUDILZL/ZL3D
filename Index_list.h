#pragma once
#include <unordered_map>
#include "Index_data.h"

//�����б�
class Index_list
{
public:
	Index_list();
	~Index_list();

	//key ֵvalue
	std::unordered_map<int, int> �б����;
	// - �������� �б�����
	std::unordered_map<int, std::pair<Index_data, int>> ��ϣ��������;

public:
	Index_data ��ȡ��������(int key);
	bool ����(Index_data ����);
	void ���(Index_data ����);
	void ���();
	std::vector<Index_data> ת�б�();

};

