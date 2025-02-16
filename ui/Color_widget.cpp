#include "Color_widget.h"

Color_widget::Color_widget(QWidget* parent)
{
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    resize(500, 400);//窗口大小
    setWindowTitle(QString::fromLocal8Bit("调色板窗口"));//窗口名字
    //只关闭自己
    setAttribute(Qt::WA_QuitOnClose, false);
    show();
    // 关闭窗口释放内存
    setAttribute(Qt::WA_DeleteOnClose);
    QHBoxLayout* 布局 = new QHBoxLayout(this);
    调色板 = new QColorDialog();
    布局->addWidget(调色板);
}

Color_widget::~Color_widget()
{

}
