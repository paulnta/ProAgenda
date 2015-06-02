#include "tasklistitem.h"

QString TaskListItem::defaultCSS =  "QWidget#taskWidgetWrapper:hover{"
                                    "background-color: rgba(153, 153, 153, 20);"
                                    "}";

QString TaskListItem::selectedCSS = "QWidget#taskWidgetWrapper{"
                                    "background-color: #ffffff; border-left: 3px solid #2ba3dd;"
                                    "}";


TaskListItem::TaskListItem(int row, QWidget* parent): QWidget(parent)
{
    dialogNote = new gradedialogbox(this);
    this->row = row;

    checkbox = new QCheckBox();
    taskName = new QLabel;
    priority = new Priority;
    course = new QLabel;
    desc = new QLabel;

    setUpLayout();

    model = Task::getInstance()->getModel();
    mapper = new QDataWidgetMapper(this);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setModel(model);

    mapper->addMapping(taskName, model->fieldIndex("name"), "text");
    mapper->addMapping(course, Task::getInstance()->getCourseIndex(), "text");
    mapper->addMapping(checkbox, model->fieldIndex("isFinished"));
    mapper->addMapping(priority, model->fieldIndex("priority"));
    mapper->addMapping(desc, model->fieldIndex("description"), "text");

    connect(checkbox, SIGNAL(stateChanged(int)), this, SLOT(checkboxChecked(int)));
    connect(checkbox, SIGNAL(clicked(bool)), this, SLOT(checkBoxClicked(bool)));

    mapper->setCurrentIndex(row);
    setToolTip(desc->text());
}

void TaskListItem::setUpLayout(){

    setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Minimum);
    taskLayout = new QHBoxLayout();
    setLayout(taskLayout);
    setStyleSheet(TaskListItem::defaultCSS);

    taskLayout->addWidget(checkbox,1);
    taskLayout->addWidget(priority, 0, Qt::AlignLeft);

    taskLayout->addSpacing(20);
    taskLayout->addWidget(taskName,10);

    taskLayout->addWidget(new QLabel(""));
    taskLayout->addWidget(course, 0, Qt::AlignLeft);
}

TaskListItem::~TaskListItem()
{

}

void TaskListItem::updateTaskWidget()
{
    mapper->setCurrentIndex(row);
}


void TaskListItem::checkboxChecked(int state)
{
    mapper->submit();

    Task::Filter currentFilter = Task::getInstance()->getCurrentFilter();
    if((currentFilter == Task::DONE && state != Qt::Checked) ||
            (currentFilter == Task::TODO && state == Qt::Checked)){
        Task::getInstance()->needRefreshView = true;
    }
}

void TaskListItem::checkBoxClicked(bool checked)
{
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

void TaskListItem::getGradeAndCoeff()
{
    model->setData(model->index(row,model->fieldIndex("note")),dialogNote->getGrade(), Qt::EditRole);
    model->setData(model->index(row, model->fieldIndex("coefficient")), dialogNote->getCoeff(), Qt::EditRole);
    if(model->isDirty()){
        model->submitAll();
    }

    emit needRefreshTask();
}

void TaskListItem::changedCanceled()
{
    checkbox->setChecked(false);
    emit needRefreshTask();
}


