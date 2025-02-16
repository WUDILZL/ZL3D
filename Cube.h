#pragma once
#include "Model_FWK.h"
#include "Model_object.h"
#include "Color_shader.h"


struct 渲染颜色属性 {
    YS_RGB 面 = YS_RGB(0.5f);
    YS_RGB 线 = YS_RGB(0.0f);
    YS_RGB 点 = YS_RGB(0.0f);
};

//立方体
class Cube :
    public Model_object
{
public:
    Cube();
    ~Cube();
    float 尺寸x;
    float 尺寸y;
    float 尺寸z;

    int 分段x;
    int 分段y;
    int 分段z;

    bool 选中状态;
    渲染状态 渲染属性;
    顶点状态 顶点属性;
    Model_FWK 立方体;
    QString 名称;
    int 队列索引;
    ui显示数据 总数据;

    渲染颜色属性 物体颜色;

public:
    //生命周期结束取消所有绑定
    void 取消渲染();
    void 注册顶点();
    void 销毁顶点();
    void 提交渲染(My_Shader 着色器, My_Camera 相机);
    void 修改模型();
    void 更新数据();

    void 渲染中更新坐标();
};

