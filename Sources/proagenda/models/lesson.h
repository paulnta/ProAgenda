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
    Lesson(QString name, QTime startHour, QTime endHour, int dayOfWeek);
    ~Lesson();
    QString getName() const;
    void setName(const QString &value);
    QTime getStartHour() const;
    void setStartHour(const QTime &value);
    QTime getEndHour() const;
    void setEndHour(const QTime &value);
    int getDayOfWeek() const;
    void setDayOfWeek(int value);
};

#endif // LESSON_H
