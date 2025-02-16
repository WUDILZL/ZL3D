#include "Model_FWK.h"

Model_FWK::Model_FWK()
{
    _��Ⱦ�� = Vertex_buffer();
    _��Ⱦ�� = Vertex_buffer();
    _��Ⱦ�� = Vertex_buffer();
}

Model_FWK::Model_FWK(std::vector<������ά> _���꼯��, std::vector<������ά> _���߼���, std::vector<������ά> _UV����, std::vector<YS_RGB> _��ɫ����, std::vector<Index_data> _�����漯��, std::vector<Index_data> _�����߼���, std::vector<Index_data> _�����㼯��)
{
    ��ά���꼯�� = _���꼯��;
    ��ά���߼��� = _���߼���;
    ��άUV���� = _UV����;
    ��ά��ɫ���� = _��ɫ����;
    �����漯�� = _�����漯��;
    �����߼��� = _�����߼���;
    �����㼯�� = _�����㼯��;
}

Model_FWK::~Model_FWK()
{
}



void Model_FWK::��ȡ��Ⱦ������()
{
    std::vector<Index_data> ��ȡ��Ⱦ���������� = ��ȡ�����漯��();
    std::vector<Face_vectex_data> �涥������;
    std::vector<unsigned int>������;
    for (int i = 0; i < ��ȡ��Ⱦ����������.size(); i++)
    {
        Index_data �� = ��ȡ��Ⱦ����������[i];
        for (int j = 0; j < ��.��������.size(); j++)
        {
            Vertex_index �涥������ = ��.��������[j];
            ������.push_back(�涥������.size());

            ������ά ���� = ������ά(0.0f);
            if (��ά���꼯��.empty() || �涥������.�������� < 0 || �涥������.�������� >= ��ά���꼯��.size()) ���� = ������ά(0.0f);
            else ���� = ��ά���꼯��[�涥������.��������];

            ������ά ���� = ������ά(0.0f);
            if (��ά���߼���.empty() || �涥������.�������� < 0 || �涥������.�������� >= ��ά���߼���.size())
                ���� = ������ά(0.0f);
            else
                ���� = ��ά���߼���[�涥������.��������];

            ������ά UV = ������ά(0.0f);
            if (��άUV����.empty() || �涥������.UV���� < 0 || �涥������.UV���� >= ��άUV����.size())
                UV = ������ά(0.0f);
            else
                UV = ��άUV����[�涥������.UV����];

            YS_RGB ��ɫ = YS_RGB(0.0f);
            if (��ά��ɫ����.empty() || �涥������.��ɫ���� < 0 || �涥������.��ɫ���� >= ��ά��ɫ����.size())
                ��ɫ = YS_RGB(0.0f);
            else ��ɫ = ��.ͳһ��ɫ;

            �涥������.push_back(Face_vectex_data(����, ����, UV, ��ɫ));
        }
    }
    std::vector<float>��������(�涥������.size() * 12);
    for (int i = 0; i < �涥������.size(); i++)
    {
        int ���� = i * 12;
        ��������[���� + 0] = �涥������[i].����.X;
        ��������[���� + 1] = �涥������[i].����.Y;
        ��������[���� + 2] = �涥������[i].����.Z;

        ��������[���� + 3] = �涥������[i].����.X;
        ��������[���� + 4] = �涥������[i].����.Y;
        ��������[���� + 5] = �涥������[i].����.Z;

        ��������[���� + 6] = �涥������[i].UV.X;
        ��������[���� + 7] = �涥������[i].UV.Y;

        ��������[���� + 8] = �涥������[i].��ɫ.r;
        ��������[���� + 9] = �涥������[i].��ɫ.g;
        ��������[���� + 10] = �涥������[i].��ɫ.b;
        ��������[���� + 11] = �涥������[i].��ɫ.a;
    }
    std::vector<float> _���궥��(�涥������.size() * 3);
    for (int i = 0; i < �涥������.size(); i++)
    {
        int ���� = i * 12;
        int ���� = i * 3;
        _���궥��[���� + 0] = ��������[���� + 0];
        _���궥��[���� + 1] = ��������[���� + 1];
        _���궥��[���� + 2] = ��������[���� + 2];
    }

    ������ = ������;
    ���������꼯�� = _���궥��;
    //_��Ⱦ��.ע�ᶥ�㻺��(��������, ������);
}

void Model_FWK::��ȡ��Ⱦ������()
{
    std::vector<Face_vectex_data> �涥������;
    std::vector<unsigned int>������;
    for (int i = 0; i < �����߼���.size(); i++)
    {
        Index_data �������ݱ� = �����߼���[i];
        for (int j = 0; j < �������ݱ�.��������.size(); j++)
        {
            Vertex_index �涥������ = �������ݱ�.��������[j];
            ������.push_back(�涥������.size());

            ������ά ���� = ������ά(0.0f);
            if (��ά���꼯��.empty() || �涥������.�������� < 0 || �涥������.�������� >= ��ά���꼯��.size()) ���� = ������ά(0.0f);
            else ���� = ��ά���꼯��[�涥������.��������];

            ������ά ���� = ������ά(0.0f);
            if (��ά���߼���.empty() || �涥������.�������� < 0 || �涥������.�������� >= ��ά���߼���.size())
                ���� = ������ά(0.0f);
            else
                ���� = ��ά���߼���[�涥������.��������];

            ������ά UV = ������ά(0.0f);
            if (��άUV����.empty() || �涥������.UV���� < 0 || �涥������.UV���� >= ��άUV����.size())
                UV = ������ά(0.0f);
            else
                UV = ��άUV����[�涥������.UV����];

            YS_RGB ��ɫ = YS_RGB(0.0f);
            if (��ά��ɫ����.empty() || �涥������.��ɫ���� < 0 || �涥������.��ɫ���� >= ��ά��ɫ����.size())
                ��ɫ = YS_RGB(0.0f);
            else ��ɫ = �������ݱ�.ͳһ��ɫ;

            �涥������.push_back(Face_vectex_data(����, ����, UV, ��ɫ));
        }
    }

    std::vector<float>��������(�涥������.size() * 12);
    for (int i = 0; i < �涥������.size(); i++)
    {
        int ���� = i * 12;
        ��������[���� + 0] = �涥������[i].����.X;
        ��������[���� + 1] = �涥������[i].����.Y;
        ��������[���� + 2] = �涥������[i].����.Z;

        ��������[���� + 3] = �涥������[i].����.X;
        ��������[���� + 4] = �涥������[i].����.Y;
        ��������[���� + 5] = �涥������[i].����.Z;

        ��������[���� + 6] = �涥������[i].UV.X;
        ��������[���� + 7] = �涥������[i].UV.Y;

        ��������[���� + 8] = �涥������[i].��ɫ.r;
        ��������[���� + 9] = �涥������[i].��ɫ.g;
        ��������[���� + 10] = �涥������[i].��ɫ.b;
        ��������[���� + 11] = �涥������[i].��ɫ.a;
    }
    std::vector<float> _�����궥��(�涥������.size() * 3);
    for (int i = 0; i < �涥������.size(); i++)
    {
        int ���� = i * 12;
        int ���� = i * 3;
        _�����궥��[���� + 0] = ��������[���� + 0];
        _�����궥��[���� + 1] = ��������[���� + 1];
        _�����궥��[���� + 2] = ��������[���� + 2];
    }
    ������ = ������;
    ���������꼯�� = _�����궥��;
}

