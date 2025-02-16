#include "MyOpenGLWidegets.h"

MyOpenGLWidegets::MyOpenGLWidegets(QWidget* parent)
{
	ÿ֡ʱ�� = 0;
	//������
	setMouseTracking(true);
	//�������
	setFocusPolicy(Qt::StrongFocus);
}

MyOpenGLWidegets::~MyOpenGLWidegets()
{
	��ά����.�������ٶ���();
}

void MyOpenGLWidegets::initializeGL()
{
	initializeOpenGLFunctions();
	��ά����.��ʼ��();
	��ά����.�ӿ� = ��ͼ�ṹ(0, 0, width(), height(), ��ά����.ȫ��ģ��.͸���������[0].�����޼�, ��ά����.ȫ��ģ��.͸���������[0].Զ���޼�);
	��ά����.ȫ��ģ��.͸���������[0].��߱� = ��ά����.�ӿ�.��߱�;
	
}

void MyOpenGLWidegets::resizeGL(int width, int height)
{
	��ά����.�ӿ� = ��ͼ�ṹ(0, 0, width, height, ��ά����.ȫ��ģ��.͸���������[0].�����޼�, ��ά����.ȫ��ģ��.͸���������[0].Զ���޼�);
	��ά����.ȫ��ģ��.͸���������[0].��߱� = ��ά����.�ӿ�.��߱�;
	��ά����.ȫ��ģ��.͸���������[0].֪ͨͶӰ����ı�();
}

void MyOpenGLWidegets::paintGL()
{
	QDateTime ֡��ʼʱ�� = QDateTime::currentDateTime();
	//��Ȳ���
	glEnable(GL_DEPTH_TEST);
	//���û��ģʽ
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//�������
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	��ά����.����ʱ����();

	QDateTime ֡����ʱ�� = QDateTime::currentDateTime();
	ÿ֡ʱ�� = ֡��ʼʱ��.msecsTo(֡����ʱ��);
	update();
}

void MyOpenGLWidegets::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		������� = true;
		������� = event->pos();
	}
}

void MyOpenGLWidegets::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) ������� = false;
}

void MyOpenGLWidegets::wheelEvent(QWheelEvent* event)
{
	int yDelta = event->angleDelta().y();
	��ά����.�����̲���.������ += yDelta;
}

void MyOpenGLWidegets::mouseMoveEvent(QMouseEvent* event)
{
	QPoint ���ʵʱ���� = event->pos();
	ʵʱ���� = ���ʵʱ����;
	if (�������)
	{
		��ά����.��ȡ�������(�������, ���ʵʱ����);
		������� = ���ʵʱ����;
	}
}

void MyOpenGLWidegets::keyPressEvent(QKeyEvent* event)
{
	if (event->modifiers() & Qt::ControlModifier)
	{
		if (��ά����.�����̲���.ctrl���)
		{
			��ά����.�����̲���.ctrl��� = false;
		}
		else
		{
			��ά����.�����̲���.ctrl��� = true;
		}
	}
	if (event->key() == Qt::Key_Escape)��ά����.�����̲���.�����¼���¼ = Wu;
	if (event->key() == Qt::Key_E) ��ά����.�����̲���.�����¼���¼ = E;
	if (event->key() == Qt::Key_R) ��ά����.�����̲���.�����¼���¼ = R;
	if (event->key() == Qt::Key_T) ��ά����.�����̲���.�����¼���¼ = T;
	if (event->key() == Qt::Key_X) ��ά����.�����̲���.�����¼���¼ = �ٿ�X;
	if (event->key() == Qt::Key_Y) ��ά����.�����̲���.�����¼���¼ = �ٿ�Y;
	if (event->key() == Qt::Key_Z) ��ά����.�����̲���.�����¼���¼ = �ٿ�Z;
}

void MyOpenGLWidegets::keyReleaseEvent(QKeyEvent* event)
{

}

void MyOpenGLWidegets::���ض���()
{
	��ά����.��ɫ�������Լ���();
}

int MyOpenGLWidegets::����֡��()
{
	if (ÿ֡ʱ�� == 0) return 1000;
	else return 1000/ÿ֡ʱ��;
	
}
