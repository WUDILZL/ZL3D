#include "Index_data.h"

Index_data::Index_data()
{
    ���������� = 0;
    ͳһ��ɫ = YS_RGB(0);
}

Index_data::Index_data(std::vector<Vertex_index> _��������)
{
    �������� = _��������;
    ���������� = 0;
    ͳһ��ɫ = YS_RGB(0);
    ��������������();
}

Index_data::~Index_data()
{
}

Index_data Index_data::operator+(int ƫ��)
{
    return ����ƫ��(ƫ��, ƫ��, ƫ��, ƫ��);
}

void Index_data::���������ϼ�(std::vector<Vertex_index> _��������)
{
    �������� = _��������;
    ���������� = 0;
    ��������������();
}

Index_data Index_data::����ƫ��(int ����ƫ��, int ����ƫ��, int UVƫ��, int ��ɫƫ��)
{
    Index_data ����;
    for (int i = 0; i < ��������.size(); i++)
    {
        Vertex_index ����;
        ����.�������� = ��������[i].�������� + ����ƫ��;
        ����.�������� = ��������[i].�������� + ����ƫ��;
        ����.UV���� = ��������[i].UV���� + UVƫ��;
        ����.��ɫ���� = ��������[i].��ɫ���� + ��ɫƫ��;
        ����.��������.push_back(����);
    }
    ����.ͳһ��ɫ = ͳһ��ɫ;
    ����.��������������();
    return ����;
}

Index_data Index_data::���㷴ת����(Index_data ������)
{
    Index_data ����;
    ����.���������� = ������.����������;
    ����.ͳһ��ɫ = ������.ͳһ��ɫ;

    for (int i = ������.��������.size(); i > 0; i--)
    {
        Vertex_index ����;
        ����.�������� = ������.��������[i - 1].��������;
        ����.�������� = ������.��������[i - 1].��������;
        ����.UV���� = ������.��������[i - 1].UV����;
        ����.��ɫ���� = ������.��������[i - 1].��ɫ����;
        ����.��������.push_back(����);
    }
    return ����;
}

void Index_data::��������������()
{
    /*for (int i = 0; i < ��������.size(); i++)
    {
        ���������� += ��������[i].��������;
    }*/

    std::vector<int> ��������;
    for (int i = 0; i < ��������.size(); i++)
    {
        ��������.push_back((int)��������[i].��������);
    }
    std::sort(��������.begin(), ��������.end());

    // ʹ�� long long ��ֹ�������
    long long hash = 17;
    for (int item : ��������) {
        hash = hash * 999983 + item;
    }
    ���������� = static_cast<int>(hash);
}

Index_data Index_data::��������ת�б�(Vertex_index a)
{
    std::vector<Vertex_index> ��������;
    ��������.push_back(a);
    std::vector<Index_data> ����;
    return Index_data(��������);
}

Index_data Index_data::��������ת�б�(Vertex_index a, Vertex_index b)
{
    std::vector<Vertex_index> ��������;
    ��������.push_back(a);
    ��������.push_back(b);
    std::vector<Index_data> ����;
    return Index_data(��������);
}

Index_data Index_data::��������ת�б�(Vertex_index a, Vertex_index b, Vertex_index c)
{
    std::vector<Vertex_index> ��������;
    ��������.push_back(a);
    ��������.push_back(b);
    ��������.push_back(c);
    std::vector<Index_data> ����;
    return Index_data(��������);
}

Index_data Index_data::��������ת�б�(Vertex_index a, Vertex_index b, Vertex_index c, Vertex_index d)
{
    std::vector<Vertex_index> ��������;
    ��������.push_back(a);
    ��������.push_back(b);
    ��������.push_back(c);
    ��������.push_back(d);
    std::vector<Index_data> ����;
    return Index_data(��������);
}