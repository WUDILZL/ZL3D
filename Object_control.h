#pragma once
#include "���ؼ���.h"
#include "Model_object.h"
#include "Color_shader.h"
#include "Model_FWK.h"
#include "Cube.h"

enum �ٿ�ģʽ {
    ��, ƽ��, ģ������, ��ת
};
enum �ٿ��� {
    X, Y, Z
};



//����ٿ���
class Object_control
{
public:
    Object_control();
    ~Object_control();

    �ٿ�ģʽ ��ǰģʽ;
    �ٿ��� ��ǰ��;

    Model_FWK ƽ��ģ��;
    Model_FWK ����ģ��;
    Model_FWK ��תģ��;

    ����4X4 ģ���������;
    ����4X4 ��ת����;

    YS_RGB ��Ⱦ��ɫ;

public:
    void ����ע��();
    void ��������();
    void ʱ����(int ��������);
    void ����(Cube& ��ǰ��������, float x, float y);
    void ��Ⱦ(My_Shader ��ɫ��,My_Camera ���);
    
};