void Model_FWK::��ȡ��Ⱦ������()
{
    std::vector<Face_vectex_data> �㶥������;
    std::vector<unsigned int>������;
    for (int i = 0; i < �����㼯��.size(); i++)
    {
        Index_data �������ݵ� = �����㼯��[i];
        for (int j = 0; j < �������ݵ�.��������.size(); j++)
        {
            Vertex_index �涥������ = �������ݵ�.��������[j];
            ������.push_back(�㶥������.size());

            ������ά ���� = ������ά(0.0f);
            if (��ά���꼯��.empty() || �涥������.�������� < 0 || �涥������.�������� >= ��ά���꼯��.size()) ���� = ������ά(0.0f);
            else ���� = ��ά���꼯��[�涥������.��������];

            ������ά ���� = ������ά(0.0f);
            if (��ά���߼���.empty() || �涥������.�������� < 0 || �涥������.�������� >= ��ά���߼���.size())
                ���� = ������ά(0.0f);
            else
                ���� = ��ά���߼���[�涥������.��������];

            ������ά UV = ������ά(0.0f);
            if (��άUV����.empty() || �涥������.UV���� < 0 || �涥������.UV���� >= ��άUV����.size())
                UV = ������ά(0.0f);
            else
                UV = ��άUV����[�涥������.UV����];

            YS_RGB ��ɫ = YS_RGB(0.0f);
            if (��ά��ɫ����.empty() || �涥������.��ɫ���� < 0 || �涥������.��ɫ���� >= ��ά��ɫ����.size())
                ��ɫ = YS_RGB(0.0f);
            else ��ɫ = �������ݵ�.ͳһ��ɫ;

            �㶥������.push_back(Face_vectex_data(����, ����, UV, ��ɫ));
        }
    }

    std::vector<float>��������(�㶥������.size() * 12);
    for (int i = 0; i < �㶥������.size(); i++)
    {
        int ���� = i * 12;
        ��������[���� + 0] = �㶥������[i].����.X;
        ��������[���� + 1] = �㶥������[i].����.Y;
        ��������[���� + 2] = �㶥������[i].����.Z;

        ��������[���� + 3] = �㶥������[i].����.X;
        ��������[���� + 4] = �㶥������[i].����.Y;
        ��������[���� + 5] = �㶥������[i].����.Z;

        ��������[���� + 6] = �㶥������[i].UV.X;
        ��������[���� + 7] = �㶥������[i].UV.Y;

        ��������[���� + 8] = �㶥������[i].��ɫ.r;
        ��������[���� + 9] = �㶥������[i].��ɫ.g;
        ��������[���� + 10] = �㶥������[i].��ɫ.b;
        ��������[���� + 11] = �㶥������[i].��ɫ.a;
    }
    std::vector<float> _�����궥��(�㶥������.size() * 3);
    for (int i = 0; i < �㶥������.size(); i++)
    {
        int ���� = i * 12;
        int ���� = i * 3;
        _�����궥��[���� + 0] = ��������[���� + 0];
        _�����궥��[���� + 1] = ��������[���� + 1];
        _�����궥��[���� + 2] = ��������[���� + 2];
    }
    ������ = ������;
    ���������꼯�� = _�����궥��;

}

void Model_FWK::�任����(��Ԫ�� ��Ԫ��)
{
    for (int i = 0; i < ��ά���꼯��.size(); i++)
    {
        ��ά���꼯��[i] = ��Ԫ��::��Ԫ������ά����(��ά���꼯��[i], ��Ԫ��);
    }
    for (int i = 0; i < ��ά���߼���.size(); i++)
    {
        ��ά���߼���[i] = ��Ԫ��::��Ԫ������ά����(��ά���߼���[i], ��Ԫ��);
    }
}

void Model_FWK::�任����(������ά ����)
{
    for (int i = 0; i < ��ά���꼯��.size(); i++)
    {
        ��ά���꼯��[i] = ��ά���꼯��[i] + ����;
    }
}

void Model_FWK::�任����(����4X4 ����)
{
    for (int i = 0; i < ��ά���꼯��.size(); i++)
    {
        ��ά���꼯��[i] = ����4X4::����ƽ��(��ά���꼯��[i], ����);
    }
    for (int i = 0; i < ��ά���߼���.size(); i++)
    {
        ��ά���߼���[i] = ����4X4::����ƽ��(��ά���߼���[i], ����4X4::�������߾���(����));
    }
}

std::vector<Index_data> Model_FWK::����ȡ��(std::vector<Index_data> _��ϼ�)
{
    Index_list �߼���;
    for (int i = 0; i < _��ϼ�.size(); i++)
    {
        Index_data �� = _��ϼ�[i];
        if (��.��������.size() > 2)
        {
            for (int j = 0; j < ��.��������.size(); j++)
            {
                int A = j, B = j + 1;
                if (B >= ��.��������.size()) B = 0;

                std::vector<Vertex_index> ����;
                ����.push_back(Vertex_index(��.��������[A]));
                ����.push_back(Vertex_index(��.��������[B]));
                Index_data �� = Index_data(����);

                if (!�߼���.����(��)) �߼���.���(��);

            }
        }
    }
    return �߼���.ת�б�();
}

std::vector<Index_data> Model_FWK::����ȡ��(std::vector<Index_data> _��ϼ�)
{
    Index_list �㼯��;
    for (int i = 0; i < _��ϼ�.size(); i++)
    {
        Index_data �� = _��ϼ�[i];
        if (��.��������.size() > 2)
        {
            for (int j = 0; j < ��.��������.size(); j++)
            {
                Vertex_index ������ = ��.��������[j];
                std::vector<Vertex_index> m;
                m.push_back(������);
                Index_data �� = Index_data(m);

                if (!�㼯��.����(��)) �㼯��.���(��);
            }
        }
    }
    return �㼯��.ת�б�();
}

