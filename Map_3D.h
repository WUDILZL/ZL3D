#pragma once
#include "��ͼ�ṹ.h"
#include "Working_plane.h"
#include "Mouse_Key.h"
#include "Cube.h"
#include "Queue.h"
#include "Object_control.h"

struct ���ٶ������� {
    int ���� = 0;
    int ���� = 0;
};

struct ��ǰ��ѡ���� {
    int ���� = -1;
    int ���� = -1;
    int �б�λ�� = -1;
};

class Map_3D
{
public:
	Map_3D();
	~Map_3D();


public:
    //͸����� 0 ����ƽ��1 ������2
    ģ�Ͷ��� ȫ��ģ��;
    ��ͼ�ṹ �ӿ�;
    My_Shader ��ɫ��;
    Mouse_Key �����̲���;
    Object_control �������;
    std::vector<���ٶ�������> �����б�;
    ��ǰ��ѡ���� ģ��;

public:
	void ��ʼ��();
	void ����ʱ����();

public:
    //����ģ����ɫ������
    void ��ɫ�������Լ���();
    //����
    void �������ٶ���();
    void ��ȡ�������(QPoint _�������, QPoint ʵʱ����);
    void ��ȡ��ǰ��ѡģ��(int ��,int ����);

public:
    void ��ӵ����ٶ���(int ����, int ����);
    void ���ģ��������ģ��();

private:
    void ����ʱ��֡();
    void ��������();
    void �������();
    void �����������();
    void ������ʱ����();
    void ��������Ⱦ();
    void ����ĩβ֡();

    void ��������();

    void ��ȡ��ǰ�б�����();
    void ����ٿ�(ģ�Ͷ���& ����ģ��);
    void ˢ�¶��в���();
private://�¼���Ӧ


};

