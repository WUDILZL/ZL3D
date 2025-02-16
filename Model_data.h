#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QLabel>
#include <QMouseEvent>
#include <QStackedWidget>


#include "Model_FWK.h"
#include "Coord_data.h"
#include "Render_state_data.h"
#include "ZLSlider.h"

//数据显示窗口
class Model_data :
    public QWidget
{
    Q_OBJECT
public:

    explicit Model_data(QWidget* parent = nullptr);
    ~Model_data();

    void 更新数据(ui显示数据 参数);
    void 跟踪更新参数(ui显示数据 参数);

public:
    
    QLabel* 名字;

    QCheckBox* 选取状态;

    ZLSlider* 尺寸x;
    ZLSlider* 尺寸y;
    ZLSlider* 尺寸z;

    ZLSlider* 分段x;
    ZLSlider* 分段y;
    ZLSlider* 分段z;

    Render_state_data* 面状态;
    Render_state_data* 线状态;
    Render_state_data* 点状态;

    Coord_data* 自身坐标;
    Coord_data* 世界坐标;

private:
    ui显示数据 数据;
};

