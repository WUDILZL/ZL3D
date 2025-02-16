#pragma once
#include "视图结构.h"
#include "Working_plane.h"
#include "Mouse_Key.h"
#include "Cube.h"
#include "Queue.h"
#include "Object_control.h"

struct 销毁队列数据 {
    int 类型 = 0;
    int 索引 = 0;
};

struct 当前所选索引 {
    int 类型 = -1;
    int 索引 = -1;
    int 列表位置 = -1;
};

class Map_3D
{
public:
	Map_3D();
	~Map_3D();


public:
    //透视相机 0 工作平面1 立方体2
    模型队列 全部模型;
    视图结构 视口;
    My_Shader 着色器;
    Mouse_Key 鼠标键盘参数;
    Object_control 物体控制;
    std::vector<销毁队列数据> 销毁列表;
    当前所选索引 模型;

public:
	void 初始化();
	void 驱动时间线();

public:
    //所有模型着色器加载
    void 着色顶点属性加载();
    //析构
    void 数据销毁队列();
    void 获取鼠标数据(QPoint _点击坐标, QPoint 实时坐标);
    void 获取当前所选模型(int 类,int 索引);

public:
    void 添加到销毁队列(int 类型, int 索引);
    void 添加模型立方体模型();

private:
    void 处理时间帧();
    void 处理输入();
    void 处理调度();
    void 处理鼠标命中();
    void 处理场景时间线();
    void 处理场景渲染();
    void 处理末尾帧();

    void 处理销毁();

    void 获取当前列表索引();
    void 物体操控(模型队列& 操纵模型);
    void 刷新队列参数();
private://事件响应


};

