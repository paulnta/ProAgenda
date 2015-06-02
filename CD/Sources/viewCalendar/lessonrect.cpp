#include "lessonrect.h"

LessonRect::LessonRect(const QSqlRecord& record, QObject* parent): QObject(parent)
{
    this->record = record;
    QTime startHour = record.value("startHour").toTime();
    QTime endHour = record.value("endHour").toTime();
    startTimeInHours = startHour.hour()+ ((double)startHour.minute()/60);
    endTimeInHours = endHour.hour() + ((double)endHour.minute()/60);
}

LessonRect::~LessonRect()
{

}

double LessonRect::getStartTimeInHours() const
{
    return startTimeInHours;
}

double LessonRect::getEndTimeInHours() const
{
    return endTimeInHours;
}

double LessonRect::getHeight(double heightForHours) const
{
    return (endTimeInHours - startTimeInHours) * heightForHours;
}

double LessonRect::getY(double heightForHours) const
{
    return startTimeInHours * heightForHours;
}

bool LessonRect::intersect(double hour) const
{
    if(hour >= startTimeInHours  && hour <= endTimeInHours ){
        return true;
    }
}

int LessonRect::getId() const
{
    return record.value("id").toInt();
}

QString LessonRect::getName() const
{
    return record.value("name").toString();
}

QString LessonRect::getCourseName()
{
    return record.value(Lesson::getInstance()->getCourseIndex()).toString();
}

