#pragma once
#include "Model_FWK.h"
#include "Model_object.h"
#include "Color_shader.h"


struct ��Ⱦ��ɫ���� {
    YS_RGB �� = YS_RGB(0.5f);
    YS_RGB �� = YS_RGB(0.0f);
    YS_RGB �� = YS_RGB(0.0f);
};

//������
class Cube :
    public Model_object
{
public:
    Cube();
    ~Cube();
    float �ߴ�x;
    float �ߴ�y;
    float �ߴ�z;

    int �ֶ�x;
    int �ֶ�y;
    int �ֶ�z;

    bool ѡ��״̬;
    ��Ⱦ״̬ ��Ⱦ����;
    ����״̬ ��������;
    Model_FWK ������;
    QString ����;
    int ��������;
    ui��ʾ���� ������;

    ��Ⱦ��ɫ���� ������ɫ;

public:
    //�������ڽ���ȡ�����а�
    void ȡ����Ⱦ();
    void ע�ᶥ��();
    void ���ٶ���();
    void �ύ��Ⱦ(My_Shader ��ɫ��, My_Camera ���);
    void �޸�ģ��();
    void ��������();

    void ��Ⱦ�и�������();
};

