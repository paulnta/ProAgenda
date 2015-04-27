#ifndef SEMESTER_H
#define SEMESTER_H
#include <QString>
#include "QDate"

class Semester
{
    QString name;
    QDate startDate;
    QDate endDate;

public:
    Semester();
    ~Semester();
};

#endif // SEMESTER_H
