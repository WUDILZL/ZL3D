#pragma once
#include "Model_object.h"
#include "Model_FWK.h"
#include "Color_shader.h"

//工作平面
class Working_plane :
    public Model_object
{
public:
    Working_plane();
    ~Working_plane();

public:
    void 注册顶点缓冲();
    void 渲染(My_Shader 着色器, My_Camera 相机);
    void 销毁顶点缓冲();

public:
    //物体控制，是否被旋转
    bool 选中;
    QString 名称;
    int 队列索引;
    bool 是否渲染;

    Model_FWK 网络模型A;
    Model_FWK 网络模型B;
    Model_FWK X轴模型;
    Model_FWK Y轴模型;
    Model_FWK Z轴模型;
};

