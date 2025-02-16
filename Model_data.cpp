#include "Model_data.h"

Model_data::Model_data(QWidget* parent)
{
	QVBoxLayout* 垂直布局 = new QVBoxLayout(this);
	名字 = new QLabel();

	选取状态 = new QCheckBox();
	选取状态->setText(QString::fromLocal8Bit("选取操控"));

	尺寸x = new ZLSlider();
	尺寸y = new ZLSlider();
	尺寸z = new ZLSlider();

	分段x = new ZLSlider();
	分段y = new ZLSlider();
	分段z = new ZLSlider();

	面状态 = new Render_state_data();
	线状态 = new Render_state_data();
	点状态 = new Render_state_data();

	自身坐标 = new Coord_data();
	世界坐标 = new Coord_data();
	垂直布局->addWidget(名字);

	垂直布局->addWidget(选取状态);

	垂直布局->addWidget(尺寸x);
	垂直布局->addWidget(尺寸y);
	垂直布局->addWidget(尺寸z);

	垂直布局->addWidget(分段x);
	垂直布局->addWidget(分段y);
	垂直布局->addWidget(分段z);

	垂直布局->addWidget(面状态);
	垂直布局->addWidget(线状态);
	垂直布局->addWidget(点状态);

	垂直布局->addWidget(自身坐标);
	垂直布局->addWidget(世界坐标);

	垂直布局->setSpacing(2);
	垂直布局->setContentsMargins(0, 0, 0, 0);
}

Model_data::~Model_data()
{
}

void Model_data::更新数据(ui显示数据 参数)
{
	数据 = 参数;
	名字->setText(数据.名称);
	选取状态->setChecked(数据.选中状态);
	尺寸x->数据设置(QString::fromLocal8Bit("尺寸X"), 数据.尺寸.X);
	尺寸y->数据设置(QString::fromLocal8Bit("尺寸Y"), 数据.尺寸.Y);
	尺寸z->数据设置(QString::fromLocal8Bit("尺寸Z"), 数据.尺寸.Z);

	分段x->数据设置(QString::fromLocal8Bit("分段X"), 数据.分段.X);
	分段y->数据设置(QString::fromLocal8Bit("分段Y"), 数据.分段.Y);
	分段z->数据设置(QString::fromLocal8Bit("分段Z"), 数据.分段.Z);

	面状态->数据更新(QString::fromLocal8Bit("渲染面"), 数据.渲染状态面);
	线状态->数据更新(QString::fromLocal8Bit("渲染线"), 数据.渲染状态线);
	点状态->数据更新(QString::fromLocal8Bit("渲染点"), 数据.渲染状态点);

	自身坐标->数据更新(QString::fromLocal8Bit("自身坐标"), 数据.自身坐标.X, 数据.自身坐标.Y, 数据.自身坐标.Z);
	世界坐标->数据更新(QString::fromLocal8Bit("世界坐标"), 数据.世界坐标.X, 数据.世界坐标.Y, 数据.世界坐标.Z);

}

void Model_data::跟踪更新参数(ui显示数据 参数)
{
	自身坐标->实时更新(参数.自身坐标.X, 参数.自身坐标.Y, 参数.自身坐标.Z);
	世界坐标->实时更新(参数.世界坐标.X, 参数.世界坐标.Y, 参数.世界坐标.Z);
}


