#pragma once
#include <qwidget.h>
#include <QTreeView>
#include <QStandardItemModel>
#include <QVBoxLayout>


#include "ZL_TreeView.h"

class Tree_list :
    public QWidget
{
    Q_OBJECT
public:
    explicit Tree_list(QWidget* parent = nullptr);
    ~Tree_list();

public:
    ZL_TreeView* ���νڵ�;

    //���� �������� ��������
    void ����ӽڵ�(QString ����,int ��������,int ��������) 
    {
        //qobject_cast ǿת
        QStandardItemModel* _ʵ�� = qobject_cast<QStandardItemModel*>(���νڵ�->model());
        // ��ȡ "������" �ڵ�
        QStandardItem* _rootStandardItem = _ʵ��->invisibleRootItem()->child(0); 
        if (_rootStandardItem) {
            QStandardItem* ���ӽڵ� = new QStandardItem(����);
            ���ӽڵ�->setData(QVariant(��������), Qt::UserRole);
            ���ӽڵ�->setData(QVariant(��������), Qt::UserRole + 1);
            _rootStandardItem->appendRow(���ӽڵ�);
        }
    }
};

