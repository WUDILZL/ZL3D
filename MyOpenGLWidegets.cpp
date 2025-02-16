#include "MyOpenGLWidegets.h"

MyOpenGLWidegets::MyOpenGLWidegets(QWidget* parent)
{
	每帧时间 = 0;
	//鼠标跟踪
	setMouseTracking(true);
	//焦点策略
	setFocusPolicy(Qt::StrongFocus);
}

MyOpenGLWidegets::~MyOpenGLWidegets()
{
	三维场景.数据销毁队列();
}

void MyOpenGLWidegets::initializeGL()
{
	initializeOpenGLFunctions();
	三维场景.初始化();
	三维场景.视口 = 视图结构(0, 0, width(), height(), 三维场景.全部模型.透视相机队列[0].近端修剪, 三维场景.全部模型.透视相机队列[0].远端修剪);
	三维场景.全部模型.透视相机队列[0].宽高比 = 三维场景.视口.宽高比;
	
}

void MyOpenGLWidegets::resizeGL(int width, int height)
{
	三维场景.视口 = 视图结构(0, 0, width, height, 三维场景.全部模型.透视相机队列[0].近端修剪, 三维场景.全部模型.透视相机队列[0].远端修剪);
	三维场景.全部模型.透视相机队列[0].宽高比 = 三维场景.视口.宽高比;
	三维场景.全部模型.透视相机队列[0].通知投影矩阵改变();
}

void MyOpenGLWidegets::paintGL()
{
	QDateTime 帧开始时间 = QDateTime::currentDateTime();
	//深度测试
	glEnable(GL_DEPTH_TEST);
	//启用混合模式
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	//画板清除
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	三维场景.驱动时间线();

	QDateTime 帧结束时间 = QDateTime::currentDateTime();
	每帧时间 = 帧开始时间.msecsTo(帧结束时间);
	update();
}

void MyOpenGLWidegets::mousePressEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton)
	{
		左键按下 = true;
		点击坐标 = event->pos();
	}
}

void MyOpenGLWidegets::mouseReleaseEvent(QMouseEvent* event)
{
	if (event->button() == Qt::LeftButton) 左键按下 = false;
}

void MyOpenGLWidegets::wheelEvent(QWheelEvent* event)
{
	int yDelta = event->angleDelta().y();
	三维场景.鼠标键盘参数.鼠标滚轮 += yDelta;
}

void MyOpenGLWidegets::mouseMoveEvent(QMouseEvent* event)
{
	QPoint 鼠标实时坐标 = event->pos();
	实时坐标 = 鼠标实时坐标;
	if (左键按下)
	{
		三维场景.获取鼠标数据(点击坐标, 鼠标实时坐标);
		点击坐标 = 鼠标实时坐标;
	}
}

void MyOpenGLWidegets::keyPressEvent(QKeyEvent* event)
{
	if (event->modifiers() & Qt::ControlModifier)
	{
		if (三维场景.鼠标键盘参数.ctrl检测)
		{
			三维场景.鼠标键盘参数.ctrl检测 = false;
		}
		else
		{
			三维场景.鼠标键盘参数.ctrl检测 = true;
		}
	}
	if (event->key() == Qt::Key_Escape)三维场景.鼠标键盘参数.键盘事件记录 = Wu;
	if (event->key() == Qt::Key_E) 三维场景.鼠标键盘参数.键盘事件记录 = E;
	if (event->key() == Qt::Key_R) 三维场景.鼠标键盘参数.键盘事件记录 = R;
	if (event->key() == Qt::Key_T) 三维场景.鼠标键盘参数.键盘事件记录 = T;
	if (event->key() == Qt::Key_X) 三维场景.鼠标键盘参数.键盘事件记录 = 操控X;
	if (event->key() == Qt::Key_Y) 三维场景.鼠标键盘参数.键盘事件记录 = 操控Y;
	if (event->key() == Qt::Key_Z) 三维场景.鼠标键盘参数.键盘事件记录 = 操控Z;
}

void MyOpenGLWidegets::keyReleaseEvent(QKeyEvent* event)
{

}

void MyOpenGLWidegets::加载队列()
{
	三维场景.着色顶点属性加载();
}

int MyOpenGLWidegets::返回帧率()
{
	if (每帧时间 == 0) return 1000;
	else return 1000/每帧时间;
	
}
