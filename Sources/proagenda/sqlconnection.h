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
        database.setDatabaseName("Database.sqlite");  // Placez le fichier  Database.sqlite dans le répertoire de l'exécutable !
        database.open();
    }

public:
    static SqlConnection* getInstance() {
        if(instance == NULL) {
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
