#include "QtWidgetsApplication2.h"

QtWidgetsApplication2::QtWidgetsApplication2(QWidget *parent)
    : QMainWindow(parent)
{
    _ui = new ALL_UI(this);
    初始化();
}

QtWidgetsApplication2::~QtWidgetsApplication2()
{}

void QtWidgetsApplication2::keyPressEvent(QKeyEvent * event)
{
    
}

void QtWidgetsApplication2::keyReleaseEvent(QKeyEvent* event)
{
    
}

void QtWidgetsApplication2::初始化()
{
    //初始化大小
    resize(1200, 740);
    setMinimumSize(800, 600);
    QWidget* 主界面 = new QWidget(this);
    setCentralWidget(主界面);
    QVBoxLayout* 布局 = new QVBoxLayout(主界面);
    //_ui->_opengl显示窗口->setFocus();
    布局->addWidget(_ui);
    布局->setSpacing(2);
    布局->setContentsMargins(2, 0, 2, 2);

    //设置菜单
    QMenuBar* 主界面上方菜单 = new QMenuBar(this);
    QMenu* 第一个菜单 = new QMenu(QString::fromLocal8Bit("创建"), 主界面上方菜单);
    QAction* 添加立方体 = new QAction(QString::fromLocal8Bit("创建立方体"), this);
    第一个菜单->addAction(添加立方体);
    主界面上方菜单->addMenu(第一个菜单);
    //设置为菜单栏
    setMenuBar(主界面上方菜单);

    connect(添加立方体, &QAction::triggered, [&]() {
        _ui->添加模型(2);
        });

}

