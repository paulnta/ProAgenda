#ifndef CALENDARDAY_H
#define CALENDARDAY_H
#include <QLabel>
#include <QWidget>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <QDebug>
#include "models/lesson.h"



class CalendarDay : public QWidget
{
    Q_OBJECT

    QList<Lesson> lessons;
    int noDay;



public:

    static int heightHour;
    static int nbDay;
    static int nbHours;

    explicit CalendarDay(int noDay, QWidget* parent = 0);
    ~CalendarDay();


    void paintEvent(QPaintEvent *event)
    {
        event->accept();
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QColor(255, 238, 197, 255));
        painter.setPen(QColor(230, 210, 97, 255));

        foreach (Lesson l, lessons) {

            double startTimeInHours = l.getStartHour().hour() + ((double)l.getStartHour().minute()/60);
            double endTimeInHours = l.getEndHour().hour() + ((double)l.getEndHour().minute()/60);
            double diffInHours = endTimeInHours - startTimeInHours;

            int height = heightHour*diffInHours;
            int topPostion = heightHour*startTimeInHours;
            painter.drawRect(0,topPostion,width(),height);

            painter.setPen(QColor(0, 0, 0, 120));
            painter.drawText(10,topPostion+10, width(),height,0,l.getName());
            painter.setPen(QColor(230, 210, 97, 255));
        }


    }

    QList<Lesson> getLessons() const;
    void setLessons(const QList<Lesson> &value);
};

#endif // CALENDARDAY_H
