#ifndef LESSON_H
#define LESSON_H
#include <QString>
#include <QTime>

class Lesson
{
    QString name;
    QTime startHour;
    QTime endHour;
    int dayOfWeek;

public:
    Lesson();
    ~Lesson();
};

#endif // LESSON_H
