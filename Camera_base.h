#pragma once
#include "Model_object.h"
#include "��ͼ�ṹ.h"
#include "���߽ṹ.h"

//���������
class Camera_base :
    public Model_object
{
public:
    Camera_base();
    ~Camera_base();

public:
    float ��߱�;
    float �����޼�;
    float Զ���޼�;
    ����4X4 ��ͼ����;
    ����4X4 ͶӰ����;
    ���߽ṹ ��������¼;

protected:
    virtual void �¼�_�����������()override;
    virtual void �¼�_����ͶӰ����();
    virtual ���߽ṹ ��ȡ�������(������ά �����Ļ����, ��ͼ�ṹ ��Ⱦ�ӿ�);
};

