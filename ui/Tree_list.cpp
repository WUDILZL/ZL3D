#include "Tree_list.h"

Tree_list::Tree_list(QWidget* parent)
{
	QVBoxLayout* 水平 = new QVBoxLayout(this);
	树形节点 = new ZL_TreeView(this);

	水平->addWidget(树形节点);
	水平->setSpacing(0);
	水平->setContentsMargins(0, 0, 0, 0);
	
}

Tree_list::~Tree_list()
{
}
