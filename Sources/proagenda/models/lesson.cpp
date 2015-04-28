#include "lesson.h"


QString Lesson::getName() const
{
    return name;
}

void Lesson::setName(const QString &value)
{
    name = value;
}

QTime Lesson::getStartHour() const
{
    return startHour;
}

void Lesson::setStartHour(const QTime &value)
{
    startHour = value;
}

QTime Lesson::getEndHour() const
{
    return endHour;
}

void Lesson::setEndHour(const QTime &value)
{
    endHour = value;
}

int Lesson::getDayOfWeek() const
{
    return dayOfWeek;
}

void Lesson::setDayOfWeek(int value)
{
    dayOfWeek = value;
}
Lesson::Lesson(QString name, QTime startHour, QTime endHour, int dayOfWeek)
{
    this->name = name;
    this->startHour = startHour;
    this->endHour = endHour;
    this->dayOfWeek = dayOfWeek;
}

Lesson::~Lesson()
{
    
}

