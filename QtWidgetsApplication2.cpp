#include "QtWidgetsApplication2.h"

QtWidgetsApplication2::QtWidgetsApplication2(QWidget *parent)
    : QMainWindow(parent)
{
    _ui = new ALL_UI(this);
    ��ʼ��();
}

QtWidgetsApplication2::~QtWidgetsApplication2()
{}

void QtWidgetsApplication2::keyPressEvent(QKeyEvent * event)
{
    
}

void QtWidgetsApplication2::keyReleaseEvent(QKeyEvent* event)
{
    
}

void QtWidgetsApplication2::��ʼ��()
{
    //��ʼ����С
    resize(1200, 740);
    setMinimumSize(800, 600);
    QWidget* ������ = new QWidget(this);
    setCentralWidget(������);
    QVBoxLayout* ���� = new QVBoxLayout(������);
    //_ui->_opengl��ʾ����->setFocus();
    ����->addWidget(_ui);
    ����->setSpacing(2);
    ����->setContentsMargins(2, 0, 2, 2);

    //���ò˵�
    QMenuBar* �������Ϸ��˵� = new QMenuBar(this);
    QMenu* ��һ���˵� = new QMenu(QString::fromLocal8Bit("����"), �������Ϸ��˵�);
    QAction* ��������� = new QAction(QString::fromLocal8Bit("����������"), this);
    ��һ���˵�->addAction(���������);
    �������Ϸ��˵�->addMenu(��һ���˵�);
    //����Ϊ�˵���
    setMenuBar(�������Ϸ��˵�);

    connect(���������, &QAction::triggered, [&]() {
        _ui->���ģ��(2);
        });

}

