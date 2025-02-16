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

    int ����;
    int ����;
    QString ����;
    QStandardItemModel* �������;
    QStandardItem* ���ɼ����ڵ�;
    QStandardItem* ������;
signals:
    //����
    void destroy();

protected:
    void contextMenuEvent(QContextMenuEvent* event) override;

private:
    void onDeleteAction(const QModelIndex& index);
};

