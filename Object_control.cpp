#include "Object_control.h"

Object_control::Object_control()
{
	模型世界矩阵 = 矩阵4X4::单位矩阵();
	旋转矩阵 = 矩阵4X4::单位矩阵();
	渲染颜色 = YS_RGB(0);
    当前轴 = X;

	平移模型 = Model_FWK::创建金字塔(0.2f, 0.4f, 0.2f) + 向量三维(0, 2, 0);
    平移模型 = 平移模型 + (Model_FWK::创建金字塔(0.2f, 0.4f, 0.2f) * 创建旋转矩阵(180, 0, 0) + 向量三维(0, -2, 0));
	平移模型 = 平移模型 + Model_FWK::创建立方体(0.1f, 4.0f, 0.1f, 1, 1, 1);

	旋转模型 = Model_FWK::创建圆盘(1.8f, 2.0f, 1, 32);

	缩放模型 = Model_FWK::创建球体(0.2f, 8) + 向量三维(0, 2, 0);
	缩放模型 = 缩放模型 + (Model_FWK::创建球体(0.2f, 8) + 向量三维(0, -2, 0));
	缩放模型 = 缩放模型 + Model_FWK::创建立方体(0.1f, 4.0f, 0.1f, 1, 1, 1);

	平移模型.获取渲染面数据();
	旋转模型.获取渲染面数据();
	缩放模型.获取渲染面数据();
}

Object_control::~Object_control()
{
}

void Object_control::顶点注册()
{
	平移模型._渲染面.注册顶点缓冲(平移模型.索引面坐标集合, 平移模型.索引面);
	旋转模型._渲染面.注册顶点缓冲(旋转模型.索引面坐标集合, 旋转模型.索引面);
	缩放模型._渲染面.注册顶点缓冲(缩放模型.索引面坐标集合, 缩放模型.索引面);
}

void Object_control::顶点销毁()
{
	平移模型._渲染面.清除顶点缓冲();
	旋转模型._渲染面.清除顶点缓冲();
	缩放模型._渲染面.清除顶点缓冲();
}


void Object_control::时间线(int 按键设置)
{
	if (按键设置 == 0) 当前模式 = 空;
	else if (按键设置 == 1) 当前模式 = 平移;
	else if (按键设置 == 2) 当前模式 = 模型缩放;
	else if (按键设置 == 3) 当前模式 = 旋转;
	else if (按键设置 == 4) 当前轴 = X;
	else if (按键设置 == 5) 当前轴 = Y;
	else if (按键设置 == 6) 当前轴 = Z;
    
}

void Object_control::控制(Cube& 当前控制物体, float x, float y)
{
    switch (当前模式)
    {
    case 空:
        break;
    case 平移:
    {
        float 平移值 = x * 0.1f;
        switch (当前轴)
        {
        case X:
            当前控制物体.设置惯性平移(向量三维(平移值, 0, 0));
            break;
        case Y:
            当前控制物体.设置惯性平移(向量三维(0, 平移值, 0));
            break;
        case Z:
            当前控制物体.设置惯性平移(向量三维(0, 0, 平移值));
            break;
        default:
            break;
        }
    }
    break;
    case 旋转:
    {
        float 旋转值 = x * 0.02f;
        switch (当前轴)
        {
        case X:
            当前控制物体.设置惯性旋转(向量三维::X轴(), 旋转值);
            break;
        case Y:
            当前控制物体.设置惯性旋转(向量三维::Y轴(), 旋转值);
            break;
        case Z:
            当前控制物体.设置惯性旋转(向量三维::Z轴(), 旋转值);
            break;
        default:
            break;
        }
    }
    break;
    case 模型缩放:
    {
        float 缩放值 = x * 0.01f;
        switch (当前轴)
        {
        case X:
            当前控制物体.缩放 = 当前控制物体.缩放 + 向量三维(缩放值, 0, 0);
            当前控制物体.设置变换_缩放(当前控制物体.缩放);
            break;
        case Y:
            当前控制物体.缩放 = 当前控制物体.缩放 + 向量三维(0, 缩放值, 0);
            当前控制物体.设置变换_缩放(当前控制物体.缩放);
            break;
        case Z:
            当前控制物体.缩放 = 当前控制物体.缩放 + 向量三维(0, 0, 缩放值);
            当前控制物体.设置变换_缩放(当前控制物体.缩放);
            break;
        default:
            break;
        }
    }
    break;
    default:
        break;
    }

    模型世界矩阵 = 当前控制物体.世界矩阵;
}

void Object_control::渲染(My_Shader 着色器, My_Camera 相机)
{
	if (当前模式 == 空) return;
    旋转矩阵 = 矩阵4X4::单位矩阵();
	switch (当前轴)
	{
	case X:
		旋转矩阵 = 创建旋转矩阵(0, 0, 90.0f);
		渲染颜色 = YS_RGB(1,0,0);
		break;
	case Y:
		渲染颜色 = YS_RGB(0, 1, 0);
		break;
	case Z:
		旋转矩阵 = 创建旋转矩阵(90.0f, 0, 0);
		渲染颜色 = YS_RGB(0, 0, 1);
		break;
	default:
		break;
	}
	switch (当前模式)
	{
	case 空:
		break;
	case 平移:
		Color_shader::渲染面(着色器, 平移模型._渲染面, 旋转矩阵 * 模型世界矩阵, 渲染颜色, 相机);
		break;
	case 模型缩放:
		Color_shader::渲染面(着色器, 缩放模型._渲染面, 旋转矩阵 * 模型世界矩阵, 渲染颜色, 相机);
		break;
	case 旋转:
		Color_shader::渲染面(着色器, 旋转模型._渲染面, 旋转矩阵 * 模型世界矩阵, 渲染颜色, 相机);
		break;
	default:
		break;
	}

}

