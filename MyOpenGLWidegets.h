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
	//初始化
	virtual void initializeGL() override;
	//窗口大小变化
	virtual void resizeGL(int width, int height) override;
	//窗口需要重绘时调用
	virtual void paintGL() override;
	//鼠标按下事件
	virtual void mousePressEvent(QMouseEvent* event) override;
	//鼠标释放事件
	virtual void mouseReleaseEvent(QMouseEvent* event) override;
	//滚轮事件
	virtual void wheelEvent(QWheelEvent* event) override;
	//鼠标移动量
	virtual void mouseMoveEvent(QMouseEvent* event) override;
	//按下事件
	virtual void keyPressEvent(QKeyEvent* event) override;
	//弹起事件
	virtual void keyReleaseEvent(QKeyEvent* event) override;

public:
	void 加载队列();
	int 返回帧率();
public:
	Map_3D 三维场景;
	qint64 每帧时间;//ms
	QPoint 实时坐标;
	

private:
	bool 左键按下 = false;
	
	QPoint 点击坐标;
	

};