Model_FWK Model_FWK::����ƽ��(float ���, float �߶�, int ��ȷֶ�, int �߶ȷֶ�)
{
    
    float U��� = ��� / ��ȷֶ�;
    float V��� = �߶� / �߶ȷֶ�;
    ������ά ����ƫ�� = ������ά(1.0f);
    ����ƫ�� = ������ά(��� / 2.0f, 0.0f, �߶� / 2.0f);
    std::vector<������ά> _���꼯��;
    std::vector<������ά> _UV����;
    std::vector<������ά> _���߼���;
    _���߼���.push_back(������ά(0.0f, 1.0f, 0.0f));
    for (int x = 0; x <= ��ȷֶ�; x++)
    {
        for (int y = 0; y <= �߶ȷֶ�; y++)
        {
            _���꼯��.push_back(������ά((float)x * U���, 0.0f, (float)y * V���) - ����ƫ��);
            _UV����.push_back(������ά((float)x / (float)��ȷֶ�, (float)y / (float)�߶ȷֶ�));
        }
    }
    std::vector<Index_data> _�����漯��;
    std::vector<Index_data> _�����߼���;
    std::vector<Index_data> _�����㼯��;
    for (int i = 0; i < _���꼯��.size() - �߶ȷֶ� - 1; i++)
    {
        if ((i + 1) % (�߶ȷֶ� + 1) != 0)
        {
            
            int ��0 = i;
            int ��1 = i + �߶ȷֶ� + 1;
            int ��2 = i + �߶ȷֶ� + 2;
            int ��3 = i + 1;
            std::vector<Vertex_index> ��������;
            ��������.push_back(Vertex_index(��3, 0, ��3, ��3));
            ��������.push_back(Vertex_index(��2, 0, ��2, ��2));
            ��������.push_back(Vertex_index(��1, 0, ��1, ��1));
            ��������.push_back(Vertex_index(��0, 0, ��0, ��0));
            
            _�����漯��.push_back(Index_data(��������));
        }
    }
    for (int i = 0; i < _���꼯��.size(); i++)
    {
        if (i < _���꼯��.size() - �߶ȷֶ� - 1)
        {
            int ��0 = i;
            int ��1 = i + �߶ȷֶ� + 1;
            std::vector<Vertex_index> ��������;
            ��������.push_back(Vertex_index(��0, 0, ��0, ��0));
            ��������.push_back(Vertex_index(��1, 0, ��1, ��1));
           
            _�����߼���.push_back(Index_data(��������));
        }
        if ((i + 1) % (�߶ȷֶ� + 1) != 0)
        {
            int ��0 = i;
            int ��1 = i + 1;
            std::vector<Vertex_index> ��������;
            ��������.push_back(Vertex_index(��0, 0, ��0, ��0));
            ��������.push_back(Vertex_index(��1, 0, ��1, ��1));

            _�����߼���.push_back(Index_data(��������));
        }
    }
    std::vector<YS_RGB> _��ɫ����;
    for (int i = 0; i < _���꼯��.size(); i++)
    {
        std::vector<Vertex_index> ��������;
        ��������.push_back(Vertex_index(i, 0, i, i));
        _�����㼯��.push_back(Index_data(��������));
        _��ɫ����.push_back(YS_RGB(0));
    }

    return Model_FWK(_���꼯��, _���߼���, _UV����, _��ɫ����, _�����漯��, _�����߼���, _�����㼯��);
    
}

Model_FWK Model_FWK::�ϲ�ģ��(std::vector<Model_FWK> ģ���б�)
{
    std::vector<������ά> �������꼯��;
    std::vector<������ά> �������߼���;
    std::vector<������ά> ����UV����;
    std::vector<YS_RGB> ������ɫ����;
    for (int i = 0; i < ģ���б�.size(); i++)
    {
        Model_FWK ģ������ = ģ���б�[i];
        for (������ά ���� : ģ������.��ά���꼯��) �������꼯��.push_back(����);
        for (������ά ���� : ģ������.��ά���߼���) �������߼���.push_back(����);
        for (������ά UV : ģ������.��άUV����) ����UV����.push_back(UV);
        for (YS_RGB ��ɫ : ģ������.��ά��ɫ����) ������ɫ����.push_back(��ɫ);
    }

    std::vector<Index_data> �����漯��;
    std::vector<Index_data> �����߼���;
    std::vector<Index_data> �����㼯��;
    int ����ƫ�� = 0, ����ƫ�� = 0, UVƫ�� = 0, ��ɫƫ�� = 0;
    for (int i = 0; i < ģ���б�.size(); i++)
    {
        Model_FWK ģ�� = ģ���б�[i];
        if (!ģ��.�����漯��.empty())
        {
            for (int j = 0; j < ģ��.�����漯��.size(); j++)
            {
                Index_data ���������� = ģ��.�����漯��[j];
                �����漯��.push_back(����������.����ƫ��(����ƫ��, ����ƫ��, UVƫ��, ��ɫƫ��));
            }
        }
        if (!ģ��.�����߼���.empty())
        {
            for (int j = 0; j < ģ��.�����߼���.size(); j++)
            {
                Index_data �������ݱ� = ģ��.�����߼���[j];
                �����߼���.push_back(�������ݱ�.����ƫ��(����ƫ��, ����ƫ��, UVƫ��, ��ɫƫ��));
            }
        }
        if (!ģ��.�����㼯��.empty())
        {
            for (int j = 0; j < ģ��.�����㼯��.size(); j++)
            {
                Index_data �������ݵ� = ģ��.�����㼯��[j];
                �����㼯��.push_back(�������ݵ�.����ƫ��(����ƫ��, ����ƫ��, UVƫ��, ��ɫƫ��));
            }
        }
        ����ƫ�� += ģ��.��ά���꼯��.size();
        ����ƫ�� += ģ��.��ά���꼯��.size();
        UVƫ�� += ģ��.��ά���꼯��.size();
        ��ɫƫ�� += ģ��.��ά���꼯��.size();
    }


    return Model_FWK(�������꼯��, �������߼���, ����UV����, ������ɫ����, �����漯��, �����߼���, �����㼯��);
}

