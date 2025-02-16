#include "Model_FWK.h"

Model_FWK::Model_FWK()
{
    _渲染面 = Vertex_buffer();
    _渲染边 = Vertex_buffer();
    _渲染点 = Vertex_buffer();
}

Model_FWK::Model_FWK(std::vector<向量三维> _坐标集合, std::vector<向量三维> _法线集合, std::vector<向量二维> _UV集合, std::vector<YS_RGB> _颜色集合, std::vector<Index_data> _索引面集合, std::vector<Index_data> _索引边集合, std::vector<Index_data> _索引点集合)
{
    三维坐标集合 = _坐标集合;
    三维法线集合 = _法线集合;
    三维UV集合 = _UV集合;
    三维颜色集合 = _颜色集合;
    索引面集合 = _索引面集合;
    索引边集合 = _索引边集合;
    索引点集合 = _索引点集合;
}

Model_FWK::~Model_FWK()
{
}



void Model_FWK::获取渲染面数据()
{
    std::vector<Index_data> 获取渲染三角面数据 = 获取三角面集合();
    std::vector<Face_vectex_data> 面顶点数据;
    std::vector<unsigned int>面索引;
    for (int i = 0; i < 获取渲染三角面数据.size(); i++)
    {
        Index_data 面 = 获取渲染三角面数据[i];
        for (int j = 0; j < 面.索引集合.size(); j++)
        {
            Vertex_index 面顶点索引 = 面.索引集合[j];
            面索引.push_back(面顶点数据.size());

            向量三维 坐标 = 向量三维(0.0f);
            if (三维坐标集合.empty() || 面顶点索引.坐标索引 < 0 || 面顶点索引.坐标索引 >= 三维坐标集合.size()) 坐标 = 向量三维(0.0f);
            else 坐标 = 三维坐标集合[面顶点索引.坐标索引];

            向量三维 法线 = 向量三维(0.0f);
            if (三维法线集合.empty() || 面顶点索引.法线索引 < 0 || 面顶点索引.法线索引 >= 三维法线集合.size())
                法线 = 向量三维(0.0f);
            else
                法线 = 三维法线集合[面顶点索引.法线索引];

            向量二维 UV = 向量二维(0.0f);
            if (三维UV集合.empty() || 面顶点索引.UV索引 < 0 || 面顶点索引.UV索引 >= 三维UV集合.size())
                UV = 向量二维(0.0f);
            else
                UV = 三维UV集合[面顶点索引.UV索引];

            YS_RGB 颜色 = YS_RGB(0.0f);
            if (三维颜色集合.empty() || 面顶点索引.颜色索引 < 0 || 面顶点索引.颜色索引 >= 三维颜色集合.size())
                颜色 = YS_RGB(0.0f);
            else 颜色 = 面.统一着色;

            面顶点数据.push_back(Face_vectex_data(坐标, 法线, UV, 颜色));
        }
    }
    std::vector<float>顶点数据(面顶点数据.size() * 12);
    for (int i = 0; i < 面顶点数据.size(); i++)
    {
        int 索引 = i * 12;
        顶点数据[索引 + 0] = 面顶点数据[i].坐标.X;
        顶点数据[索引 + 1] = 面顶点数据[i].坐标.Y;
        顶点数据[索引 + 2] = 面顶点数据[i].坐标.Z;

        顶点数据[索引 + 3] = 面顶点数据[i].法线.X;
        顶点数据[索引 + 4] = 面顶点数据[i].法线.Y;
        顶点数据[索引 + 5] = 面顶点数据[i].法线.Z;

        顶点数据[索引 + 6] = 面顶点数据[i].UV.X;
        顶点数据[索引 + 7] = 面顶点数据[i].UV.Y;

        顶点数据[索引 + 8] = 面顶点数据[i].颜色.r;
        顶点数据[索引 + 9] = 面顶点数据[i].颜色.g;
        顶点数据[索引 + 10] = 面顶点数据[i].颜色.b;
        顶点数据[索引 + 11] = 面顶点数据[i].颜色.a;
    }
    std::vector<float> _坐标顶点(面顶点数据.size() * 3);
    for (int i = 0; i < 面顶点数据.size(); i++)
    {
        int 索引 = i * 12;
        int 叠加 = i * 3;
        _坐标顶点[叠加 + 0] = 顶点数据[索引 + 0];
        _坐标顶点[叠加 + 1] = 顶点数据[索引 + 1];
        _坐标顶点[叠加 + 2] = 顶点数据[索引 + 2];
    }

    索引面 = 面索引;
    索引面坐标集合 = _坐标顶点;
    //_渲染面.注册顶点缓冲(顶点数据, 面索引);
}

void Model_FWK::获取渲染边数据()
{
    std::vector<Face_vectex_data> 面顶点数据;
    std::vector<unsigned int>边索引;
    for (int i = 0; i < 索引边集合.size(); i++)
    {
        Index_data 索引数据边 = 索引边集合[i];
        for (int j = 0; j < 索引数据边.索引集合.size(); j++)
        {
            Vertex_index 面顶点索引 = 索引数据边.索引集合[j];
            边索引.push_back(面顶点数据.size());

            向量三维 坐标 = 向量三维(0.0f);
            if (三维坐标集合.empty() || 面顶点索引.坐标索引 < 0 || 面顶点索引.坐标索引 >= 三维坐标集合.size()) 坐标 = 向量三维(0.0f);
            else 坐标 = 三维坐标集合[面顶点索引.坐标索引];

            向量三维 法线 = 向量三维(0.0f);
            if (三维法线集合.empty() || 面顶点索引.法线索引 < 0 || 面顶点索引.法线索引 >= 三维法线集合.size())
                法线 = 向量三维(0.0f);
            else
                法线 = 三维法线集合[面顶点索引.法线索引];

            向量二维 UV = 向量二维(0.0f);
            if (三维UV集合.empty() || 面顶点索引.UV索引 < 0 || 面顶点索引.UV索引 >= 三维UV集合.size())
                UV = 向量二维(0.0f);
            else
                UV = 三维UV集合[面顶点索引.UV索引];

            YS_RGB 颜色 = YS_RGB(0.0f);
            if (三维颜色集合.empty() || 面顶点索引.颜色索引 < 0 || 面顶点索引.颜色索引 >= 三维颜色集合.size())
                颜色 = YS_RGB(0.0f);
            else 颜色 = 索引数据边.统一着色;

            面顶点数据.push_back(Face_vectex_data(坐标, 法线, UV, 颜色));
        }
    }

    std::vector<float>顶点数据(面顶点数据.size() * 12);
    for (int i = 0; i < 面顶点数据.size(); i++)
    {
        int 索引 = i * 12;
        顶点数据[索引 + 0] = 面顶点数据[i].坐标.X;
        顶点数据[索引 + 1] = 面顶点数据[i].坐标.Y;
        顶点数据[索引 + 2] = 面顶点数据[i].坐标.Z;

        顶点数据[索引 + 3] = 面顶点数据[i].法线.X;
        顶点数据[索引 + 4] = 面顶点数据[i].法线.Y;
        顶点数据[索引 + 5] = 面顶点数据[i].法线.Z;

        顶点数据[索引 + 6] = 面顶点数据[i].UV.X;
        顶点数据[索引 + 7] = 面顶点数据[i].UV.Y;

        顶点数据[索引 + 8] = 面顶点数据[i].颜色.r;
        顶点数据[索引 + 9] = 面顶点数据[i].颜色.g;
        顶点数据[索引 + 10] = 面顶点数据[i].颜色.b;
        顶点数据[索引 + 11] = 面顶点数据[i].颜色.a;
    }
    std::vector<float> _边坐标顶点(面顶点数据.size() * 3);
    for (int i = 0; i < 面顶点数据.size(); i++)
    {
        int 索引 = i * 12;
        int 叠加 = i * 3;
        _边坐标顶点[叠加 + 0] = 顶点数据[索引 + 0];
        _边坐标顶点[叠加 + 1] = 顶点数据[索引 + 1];
        _边坐标顶点[叠加 + 2] = 顶点数据[索引 + 2];
    }
    索引边 = 边索引;
    索引边坐标集合 = _边坐标顶点;
}

