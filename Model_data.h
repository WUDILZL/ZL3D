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

//������ʾ����
class Model_data :
    public QWidget
{
    Q_OBJECT
public:

    explicit Model_data(QWidget* parent = nullptr);
    ~Model_data();

    void ��������(ui��ʾ���� ����);
    void ���ٸ��²���(ui��ʾ���� ����);

public:
    
    QLabel* ����;

    QCheckBox* ѡȡ״̬;

    ZLSlider* �ߴ�x;
    ZLSlider* �ߴ�y;
    ZLSlider* �ߴ�z;

    ZLSlider* �ֶ�x;
    ZLSlider* �ֶ�y;
    ZLSlider* �ֶ�z;

    Render_state_data* ��״̬;
    Render_state_data* ��״̬;
    Render_state_data* ��״̬;

    Coord_data* ��������;
    Coord_data* ��������;

private:
    ui��ʾ���� ����;
};

