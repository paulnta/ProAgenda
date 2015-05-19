#include "taskcheckbox.h"
#include "ui_taskcheckbox.h"
#include "sidebartask.h"

QString TaskCheckBox::defaultCSS ="QWidget#taskWidgetWrapper:hover{"
                                "background-color: rgba(153, 153, 153, 20);"
                                 "}";

QString TaskCheckBox::selectedCSS =   "QWidget#taskWidgetWrapper{"
                                    "background-color: #ffffff; border-left: 3px solid #2ba3dd;"
                                    "}";


TaskCheckBox::TaskCheckBox(SideBarTask* sidebar, int row, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskWidget), sidebar(sidebar)
{
    this->row = row;
    qDebug() << row;
    ui->setupUi(this);

    checkbox = new QCheckBox();
    taskName = new QLabel;
    termDate = new QDateTimeEdit;
    priority = new QLabel;

    ui->taskLayout->addWidget(checkbox,1);
    ui->taskLayout->addWidget(taskName,10);
    ui->taskLayout->addWidget(new QLabel(""));
    ui->taskLayout->addWidget(priority, 0, Qt::AlignLeft);
    ui->taskLayout->addWidget(termDate, 0, Qt::AlignLeft);

    QSqlRelationalTableModel* model = Task::getModel();
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setModel(model);

    mapper->addMapping(taskName, model->fieldIndex("name"), "text");
    mapper->addMapping(termDate, model->fieldIndex("termDate"));
    mapper->addMapping(checkbox, model->fieldIndex("isFinished"));

    mapper->addMapping(priority, model->fieldIndex("priority"),"text");
    mapper->setCurrentIndex(row);

    connect(checkbox, SIGNAL(stateChanged(int)), mapper, SLOT(submit()));
    connect(this,SIGNAL(editTask(int)), sidebar, SLOT(loadTask(int)));
}

void TaskCheckBox::setSelected(bool enable)
{
    if(enable)
        setStyleSheet(TaskCheckBox::selectedCSS);
    else
        setStyleSheet(TaskCheckBox::defaultCSS);
}

void TaskCheckBox::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){  // click button left
        emit editTask(row);
    }
}

TaskCheckBox::~TaskCheckBox()
{
    delete ui;
    delete taskName;
    delete checkbox;
    delete priority;
    delete termDate;
    delete mapper;
}

void TaskCheckBox::updateTaskWidget()
{
    mapper->setCurrentIndex(row);
}

