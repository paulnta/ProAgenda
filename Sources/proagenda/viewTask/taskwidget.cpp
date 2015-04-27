#include "taskwidget.h"
#include "ui_taskwidget.h"
#include "sidebartask.h"


taskWidget::taskWidget(SideBarTask* sidebar, QWidget *parent, Task* task) :
    QWidget(parent),
    ui(new Ui::taskWidget),task(task), sidebar(sidebar)
{
    ui->setupUi(this);


//    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);

    checkbox = new QCheckBox();
    checkbox->setChecked(task->isFinished());
    taskName = new QLabel(this->task->getName());

    ui->taskLayout->addWidget(checkbox,1);
    ui->taskLayout->addWidget(taskName,10);
    ui->taskLayout->addWidget(new QLabel(""));

    connect(this,SIGNAL(editTask(Task*)), sidebar, SLOT(loadTask(Task*)));
}

void taskWidget::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){  // click button left
        emit editTask(task);
    }
}

taskWidget::~taskWidget()
{
    delete ui;
    delete taskName;
    delete checkbox;
}
