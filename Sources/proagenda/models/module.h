#ifndef MODULE_H
#define MODULE_H

#include <QString>

class Module
{
    QString name;
    QString description;
    double threshold;

public:
    Module();
    ~Module();
};

#endif // MODULE_H
