#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include <QAbstractItemModel>

#include "module.h"
#include "semester.h"

class Course : public QAbstractItemModel
{
    QString name;
    QString description;
    double threshold;
    double weighting;
    Module module;
    Semester semester;

public:
    Course();
    ~Course();
};

#endif // COURSE_H