void Model_FWK::获取渲染点数据()
{
    std::vector<Face_vectex_data> 点顶点数据;
    std::vector<unsigned int>点索引;
    for (int i = 0; i < 索引点集合.size(); i++)
    {
        Index_data 索引数据点 = 索引点集合[i];
        for (int j = 0; j < 索引数据点.索引集合.size(); j++)
        {
            Vertex_index 面顶点索引 = 索引数据点.索引集合[j];
            点索引.push_back(点顶点数据.size());

            向量三维 坐标 = 向量三维(0.0f);
            if (三维坐标集合.empty() || 面顶点索引.坐标索引 < 0 || 面顶点索引.坐标索引 >= 三维坐标集合.size()) 坐标 = 向量三维(0.0f);
            else 坐标 = 三维坐标集合[面顶点索引.坐标索引];

            向量三维 法线 = 向量三维(0.0f);
            if (三维法线集合.empty() || 面顶点索引.法线索引 < 0 || 面顶点索引.法线索引 >= 三维法线集合.size())
                法线 = 向量三维(0.0f);
            else
                法线 = 三维法线集合[面顶点索引.法线索引];

            向量二维 UV = 向量二维(0.0f);
            if (三维UV集合.empty() || 面顶点索引.UV索引 < 0 || 面顶点索引.UV索引 >= 三维UV集合.size())
                UV = 向量二维(0.0f);
            else
                UV = 三维UV集合[面顶点索引.UV索引];

            YS_RGB 颜色 = YS_RGB(0.0f);
            if (三维颜色集合.empty() || 面顶点索引.颜色索引 < 0 || 面顶点索引.颜色索引 >= 三维颜色集合.size())
                颜色 = YS_RGB(0.0f);
            else 颜色 = 索引数据点.统一着色;

            点顶点数据.push_back(Face_vectex_data(坐标, 法线, UV, 颜色));
        }
    }

    std::vector<float>顶点数据(点顶点数据.size() * 12);
    for (int i = 0; i < 点顶点数据.size(); i++)
    {
        int 索引 = i * 12;
        顶点数据[索引 + 0] = 点顶点数据[i].坐标.X;
        顶点数据[索引 + 1] = 点顶点数据[i].坐标.Y;
        顶点数据[索引 + 2] = 点顶点数据[i].坐标.Z;

        顶点数据[索引 + 3] = 点顶点数据[i].法线.X;
        顶点数据[索引 + 4] = 点顶点数据[i].法线.Y;
        顶点数据[索引 + 5] = 点顶点数据[i].法线.Z;

        顶点数据[索引 + 6] = 点顶点数据[i].UV.X;
        顶点数据[索引 + 7] = 点顶点数据[i].UV.Y;

        顶点数据[索引 + 8] = 点顶点数据[i].颜色.r;
        顶点数据[索引 + 9] = 点顶点数据[i].颜色.g;
        顶点数据[索引 + 10] = 点顶点数据[i].颜色.b;
        顶点数据[索引 + 11] = 点顶点数据[i].颜色.a;
    }
    std::vector<float> _点坐标顶点(点顶点数据.size() * 3);
    for (int i = 0; i < 点顶点数据.size(); i++)
    {
        int 索引 = i * 12;
        int 叠加 = i * 3;
        _点坐标顶点[叠加 + 0] = 顶点数据[索引 + 0];
        _点坐标顶点[叠加 + 1] = 顶点数据[索引 + 1];
        _点坐标顶点[叠加 + 2] = 顶点数据[索引 + 2];
    }
    索引点 = 点索引;
    索引点坐标集合 = _点坐标顶点;

}

void Model_FWK::变换坐标(四元数 四元数)
{
    for (int i = 0; i < 三维坐标集合.size(); i++)
    {
        三维坐标集合[i] = 四元数::四元数乘三维向量(三维坐标集合[i], 四元数);
    }
    for (int i = 0; i < 三维法线集合.size(); i++)
    {
        三维法线集合[i] = 四元数::四元数乘三维向量(三维法线集合[i], 四元数);
    }
}

void Model_FWK::变换坐标(向量三维 向量)
{
    for (int i = 0; i < 三维坐标集合.size(); i++)
    {
        三维坐标集合[i] = 三维坐标集合[i] + 向量;
    }
}

void Model_FWK::变换坐标(矩阵4X4 矩阵)
{
    for (int i = 0; i < 三维坐标集合.size(); i++)
    {
        三维坐标集合[i] = 矩阵4X4::返回平移(三维坐标集合[i], 矩阵);
    }
    for (int i = 0; i < 三维法线集合.size(); i++)
    {
        三维法线集合[i] = 矩阵4X4::返回平移(三维法线集合[i], 矩阵4X4::创建法线矩阵(矩阵));
    }
}

