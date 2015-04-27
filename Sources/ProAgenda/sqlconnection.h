#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QtSql/QtSql>

class SqlConnection
{
private:
    static SqlConnection* instance;

    QSqlDatabase database;

    SqlConnection() {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName("/home/thibaud/Database.sqlite");
        database.open();
    }

public:
    static SqlConnection* getInstance() {
        if(instance == nullptr) {
            instance = new SqlConnection;
        }

        return instance;
    }

    static QSqlDatabase getDatabase() {
        return getInstance()->database;
    }

    ~SqlConnection() {
        database.close();
        delete instance;
    }
};

#endif // SQLCONNECTION_H
