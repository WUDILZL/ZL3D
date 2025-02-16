#pragma once
#include <unordered_map>
#include "Index_data.h"

//索引列表
class Index_list
{
public:
	Index_list();
	~Index_list();

	//key 值value
	std::unordered_map<int, int> 列表访问;
	// - 索引数据 列表索引
	std::unordered_map<int, std::pair<Index_data, int>> 哈希索引数据;

public:
	Index_data 获取索引数据(int key);
	bool 查找(Index_data 数据);
	void 添加(Index_data 数据);
	void 清空();
	std::vector<Index_data> 转列表();

};

