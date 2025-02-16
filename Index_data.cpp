#include "Index_data.h"

Index_data::Index_data()
{
    坐标索引和 = 0;
    统一着色 = YS_RGB(0);
}

Index_data::Index_data(std::vector<Vertex_index> _索引集合)
{
    索引集合 = _索引集合;
    坐标索引和 = 0;
    统一着色 = YS_RGB(0);
    更新坐标索引和();
}

Index_data::~Index_data()
{
}

Index_data Index_data::operator+(int 偏移)
{
    return 索引偏移(偏移, 偏移, 偏移, 偏移);
}

void Index_data::更新索引合集(std::vector<Vertex_index> _索引集合)
{
    索引集合 = _索引集合;
    坐标索引和 = 0;
    更新坐标索引和();
}

Index_data Index_data::索引偏移(int 坐标偏移, int 法线偏移, int UV偏移, int 颜色偏移)
{
    Index_data 新面;
    for (int i = 0; i < 索引集合.size(); i++)
    {
        Vertex_index 数据;
        数据.坐标索引 = 索引集合[i].坐标索引 + 坐标偏移;
        数据.法线索引 = 索引集合[i].法线索引 + 法线偏移;
        数据.UV索引 = 索引集合[i].UV索引 + UV偏移;
        数据.颜色索引 = 索引集合[i].颜色索引 + 颜色偏移;
        新面.索引集合.push_back(数据);
    }
    新面.统一着色 = 统一着色;
    新面.更新坐标索引和();
    return 新面;
}

Index_data Index_data::计算反转索引(Index_data 旧数据)
{
    Index_data 数据;
    数据.坐标索引和 = 旧数据.坐标索引和;
    数据.统一着色 = 旧数据.统一着色;

    for (int i = 旧数据.索引集合.size(); i > 0; i--)
    {
        Vertex_index 参数;
        参数.坐标索引 = 旧数据.索引集合[i - 1].坐标索引;
        参数.法线索引 = 旧数据.索引集合[i - 1].法线索引;
        参数.UV索引 = 旧数据.索引集合[i - 1].UV索引;
        参数.颜色索引 = 旧数据.索引集合[i - 1].颜色索引;
        数据.索引集合.push_back(参数);
    }
    return 数据;
}

void Index_data::更新坐标索引和()
{
    /*for (int i = 0; i < 索引集合.size(); i++)
    {
        坐标索引和 += 索引集合[i].坐标索引;
    }*/

    std::vector<int> 索引排序;
    for (int i = 0; i < 索引集合.size(); i++)
    {
        索引排序.push_back((int)索引集合[i].坐标索引);
    }
    std::sort(索引排序.begin(), 索引排序.end());

    // 使用 long long 防止算术溢出
    long long hash = 17;
    for (int item : 索引排序) {
        hash = hash * 999983 + item;
    }
    坐标索引和 = static_cast<int>(hash);
}

Index_data Index_data::顶点索引转列表(Vertex_index a)
{
    std::vector<Vertex_index> 顶点数据;
    顶点数据.push_back(a);
    std::vector<Index_data> 数据;
    return Index_data(顶点数据);
}

Index_data Index_data::顶点索引转列表(Vertex_index a, Vertex_index b)
{
    std::vector<Vertex_index> 顶点数据;
    顶点数据.push_back(a);
    顶点数据.push_back(b);
    std::vector<Index_data> 数据;
    return Index_data(顶点数据);
}

Index_data Index_data::顶点索引转列表(Vertex_index a, Vertex_index b, Vertex_index c)
{
    std::vector<Vertex_index> 顶点数据;
    顶点数据.push_back(a);
    顶点数据.push_back(b);
    顶点数据.push_back(c);
    std::vector<Index_data> 数据;
    return Index_data(顶点数据);
}

Index_data Index_data::顶点索引转列表(Vertex_index a, Vertex_index b, Vertex_index c, Vertex_index d)
{
    std::vector<Vertex_index> 顶点数据;
    顶点数据.push_back(a);
    顶点数据.push_back(b);
    顶点数据.push_back(c);
    顶点数据.push_back(d);
    std::vector<Index_data> 数据;
    return Index_data(顶点数据);
}