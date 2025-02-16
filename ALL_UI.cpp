#include "ALL_UI.h"

ALL_UI::ALL_UI(QWidget* parent)
{
	//当前界面布局
	QHBoxLayout* buju = new QHBoxLayout(this);
	QWidget* 窗口1 = new QWidget();

	//最左显示窗口
	_opengl显示窗口 = new MyOpenGLWidegets(this);

	//水平上方布局
	树状图形节点显示 = new Tree_list(this);
	//右侧布局
	QVBoxLayout* 水平 = new QVBoxLayout(窗口1);

	//切换窗口
	页面分布 = new QStackedWidget(this);
	//数据第二页 立方体数据
	立方体数据显示窗口 = new Model_data(this);
	//数据第一页 空白
	QWidget* 无数据窗口 = new QWidget(this);

	页面分布->addWidget(无数据窗口);//0
	页面分布->addWidget(立方体数据显示窗口);//1

	//右侧布局
	水平->addWidget(树状图形节点显示, 5);
	水平->addWidget(页面分布, 5);
	水平->setSpacing(2);
	水平->setContentsMargins(0, 0, 0, 0);

	//总布局
	buju->addWidget(_opengl显示窗口, 4);
	buju->addWidget(窗口1, 1);
	buju->setSpacing(2);//设置每个控件间隔
	buju->setContentsMargins(0, 0, 0, 0);//左右上下间隙
	

	//数据显示窗口->更新数据(_opengl显示窗口->三维场景.立方体.总数据);
	获取所有节点名称(_opengl显示窗口->三维场景.全部模型);
	树形列表信号交互();
	模型信号();
	
}

ALL_UI::~ALL_UI()
{
}

void ALL_UI::树形列表信号交互()
{
	connect(树状图形节点显示->树形节点, &QTreeView::clicked, [&](const QModelIndex& index) {
		数据更新前对模型选取取消();
		当前节点类型 = index.data(Qt::UserRole).toInt();
		当前节点索引 = index.data(Qt::UserRole + 1).toInt();
		更新ui模型数据();
		_opengl显示窗口->三维场景.获取当前所选模型(当前节点类型, 当前节点索引);
		});
	
	connect(树状图形节点显示->树形节点, &ZL_TreeView::destroy, [&]() {
		销毁物体(树状图形节点显示->树形节点->类型, 树状图形节点显示->树形节点->索引);
		当前节点类型 = -1;
		当前节点索引 = -1;
		_opengl显示窗口->三维场景.获取当前所选模型(当前节点类型, 当前节点索引);
		});
}

void ALL_UI::模型信号()
{
	立方体模型信号();
}

void ALL_UI::添加模型(int 类型)
{
	if (类型 == 0)
	{

	}
	else if (类型 == 1)
	{

	}
	else if (类型 == 2)
	{
		if (_opengl显示窗口->三维场景.全部模型.立方体队列.empty())
		{
			_opengl显示窗口->三维场景.全部模型.立方体队列.push_back(Cube());
			树状图形节点显示->添加子节点(_opengl显示窗口->三维场景.全部模型.立方体队列[0].名称, 2, _opengl显示窗口->三维场景.全部模型.立方体队列[0].队列索引);
			_opengl显示窗口->三维场景.添加模型立方体模型();
		}
		else
		{
			int 末尾索引 = _opengl显示窗口->三维场景.全部模型.立方体队列.size() - 1;
			int 获取队列 = _opengl显示窗口->三维场景.全部模型.立方体队列[末尾索引].队列索引 + 1;
			Cube 立方体 = Cube();
			立方体.名称.append(QString::number(末尾索引 + 1));
			立方体.队列索引 = 获取队列;
			_opengl显示窗口->三维场景.全部模型.立方体队列.push_back(立方体);
			树状图形节点显示->添加子节点(立方体.名称, 2, 获取队列);
			_opengl显示窗口->三维场景.添加模型立方体模型();
		}
	}
}

void ALL_UI::获取所有节点名称(模型队列 模型)
{
	if (!模型.工作平面队列.empty())
	{
		for (int i = 0; i < 模型.工作平面队列.size(); i++)
		{
			树状图形节点显示->添加子节点(模型.工作平面队列[i].名称, 1, 模型.工作平面队列[i].队列索引);
		}
	}
	if (!模型.透视相机队列.empty())
	{
		for (int i = 0; i < 模型.透视相机队列.size(); i++)
		{
			树状图形节点显示->添加子节点(模型.透视相机队列[i].名称, 0, 模型.透视相机队列[i].队列索引);
		}
	}
	if (!模型.立方体队列.empty())
	{
		for (int i = 0; i < 模型.立方体队列.size(); i++)
		{
			树状图形节点显示->添加子节点(模型.立方体队列[i].名称, 2, 模型.立方体队列[i].队列索引);
		}
	}

}

void ALL_UI::数据更新前对模型选取取消()
{
	模型操纵状态.立方体 = false;
	if (当前节点类型 == 0)
	{

	}
	if (当前节点类型 == 1)
	{

	}
	if (当前节点类型 == 2)
	{
		for (int i = 0; i < _opengl显示窗口->三维场景.全部模型.立方体队列.size(); i++)
		{
			if (_opengl显示窗口->三维场景.全部模型.立方体队列[i].选中状态) _opengl显示窗口->三维场景.全部模型.立方体队列[i].选中状态 = false;
		}
		
	}
}

