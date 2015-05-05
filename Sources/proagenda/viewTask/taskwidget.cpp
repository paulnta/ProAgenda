#include "taskwidget.h"
#include "ui_taskwidget.h"
#include "sidebartask.h"
#include <QSqlQuery>


taskWidget::taskWidget(SideBarTask* sidebar, QWidget *parent, Task* task) :
    QWidget(parent),
    ui(new Ui::taskWidget),task(task), sidebar(sidebar)
{
    ui->setupUi(this);
    setupModel();


//    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::MinimumExpanding);

    checkbox = new QCheckBox();
    checkbox->setChecked(task->isFinished());
    taskName = new QLabel(this->task->getName());
    termDate = new QDateTimeEdit(this->task->getTermDate());
    priority = new QLabel(QString::number(this->task->getPriority()));
    type = new QLabel(this->task->getTaskType().getName());


    //SQLRelation set dropdown to search course name in DB
//    QSqlTableModel *relModel = model->relationModel(typeIndex);
///*    type->setModel(relModel);
//    type->setModelColumn(relModel->fieldIndex("name"))*/;

//    mapper = new QDataWidgetMapper(this);
//    mapper->setModel(model);
//    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
////    mapper->addMapping(nameEdit, model->fieldIndex("name"));
////    mapper->addMapping(addressEdit, model->fieldIndex("course"));
//    mapper->addMapping(type, typeIndex);


    ui->taskLayout->addWidget(checkbox,1);
    ui->taskLayout->addWidget(taskName,10);
    ui->taskLayout->addWidget(new QLabel(""));
    ui->taskLayout->addWidget(priority, 0, Qt::AlignLeft);
    ui->taskLayout->addWidget(termDate, 0, Qt::AlignLeft);
    ui->taskLayout->addWidget(type, 0, Qt::AlignLeft);

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
    delete type;
    delete priority;
    delete termDate;
}

void taskWidget::setupModel(){

    QSqlQuery query("SELECT* FROM Type");
    query.exec();
    model = new QSqlRelationalTableModel(this, SqlConnection::getInstance()->getDatabase());
    model->setTable("task");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    typeIndex = model->fieldIndex("typeId");
    model->setRelation(typeIndex, QSqlRelation("type", "id", "name"));
    model->select();


}