std::vector<Index_data> Model_FWK::面提取边(std::vector<Index_data> _面合集)
{
    Index_list 边集合;
    for (int i = 0; i < _面合集.size(); i++)
    {
        Index_data 面 = _面合集[i];
        if (面.索引集合.size() > 2)
        {
            for (int j = 0; j < 面.索引集合.size(); j++)
            {
                int A = j, B = j + 1;
                if (B >= 面.索引集合.size()) B = 0;

                std::vector<Vertex_index> 数据;
                数据.push_back(Vertex_index(面.索引集合[A]));
                数据.push_back(Vertex_index(面.索引集合[B]));
                Index_data 边 = Index_data(数据);

                if (!边集合.查找(边)) 边集合.添加(边);

            }
        }
    }
    return 边集合.转列表();
}

std::vector<Index_data> Model_FWK::面提取点(std::vector<Index_data> _面合集)
{
    Index_list 点集合;
    for (int i = 0; i < _面合集.size(); i++)
    {
        Index_data 面 = _面合集[i];
        if (面.索引集合.size() > 2)
        {
            for (int j = 0; j < 面.索引集合.size(); j++)
            {
                Vertex_index 点索引 = 面.索引集合[j];
                std::vector<Vertex_index> m;
                m.push_back(点索引);
                Index_data 点 = Index_data(m);

                if (!点集合.查找(点)) 点集合.添加(点);
            }
        }
    }
    return 点集合.转列表();
}

Model_FWK Model_FWK::创建平面(float 宽度, float 高度, int 宽度分段, int 高度分段)
{
    
    float U间隔 = 宽度 / 宽度分段;
    float V间隔 = 高度 / 高度分段;
    向量三维 中心偏移 = 向量三维(1.0f);
    中心偏移 = 向量三维(宽度 / 2.0f, 0.0f, 高度 / 2.0f);
    std::vector<向量三维> _坐标集合;
    std::vector<向量二维> _UV集合;
    std::vector<向量三维> _法线集合;
    _法线集合.push_back(向量三维(0.0f, 1.0f, 0.0f));
    for (int x = 0; x <= 宽度分段; x++)
    {
        for (int y = 0; y <= 高度分段; y++)
        {
            _坐标集合.push_back(向量三维((float)x * U间隔, 0.0f, (float)y * V间隔) - 中心偏移);
            _UV集合.push_back(向量二维((float)x / (float)宽度分段, (float)y / (float)高度分段));
        }
    }
    std::vector<Index_data> _索引面集合;
    std::vector<Index_data> _索引边集合;
    std::vector<Index_data> _索引点集合;
    for (int i = 0; i < _坐标集合.size() - 高度分段 - 1; i++)
    {
        if ((i + 1) % (高度分段 + 1) != 0)
        {
            
            int 点0 = i;
            int 点1 = i + 高度分段 + 1;
            int 点2 = i + 高度分段 + 2;
            int 点3 = i + 1;
            std::vector<Vertex_index> 索引数据;
            索引数据.push_back(Vertex_index(点3, 0, 点3, 点3));
            索引数据.push_back(Vertex_index(点2, 0, 点2, 点2));
            索引数据.push_back(Vertex_index(点1, 0, 点1, 点1));
            索引数据.push_back(Vertex_index(点0, 0, 点0, 点0));
            
            _索引面集合.push_back(Index_data(索引数据));
        }
    }
    for (int i = 0; i < _坐标集合.size(); i++)
    {
        if (i < _坐标集合.size() - 高度分段 - 1)
        {
            int 点0 = i;
            int 点1 = i + 高度分段 + 1;
            std::vector<Vertex_index> 索引数据;
            索引数据.push_back(Vertex_index(点0, 0, 点0, 点0));
            索引数据.push_back(Vertex_index(点1, 0, 点1, 点1));
           
            _索引边集合.push_back(Index_data(索引数据));
        }
        if ((i + 1) % (高度分段 + 1) != 0)
        {
            int 点0 = i;
            int 点1 = i + 1;
            std::vector<Vertex_index> 索引数据;
            索引数据.push_back(Vertex_index(点0, 0, 点0, 点0));
            索引数据.push_back(Vertex_index(点1, 0, 点1, 点1));

            _索引边集合.push_back(Index_data(索引数据));
        }
    }
    std::vector<YS_RGB> _颜色集合;
    for (int i = 0; i < _坐标集合.size(); i++)
    {
        std::vector<Vertex_index> 索引数据;
        索引数据.push_back(Vertex_index(i, 0, i, i));
        _索引点集合.push_back(Index_data(索引数据));
        _颜色集合.push_back(YS_RGB(0));
    }

    return Model_FWK(_坐标集合, _法线集合, _UV集合, _颜色集合, _索引面集合, _索引边集合, _索引点集合);
    
}

Model_FWK Model_FWK::合并模型(std::vector<Model_FWK> 模型列表)
{
    std::vector<向量三维> 构建坐标集合;
    std::vector<向量三维> 构建法线集合;
    std::vector<向量二维> 构建UV集合;
    std::vector<YS_RGB> 构建颜色集合;
    for (int i = 0; i < 模型列表.size(); i++)
    {
        Model_FWK 模型数据 = 模型列表[i];
        for (向量三维 坐标 : 模型数据.三维坐标集合) 构建坐标集合.push_back(坐标);
        for (向量三维 法线 : 模型数据.三维法线集合) 构建法线集合.push_back(法线);
        for (向量二维 UV : 模型数据.三维UV集合) 构建UV集合.push_back(UV);
        for (YS_RGB 颜色 : 模型数据.三维颜色集合) 构建颜色集合.push_back(颜色);
    }

    std::vector<Index_data> 构建面集合;
    std::vector<Index_data> 构建边集合;
    std::vector<Index_data> 构建点集合;
    int 坐标偏移 = 0, 法线偏移 = 0, UV偏移 = 0, 颜色偏移 = 0;
    for (int i = 0; i < 模型列表.size(); i++)
    {
        Model_FWK 模型 = 模型列表[i];
        if (!模型.索引面集合.empty())
        {
            for (int j = 0; j < 模型.索引面集合.size(); j++)
            {
                Index_data 索引数据面 = 模型.索引面集合[j];
                构建面集合.push_back(索引数据面.索引偏移(坐标偏移, 法线偏移, UV偏移, 颜色偏移));
            }
        }
        if (!模型.索引边集合.empty())
        {
            for (int j = 0; j < 模型.索引边集合.size(); j++)
            {
                Index_data 索引数据边 = 模型.索引边集合[j];
                构建边集合.push_back(索引数据边.索引偏移(坐标偏移, 法线偏移, UV偏移, 颜色偏移));
            }
        }
        if (!模型.索引点集合.empty())
        {
            for (int j = 0; j < 模型.索引点集合.size(); j++)
            {
                Index_data 索引数据点 = 模型.索引点集合[j];
                构建点集合.push_back(索引数据点.索引偏移(坐标偏移, 法线偏移, UV偏移, 颜色偏移));
            }
        }
        坐标偏移 += 模型.三维坐标集合.size();
        法线偏移 += 模型.三维坐标集合.size();
        UV偏移 += 模型.三维坐标集合.size();
        颜色偏移 += 模型.三维坐标集合.size();
    }


    return Model_FWK(构建坐标集合, 构建法线集合, 构建UV集合, 构建颜色集合, 构建面集合, 构建边集合, 构建点集合);
}

