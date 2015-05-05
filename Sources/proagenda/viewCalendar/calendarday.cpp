#include "calendarday.h"
#include "headerhours.h"

int CalendarDay::heightHour = 50;
int CalendarDay::nbDay = 8;
int CalendarDay::nbHours = 24;

QList<Lesson> CalendarDay::getLessons() const
{
    return lessons;
}

void CalendarDay::setLessons(const QList<Lesson> &value)
{
    lessons = value;
}
CalendarDay::CalendarDay(int noDay, QWidget* parent): QWidget(parent)
{
    this->noDay = noDay;
}

CalendarDay::~CalendarDay()
{

}

