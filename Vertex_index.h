#pragma once

//��������
class Vertex_index
{
public:
	Vertex_index();
	Vertex_index(unsigned int ����);
	Vertex_index(unsigned int _��������, unsigned int _��������, unsigned int _UV����, unsigned int _��ɫ����);
	~Vertex_index();

	unsigned int ��������, ��������, UV����, ��ɫ����;
public:
	bool operator ==(Vertex_index ��);
	bool operator !=(Vertex_index ��);

public:
	Vertex_index ƫ��(unsigned int ����ƫ��, unsigned int ����ƫ��, unsigned int UVƫ��, unsigned int ��ɫƫ��);

};