void Model_FWK::平滑着色(Model_FWK& 模型, float 角度)
{
    float 平滑弧度 = 角度 * 计算::弧度();
    //int 点 法线
    std::unordered_map<int, std::vector<Vectex_face>> 顶点关联面集合;

    for (int i = 0; i < 模型.索引面集合.size(); i++)
    {
        Index_data 面 = 模型.索引面集合[i];
        std::vector<向量三维> 数据;
        数据.push_back(模型.三维坐标集合[面.索引集合[0].坐标索引]);
        数据.push_back(模型.三维坐标集合[面.索引集合[1].坐标索引]);
        数据.push_back(模型.三维坐标集合[面.索引集合[2].坐标索引]);
        向量三维 面法线 = 向量三维::计算面法线(数据);
        if (向量三维::检查为空(面法线)) 面法线 = 向量三维(0);

        for (int j = 0; j < 面.索引集合.size(); j++)
        {
            Vertex_index 索引 = 面.索引集合[j];

            if (顶点关联面集合.count(索引.坐标索引))
            {
                //修改
                Vectex_face 关联数据;
                关联数据.顶点索引 = 索引;
                关联数据.法线 = 面法线;
                std::vector<Vectex_face>顶点关联数据 = 顶点关联面集合[索引.坐标索引];// [索引.坐标索引] = 关联数据;
                顶点关联数据.push_back(关联数据);
                顶点关联面集合[索引.坐标索引] = 顶点关联数据;
            }
            else
            {
                //添加
                Vectex_face 关联数据;
                关联数据.顶点索引 = 索引;
                关联数据.法线 = 面法线;
                std::vector<Vectex_face>顶点关联数据;
                顶点关联数据.push_back(关联数据);
                顶点关联面集合.insert(std::make_pair(索引.坐标索引, 顶点关联数据));
            }

        }

    }

    std::vector<平滑集合> 平滑着色合集;
    for (auto it = 顶点关联面集合.begin(); it != 顶点关联面集合.end(); ++it)
    {
        //点 法线
        std::vector<Vectex_face>顶点关联 = it->second;
        std::vector<向量三维> 法线;
        for (int i = 0; i < 顶点关联.size(); i++)
        {
            //点 法线
            Vectex_face 法线数据 = 顶点关联[i];
            法线.push_back(法线数据.法线);
        }
        向量三维 平滑法线 = 向量三维::计算单位向量(向量三维::计算重心(法线));

        for (int i = 0; i < 顶点关联.size(); i++)
        {
            // 点 法线
            Vectex_face 点数据 = 顶点关联[i];
            if (向量三维::计算夹角(平滑法线, 点数据.法线) < 平滑弧度)
            {
                if (列表添加并查重(平滑着色合集, 平滑法线))
                {
                    平滑集合 数据;
                    数据.法线 = 平滑法线;
                    数据.索引 = 平滑着色合集.size();
                    平滑着色合集.push_back(数据);
                }
            }
            else
            {
                if (列表添加并查重(平滑着色合集, 点数据.法线))
                {
                    平滑集合 数据;
                    数据.法线 = 点数据.法线;
                    数据.索引 = 平滑着色合集.size();
                    平滑着色合集.push_back(数据);
                }
            }
        }

    }

    std::vector<向量三维> 法线集合;
    for (int i = 0; i < 平滑着色合集.size(); i++)
    {
        法线集合.push_back(平滑着色合集[i].法线);
    }

    模型.三维法线集合 = 法线集合;
}

Model_FWK Model_FWK::创建面(std::vector<向量三维> _坐标合集)
{
    return Model_FWK();
}

void Model_FWK::优化顶点模型(Model_FWK& 模型, float 公差)
{
    std::vector<向量三维> 去重坐标集合;
    std::unordered_map<int, int> 坐标映射集合;
    for (int i = 0; i < 模型.三维坐标集合.size(); i++)
    {
        向量三维 坐标 = 模型.三维坐标集合[i];
        int 查找坐标索引 = -1;
        if (去重坐标集合.empty())
        {
            查找坐标索引 = -1;
        }
        else
        {
            for (int j = 0; j < 去重坐标集合.size(); j++)
            {
                向量三维 zb = 去重坐标集合[j];
                //计算空间两点直线距离
                float 距离 = 向量三维::计算距离(zb, 坐标);
                if (距离 < 公差)
                {
                    查找坐标索引 = j;
                    break;
                }
                else 查找坐标索引 = -1;
            }
        }

        if (查找坐标索引 == -1)
        {
            坐标映射集合.insert(std::make_pair(i, (int)去重坐标集合.size()));
            去重坐标集合.push_back(坐标);
        }
        else 坐标映射集合.insert(std::make_pair(i, 查找坐标索引));
    }

    Index_list 去重面集合;
    for (int i = 0; i < 模型.索引面集合.size(); i++)
    {
        std::vector<Vertex_index> 顶点集合;
        Index_data 面 = 模型.索引面集合[i];
        for (int j = 0; j < 面.索引集合.size(); j++)
        {
            Vertex_index 顶点 = 面.索引集合[j];
            Vertex_index 映射顶点 = Vertex_index(坐标映射集合[顶点.坐标索引], 坐标映射集合[顶点.法线索引], 坐标映射集合[顶点.UV索引], 坐标映射集合[顶点.颜色索引]);
            if (顶点集合.empty())顶点集合.push_back(映射顶点);
            else if (是否包含(顶点集合, 映射顶点))顶点集合.push_back(映射顶点);
        }
        if (!顶点集合.empty() && 顶点集合.size() > 2)
        {
            Index_data 记录面 = Index_data(顶点集合);
            if (!去重面集合.查找(记录面)) 去重面集合.添加(记录面);
        }
    }

    Index_list 去重边集合;
    for (int i = 0; i < 模型.索引边集合.size(); i++)
    {
        std::vector<Vertex_index> 顶点集合;
        Index_data 边 = 模型.索引边集合[i];
        for (int j = 0; j < 边.索引集合.size(); j++)
        {
            Vertex_index 顶点 = 边.索引集合[j];
            Vertex_index 映射顶点 = Vertex_index(坐标映射集合[顶点.坐标索引], 顶点.法线索引, 顶点.UV索引, 顶点.颜色索引);
            if (顶点集合.empty()) 顶点集合.push_back(映射顶点);
            else if (是否包含(顶点集合, 映射顶点))顶点集合.push_back(映射顶点);
        }
        if (顶点集合.size() > 1)
        {
            Index_data 记录边 = Index_data(顶点集合);
            if (!去重边集合.查找(记录边)) 去重边集合.添加(记录边);
        }
    }

    Index_list 去重点集合;
    for (int i = 0; i < 模型.索引点集合.size(); i++)
    {
        std::vector<Vertex_index> 顶点集合;
        Index_data 点 = 模型.索引点集合[i];
        for (int j = 0; j < 点.索引集合.size(); j++)
        {
            Vertex_index 顶点 = 点.索引集合[j];
            Vertex_index 映射顶点 = Vertex_index(坐标映射集合[顶点.坐标索引], 坐标映射集合[顶点.法线索引], 坐标映射集合[顶点.UV索引], 坐标映射集合[顶点.颜色索引]);
            if (顶点集合.empty()) 顶点集合.push_back(映射顶点);
            else if (是否包含(顶点集合, 映射顶点))顶点集合.push_back(映射顶点);
        }
        if (!顶点集合.empty() && 顶点集合.size() > 0)
        {
            Index_data 记录点 = Index_data(顶点集合);
            if (!去重点集合.查找(记录点)) 去重点集合.添加(记录点);
        }
    }
    模型.三维坐标集合 = 去重坐标集合;
    模型.索引面集合 = 去重面集合.转列表();
    模型.索引边集合 = 去重边集合.转列表();
    模型.索引点集合 = 去重点集合.转列表();
}

