#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QtSql/QtSql>
#include "models/task.h"

class SqlConnection
{

private:
    static SqlConnection* instance;
    QSqlDatabase database;
    SqlConnection();

public:

    static SqlConnection* getInstance();
    static QSqlDatabase getDatabase();
    ~SqlConnection();
};

#endif // SQLCONNECTION_H
