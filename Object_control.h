#pragma once
#include "多重计算.h"
#include "Model_object.h"
#include "Color_shader.h"
#include "Model_FWK.h"
#include "Cube.h"

enum 操控模式 {
    空, 平移, 模型缩放, 旋转
};
enum 操控轴 {
    X, Y, Z
};



//物体操控类
class Object_control
{
public:
    Object_control();
    ~Object_control();

    操控模式 当前模式;
    操控轴 当前轴;

    Model_FWK 平移模型;
    Model_FWK 缩放模型;
    Model_FWK 旋转模型;

    矩阵4X4 模型世界矩阵;
    矩阵4X4 旋转矩阵;

    YS_RGB 渲染颜色;

public:
    void 顶点注册();
    void 顶点销毁();
    void 时间线(int 按键设置);
    void 控制(Cube& 当前控制物体, float x, float y);
    void 渲染(My_Shader 着色器,My_Camera 相机);
    
};

