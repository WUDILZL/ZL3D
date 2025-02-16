#include "ZL_TreeView.h"

ZL_TreeView::ZL_TreeView(QWidget* parent) : QTreeView(parent)
{
    类型 = 0;
    索引 = 0;
    表格数据 = new QStandardItemModel(this);
    //获取模型不可见的根节点
    不可见根节点 = 表格数据->invisibleRootItem();

    // 创建根节点
    主场景 = new QStandardItem(QString::fromLocal8Bit("主场景"));
    不可见根节点->appendRow(主场景);

    setModel(表格数据);
    header()->hide();
    //hide();
    setEditTriggers(QAbstractItemView::NoEditTriggers);
}

ZL_TreeView::~ZL_TreeView()
{
}



void ZL_TreeView::contextMenuEvent(QContextMenuEvent* event)
{
    //获取鼠标右键点击的对应位置 
    //event->pos()返回鼠标位置
    //indexAt 通过鼠标位置，查找对应列表值 
    QModelIndex index = indexAt(event->pos());
    QAbstractItemModel* model = this->model();
    QString data = model->data(index).toString();
    
    int zz = QString::compare(data, QString::fromLocal8Bit("主场景"));
    int xx = QString::compare(data, QString::fromLocal8Bit("透视相机"));
    if (zz == 0 || xx == 0) return;
    //检查是否存在
    if (index.isValid()) {
        //为父级添加一个菜单
        QMenu menu(this);
        QAction* deleteAction = new QAction(QString::fromLocal8Bit("删除"), this);
        connect(deleteAction, &QAction::triggered, this, [this, index, data]() {
            类型 = index.data(Qt::UserRole).toInt();
            索引 = index.data(Qt::UserRole + 1).toInt();
            名字 = data;
            onDeleteAction(index);
            emit destroy();
            });

        menu.addAction(deleteAction);
        //生成在鼠标所在位置
        menu.exec(event->globalPos());
    }
}

void ZL_TreeView::onDeleteAction(const QModelIndex& index)
{
    QStandardItemModel* model = static_cast<QStandardItemModel*>(this->model());
    QModelIndex parentIndex = index.parent();
    int row = index.row();
    if (model->removeRow(row, parentIndex)) {
        return;
    }
    else {
        //错误提示框
        QMessageBox::warning(this, QString::fromLocal8Bit("错误"), QString::fromLocal8Bit("无法删除节点"));
    }
}
