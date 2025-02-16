#pragma once
#include <qwidget.h>
#include <QVBoxLayout>
#include <QLineEdit>
#include <QTimer>
#include "MyOpenGLWidegets.h"
#include "Model_data.h"
#include "Tree_list.h"

struct ���ݿ��ö��� {
    bool ������ = false;
};

class ALL_UI :
    public QWidget
{
    Q_OBJECT
public:

    explicit ALL_UI(QWidget* parent = nullptr);
    ~ALL_UI();

    void �����б��źŽ���();
    void ģ���ź�();
    //0͸����� 1����ƽ�� 2������
    void ���ģ��(int ����);
public:
    MyOpenGLWidegets* _opengl��ʾ����;
    QStackedWidget* ҳ��ֲ�;
    Model_data* ������������ʾ����;
    Tree_list* ��״ͼ�νڵ���ʾ;
    //QTimer* ��ʱ��;
private:
    //͸����� 0 ����ƽ��1 ������2
    int ��ǰ�ڵ����� = 0;
    int ��ǰ�ڵ����� = 0;

    //
    int ��ǰѡ������ = 0;
    int ��ǰѡ������ = 0;

    ���ݿ��ö��� ģ�Ͳ���״̬;

private:
    void ��ȡ���нڵ�����(ģ�Ͷ��� ģ��);
    void ���ݸ���ǰ��ģ��ѡȡȡ��();
    void ����uiģ������();
    void ������ģ���ź�();
    void ��������(int ����, int ����);
};