Model_FWK Model_FWK::创建立方体(float 尺寸x, float 尺寸y, float 尺寸z, int 分段x, int 分段y, int 分段z)
{
    
    Model_FWK 正面 = 创建平面(尺寸x, 尺寸y, 分段x, 分段y) * 四元数::创建轴角旋转(向量三维::X轴(), 计算::角度转弧度(-90));
    Model_FWK 背面 = 正面 * 四元数::创建轴角旋转(向量三维::X轴(), 计算::角度转弧度(180));

    四元数 零时变量 = 四元数::创建轴角旋转(向量三维::X轴(), 计算::角度转弧度(90)) * 四元数::创建轴角旋转(向量三维::Z轴(), 计算::角度转弧度(-90));
    Model_FWK 右面 = 创建平面(尺寸z, 尺寸y, 分段z, 分段y) * 零时变量;
    Model_FWK 左面 = 右面 * 四元数::创建轴角旋转(向量三维::Z轴(), 计算::角度转弧度(-180));

    Model_FWK 顶面 = 创建平面(尺寸x, 尺寸z, 分段x, 分段z);
    Model_FWK 底面 = 顶面 * 四元数::创建轴角旋转(向量三维::X轴(), 计算::角度转弧度(180));

    正面 = 正面 - 向量三维(0, 0, 尺寸z * 0.5f);
    背面 = 背面 + 向量三维(0, 0, 尺寸z * 0.5f);

    右面 = 右面 + 向量三维(尺寸x * 0.5f, 0, 0);
    左面 = 左面 - 向量三维(尺寸x * 0.5f, 0, 0);

    顶面 = 顶面 + 向量三维(0, 尺寸y * 0.5f, 0);
    底面 = 底面 - 向量三维(0, 尺寸y * 0.5f, 0);

    std::vector<Model_FWK> 模型列表;
    模型列表.push_back(正面);
    模型列表.push_back(背面);
    模型列表.push_back(右面);
    模型列表.push_back(左面);
    模型列表.push_back(顶面);
    模型列表.push_back(底面);
    Model_FWK 新模型 = 合并模型(模型列表);

    优化顶点模型(新模型);

    return 新模型;

}

Model_FWK Model_FWK::创建圆管(float 半径, float 高度, int 旋转分段, int 高度分段, float 起点角度, float 终点角度)
{
    计算::重新分配大小(起点角度, 终点角度);
    if (std::abs(终点角度 - 起点角度) > 360) 终点角度 = 起点角度 + 360;
    std::vector<向量三维> 旋转向量集合;
    旋转向量集合.push_back(向量三维(高度分段 + 1));
    float 半高 = 高度 / 2;
    for (int i = 0; i < 旋转向量集合.size(); i++)
    {
        float 高度百分比 = (float)i / (旋转向量集合.size() - 1);
        矩阵4X4 旋转矩阵 = 矩阵4X4::创建旋转矩阵Y(起点角度 * 计算::弧度());
        旋转向量集合[i] = 旋转矩阵 * 向量三维(半径, 高度百分比 * 高度 - 半高, 0);
    }
    std::vector<向量三维> 坐标集合;
    std::vector<向量三维> 法线集合;
    std::vector<向量二维> UV集合;
    std::vector<YS_RGB> 颜色集合;
    颜色集合.push_back(YS_RGB());
    for (int i = 0; i <= 旋转分段; i++)
    {
        float U = (float)i / 旋转分段;
        矩阵4X4 旋转矩阵 = 矩阵4X4::创建旋转矩阵Y(U * (终点角度 - 起点角度) * 计算::弧度());
        for (int j = 0; j < 旋转向量集合.size(); j++)
        {
            float V = (float)j / (旋转向量集合.size() - 1);
            向量三维 坐标 = 旋转矩阵 * 旋转向量集合[j];
            坐标集合.push_back(坐标);
            法线集合.push_back(向量三维::计算单位向量(向量三维(坐标.X, 0, 坐标.Z)));
            UV集合.push_back(向量二维(1 - U, V));
        }
    }

    std::vector<Index_data> 面集合;
    std::vector<Index_data> 边集合;
    std::vector<Index_data> 点集合;
    for (int i = 0; i < 坐标集合.size() - 高度分段 - 1; i++)
    {
        if ((i + 1) % (高度分段 + 1) != 0)
        {
            int 点0 = i;
            int 点1 = i + 高度分段 + 1;
            int 点2 = i + 高度分段 + 2;
            int 点3 = i + 1;
            std::vector<Vertex_index> 顶点索引;
            顶点索引.push_back(Vertex_index(点0, 点0, 点0, 点0));
            顶点索引.push_back(Vertex_index(点1, 点1, 点1, 点1));
            顶点索引.push_back(Vertex_index(点2, 点2, 点2, 点2));
            顶点索引.push_back(Vertex_index(点3, 点3, 点3, 点3));

            面集合.push_back(Index_data(顶点索引));
        }
    }
    for (int i = 0; i < 坐标集合.size(); i++)
    {
        if (i < 坐标集合.size() - 高度分段 - 1)
        {
            int 点0 = i;
            int 点1 = i + 高度分段 + 1;
            std::vector<Vertex_index> 顶点索引;
            顶点索引.push_back(Vertex_index(点0, 点0, 点0, 点0));
            顶点索引.push_back(Vertex_index(点1, 点1, 点1, 点1));

            边集合.push_back(Index_data(顶点索引));
        }
        if ((i + 1) % (高度分段 + 1) != 0)
        {
            int 点0 = i;
            int 点1 = i + 1;
            std::vector<Vertex_index> 顶点索引;
            顶点索引.push_back(Vertex_index(点0, 点0, 点0, 点0));
            顶点索引.push_back(Vertex_index(点1, 点1, 点1, 点1));

            边集合.push_back(Index_data(顶点索引));
        }
    }
    for (int i = 0; i < 坐标集合.size(); i++)
    {
        std::vector<Vertex_index> 顶点索引;
        顶点索引.push_back(Vertex_index(i, i, i, i));
        点集合.push_back(Index_data(顶点索引));
    }
    Model_FWK 新模型;
    新模型.三维坐标集合 = 坐标集合;
    新模型.三维法线集合 = 法线集合;
    新模型.三维UV集合 = UV集合;
    新模型.索引面集合 = 面集合;
    新模型.索引边集合 = 边集合;
    新模型.索引点集合 = 点集合;
    新模型.三维颜色集合 = 颜色集合;
    if (终点角度 - 起点角度 == 0) 优化顶点模型(新模型);

    return 新模型;
}

