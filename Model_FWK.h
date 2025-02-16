#pragma once
#include <set>
#include "���ؼ���.h"
#include "RGB.h"
#include "Line_seg.h"
#include "Index_list.h"
#include "Vertex_buffer.h"

//�涥������
class Face_vectex_data
{
public:
	Face_vectex_data() {
		���� = ���� = ������ά(0.0f);
		UV = ������ά(0.0f);
		��ɫ = YS_RGB(0);
	}
	Face_vectex_data(������ά z, ������ά f, ������ά u, YS_RGB y)
	{
		���� = z;
		���� = f;
		UV = u;
		��ɫ = y;
	}
	~Face_vectex_data()
	{

	}
	������ά ����;
	������ά ����;
	������ά UV;
	YS_RGB ��ɫ;
};

// �������� ����
struct Vectex_face {
	Vertex_index ��������;
	������ά ����;
};

struct ƽ������ {
	������ά ����;
	int ����;
};

struct ��Ⱦ״̬ {
	bool �Ƿ���Ⱦ = true;
	bool ��Ⱦ�� = true;
	bool ��Ⱦ�� = true;
	bool ��Ⱦ�� = true;
};

struct ����״̬ {
	bool ��Ⱦ�涥��ע�� = false;
	bool ��Ⱦ�߶���ע�� = false;
	bool ��Ⱦ�㶥��ע�� = false;
};

//������
struct ui��ʾ����
{
	QString ����;
	bool ѡ��״̬ = false;
	������ά �ߴ�;
	������ά �ֶ�;

	bool ��Ⱦ״̬�� = true;
	bool ��Ⱦ״̬�� = true;
	bool ��Ⱦ״̬�� = true;

	������ά ��������;
	������ά ��������;

};


//���л��ƾ�����˳ʱ��
// ģ�ͼܹ� ,model framework
class Model_FWK
{
public:
	Model_FWK();
	Model_FWK(std::vector<������ά> _���꼯��, std::vector<������ά> _���߼���, std::vector<������ά> _UV����, std::vector<YS_RGB> _��ɫ����, std::vector<Index_data> _�����漯��, std::vector<Index_data> _�����߼���, std::vector<Index_data> _�����㼯��);
	~Model_FWK();

public:
	Vertex_buffer _��Ⱦ��;
	Vertex_buffer _��Ⱦ��;
	Vertex_buffer _��Ⱦ��;

	std::vector<������ά> ��ά���꼯��;
	std::vector<������ά> ��ά���߼���;
	std::vector<������ά> ��άUV����;
	std::vector<YS_RGB> ��ά��ɫ����;
	

	std::vector<Index_data> �����漯��;
	std::vector<Index_data> �����߼���;
	std::vector<Index_data> �����㼯��;

	std::vector<float> ���������꼯��;
	std::vector<float> ���������꼯��;
	std::vector<float> ���������꼯��;

	std::vector<unsigned int> ������;
	std::vector<unsigned int> ������;
	std::vector<unsigned int> ������;

public:
	
	void ��ȡ��Ⱦ������();
	void ��ȡ��Ⱦ������();
	void ��ȡ��Ⱦ������();
	void �任����(��Ԫ�� ��Ԫ��);
	void �任����(������ά ����);
	void �任����(����4X4 ����);

	static std::vector<Index_data> ����ȡ��(std::vector<Index_data> _��ϼ�);
	static std::vector<Index_data> ����ȡ��(std::vector<Index_data> _��ϼ�);
	static Model_FWK ����ƽ��(float ���, float �߶�, int ��ȷֶ�, int �߶ȷֶ�);
	static Model_FWK �ϲ�ģ��(std::vector<Model_FWK> ģ���б�);
	static void ƽ����ɫ(Model_FWK& ģ��, float �Ƕ�);
	static Model_FWK ������(std::vector<������ά> _����ϼ�);
	static void �Ż�����ģ��(Model_FWK& ģ��, float ���� = 0.001f);
	static Model_FWK ����������(float �ߴ�x, float �ߴ�y, float �ߴ�z, int �ֶ�x, int �ֶ�y, int �ֶ�z);
	static Model_FWK ����Բ��(float �뾶, float �߶�, int ��ת�ֶ�, int �߶ȷֶ�, float ���Ƕ� = 0.0f, float �յ�Ƕ� = 360.0f);
	static Model_FWK ��������(float �뾶, int �ֶ�);
	static Model_FWK ����������(float �뾶, int �ֶ�);
	static Model_FWK ����������(float �ߴ�X, float Y, float Z);
	static Model_FWK ����Բ��(float �ڰ뾶, float ��뾶, int Բ�̷ֶ�, int ��ת�ֶ�, float ���Ƕ� = 0.01f, float �յ�Ƕ� = 360.0f);
	static Model_FWK �����ܵ�(float �ڰ뾶, float ��뾶, float �߶�, int ��ת�ֶ�, int Բ�̷ֶ� = 1, int �߶ȷֶ� = 1, float ���Ƕ� = 0.0f, float �յ�Ƕ� = 360.0f);
	static Model_FWK ��������(std::vector<������ά> �����б�);
	static Model_FWK ��������(std::vector<Line_seg> �����б�);
	static Model_FWK ������ͷ��(������ά ���, ������ά �յ�, float ��ͷ�ߴ�);
	static Model_FWK ����Բ����(float �뾶, int �ֶ�);

	Model_FWK operator *(��Ԫ�� ��Ԫ��);
	Model_FWK operator +(������ά ����);
	Model_FWK operator -(������ά ����);
	Model_FWK operator +(Model_FWK ģ��);
	Model_FWK operator *(����4X4 ����);

private:
	std::vector<Index_data> ��ȡ�����漯��();
	static bool �Ƿ����(std::vector<Vertex_index> ����, Vertex_index ����);
	static bool �б���Ӳ�����(std::vector<ƽ������> ����, ������ά ����);
};