void Model_FWK::ƽ����ɫ(Model_FWK& ģ��, float �Ƕ�)
{
    float ƽ������ = �Ƕ� * ����::����();
    //int �� ����
    std::unordered_map<int, std::vector<Vectex_face>> ��������漯��;

    for (int i = 0; i < ģ��.�����漯��.size(); i++)
    {
        Index_data �� = ģ��.�����漯��[i];
        std::vector<������ά> ����;
        ����.push_back(ģ��.��ά���꼯��[��.��������[0].��������]);
        ����.push_back(ģ��.��ά���꼯��[��.��������[1].��������]);
        ����.push_back(ģ��.��ά���꼯��[��.��������[2].��������]);
        ������ά �淨�� = ������ά::�����淨��(����);
        if (������ά::���Ϊ��(�淨��)) �淨�� = ������ά(0);

        for (int j = 0; j < ��.��������.size(); j++)
        {
            Vertex_index ���� = ��.��������[j];

            if (��������漯��.count(����.��������))
            {
                //�޸�
                Vectex_face ��������;
                ��������.�������� = ����;
                ��������.���� = �淨��;
                std::vector<Vectex_face>����������� = ��������漯��[����.��������];// [����.��������] = ��������;
                �����������.push_back(��������);
                ��������漯��[����.��������] = �����������;
            }
            else
            {
                //���
                Vectex_face ��������;
                ��������.�������� = ����;
                ��������.���� = �淨��;
                std::vector<Vectex_face>�����������;
                �����������.push_back(��������);
                ��������漯��.insert(std::make_pair(����.��������, �����������));
            }

        }

    }

    std::vector<ƽ������> ƽ����ɫ�ϼ�;
    for (auto it = ��������漯��.begin(); it != ��������漯��.end(); ++it)
    {
        //�� ����
        std::vector<Vectex_face>������� = it->second;
        std::vector<������ά> ����;
        for (int i = 0; i < �������.size(); i++)
        {
            //�� ����
            Vectex_face �������� = �������[i];
            ����.push_back(��������.����);
        }
        ������ά ƽ������ = ������ά::���㵥λ����(������ά::��������(����));

        for (int i = 0; i < �������.size(); i++)
        {
            // �� ����
            Vectex_face ������ = �������[i];
            if (������ά::����н�(ƽ������, ������.����) < ƽ������)
            {
                if (�б���Ӳ�����(ƽ����ɫ�ϼ�, ƽ������))
                {
                    ƽ������ ����;
                    ����.���� = ƽ������;
                    ����.���� = ƽ����ɫ�ϼ�.size();
                    ƽ����ɫ�ϼ�.push_back(����);
                }
            }
            else
            {
                if (�б���Ӳ�����(ƽ����ɫ�ϼ�, ������.����))
                {
                    ƽ������ ����;
                    ����.���� = ������.����;
                    ����.���� = ƽ����ɫ�ϼ�.size();
                    ƽ����ɫ�ϼ�.push_back(����);
                }
            }
        }

    }

    std::vector<������ά> ���߼���;
    for (int i = 0; i < ƽ����ɫ�ϼ�.size(); i++)
    {
        ���߼���.push_back(ƽ����ɫ�ϼ�[i].����);
    }

    ģ��.��ά���߼��� = ���߼���;
}

Model_FWK Model_FWK::������(std::vector<������ά> _����ϼ�)
{
    return Model_FWK();
}

void Model_FWK::�Ż�����ģ��(Model_FWK& ģ��, float ����)
{
    std::vector<������ά> ȥ�����꼯��;
    std::unordered_map<int, int> ����ӳ�伯��;
    for (int i = 0; i < ģ��.��ά���꼯��.size(); i++)
    {
        ������ά ���� = ģ��.��ά���꼯��[i];
        int ������������ = -1;
        if (ȥ�����꼯��.empty())
        {
            ������������ = -1;
        }
        else
        {
            for (int j = 0; j < ȥ�����꼯��.size(); j++)
            {
                ������ά zb = ȥ�����꼯��[j];
                //����ռ�����ֱ�߾���
                float ���� = ������ά::�������(zb, ����);
                if (���� < ����)
                {
                    ������������ = j;
                    break;
                }
                else ������������ = -1;
            }
        }

        if (������������ == -1)
        {
            ����ӳ�伯��.insert(std::make_pair(i, (int)ȥ�����꼯��.size()));
            ȥ�����꼯��.push_back(����);
        }
        else ����ӳ�伯��.insert(std::make_pair(i, ������������));
    }

    Index_list ȥ���漯��;
    for (int i = 0; i < ģ��.�����漯��.size(); i++)
    {
        std::vector<Vertex_index> ���㼯��;
        Index_data �� = ģ��.�����漯��[i];
        for (int j = 0; j < ��.��������.size(); j++)
        {
            Vertex_index ���� = ��.��������[j];
            Vertex_index ӳ�䶥�� = Vertex_index(����ӳ�伯��[����.��������], ����ӳ�伯��[����.��������], ����ӳ�伯��[����.UV����], ����ӳ�伯��[����.��ɫ����]);
            if (���㼯��.empty())���㼯��.push_back(ӳ�䶥��);
            else if (�Ƿ����(���㼯��, ӳ�䶥��))���㼯��.push_back(ӳ�䶥��);
        }
        if (!���㼯��.empty() && ���㼯��.size() > 2)
        {
            Index_data ��¼�� = Index_data(���㼯��);
            if (!ȥ���漯��.����(��¼��)) ȥ���漯��.���(��¼��);
        }
    }

    Index_list ȥ�ر߼���;
    for (int i = 0; i < ģ��.�����߼���.size(); i++)
    {
        std::vector<Vertex_index> ���㼯��;
        Index_data �� = ģ��.�����߼���[i];
        for (int j = 0; j < ��.��������.size(); j++)
        {
            Vertex_index ���� = ��.��������[j];
            Vertex_index ӳ�䶥�� = Vertex_index(����ӳ�伯��[����.��������], ����.��������, ����.UV����, ����.��ɫ����);
            if (���㼯��.empty()) ���㼯��.push_back(ӳ�䶥��);
            else if (�Ƿ����(���㼯��, ӳ�䶥��))���㼯��.push_back(ӳ�䶥��);
        }
        if (���㼯��.size() > 1)
        {
            Index_data ��¼�� = Index_data(���㼯��);
            if (!ȥ�ر߼���.����(��¼��)) ȥ�ر߼���.���(��¼��);
        }
    }

    Index_list ȥ�ص㼯��;
    for (int i = 0; i < ģ��.�����㼯��.size(); i++)
    {
        std::vector<Vertex_index> ���㼯��;
        Index_data �� = ģ��.�����㼯��[i];
        for (int j = 0; j < ��.��������.size(); j++)
        {
            Vertex_index ���� = ��.��������[j];
            Vertex_index ӳ�䶥�� = Vertex_index(����ӳ�伯��[����.��������], ����ӳ�伯��[����.��������], ����ӳ�伯��[����.UV����], ����ӳ�伯��[����.��ɫ����]);
            if (���㼯��.empty()) ���㼯��.push_back(ӳ�䶥��);
            else if (�Ƿ����(���㼯��, ӳ�䶥��))���㼯��.push_back(ӳ�䶥��);
        }
        if (!���㼯��.empty() && ���㼯��.size() > 0)
        {
            Index_data ��¼�� = Index_data(���㼯��);
            if (!ȥ�ص㼯��.����(��¼��)) ȥ�ص㼯��.���(��¼��);
        }
    }
    ģ��.��ά���꼯�� = ȥ�����꼯��;
    ģ��.�����漯�� = ȥ���漯��.ת�б�();
    ģ��.�����߼��� = ȥ�ر߼���.ת�б�();
    ģ��.�����㼯�� = ȥ�ص㼯��.ת�б�();
}