Model_FWK Model_FWK::创建球体(float 半径, int 分段)
{
    int 经度分段 = 分段;
    int 纬度分段 = 经度分段 / 2 + 1;
    float 旋转角度 = 计算::角360() / 经度分段;
    std::vector<向量三维> 旋转向量集合(纬度分段);
    for (int i = 0; i < 纬度分段; i++)
    {
        float V百分比 = (float)i / (纬度分段 - 1);
        旋转向量集合[i] = 矩阵4X4::返回平移(向量三维::Y轴(), 矩阵4X4::创建旋转矩阵Z(V百分比 * 计算::角180()));
    }

    std::vector<向量三维> _坐标集合;
    std::vector<向量二维> _UV集合;
    for (int x = 0; x < 经度分段; x++)
    {
        float U百分比 = x / (float)经度分段;
        for (int y = 0; y < 纬度分段; y++)
        {
            float V百分比 = (float)y / (纬度分段 - 1);
            向量三维 法线 = 矩阵4X4::返回平移(旋转向量集合[y], 矩阵4X4::创建旋转矩阵Y(x * -旋转角度));
            _坐标集合.push_back(法线 * 半径);
            _UV集合.push_back(向量二维(U百分比, 1 - V百分比));
        }
    }
    for (int y = 0; y < 纬度分段; y++)
    {
        float V百分比 = y / (float)(纬度分段 - 1.0);
        _UV集合.push_back(向量二维(1, 1 - V百分比));
    }

    std::vector<Index_data> 面集合;
    for (int i = 0; i < _坐标集合.size() - 1; i++)
    {
        int UV0 = i;
        int UV1 = i + 纬度分段;
        int UV2 = i + 纬度分段 + 1;
        int UV3 = i + 1;

        int 点0 = UV0;
        int 点1 = UV1;
        int 点2 = UV2;
        int 点3 = UV3;

        if (!(点1 < _坐标集合.size())) 点1 -= _坐标集合.size();
        if (!(点2 < _坐标集合.size())) 点2 -= _坐标集合.size();
        if (!(点3 < _坐标集合.size())) 点3 -= _坐标集合.size();


        if ((i + 1) % 纬度分段 == 0)
        {
            //面集合.Add(new 索引数据(
            //   new 顶点索引(点3, 点3, UV3, 0),
            //   new 顶点索引(点2, 点2, UV2, 0),
            //   new 顶点索引(点1, 点1, UV1, 0),
            //   new 顶点索引(点0, 点0, UV0, 0)
            //));

        }
        else
        {
            std::vector<Vertex_index> 数据;
            数据.push_back(Vertex_index(点0, 点0, UV0, 0));
            数据.push_back(Vertex_index(点1, 点1, UV1, 0));
            数据.push_back(Vertex_index(点2, 点2, UV2, 0));
            数据.push_back(Vertex_index(点3, 点3, UV3, 0));
            面集合.push_back(Index_data(数据));
        }

    }
    Model_FWK 球体模型;
    球体模型.三维坐标集合 = _坐标集合;
    球体模型.三维UV集合 = _UV集合;
    球体模型.三维颜色集合.push_back(YS_RGB(0));
    球体模型.索引面集合 = 面集合;
    球体模型.索引边集合 = 面提取边(面集合);
    球体模型.索引点集合 = 面提取点(面集合);
    优化顶点模型(球体模型);
    return 球体模型;
}

Model_FWK Model_FWK::创建半球体(float 半径, int 分段)
{
    return Model_FWK();
}

