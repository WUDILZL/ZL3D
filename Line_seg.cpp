#include "Line_seg.h"

Line_seg::Line_seg()
{
}

Line_seg::Line_seg(std::vector<向量三维> 顶点集合)
{
	顶点坐标集合 = 顶点集合;
	索引列表.resize(顶点集合.size() * 2 - 2);
    索引列表[0] = 0;
    for (int i = 1; i < 索引列表.size(); i++)
    {
        if (i % 2 == 0)
        {
            索引列表[i] = 索引列表[i - 1];
        }
        else
        {
            索引列表[i] = 索引列表[i - 1] + 1;
        }

    }
}

Line_seg::~Line_seg()
{
}