Model_FWK Model_FWK::����������(float �ߴ�x, float �ߴ�y, float �ߴ�z, int �ֶ�x, int �ֶ�y, int �ֶ�z)
{
    
    Model_FWK ���� = ����ƽ��(�ߴ�x, �ߴ�y, �ֶ�x, �ֶ�y) * ��Ԫ��::���������ת(������ά::X��(), ����::�Ƕ�ת����(-90));
    Model_FWK ���� = ���� * ��Ԫ��::���������ת(������ά::X��(), ����::�Ƕ�ת����(180));

    ��Ԫ�� ��ʱ���� = ��Ԫ��::���������ת(������ά::X��(), ����::�Ƕ�ת����(90)) * ��Ԫ��::���������ת(������ά::Z��(), ����::�Ƕ�ת����(-90));
    Model_FWK ���� = ����ƽ��(�ߴ�z, �ߴ�y, �ֶ�z, �ֶ�y) * ��ʱ����;
    Model_FWK ���� = ���� * ��Ԫ��::���������ת(������ά::Z��(), ����::�Ƕ�ת����(-180));

    Model_FWK ���� = ����ƽ��(�ߴ�x, �ߴ�z, �ֶ�x, �ֶ�z);
    Model_FWK ���� = ���� * ��Ԫ��::���������ת(������ά::X��(), ����::�Ƕ�ת����(180));

    ���� = ���� - ������ά(0, 0, �ߴ�z * 0.5f);
    ���� = ���� + ������ά(0, 0, �ߴ�z * 0.5f);

    ���� = ���� + ������ά(�ߴ�x * 0.5f, 0, 0);
    ���� = ���� - ������ά(�ߴ�x * 0.5f, 0, 0);

    ���� = ���� + ������ά(0, �ߴ�y * 0.5f, 0);
    ���� = ���� - ������ά(0, �ߴ�y * 0.5f, 0);

    std::vector<Model_FWK> ģ���б�;
    ģ���б�.push_back(����);
    ģ���б�.push_back(����);
    ģ���б�.push_back(����);
    ģ���б�.push_back(����);
    ģ���б�.push_back(����);
    ģ���б�.push_back(����);
    Model_FWK ��ģ�� = �ϲ�ģ��(ģ���б�);

    �Ż�����ģ��(��ģ��);

    return ��ģ��;

}

Model_FWK Model_FWK::����Բ��(float �뾶, float �߶�, int ��ת�ֶ�, int �߶ȷֶ�, float ���Ƕ�, float �յ�Ƕ�)
{
    ����::���·����С(���Ƕ�, �յ�Ƕ�);
    if (std::abs(�յ�Ƕ� - ���Ƕ�) > 360) �յ�Ƕ� = ���Ƕ� + 360;
    std::vector<������ά> ��ת��������;
    ��ת��������.push_back(������ά(�߶ȷֶ� + 1));
    float ��� = �߶� / 2;
    for (int i = 0; i < ��ת��������.size(); i++)
    {
        float �߶Ȱٷֱ� = (float)i / (��ת��������.size() - 1);
        ����4X4 ��ת���� = ����4X4::������ת����Y(���Ƕ� * ����::����());
        ��ת��������[i] = ��ת���� * ������ά(�뾶, �߶Ȱٷֱ� * �߶� - ���, 0);
    }
    std::vector<������ά> ���꼯��;
    std::vector<������ά> ���߼���;
    std::vector<������ά> UV����;
    std::vector<YS_RGB> ��ɫ����;
    ��ɫ����.push_back(YS_RGB());
    for (int i = 0; i <= ��ת�ֶ�; i++)
    {
        float U = (float)i / ��ת�ֶ�;
        ����4X4 ��ת���� = ����4X4::������ת����Y(U * (�յ�Ƕ� - ���Ƕ�) * ����::����());
        for (int j = 0; j < ��ת��������.size(); j++)
        {
            float V = (float)j / (��ת��������.size() - 1);
            ������ά ���� = ��ת���� * ��ת��������[j];
            ���꼯��.push_back(����);
            ���߼���.push_back(������ά::���㵥λ����(������ά(����.X, 0, ����.Z)));
            UV����.push_back(������ά(1 - U, V));
        }
    }

    std::vector<Index_data> �漯��;
    std::vector<Index_data> �߼���;
    std::vector<Index_data> �㼯��;
    for (int i = 0; i < ���꼯��.size() - �߶ȷֶ� - 1; i++)
    {
        if ((i + 1) % (�߶ȷֶ� + 1) != 0)
        {
            int ��0 = i;
            int ��1 = i + �߶ȷֶ� + 1;
            int ��2 = i + �߶ȷֶ� + 2;
            int ��3 = i + 1;
            std::vector<Vertex_index> ��������;
            ��������.push_back(Vertex_index(��0, ��0, ��0, ��0));
            ��������.push_back(Vertex_index(��1, ��1, ��1, ��1));
            ��������.push_back(Vertex_index(��2, ��2, ��2, ��2));
            ��������.push_back(Vertex_index(��3, ��3, ��3, ��3));

            �漯��.push_back(Index_data(��������));
        }
    }
    for (int i = 0; i < ���꼯��.size(); i++)
    {
        if (i < ���꼯��.size() - �߶ȷֶ� - 1)
        {
            int ��0 = i;
            int ��1 = i + �߶ȷֶ� + 1;
            std::vector<Vertex_index> ��������;
            ��������.push_back(Vertex_index(��0, ��0, ��0, ��0));
            ��������.push_back(Vertex_index(��1, ��1, ��1, ��1));

            �߼���.push_back(Index_data(��������));
        }
        if ((i + 1) % (�߶ȷֶ� + 1) != 0)
        {
            int ��0 = i;
            int ��1 = i + 1;
            std::vector<Vertex_index> ��������;
            ��������.push_back(Vertex_index(��0, ��0, ��0, ��0));
            ��������.push_back(Vertex_index(��1, ��1, ��1, ��1));

            �߼���.push_back(Index_data(��������));
        }
    }
    for (int i = 0; i < ���꼯��.size(); i++)
    {
        std::vector<Vertex_index> ��������;
        ��������.push_back(Vertex_index(i, i, i, i));
        �㼯��.push_back(Index_data(��������));
    }
    Model_FWK ��ģ��;
    ��ģ��.��ά���꼯�� = ���꼯��;
    ��ģ��.��ά���߼��� = ���߼���;
    ��ģ��.��άUV���� = UV����;
    ��ģ��.�����漯�� = �漯��;
    ��ģ��.�����߼��� = �߼���;
    ��ģ��.�����㼯�� = �㼯��;
    ��ģ��.��ά��ɫ���� = ��ɫ����;
    if (�յ�Ƕ� - ���Ƕ� == 0) �Ż�����ģ��(��ģ��);

    return ��ģ��;
}