Model_FWK Model_FWK::创建金字塔(float 尺寸X, float Y, float Z)
{
    float x = 尺寸X / 2.0f;
    float y = Y;
    float z = Z / 2.0f;
    std::vector<向量三维> 坐标集合;
    坐标集合.push_back(向量三维(-x, 0, -z));
    坐标集合.push_back(向量三维(+x, 0, -z));
    坐标集合.push_back(向量三维(+x, 0, +z));
    坐标集合.push_back(向量三维(-x, 0, +z));
    坐标集合.push_back(向量三维(0, y, 0));
    std::vector<向量三维> 法线集合;
    for (int i = 0; i < 坐标集合.size(); i++)
    {
        法线集合.push_back(向量三维::计算单位向量(坐标集合[i]));
    }
    std::vector<向量二维> UV集合;
    UV集合.push_back(向量二维(0, 0));
    UV集合.push_back(向量二维(1, 0));
    UV集合.push_back(向量二维(1, 1));
    UV集合.push_back(向量二维(0, 1));
    UV集合.push_back(向量二维(0.5f, 1));

    std::vector<Index_data> 面集合;
    std::vector<Vertex_index> 数据;
    数据.push_back(Vertex_index(0, 0, 0, 0));
    数据.push_back(Vertex_index(1, 1, 1, 1));
    数据.push_back(Vertex_index(2, 2, 2, 2));
    数据.push_back(Vertex_index(3, 3, 3, 3));
    面集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(0, 0, 1, 0));
    数据.push_back(Vertex_index(4, 4, 4, 4));
    数据.push_back(Vertex_index(1, 1, 2, 1));
    面集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(1, 0, 1, 0));
    数据.push_back(Vertex_index(4, 1, 4, 4));
    数据.push_back(Vertex_index(2, 2, 2, 2));
    面集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(2, 0, 1, 2));
    数据.push_back(Vertex_index(4, 1, 4, 4));
    数据.push_back(Vertex_index(3, 2, 2, 3));
    面集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(3, 0, 1, 3));
    数据.push_back(Vertex_index(4, 1, 4, 4));
    数据.push_back(Vertex_index(0, 2, 2, 0));
    面集合.push_back(Index_data(数据));



    std::vector<Index_data> 边集合;
    数据.clear();
    数据.push_back(Vertex_index(0, 0, 0, 0));
    数据.push_back(Vertex_index(4, 4, 4, 0));
    边集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(1, 1, 1, 0));
    数据.push_back(Vertex_index(4, 4, 4, 4));
    边集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(2, 2, 2, 2));
    数据.push_back(Vertex_index(4, 4, 4, 4));
    边集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(3, 3, 3, 3));
    数据.push_back(Vertex_index(4, 4, 4, 4));
    边集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(0, 0, 0, 0));
    数据.push_back(Vertex_index(1, 1, 1, 1));
    边集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(1, 1, 1, 0));
    数据.push_back(Vertex_index(2, 2, 2, 2));
    边集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(2, 2, 2, 0));
    数据.push_back(Vertex_index(3, 3, 3, 3));
    边集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(3, 3, 3, 3));
    数据.push_back(Vertex_index(0, 0, 0, 0));
    边集合.push_back(Index_data(数据));

    std::vector<Index_data> 点集合;
    数据.clear();
    数据.push_back(Vertex_index(0, 0, 0, 0));
    点集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(1, 1, 1, 1));
    点集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(2, 2, 2, 2));
    点集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(3, 3, 3, 3));
    点集合.push_back(Index_data(数据));

    数据.clear();
    数据.push_back(Vertex_index(4, 4, 4, 4));
    点集合.push_back(Index_data(数据));

    std::vector<YS_RGB> 颜色集合;
    for (int i = 0; i < 坐标集合.size(); i++)
    {
        颜色集合.push_back(YS_RGB());
    }


    return Model_FWK(坐标集合, 法线集合, UV集合, 颜色集合, 面集合, 边集合, 点集合);
}

Model_FWK Model_FWK::创建圆盘(float 内半径, float 外半径, int 圆盘分段, int 旋转分段, float 起点角度, float 终点角度)
{
    计算::重新分配大小(内半径, 外半径);
    计算::重新分配大小(起点角度, 终点角度);
    std::vector<向量三维> 旋转向量集合(2);
    for (int i = 0; i < 旋转向量集合.size(); i++)
    {
        矩阵4X4 旋转矩阵 = 矩阵4X4::创建旋转矩阵Y(起点角度 * 计算::弧度());
        旋转向量集合[i] = 旋转矩阵 * 向量三维((float)i / 圆盘分段 * (外半径 - 内半径) + 内半径, 0, 0);
    }
    std::vector<向量三维> 坐标集合;
    std::vector<向量三维> 法线集合;
    法线集合.push_back(向量三维::Y轴());
    std::vector<向量二维> UV集合;
    std::vector<YS_RGB> 颜色集合;
    颜色集合.push_back(YS_RGB());

    for (int i = 0; i <= 旋转分段; i++)
    {
        float U = (float)i / 旋转分段;
        矩阵4X4 旋转矩阵 = 矩阵4X4::创建旋转矩阵Y(U * (终点角度 - 起点角度) * 计算::弧度());
        for (int j = 0; j < 旋转向量集合.size(); j++)
        {
            向量三维 坐标 = 旋转矩阵 * 旋转向量集合[j];
            坐标集合.push_back(坐标);
            if (内半径 == 0)
            {
                UV集合.push_back(向量二维(计算::范围映射(坐标.X, 0, 外半径, 0, 0.5f) + 0.5f, 计算::范围映射(坐标.Z, 0, 外半径, 0, 0.5f) + 0.5f));
            }
            else
            {
                float V = (float)j / (旋转向量集合.size() - 1);
                UV集合.push_back(向量二维(U, V));
            }
        }
    }

    Index_list 面集合;
    Index_list 边集合;
    Index_list 点集合;
    for (int i = 0; i < 坐标集合.size() - 旋转向量集合.size() - 1; i++)
    {
        if (i % 旋转向量集合.size() != 旋转向量集合.size() - 1)
        {
            int A = i;
            int B = A + 1;
            int C = A + 旋转向量集合.size();
            int D = C + 1;

            std::vector<Vertex_index> 索引数据;
            索引数据.push_back(Vertex_index(A, 0, A, 0));
            索引数据.push_back(Vertex_index(B, 0, B, 0));
            索引数据.push_back(Vertex_index(D, 0, D, 0));
            索引数据.push_back(Vertex_index(C, 0, C, 0));

            Index_data 面 = Index_data(索引数据);
            if (!面集合.查找(面)) 面集合.添加(面);
           
            for (int j = 0; j < 面.索引集合.size() - 1; j++)
            {
                std::vector<Vertex_index> 顶点索引;
                顶点索引.push_back(面.索引集合[j]);
                顶点索引.push_back(面.索引集合[j + 1]);
                Index_data 边 = Index_data(顶点索引);

                顶点索引.clear();
                顶点索引.push_back(面.索引集合[j]);
                Index_data 点 = Index_data(顶点索引);

                if (!边集合.查找(边))
                    边集合.添加(边);
                if (!点集合.查找(点))
                    点集合.添加(点);
            }
        }
    }

    std::vector<Index_data> _面集合 = 面集合.转列表();
    std::vector<Index_data> _边集合 = 边集合.转列表();
    std::vector<Index_data> _点集合 = 点集合.转列表();

    return Model_FWK(坐标集合, 法线集合, UV集合, 颜色集合, _面集合, _边集合, _点集合);
}

Model_FWK Model_FWK::创建管道(float 内半径, float 外半径, float 高度, int 旋转分段, int 圆盘分段, int 高度分段, float 起点角度, float 终点角度)
{
    return Model_FWK();
}

