#include "columnday.h"
#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include "hourcal.h"


ColumnDay::ColumnDay(QSqlRelationalTableModel* model, QDate* date, QWidget* parent):
    CalendarColumn(parent), modelLesson(model), date(date)
{
    taskInstance = Task::getInstance();
    modelTask = taskInstance->getModel();

    idSelectedLesson = -1;

    for(int j=0; j < CalendarColumn::nbHours; j++)
        addRow(new HourCal);
}

void ColumnDay::updateValues(){

    lessPerDay.clear();
    modelLesson->setFilter("dayOfWeek = '" + QString::number(date->dayOfWeek()) + "'");
    modelLesson->select();

    for(int k = 0; k < modelLesson->rowCount(); k++)
        lessPerDay.append(new LessonRect(modelLesson->record(k)));

    update();
}

void ColumnDay::deselectLesson()
{
    if(idSelectedLesson > 0){
        idSelectedLesson = -1;
        update();
    }
}

void ColumnDay::selectLesson(int id)
{
    idSelectedLesson = id;
    update();
    emit lessonSelected(date->dayOfWeek());
}

int ColumnDay::getDayOfWeek()
{
    return date->dayOfWeek();
}

void ColumnDay::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        double hour = (double)event->pos().y()/ColumnDay::heightHour;
        selectLessonByHour(hour);
    }
}

void ColumnDay::selectLessonByHour(double hour){

    for(int i = 0; i < lessPerDay.size(); ++i){

        if(lessPerDay.at(i)->intersect(hour)){
            selectLesson(lessPerDay.at(i)->getId());
            emit lessonSelected(*date, lessPerDay.at(i)->getCourseName());
            return;
        }
    }

    emit columnDaySelected(date->dayOfWeek());
}

void ColumnDay::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);

    for(int i = 0; i < lessPerDay.size(); ++i){

        double height = lessPerDay.at(i)->getHeight(CalendarColumn::heightHour);
        double topPostion = lessPerDay.at(i)->getY(CalendarColumn::heightHour);

        if(lessPerDay.at(i)->getId() == idSelectedLesson)
            painter.setBrush(QColor("#ffe0c4"));
        else
            painter.setBrush(QColor(255, 238, 197, 255));

        painter.setPen(QColor(230, 210, 97, 255));
        painter.drawRect(QRect(0,topPostion,width(),height));

        painter.setPen(QColor(0, 0, 0, 120));
        painter.drawText(10,topPostion+10, width(),height,Qt::TextWordWrap, lessPerDay.at(i)->getName());
    }
}

ColumnDay::~ColumnDay()
{

}
