#include "taskwidget.h"
#include "ui_taskwidget.h"
#include "sidebartask.h"
#include <QSqlQuery>

QString taskCheckBox::defaultCSS ="QWidget#taskWidgetWrapper:hover{"
                                "background-color: rgba(153, 153, 153, 20);"
                                 "}";

QString taskCheckBox::selectedCSS =   "QWidget#taskWidgetWrapper{"
                                    "background-color: #ffffff; border-left: 3px solid #2ba3dd;"
                                    "}";

taskCheckBox::taskCheckBox(SideBarTask* sidebar, QWidget *parent, Task* task) :
    QWidget(parent),
    ui(new Ui::taskWidget),task(task), sidebar(sidebar)
{
    ui->setupUi(this);

    checkbox = new QCheckBox();
    taskName = new QLabel;
    termDate = new QDateTimeEdit(this->task->getTermDate());
    priority = new QLabel;
//    type = new QLabel(this->task->getTaskType().getName());


    ui->taskLayout->addWidget(checkbox,1);
    ui->taskLayout->addWidget(taskName,10);
    ui->taskLayout->addWidget(new QLabel(""));
    ui->taskLayout->addWidget(priority, 0, Qt::AlignLeft);
    ui->taskLayout->addWidget(termDate, 0, Qt::AlignLeft);
//    ui->taskLayout->addWidget(type, 0, Qt::AlignLeft);

    QSqlRelationalTableModel* model = Task::getModel();
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setModel(model);
    mapper->addMapping(taskName, model->fieldIndex("name"), "text");
    mapper->addMapping(termDate, model->fieldIndex("termDate"));
    mapper->addMapping(checkbox, model->fieldIndex("isFinished"));
    mapper->addMapping(priority, model->fieldIndex("priority"),"text");
    mapper->setCurrentIndex(task->getRow());

    connect(checkbox, SIGNAL(stateChanged(int)), mapper, SLOT(submit()));
    connect(this,SIGNAL(editTask(Task*)), sidebar, SLOT(loadTask(Task*)));
}

void taskCheckBox::setSelected(bool enable)
{
    if(enable)
        setStyleSheet(taskCheckBox::selectedCSS);
    else
        setStyleSheet(taskCheckBox::defaultCSS);
}

void taskCheckBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){  // click button left
        emit editTask(task);
    }
}

taskCheckBox::~taskCheckBox()
{
    delete ui;
    delete taskName;
    delete checkbox;
//    delete type;
    delete priority;
    delete termDate;
    delete mapper;
}

void taskCheckBox::updateTaskWidget()
{
    mapper->setCurrentIndex(task->getRow());
}