void ALL_UI::更新ui模型数据()
{
	if (当前节点类型 == 0)
	{

	}
	if (当前节点类型 == 1)
	{
		
	}
	if (当前节点类型 == 2)
	{
		页面分布->setCurrentIndex(1);
		for (int i = 0; i < _opengl显示窗口->三维场景.全部模型.立方体队列.size(); i++)
		{
			if (_opengl显示窗口->三维场景.全部模型.立方体队列[i].队列索引 == 当前节点索引)
			{
				_opengl显示窗口->三维场景.全部模型.立方体队列[i].选中状态 = true;
				_opengl显示窗口->三维场景.全部模型.立方体队列[i].更新数据();
				立方体数据显示窗口->更新数据(_opengl显示窗口->三维场景.全部模型.立方体队列[i].总数据);
				当前选中类型 = 当前节点类型;
				当前选中索引 = i;
				模型操纵状态.立方体 = true;
				return;
			}
		}
		
	}
}

void ALL_UI::立方体模型信号()
{
	connect(立方体数据显示窗口->选取状态, &QCheckBox::toggled, [&](bool checked) {
		if (!模型操纵状态.立方体) return;
		if (checked) _opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].选中状态 = true;
		else _opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].选中状态 = false;
		});
	
	connect(立方体数据显示窗口->尺寸x->拖动条, &QSlider::valueChanged, [=](int value) {
		if (!模型操纵状态.立方体) return;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].尺寸x = value;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].修改模型();
		立方体数据显示窗口->尺寸x->数值显示->setText(QString::number(value));
		});

	connect(立方体数据显示窗口->尺寸y->拖动条, &QSlider::valueChanged, [=](int value) {
		if (!模型操纵状态.立方体) return;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].尺寸y = value;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].修改模型();
		立方体数据显示窗口->尺寸y->数值显示->setText(QString::number(value));
		});

	connect(立方体数据显示窗口->尺寸z->拖动条, &QSlider::valueChanged, [=](int value) {
		if (!模型操纵状态.立方体) return;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].尺寸z = value;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].修改模型();
		立方体数据显示窗口->尺寸z->数值显示->setText(QString::number(value));
		});


	connect(立方体数据显示窗口->分段x->拖动条, &QSlider::valueChanged, [=](int value) {
		if (!模型操纵状态.立方体) return;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].分段x = value;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].修改模型();
		立方体数据显示窗口->分段x->数值显示->setText(QString::number(value));
		});
	connect(立方体数据显示窗口->分段y->拖动条, &QSlider::valueChanged, [=](int value) {
		if (!模型操纵状态.立方体) return;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].分段y = value;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].修改模型();
		立方体数据显示窗口->分段y->数值显示->setText(QString::number(value));
		});
	connect(立方体数据显示窗口->分段z->拖动条, &QSlider::valueChanged, [=](int value) {
		if (!模型操纵状态.立方体) return;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].分段z = value;
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].修改模型();
		立方体数据显示窗口->分段z->数值显示->setText(QString::number(value));
		});

	connect(立方体数据显示窗口->面状态->状态, &QCheckBox::toggled, [&](bool checked) {
		if (!模型操纵状态.立方体) return;
		if (checked) _opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].渲染属性.渲染面 = true;
		else _opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].渲染属性.渲染面 = false;
		});

	connect(立方体数据显示窗口->线状态->状态, &QCheckBox::toggled, [&](bool checked) {
		if (!模型操纵状态.立方体) return;
		if (checked) _opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].渲染属性.渲染线 = true;
		else _opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].渲染属性.渲染线 = false;
		});

	connect(立方体数据显示窗口->点状态->状态, &QCheckBox::toggled, [&](bool checked) {
		if (!模型操纵状态.立方体) return;
		if (checked) _opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].渲染属性.渲染点 = true;
		else _opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].渲染属性.渲染点 = false;
		});

	connect(立方体数据显示窗口->面状态, &Render_state_data::setcolor, [=](QColor color) {
		if (!模型操纵状态.立方体) return;
		int red = color.red();
		int green = color.green();
		int blue = color.blue();
		int alpha = color.alpha();
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].物体颜色.面 = YS_RGB((float)red / 255.0f, (float)green / 255.0f, (float)blue / 255.0f, (float)alpha / 255.0f);
		});

	connect(立方体数据显示窗口->线状态, &Render_state_data::setcolor, [=](QColor color) {
		if (!模型操纵状态.立方体) return;
		int red = color.red();
		int green = color.green();
		int blue = color.blue();
		int alpha = color.alpha();
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].物体颜色.线 = YS_RGB((float)red / 255.0f, (float)green / 255.0f, (float)blue / 255.0f, (float)alpha / 255.0f);
		});

	connect(立方体数据显示窗口->点状态, &Render_state_data::setcolor, [=](QColor color) {
		if (!模型操纵状态.立方体) return;
		int red = color.red();
		int green = color.green();
		int blue = color.blue();
		int alpha = color.alpha();
		_opengl显示窗口->三维场景.全部模型.立方体队列[当前选中索引].物体颜色.点 = YS_RGB((float)red / 255.0f, (float)green / 255.0f, (float)blue / 255.0f, (float)alpha / 255.0f);
		});
	
}

void ALL_UI::销毁物体(int 类型, int 索引)
{
	
	_opengl显示窗口->三维场景.添加到销毁队列(类型, 索引);
}
