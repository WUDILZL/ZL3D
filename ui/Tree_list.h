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
    ZL_TreeView* 树形节点;

    //名称 数据类型 数据索引
    void 添加子节点(QString 名字,int 数据类型,int 数据索引) 
    {
        //qobject_cast 强转
        QStandardItemModel* _实列 = qobject_cast<QStandardItemModel*>(树形节点->model());
        // 获取 "主场景" 节点
        QStandardItem* _rootStandardItem = _实列->invisibleRootItem()->child(0); 
        if (_rootStandardItem) {
            QStandardItem* 新子节点 = new QStandardItem(名字);
            新子节点->setData(QVariant(数据类型), Qt::UserRole);
            新子节点->setData(QVariant(数据索引), Qt::UserRole + 1);
            _rootStandardItem->appendRow(新子节点);
        }
    }
};

