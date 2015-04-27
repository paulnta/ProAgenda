#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QtSql/QtSql>
#include "models/task.h"

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

    /*
     * Ecriture et lecture des tâches dans la base de donnée
     */
    QList<Task*>getAllTasks();

    //Cree et/ou modifie une tâche
    void modifyTask(Task*);

    void eraseTask(Task*);
private:
    Task* findTask(int id);
    QString taskToQuery(Task*);




};

#endif // SQLCONNECTION_H
