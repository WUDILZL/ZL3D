#include "Vertex_index.h"

Vertex_index::Vertex_index()
{
    �������� = �������� = UV���� = ��ɫ���� = 0;
}

Vertex_index::Vertex_index(unsigned int ����)
{
    �������� = �������� = UV���� = ��ɫ���� = ����;
}

Vertex_index::Vertex_index(unsigned int _��������, unsigned int _��������, unsigned int _UV����, unsigned int _��ɫ����)
{
    �������� = _��������;
    �������� = _��������;
    UV���� = _UV����;
    ��ɫ���� = _��ɫ����;
}

Vertex_index::~Vertex_index()
{
}

bool Vertex_index::operator==(Vertex_index ��)
{
    if (�������� == -1 && �������� == -1 && UV���� == -1 && ��ɫ���� == -1 && ��.�������� == -1 && ��.�������� == -1 && ��.UV���� == -1 && ��.��ɫ���� == -1) return true;
    else if (�������� == -1 && �������� == -1 && UV���� == -1 && ��ɫ���� == -1 || ��.�������� == -1 && ��.�������� == -1 && ��.UV���� == -1 && ��.��ɫ���� == -1) return false;
    //if (�������� == ��.��������)return true;
    return false;
}

bool Vertex_index::operator!=(Vertex_index ��)
{
    if (�������� == -1 && �������� == -1 && UV���� == -1 && ��ɫ���� == -1 && ��.�������� == -1 && ��.�������� == -1 && ��.UV���� == -1 && ��.��ɫ���� == -1) return true;
    else if (�������� == -1 && �������� == -1 && UV���� == -1 && ��ɫ���� == -1 || ��.�������� == -1 && ��.�������� == -1 && ��.UV���� == -1 && ��.��ɫ���� == -1) return false;
    //if (�������� != ��.��������)return true;
    return false;
}

Vertex_index Vertex_index::ƫ��(unsigned int ����ƫ��, unsigned int ����ƫ��, unsigned int UVƫ��, unsigned int ��ɫƫ��)
{
    return Vertex_index(�������� + ����ƫ��, �������� + ����ƫ��, UV���� + UVƫ��, ��ɫ���� + ��ɫƫ��);
}