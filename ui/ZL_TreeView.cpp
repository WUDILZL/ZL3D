#include "ZL_TreeView.h"

ZL_TreeView::ZL_TreeView(QWidget* parent) : QTreeView(parent)
{
    ���� = 0;
    ���� = 0;
    ������� = new QStandardItemModel(this);
    //��ȡģ�Ͳ��ɼ��ĸ��ڵ�
    ���ɼ����ڵ� = �������->invisibleRootItem();

    // �������ڵ�
    ������ = new QStandardItem(QString::fromLocal8Bit("������"));
    ���ɼ����ڵ�->appendRow(������);

    setModel(�������);
    header()->hide();
    //hide();
    setEditTriggers(QAbstractItemView::NoEditTriggers);
}

ZL_TreeView::~ZL_TreeView()
{
}



void ZL_TreeView::contextMenuEvent(QContextMenuEvent* event)
{
    //��ȡ����Ҽ�����Ķ�Ӧλ�� 
    //event->pos()�������λ��
    //indexAt ͨ�����λ�ã����Ҷ�Ӧ�б�ֵ 
    QModelIndex index = indexAt(event->pos());
    QAbstractItemModel* model = this->model();
    QString data = model->data(index).toString();
    
    int zz = QString::compare(data, QString::fromLocal8Bit("������"));
    int xx = QString::compare(data, QString::fromLocal8Bit("͸�����"));
    if (zz == 0 || xx == 0) return;
    //����Ƿ����
    if (index.isValid()) {
        //Ϊ�������һ���˵�
        QMenu menu(this);
        QAction* deleteAction = new QAction(QString::fromLocal8Bit("ɾ��"), this);
        connect(deleteAction, &QAction::triggered, this, [this, index, data]() {
            ���� = index.data(Qt::UserRole).toInt();
            ���� = index.data(Qt::UserRole + 1).toInt();
            ���� = data;
            onDeleteAction(index);
            emit destroy();
            });

        menu.addAction(deleteAction);
        //�������������λ��
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
        //������ʾ��
        QMessageBox::warning(this, QString::fromLocal8Bit("����"), QString::fromLocal8Bit("�޷�ɾ���ڵ�"));
    }
}
