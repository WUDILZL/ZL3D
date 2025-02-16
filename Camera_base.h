#pragma once
#include "Model_object.h"
#include "视图结构.h"
#include "射线结构.h"

//摄像机基类
class Camera_base :
    public Model_object
{
public:
    Camera_base();
    ~Camera_base();

public:
    float 宽高比;
    float 近端修剪;
    float 远端修剪;
    矩阵4X4 视图矩阵;
    矩阵4X4 投影矩阵;
    射线结构 鼠标坐标记录;

protected:
    virtual void 事件_计算世界矩阵()override;
    virtual void 事件_更新投影矩阵();
    virtual 射线结构 获取鼠标射线(向量二维 鼠标屏幕坐标, 视图结构 渲染视口);
};

