#include "Vertex_index.h"

Vertex_index::Vertex_index()
{
    坐标索引 = 法线索引 = UV索引 = 颜色索引 = 0;
}

Vertex_index::Vertex_index(unsigned int 索引)
{
    坐标索引 = 法线索引 = UV索引 = 颜色索引 = 索引;
}

Vertex_index::Vertex_index(unsigned int _坐标索引, unsigned int _法线索引, unsigned int _UV索引, unsigned int _颜色索引)
{
    坐标索引 = _坐标索引;
    法线索引 = _法线索引;
    UV索引 = _UV索引;
    颜色索引 = _颜色索引;
}

Vertex_index::~Vertex_index()
{
}

bool Vertex_index::operator==(Vertex_index 右)
{
    if (坐标索引 == -1 && 法线索引 == -1 && UV索引 == -1 && 颜色索引 == -1 && 右.坐标索引 == -1 && 右.法线索引 == -1 && 右.UV索引 == -1 && 右.颜色索引 == -1) return true;
    else if (坐标索引 == -1 && 法线索引 == -1 && UV索引 == -1 && 颜色索引 == -1 || 右.坐标索引 == -1 && 右.法线索引 == -1 && 右.UV索引 == -1 && 右.颜色索引 == -1) return false;
    //if (坐标索引 == 右.法线索引)return true;
    return false;
}

bool Vertex_index::operator!=(Vertex_index 右)
{
    if (坐标索引 == -1 && 法线索引 == -1 && UV索引 == -1 && 颜色索引 == -1 && 右.坐标索引 == -1 && 右.法线索引 == -1 && 右.UV索引 == -1 && 右.颜色索引 == -1) return true;
    else if (坐标索引 == -1 && 法线索引 == -1 && UV索引 == -1 && 颜色索引 == -1 || 右.坐标索引 == -1 && 右.法线索引 == -1 && 右.UV索引 == -1 && 右.颜色索引 == -1) return false;
    //if (坐标索引 != 右.法线索引)return true;
    return false;
}

Vertex_index Vertex_index::偏移(unsigned int 坐标偏移, unsigned int 法线偏移, unsigned int UV偏移, unsigned int 颜色偏移)
{
    return Vertex_index(坐标索引 + 坐标偏移, 法线索引 + 法线偏移, UV索引 + UV偏移, 颜色索引 + 颜色偏移);
}