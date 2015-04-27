#ifndef SQLCONNECTION_H
#define SQLCONNECTION_H

#include <QtSql/QtSql>
#include "viewTask/taskmodel.h"

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
    QList<TaskModel*>getAllTasks();

    //Cree et/ou modifie une tâche
    void modifyTask(TaskModel*);

    void eraseTask(TaskModel*);
private:
    TaskModel* findTask(int id);
    QString taskToQuery(TaskModel*);




};

#endif // SQLCONNECTION_H