Model_FWK Model_FWK::��������(float �뾶, int �ֶ�)
{
    int ���ȷֶ� = �ֶ�;
    int γ�ȷֶ� = ���ȷֶ� / 2 + 1;
    float ��ת�Ƕ� = ����::��360() / ���ȷֶ�;
    std::vector<������ά> ��ת��������(γ�ȷֶ�);
    for (int i = 0; i < γ�ȷֶ�; i++)
    {
        float V�ٷֱ� = (float)i / (γ�ȷֶ� - 1);
        ��ת��������[i] = ����4X4::����ƽ��(������ά::Y��(), ����4X4::������ת����Z(V�ٷֱ� * ����::��180()));
    }

    std::vector<������ά> _���꼯��;
    std::vector<������ά> _UV����;
    for (int x = 0; x < ���ȷֶ�; x++)
    {
        float U�ٷֱ� = x / (float)���ȷֶ�;
        for (int y = 0; y < γ�ȷֶ�; y++)
        {
            float V�ٷֱ� = (float)y / (γ�ȷֶ� - 1);
            ������ά ���� = ����4X4::����ƽ��(��ת��������[y], ����4X4::������ת����Y(x * -��ת�Ƕ�));
            _���꼯��.push_back(���� * �뾶);
            _UV����.push_back(������ά(U�ٷֱ�, 1 - V�ٷֱ�));
        }
    }
    for (int y = 0; y < γ�ȷֶ�; y++)
    {
        float V�ٷֱ� = y / (float)(γ�ȷֶ� - 1.0);
        _UV����.push_back(������ά(1, 1 - V�ٷֱ�));
    }

    std::vector<Index_data> �漯��;
    for (int i = 0; i < _���꼯��.size() - 1; i++)
    {
        int UV0 = i;
        int UV1 = i + γ�ȷֶ�;
        int UV2 = i + γ�ȷֶ� + 1;
        int UV3 = i + 1;

        int ��0 = UV0;
        int ��1 = UV1;
        int ��2 = UV2;
        int ��3 = UV3;

        if (!(��1 < _���꼯��.size())) ��1 -= _���꼯��.size();
        if (!(��2 < _���꼯��.size())) ��2 -= _���꼯��.size();
        if (!(��3 < _���꼯��.size())) ��3 -= _���꼯��.size();


        if ((i + 1) % γ�ȷֶ� == 0)
        {
            //�漯��.Add(new ��������(
            //   new ��������(��3, ��3, UV3, 0),
            //   new ��������(��2, ��2, UV2, 0),
            //   new ��������(��1, ��1, UV1, 0),
            //   new ��������(��0, ��0, UV0, 0)
            //));

        }
        else
        {
            std::vector<Vertex_index> ����;
            ����.push_back(Vertex_index(��0, ��0, UV0, 0));
            ����.push_back(Vertex_index(��1, ��1, UV1, 0));
            ����.push_back(Vertex_index(��2, ��2, UV2, 0));
            ����.push_back(Vertex_index(��3, ��3, UV3, 0));
            �漯��.push_back(Index_data(����));
        }

    }
    Model_FWK ����ģ��;
    ����ģ��.��ά���꼯�� = _���꼯��;
    ����ģ��.��άUV���� = _UV����;
    ����ģ��.��ά��ɫ����.push_back(YS_RGB(0));
    ����ģ��.�����漯�� = �漯��;
    ����ģ��.�����߼��� = ����ȡ��(�漯��);
    ����ģ��.�����㼯�� = ����ȡ��(�漯��);
    �Ż�����ģ��(����ģ��);
    return ����ģ��;
}

Model_FWK Model_FWK::����������(float �뾶, int �ֶ�)
{
    return Model_FWK();
}

