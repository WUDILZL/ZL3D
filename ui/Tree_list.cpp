#include "Tree_list.h"

Tree_list::Tree_list(QWidget* parent)
{
	QVBoxLayout* ˮƽ = new QVBoxLayout(this);
	���νڵ� = new ZL_TreeView(this);

	ˮƽ->addWidget(���νڵ�);
	ˮƽ->setSpacing(0);
	ˮƽ->setContentsMargins(0, 0, 0, 0);
	
}

Tree_list::~Tree_list()
{
}
