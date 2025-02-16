#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include <QLabel>
#include <QCheckBox>
#include <QPushButton>

#include "Color_widget.h"

//渲染状态显示
class Render_state_data :
    public QWidget
{
    Q_OBJECT
public:
    explicit Render_state_data(QWidget* parent = nullptr);
    ~Render_state_data();
    void 数据更新(QString 名,bool _状态);
public:
    QLabel* 名称;
    QCheckBox* 状态;
    QPushButton* 调色板;
    Color_widget* 调色板窗口;
    bool 调色板状态 = true;
    QColor 面板颜色;

signals:
    //颜色更新信号
    void setcolor(QColor color);
};

