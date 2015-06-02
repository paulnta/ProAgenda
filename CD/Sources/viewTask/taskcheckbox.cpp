#include "taskcheckbox.h"
#include "ui_taskcheckbox.h"
#include "sidebartask.h"
#include <QInputDialog>


QString TaskCheckBox::defaultCSS =  "QWidget#taskWidgetWrapper:hover{"
                                    "background-color: rgba(153, 153, 153, 20);"
                                    "}";

QString TaskCheckBox::selectedCSS = "QWidget#taskWidgetWrapper{"
                                    "background-color: #ffffff; border-left: 3px solid #2ba3dd;"
                                    "}";


TaskCheckBox::TaskCheckBox(SideBarTask* sidebar, int row, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskWidget), sidebar(sidebar)
{

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    dialogNote = new gradedialogbox(this);
    this->row = row;
    ui->setupUi(this);
    setStyleSheet(TaskCheckBox::defaultCSS);
    removeTaskBtn = new QPushButton("X");
    checkbox = new QCheckBox();
    taskName = new QLabel;
    termDate = new TermDate;
    priority = new Priority;
    grade = new QLabel;
    coefficient = new QLabel;
    course = new QLabel;
    desc = new QLabel;
    desc->setStyleSheet("QLabel{color: #9b9b9b}");
    ui->taskLayout->addWidget(checkbox,1);
    ui->taskLayout->addWidget(priority, 0, Qt::AlignLeft);


    //Name and Description
    QWidget* taskNameDesc= new QWidget;
    QVBoxLayout* taskNameDescLayout = new QVBoxLayout(taskNameDesc);
    taskNameDescLayout->setContentsMargins(0,0,0,0);
    taskNameDescLayout->setSpacing(2);
    taskNameDescLayout->addWidget(taskName, 0);
    taskNameDescLayout->addWidget(desc);
    ui->taskLayout->addSpacing(20);
    ui->taskLayout->addWidget(taskNameDesc,10);
    ui->taskLayout->addWidget(grade);
    ui->taskLayout->addWidget(coefficient);

    ui->taskLayout->addWidget(new QLabel(""));
    ui->taskLayout->addWidget(termDate, 0, Qt::AlignLeft);
    ui->taskLayout->addWidget(course, 0, Qt::AlignLeft);
    ui->taskLayout->addWidget(removeTaskBtn, 0, Qt::AlignLeft);

    model = Task::getInstance()->getModel();
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setModel(model);

    mapper->addMapping(taskName, model->fieldIndex("name"), "text");
    mapper->addMapping(course, Task::getInstance()->getCourseIndex(), "text");
    mapper->addMapping(termDate, model->fieldIndex("termDate"));
    mapper->addMapping(checkbox, model->fieldIndex("isFinished"));
    mapper->addMapping(priority, model->fieldIndex("priority"));
    mapper->addMapping(desc, model->fieldIndex("description"), "text");
    mapper->addMapping(grade, model->fieldIndex("note"), "text");
    mapper->addMapping(coefficient, model->fieldIndex("coefficient"), "text");

    connect(checkbox, SIGNAL(stateChanged(int)), this, SLOT(checkboxChecked(int)));
    connect(this,SIGNAL(editTask(int)), sidebar, SLOT(loadTask(int)));
    connect(removeTaskBtn, SIGNAL(clicked()), this, SLOT(onRemoveTaskClicked()));
    connect(checkbox, SIGNAL(clicked(bool)), this, SLOT(checkBoxClicked(bool)));



    mapper->setCurrentIndex(row);
}

void TaskCheckBox::checkBoxClicked(bool checked){
    if(checked){
        //Est un devoir noté ou un TE
        if(model->record(row).value("typeId") != 2){
            dialogNote = new gradedialogbox(this);
            connect(dialogNote, SIGNAL(updateValue()), this, SLOT(getGradeAndCoeff()));
            connect(dialogNote, SIGNAL(canceledValue()), this, SLOT(changedCanceled()));
            dialogNote->exec();
        }
    }
}

void TaskCheckBox::changedCanceled(){
    checkbox->setChecked(false);
    emit needRefreshTask();

}

void TaskCheckBox::getGradeAndCoeff(){
    qDebug() << dialogNote->getGrade();
    model->setData(model->index(row,model->fieldIndex("note")),dialogNote->getGrade(), Qt::EditRole);
    model->setData(model->index(row, model->fieldIndex("coefficient")), dialogNote->getCoeff(), Qt::EditRole);
    if(model->isDirty()){
        model->submitAll();
    }

    emit needRefreshTask();
}

void TaskCheckBox::checkboxChecked(int state){

        mapper->submit();

        Task::Filter currentFilter = Task::getInstance()->getCurrentFilter();
        if((currentFilter == Task::DONE && state != Qt::Checked) ||
                (currentFilter == Task::TODO && state == Qt::Checked)){
            Task::getInstance()->needRefreshView = true;
        }
}

void TaskCheckBox::setSelected(bool enable)
{

    if(enable){
        setStyleSheet(TaskCheckBox::selectedCSS);
    }
    else{
        setStyleSheet(TaskCheckBox::defaultCSS);
    }
}

int TaskCheckBox::getRow()
{
    return row;
}

void TaskCheckBox::mousePressEvent(QMouseEvent *event)
{
    qDebug() << "editTask" << row;
    if(event->button() == Qt::LeftButton){  // click button left
        emit editTask(row);
    }
}

void TaskCheckBox::emitEditTask(){
    qDebug() << "editTask" << row;
    emit editTask(row);
}

void TaskCheckBox::onRemoveTaskClicked(){
    emit removeTask(row);
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

