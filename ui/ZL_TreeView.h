#pragma once
#include <qtreeview.h>
#include <QMenu>
#include <QContextMenuEvent>
#include <QStandardItemModel>
#include <QMessageBox>
#include <QDebug>
#include <QHeaderView>

class ZL_TreeView :
    public QTreeView
{
    Q_OBJECT
public:
    ZL_TreeView(QWidget* parent = nullptr);
    ~ZL_TreeView();

    int 类型;
    int 索引;
    QString 名字;
    QStandardItemModel* 表格数据;
    QStandardItem* 不可见根节点;
    QStandardItem* 主场景;
signals:
    //销毁
    void destroy();

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;

private:
    void onDeleteAction(const QModelIndex& index);
};

