#pragma once
#include <QOpenGLWidget>
#include <QMouseEvent>
#include <QDateTime>
#include "Map_3D.h"

class MyOpenGLWidegets :
    public QOpenGLWidget, QOpenGLExtraFunctions
{
	Q_OBJECT
public:
	MyOpenGLWidegets(QWidget* parent = nullptr);
	~MyOpenGLWidegets();

protected:
	//��ʼ��
	virtual void initializeGL() override;
	//���ڴ�С�仯
	virtual void resizeGL(int width, int height) override;
	//������Ҫ�ػ�ʱ����
	virtual void paintGL() override;
	//��갴���¼�
	virtual void mousePressEvent(QMouseEvent* event) override;
	//����ͷ��¼�
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	//�����¼�
	virtual void wheelEvent(QWheelEvent* event) override;
	//����ƶ���
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	//�����¼�
	virtual void keyPressEvent(QKeyEvent* event) override;
	//�����¼�
	virtual void keyReleaseEvent(QKeyEvent* event) override;

public:
	void ���ض���();
	int ����֡��();
public:
	Map_3D ��ά����;
	qint64 ÿ֡ʱ��;//ms
	QPoint ʵʱ����;
	

private:
	bool ������� = false;
	
	QPoint �������;
	

};

