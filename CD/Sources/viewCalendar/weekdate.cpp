#include "weekdate.h"

WeekDate::WeekDate(QWidget* parent): QLabel(parent), QDate()
{
    setCursor(Qt::PointingHandCursor);
}


WeekDate::~WeekDate()
{

}

void WeekDate::setDate(QDate date)
{
    QDate::setDate(date.year(),date.month(),date.day());
    QLabel::setText(QDate::shortDayName(QDate::dayOfWeek()) + " " +
                    QString::number(QDate::day()));
}

void WeekDate::mousePressEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton){
        emit daySelected(QDate(QDate::year(),QDate::month(),QDate::day()));
    }
}

