#include "Line_seg.h"

Line_seg::Line_seg()
{
}

Line_seg::Line_seg(std::vector<������ά> ���㼯��)
{
	�������꼯�� = ���㼯��;
	�����б�.resize(���㼯��.size() * 2 - 2);
    �����б�[0] = 0;
    for (int i = 1; i < �����б�.size(); i++)
    {
        if (i % 2 == 0)
        {
            �����б�[i] = �����б�[i - 1];
        }
        else
        {
            �����б�[i] = �����б�[i - 1] + 1;
        }

    }
}

Line_seg::~Line_seg()
{
}
