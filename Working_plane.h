#pragma once
#include "Model_object.h"
#include "Model_FWK.h"
#include "Color_shader.h"

//����ƽ��
class Working_plane :
    public Model_object
{
public:
    Working_plane();
    ~Working_plane();

public:
    void ע�ᶥ�㻺��();
    void ��Ⱦ(My_Shader ��ɫ��, My_Camera ���);
    void ���ٶ��㻺��();

public:
    //������ƣ��Ƿ���ת
    bool ѡ��;
    QString ����;
    int ��������;
    bool �Ƿ���Ⱦ;

    Model_FWK ����ģ��A;
    Model_FWK ����ģ��B;
    Model_FWK X��ģ��;
    Model_FWK Y��ģ��;
    Model_FWK Z��ģ��;
};

