#pragma once
#include <glm.hpp>
#include <gtc/matrix_transform.hpp>
#include <gtc/type_ptr.hpp>
#include <QString>
#include "Camera_base.h"

//͸�����
class My_Camera : public Camera_base
{
public:
	My_Camera();
	~My_Camera();
	
	
public:
	float ����;
	float ��׶�Ƕ�;
	float �α����;
	������ά �α�����;
	QString ����;

	int ��������;

protected:
	virtual void �¼�_����ͶӰ����()override;

public:
	void ֪ͨͶӰ����ı�();
	void ���ñ���_����(float value);
	void ���ñ���_��׶�Ƕ�(float value);
	void ���ñ���_�α����(float value);

	static float ����ת��Ұ�Ƕ�(float ��������, float �������ߴ�);
	static float ��Ұ�Ƕ�ת����(float ��Ұ�Ƕ�����, float �������ߴ�);

	void ��ȡ�������(float ����ֵ, float x, float y);

private:
	float _����;
	float _��׶�Ƕ�;
	float _�α����;
};

