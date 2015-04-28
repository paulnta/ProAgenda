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

    explicit CalendarDay(int noDay, QWidget* parent = 0);
    ~CalendarDay();


    void paintEvent(QPaintEvent *event)
    {
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QColor(255, 238, 197, 255));
        painter.setPen(QColor(230, 238, 197, 255));

        foreach (Lesson l, lessons) {
            int height = heightHour*(l.getEndHour().hour() - l.getStartHour().hour());
            int posY = heightHour*l.getStartHour().hour();
            painter.drawRect(0,posY,width(),height);

             painter.setPen(QColor(0, 0, 0, 120));
            painter.drawText(10,posY+10, width(),height,0,l.getName());
            painter.setPen(QColor(230, 238, 197, 255));
        }


    }

    QList<Lesson> getLessons() const;
    void setLessons(const QList<Lesson> &value);
};

#endif // CALENDARDAY_H
