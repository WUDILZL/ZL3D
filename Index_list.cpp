#include "Index_list.h"

Index_list::Index_list()
{
}

Index_list::~Index_list()
{
}

Index_data Index_list::��ȡ��������(int key)
{
	int ֵ = �б����[key];
	std::pair<Index_data, int> ������ = ��ϣ��������[ֵ];
	return ������.first;
}

bool Index_list::����(Index_data ����)
{
	if (��ϣ��������.count(����.����������)) return true;
	else return false;
}

void Index_list::���(Index_data ����)
{
	std::pair<Index_data, int> ����(����, (int)�б����.size());
	��ϣ��������.insert(std::make_pair(����.����������, ����));// [����.����������] = ����;
	�б����.insert(std::make_pair((int)�б����.size(), ����.����������));// [�б����.size()] = ����.����������;
}

void Index_list::���()
{
	��ϣ��������.clear();
	�б����.clear();
}

std::vector<Index_data> Index_list::ת�б�()
{
	std::vector<std::pair<Index_data, int>> ����;
	std::vector<Index_data> ���ز���;
	for (auto it = ��ϣ��������.begin(); it != ��ϣ��������.end(); ++it)
	{
		����.push_back(it->second);
	}
	for (int i = 0; i < ����.size(); i++)
	{
		���ز���.push_back(����[i].first);
	}
	return ���ز���;
}