Model_FWK Model_FWK::����������(float �ߴ�X, float Y, float Z)
{
    float x = �ߴ�X / 2.0f;
    float y = Y;
    float z = Z / 2.0f;
    std::vector<������ά> ���꼯��;
    ���꼯��.push_back(������ά(-x, 0, -z));
    ���꼯��.push_back(������ά(+x, 0, -z));
    ���꼯��.push_back(������ά(+x, 0, +z));
    ���꼯��.push_back(������ά(-x, 0, +z));
    ���꼯��.push_back(������ά(0, y, 0));
    std::vector<������ά> ���߼���;
    for (int i = 0; i < ���꼯��.size(); i++)
    {
        ���߼���.push_back(������ά::���㵥λ����(���꼯��[i]));
    }
    std::vector<������ά> UV����;
    UV����.push_back(������ά(0, 0));
    UV����.push_back(������ά(1, 0));
    UV����.push_back(������ά(1, 1));
    UV����.push_back(������ά(0, 1));
    UV����.push_back(������ά(0.5f, 1));

    std::vector<Index_data> �漯��;
    std::vector<Vertex_index> ����;
    ����.push_back(Vertex_index(0, 0, 0, 0));
    ����.push_back(Vertex_index(1, 1, 1, 1));
    ����.push_back(Vertex_index(2, 2, 2, 2));
    ����.push_back(Vertex_index(3, 3, 3, 3));
    �漯��.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(0, 0, 1, 0));
    ����.push_back(Vertex_index(4, 4, 4, 4));
    ����.push_back(Vertex_index(1, 1, 2, 1));
    �漯��.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(1, 0, 1, 0));
    ����.push_back(Vertex_index(4, 1, 4, 4));
    ����.push_back(Vertex_index(2, 2, 2, 2));
    �漯��.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(2, 0, 1, 2));
    ����.push_back(Vertex_index(4, 1, 4, 4));
    ����.push_back(Vertex_index(3, 2, 2, 3));
    �漯��.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(3, 0, 1, 3));
    ����.push_back(Vertex_index(4, 1, 4, 4));
    ����.push_back(Vertex_index(0, 2, 2, 0));
    �漯��.push_back(Index_data(����));



    std::vector<Index_data> �߼���;
    ����.clear();
    ����.push_back(Vertex_index(0, 0, 0, 0));
    ����.push_back(Vertex_index(4, 4, 4, 0));
    �߼���.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(1, 1, 1, 0));
    ����.push_back(Vertex_index(4, 4, 4, 4));
    �߼���.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(2, 2, 2, 2));
    ����.push_back(Vertex_index(4, 4, 4, 4));
    �߼���.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(3, 3, 3, 3));
    ����.push_back(Vertex_index(4, 4, 4, 4));
    �߼���.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(0, 0, 0, 0));
    ����.push_back(Vertex_index(1, 1, 1, 1));
    �߼���.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(1, 1, 1, 0));
    ����.push_back(Vertex_index(2, 2, 2, 2));
    �߼���.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(2, 2, 2, 0));
    ����.push_back(Vertex_index(3, 3, 3, 3));
    �߼���.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(3, 3, 3, 3));
    ����.push_back(Vertex_index(0, 0, 0, 0));
    �߼���.push_back(Index_data(����));

    std::vector<Index_data> �㼯��;
    ����.clear();
    ����.push_back(Vertex_index(0, 0, 0, 0));
    �㼯��.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(1, 1, 1, 1));
    �㼯��.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(2, 2, 2, 2));
    �㼯��.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(3, 3, 3, 3));
    �㼯��.push_back(Index_data(����));

    ����.clear();
    ����.push_back(Vertex_index(4, 4, 4, 4));
    �㼯��.push_back(Index_data(����));

    std::vector<YS_RGB> ��ɫ����;
    for (int i = 0; i < ���꼯��.size(); i++)
    {
        ��ɫ����.push_back(YS_RGB());
    }


    return Model_FWK(���꼯��, ���߼���, UV����, ��ɫ����, �漯��, �߼���, �㼯��);
}

Model_FWK Model_FWK::����Բ��(float �ڰ뾶, float ��뾶, int Բ�̷ֶ�, int ��ת�ֶ�, float ���Ƕ�, float �յ�Ƕ�)
{
    ����::���·����С(�ڰ뾶, ��뾶);
    ����::���·����С(���Ƕ�, �յ�Ƕ�);
    std::vector<������ά> ��ת��������(2);
    for (int i = 0; i < ��ת��������.size(); i++)
    {
        ����4X4 ��ת���� = ����4X4::������ת����Y(���Ƕ� * ����::����());
        ��ת��������[i] = ��ת���� * ������ά((float)i / Բ�̷ֶ� * (��뾶 - �ڰ뾶) + �ڰ뾶, 0, 0);
    }
    std::vector<������ά> ���꼯��;
    std::vector<������ά> ���߼���;
    ���߼���.push_back(������ά::Y��());
    std::vector<������ά> UV����;
    std::vector<YS_RGB> ��ɫ����;
    ��ɫ����.push_back(YS_RGB());

    for (int i = 0; i <= ��ת�ֶ�; i++)
    {
        float U = (float)i / ��ת�ֶ�;
        ����4X4 ��ת���� = ����4X4::������ת����Y(U * (�յ�Ƕ� - ���Ƕ�) * ����::����());
        for (int j = 0; j < ��ת��������.size(); j++)
        {
            ������ά ���� = ��ת���� * ��ת��������[j];
            ���꼯��.push_back(����);
            if (�ڰ뾶 == 0)
            {
                UV����.push_back(������ά(����::��Χӳ��(����.X, 0, ��뾶, 0, 0.5f) + 0.5f, ����::��Χӳ��(����.Z, 0, ��뾶, 0, 0.5f) + 0.5f));
            }
            else
            {
                float V = (float)j / (��ת��������.size() - 1);
                UV����.push_back(������ά(U, V));
            }
        }
    }

    Index_list �漯��;
    Index_list �߼���;
    Index_list �㼯��;
    for (int i = 0; i < ���꼯��.size() - ��ת��������.size() - 1; i++)
    {
        if (i % ��ת��������.size() != ��ת��������.size() - 1)
        {
            int A = i;
            int B = A + 1;
            int C = A + ��ת��������.size();
            int D = C + 1;

            std::vector<Vertex_index> ��������;
            ��������.push_back(Vertex_index(A, 0, A, 0));
            ��������.push_back(Vertex_index(B, 0, B, 0));
            ��������.push_back(Vertex_index(D, 0, D, 0));
            ��������.push_back(Vertex_index(C, 0, C, 0));

            Index_data �� = Index_data(��������);
            if (!�漯��.����(��)) �漯��.���(��);
           
            for (int j = 0; j < ��.��������.size() - 1; j++)
            {
                std::vector<Vertex_index> ��������;
                ��������.push_back(��.��������[j]);
                ��������.push_back(��.��������[j + 1]);
                Index_data �� = Index_data(��������);

                ��������.clear();
                ��������.push_back(��.��������[j]);
                Index_data �� = Index_data(��������);

                if (!�߼���.����(��))
                    �߼���.���(��);
                if (!�㼯��.����(��))
                    �㼯��.���(��);
            }
        }
    }

    std::vector<Index_data> _�漯�� = �漯��.ת�б�();
    std::vector<Index_data> _�߼��� = �߼���.ת�б�();
    std::vector<Index_data> _�㼯�� = �㼯��.ת�б�();

    return Model_FWK(���꼯��, ���߼���, UV����, ��ɫ����, _�漯��, _�߼���, _�㼯��);
}

Model_FWK Model_FWK::�����ܵ�(float �ڰ뾶, float ��뾶, float �߶�, int ��ת�ֶ�, int Բ�̷ֶ�, int �߶ȷֶ�, float ���Ƕ�, float �յ�Ƕ�)
{
    return Model_FWK();
}

Model_FWK Model_FWK::��������(std::vector<������ά> �����б�)
{
    std::vector<������ά> _���ߺϼ�;
    _���ߺϼ�.push_back(������ά::Y��());
    std::vector<������ά> _UV�ϼ�;
    _UV�ϼ�.push_back(������ά(0));

    std::vector<Index_data> _�漯��;
    std::vector<Index_data> _�߼���;
    for (int i = 0; i < �����б�.size() - 1; i++)
    {
        _�߼���.push_back(Index_data(Index_data::��������ת�б�(Vertex_index(i, 0, 0, i), Vertex_index(i + 1, 0, 0, i + 1))));
    }

    std::vector<Index_data> _�㼯��;
    for (int i = 0; i < �����б�.size() - 1; i++)
    {
        _�㼯��.push_back(Index_data(Index_data::��������ת�б�(Vertex_index(i, 0, 0, 0))));
    }
    std::vector<YS_RGB> _��ɫ����;
    for (int i = 0; i < �����б�.size() - 1; i++)
    {
        _��ɫ����.push_back(YS_RGB(0));
    }
    return Model_FWK(�����б�, _���ߺϼ�, _UV�ϼ�, _��ɫ����, _�漯��, _�߼���, _�㼯��);
}

