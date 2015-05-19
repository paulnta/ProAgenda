#include "task.h"
#include "sqlconnection.h"

#include <QMessageBox>
#include "viewTask/taskdisplay.h"

QSqlRelationalTableModel *Task::model = NULL;
int Task::courseIndex = 0;
QString Task::dateFormat = "yyyy-MM-ddTHH:mm:ss.zzz";


Task::Task(const QSqlRecord& record, const int& row): row(row)
{
    id          = record.value("id").toInt();
    name        = record.value("name").toString();
    description = record.value("description").toString();
    termDate    = QDateTime::fromString(record.value("termDate").toString(), Task::dateFormat );
    note        = record.value("note").toDouble();
    priority    = record.value("priority").toInt();
    finished    = record.value("isFinished").toInt();
    coefficient = record.value("coefficient").toDouble();
    courseId    = record.value("courseId").toInt();

    // TODO: FIX TASKTYPE and typeIndex
    courseIndex   = record.value("typeId").toInt();
    taskType    = new TaskType("type",4);

}

Task::~Task()
{

}

QString Task::getName(){
    return name;
}

bool Task::isFinished()
{
    return finished;
}
QString Task::getDescription() const
{
    return description;
}

void Task::setDescription(const QString &value)
{
    description = value;
}
QDateTime Task::getTermDate() const
{
    return termDate;
}

void Task::setTermDate(const QDateTime &value)
{
    termDate = value;
}
double Task::getNote() const
{
    return note;
}

void Task::setNote(double value)
{
    note = value;
}
int Task::getPriority() const
{
    return priority;
}

void Task::setPriority(int value)
{
    priority = value;
}
bool Task::getFinished() const
{
    return finished;
}

void Task::setFinished(bool value)
{
    finished = value;
}
double Task::getCoefficient() const
{
    return coefficient;
}

void Task::setCoefficient(double value)
{
    coefficient = value;
}

TaskType Task::getTaskType() const
{
    return *taskType;
}

void Task::setTaskType(const TaskType &value)
{
    *taskType = value;
}

int Task::getRow()
{
    return row;
}
int Task::getTypeIndex()
{
    return courseIndex;
}

void Task::setTypeIndex(int value)
{
    courseIndex = value;
}

void Task::addTask(){

    QSqlRecord record = model->record();

    record.setValue(1,"new Task");
    record.setValue(8,1);
    record.setValue(9,1);

    model->insertRecord(-1,record);
    model->submitAll();

    if(model->isDirty()){
        QMessageBox::warning(0,"SQL error", model->lastError().text());
    }

    taskDisplay::addTaskTemp();

}

//Setting up the relation between the database and the model / view
//Displaying in the name of the course and not its ID

void Task::setupModel(QString orderbyColumnName){

    model = new QSqlRelationalTableModel(0);
    model->setTable("Task");
    model->setSort(model->fieldIndex(orderbyColumnName),Qt::DescendingOrder);
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    courseIndex = model->fieldIndex("courseId");
    model->setRelation(courseIndex, QSqlRelation("Course", "id", "name"));
    model->select();
}

QSqlRelationalTableModel* Task::getModel(){
    return model;
}


