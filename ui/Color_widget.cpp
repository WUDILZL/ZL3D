#include "Color_widget.h"

Color_widget::Color_widget(QWidget* parent)
{
    setWindowFlags(windowFlags() | Qt::WindowStaysOnTopHint);
    resize(500, 400);//���ڴ�С
    setWindowTitle(QString::fromLocal8Bit("��ɫ�崰��"));//��������
    //ֻ�ر��Լ�
    setAttribute(Qt::WA_QuitOnClose, false);
    show();
    // �رմ����ͷ��ڴ�
    setAttribute(Qt::WA_DeleteOnClose);
    QHBoxLayout* ���� = new QHBoxLayout(this);
    ��ɫ�� = new QColorDialog();
    ����->addWidget(��ɫ��);
}

Color_widget::~Color_widget()
{

}
