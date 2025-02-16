#include "Index_list.h"

Index_list::Index_list()
{
}

Index_list::~Index_list()
{
}

Index_data Index_list::获取索引数据(int key)
{
	int 值 = 列表访问[key];
	std::pair<Index_data, int> 总数据 = 哈希索引数据[值];
	return 总数据.first;
}

bool Index_list::查找(Index_data 数据)
{
	if (哈希索引数据.count(数据.坐标索引和)) return true;
	else return false;
}

void Index_list::添加(Index_data 数据)
{
	std::pair<Index_data, int> 参数(数据, (int)列表访问.size());
	哈希索引数据.insert(std::make_pair(数据.坐标索引和, 参数));// [数据.坐标索引和] = 参数;
	列表访问.insert(std::make_pair((int)列表访问.size(), 数据.坐标索引和));// [列表访问.size()] = 数据.坐标索引和;
}

void Index_list::清空()
{
	哈希索引数据.clear();
	列表访问.clear();
}

std::vector<Index_data> Index_list::转列表()
{
	std::vector<std::pair<Index_data, int>> 数据;
	std::vector<Index_data> 返回参数;
	for (auto it = 哈希索引数据.begin(); it != 哈希索引数据.end(); ++it)
	{
		数据.push_back(it->second);
	}
	for (int i = 0; i < 数据.size(); i++)
	{
		返回参数.push_back(数据[i].first);
	}
	return 返回参数;
}