Model_FWK Model_FWK::创建线条(std::vector<向量三维> 坐标列表)
{
    std::vector<向量三维> _法线合集;
    _法线合集.push_back(向量三维::Y轴());
    std::vector<向量二维> _UV合集;
    _UV合集.push_back(向量二维(0));

    std::vector<Index_data> _面集合;
    std::vector<Index_data> _边集合;
    for (int i = 0; i < 坐标列表.size() - 1; i++)
    {
        _边集合.push_back(Index_data(Index_data::顶点索引转列表(Vertex_index(i, 0, 0, i), Vertex_index(i + 1, 0, 0, i + 1))));
    }

    std::vector<Index_data> _点集合;
    for (int i = 0; i < 坐标列表.size() - 1; i++)
    {
        _点集合.push_back(Index_data(Index_data::顶点索引转列表(Vertex_index(i, 0, 0, 0))));
    }
    std::vector<YS_RGB> _颜色集合;
    for (int i = 0; i < 坐标列表.size() - 1; i++)
    {
        _颜色集合.push_back(YS_RGB(0));
    }
    return Model_FWK(坐标列表, _法线合集, _UV合集, _颜色集合, _面集合, _边集合, _点集合);
}

Model_FWK Model_FWK::创建线条(std::vector<Line_seg> 坐标列表)
{
    std::vector<向量三维> 坐标集合;
    std::vector<Index_data> 边索引;
    for (int i = 0; i < 坐标列表.size(); i++)
    {
        Line_seg 线段 = 坐标列表[i];
        for (int j = 0; j < 线段.顶点坐标集合.size()-1; j++)
        {
            std::vector<Vertex_index> 索引数据;
            索引数据.push_back(Vertex_index(坐标集合.size() + j, 0, 0, 0));
            索引数据.push_back(Vertex_index(坐标集合.size() + j + 1, 0, 0, 0));
            边索引.push_back(Index_data(索引数据));
            
        }
        for (int j = 0; j < 线段.顶点坐标集合.size(); j++)
        {
            坐标集合.push_back(线段.顶点坐标集合[j]);
        }
       
    }
    Model_FWK 新模型;
    新模型.三维坐标集合 = 坐标集合;
    新模型.索引边集合 = 边索引;
    return 新模型;
}

Model_FWK Model_FWK::创建箭头线(向量三维 起点, 向量三维 终点, float 箭头尺寸)
{
    四元数 旋转 = 四元数::创建目标旋转(起点, 终点, 向量三维::Y轴(), 向量三维::Z轴());
    std::vector<向量三维> 列表;
    列表.push_back(向量三维::零());
    列表.push_back(向量三维(-箭头尺寸, 0, -箭头尺寸));
    Model_FWK 模型A = 创建线条(列表) * 旋转 + 终点;

    列表.clear();
    列表.push_back(向量三维::零());
    列表.push_back(向量三维(箭头尺寸, 0, -箭头尺寸));
    Model_FWK 模型B = 创建线条(列表) * 旋转 + 终点;
    列表.clear();
    列表.push_back(起点);
    列表.push_back(终点);
    Model_FWK 模型C = 创建线条(列表);

    std::vector<Model_FWK> 模型列表;
    模型列表.push_back(模型A);
    模型列表.push_back(模型B);
    模型列表.push_back(模型C);
    return 合并模型(模型列表);
}

Model_FWK Model_FWK::创建圆环线(float 半径, int 分段)
{
    return Model_FWK();
}

std::vector<Index_data> Model_FWK::获取三角面集合()
{
    std::vector<Index_data> 三角面索引合集;
    for (int i = 0; i < 索引面集合.size(); i++)
    {
        Index_data 面 = 索引面集合[i];
        if (面.索引集合.size() == 3)
        {
            三角面索引合集.push_back(面);
        }
        else
        {
            for (int i = 2; i < 面.索引集合.size(); i++)
            {
                int 点1 = 0;
                int 点2 = i - 1;
                int 点3 = i;
                std::vector<Vertex_index> 顶点索引;
                顶点索引.push_back(面.索引集合[点1]);
                顶点索引.push_back(面.索引集合[点2]);
                顶点索引.push_back(面.索引集合[点3]);
                三角面索引合集.push_back(Index_data(顶点索引));
                
            }
        }
    }
    return 三角面索引合集;
}

bool Model_FWK::是否包含(std::vector<Vertex_index> 数据, Vertex_index 查找)
{
    for (int i = 0; i < 数据.size(); i++)
    {
        if (数据[i] == 查找) return false;
    }
    return true;
}

bool Model_FWK::列表添加并查重(std::vector<平滑集合> 集合, 向量三维 法线)
{
    if (集合.empty())return true;
    else {
        for (int i = 0; i < 集合.size(); i++)
        {
            if (集合[i].法线 == 法线)return false;
        }
    }
    return true;
}





Model_FWK Model_FWK::operator*(四元数 四元数)
{
    Model_FWK 新模型(三维坐标集合, 三维法线集合, 三维UV集合, 三维颜色集合, 索引面集合, 索引边集合, 索引点集合);
    新模型.变换坐标(四元数);
    return 新模型;
}

Model_FWK Model_FWK::operator+(向量三维 向量)
{
    Model_FWK 新模型(三维坐标集合, 三维法线集合, 三维UV集合, 三维颜色集合, 索引面集合, 索引边集合, 索引点集合);
    新模型.变换坐标(向量);
    return 新模型;
}

Model_FWK Model_FWK::operator-(向量三维 向量)
{
    Model_FWK 新模型(三维坐标集合, 三维法线集合, 三维UV集合, 三维颜色集合, 索引面集合, 索引边集合, 索引点集合);
    新模型.变换坐标(-向量);
    return 新模型;
}

Model_FWK Model_FWK::operator+(Model_FWK 模型)
{
    Model_FWK 新模型;
    新模型.三维坐标集合 = 三维坐标集合;
    新模型.三维法线集合 = 三维法线集合;
    新模型.三维UV集合 = 三维UV集合;
    新模型.三维颜色集合 = 三维颜色集合;
    新模型.索引面集合 = 索引面集合;
    新模型.索引边集合 = 索引边集合;
    新模型.索引点集合 = 索引点集合;

    std::vector<Model_FWK> 模型列表;
    模型列表.push_back(新模型);
    模型列表.push_back(模型);
    return 合并模型(模型列表);
}

Model_FWK Model_FWK::operator*(矩阵4X4 矩阵)
{
    Model_FWK 新模型;
    新模型.三维坐标集合 = 三维坐标集合;
    新模型.三维法线集合 = 三维法线集合;
    新模型.三维UV集合 = 三维UV集合;
    新模型.三维颜色集合 = 三维颜色集合;
    新模型.索引面集合 = 索引面集合;
    新模型.索引边集合 = 索引边集合;
    新模型.索引点集合 = 索引点集合;
    新模型.变换坐标(矩阵);
    return 新模型;
}
