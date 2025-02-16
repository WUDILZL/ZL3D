#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTimer>
#include "MyOpenGLWidegets.h"
#include "Model_data.h"
#include "Tree_list.h"

struct 数据可用队列 {
    bool 立方体 = false;
};

class ALL_UI :
    public QWidget
{
    Q_OBJECT
public:

    explicit ALL_UI(QWidget* parent = nullptr);
    ~ALL_UI();

    void 树形列表信号交互();
    void 模型信号();
    //0透视相机 1工作平面 2立方体
    void 添加模型(int 类型);
public:
    MyOpenGLWidegets* _opengl显示窗口;
    QStackedWidget* 页面分布;
    Model_data* 立方体数据显示窗口;
    Tree_list* 树状图形节点显示;
    //QTimer* 定时器;
private:
    //透视相机 0 工作平面1 立方体2
    int 当前节点类型 = 0;
    int 当前节点索引 = 0;

    //
    int 当前选中类型 = 0;
    int 当前选中索引 = 0;

    数据可用队列 模型操纵状态;

private:
    void 获取所有节点名称(模型队列 模型);
    void 数据更新前对模型选取取消();
    void 更新ui模型数据();
    void 立方体模型信号();
    void 销毁物体(int 类型, int 索引);
};