Model_FWK Model_FWK::��������(std::vector<Line_seg> �����б�)
{
    std::vector<������ά> ���꼯��;
    std::vector<Index_data> ������;
    for (int i = 0; i < �����б�.size(); i++)
    {
        Line_seg �߶� = �����б�[i];
        for (int j = 0; j < �߶�.�������꼯��.size()-1; j++)
        {
            std::vector<Vertex_index> ��������;
            ��������.push_back(Vertex_index(���꼯��.size() + j, 0, 0, 0));
            ��������.push_back(Vertex_index(���꼯��.size() + j + 1, 0, 0, 0));
            ������.push_back(Index_data(��������));
            
        }
        for (int j = 0; j < �߶�.�������꼯��.size(); j++)
        {
            ���꼯��.push_back(�߶�.�������꼯��[j]);
        }
       
    }
    Model_FWK ��ģ��;
    ��ģ��.��ά���꼯�� = ���꼯��;
    ��ģ��.�����߼��� = ������;
    return ��ģ��;
}

Model_FWK Model_FWK::������ͷ��(������ά ���, ������ά �յ�, float ��ͷ�ߴ�)
{
    ��Ԫ�� ��ת = ��Ԫ��::����Ŀ����ת(���, �յ�, ������ά::Y��(), ������ά::Z��());
    std::vector<������ά> �б�;
    �б�.push_back(������ά::��());
    �б�.push_back(������ά(-��ͷ�ߴ�, 0, -��ͷ�ߴ�));
    Model_FWK ģ��A = ��������(�б�) * ��ת + �յ�;

    �б�.clear();
    �б�.push_back(������ά::��());
    �б�.push_back(������ά(��ͷ�ߴ�, 0, -��ͷ�ߴ�));
    Model_FWK ģ��B = ��������(�б�) * ��ת + �յ�;
    �б�.clear();
    �б�.push_back(���);
    �б�.push_back(�յ�);
    Model_FWK ģ��C = ��������(�б�);

    std::vector<Model_FWK> ģ���б�;
    ģ���б�.push_back(ģ��A);
    ģ���б�.push_back(ģ��B);
    ģ���б�.push_back(ģ��C);
    return �ϲ�ģ��(ģ���б�);
}

Model_FWK Model_FWK::����Բ����(float �뾶, int �ֶ�)
{
    return Model_FWK();
}

std::vector<Index_data> Model_FWK::��ȡ�����漯��()
{
    std::vector<Index_data> �����������ϼ�;
    for (int i = 0; i < �����漯��.size(); i++)
    {
        Index_data �� = �����漯��[i];
        if (��.��������.size() == 3)
        {
            �����������ϼ�.push_back(��);
        }
        else
        {
            for (int i = 2; i < ��.��������.size(); i++)
            {
                int ��1 = 0;
                int ��2 = i - 1;
                int ��3 = i;
                std::vector<Vertex_index> ��������;
                ��������.push_back(��.��������[��1]);
                ��������.push_back(��.��������[��2]);
                ��������.push_back(��.��������[��3]);
                �����������ϼ�.push_back(Index_data(��������));
                
            }
        }
    }
    return �����������ϼ�;
}

bool Model_FWK::�Ƿ����(std::vector<Vertex_index> ����, Vertex_index ����)
{
    for (int i = 0; i < ����.size(); i++)
    {
        if (����[i] == ����) return false;
    }
    return true;
}

bool Model_FWK::�б���Ӳ�����(std::vector<ƽ������> ����, ������ά ����)
{
    if (����.empty())return true;
    else {
        for (int i = 0; i < ����.size(); i++)
        {
            if (����[i].���� == ����)return false;
        }
    }
    return true;
}





Model_FWK Model_FWK::operator*(��Ԫ�� ��Ԫ��)
{
    Model_FWK ��ģ��(��ά���꼯��, ��ά���߼���, ��άUV����, ��ά��ɫ����, �����漯��, �����߼���, �����㼯��);
    ��ģ��.�任����(��Ԫ��);
    return ��ģ��;
}

Model_FWK Model_FWK::operator+(������ά ����)
{
    Model_FWK ��ģ��(��ά���꼯��, ��ά���߼���, ��άUV����, ��ά��ɫ����, �����漯��, �����߼���, �����㼯��);
    ��ģ��.�任����(����);
    return ��ģ��;
}

Model_FWK Model_FWK::operator-(������ά ����)
{
    Model_FWK ��ģ��(��ά���꼯��, ��ά���߼���, ��άUV����, ��ά��ɫ����, �����漯��, �����߼���, �����㼯��);
    ��ģ��.�任����(-����);
    return ��ģ��;
}

Model_FWK Model_FWK::operator+(Model_FWK ģ��)
{
    Model_FWK ��ģ��;
    ��ģ��.��ά���꼯�� = ��ά���꼯��;
    ��ģ��.��ά���߼��� = ��ά���߼���;
    ��ģ��.��άUV���� = ��άUV����;
    ��ģ��.��ά��ɫ���� = ��ά��ɫ����;
    ��ģ��.�����漯�� = �����漯��;
    ��ģ��.�����߼��� = �����߼���;
    ��ģ��.�����㼯�� = �����㼯��;

    std::vector<Model_FWK> ģ���б�;
    ģ���б�.push_back(��ģ��);
    ģ���б�.push_back(ģ��);
    return �ϲ�ģ��(ģ���б�);
}

Model_FWK Model_FWK::operator*(����4X4 ����)
{
    Model_FWK ��ģ��;
    ��ģ��.��ά���꼯�� = ��ά���꼯��;
    ��ģ��.��ά���߼��� = ��ά���߼���;
    ��ģ��.��άUV���� = ��άUV����;
    ��ģ��.��ά��ɫ���� = ��ά��ɫ����;
    ��ģ��.�����漯�� = �����漯��;
    ��ģ��.�����߼��� = �����߼���;
    ��ģ��.�����㼯�� = �����㼯��;
    ��ģ��.�任����(����);
    return ��ģ��;
}
