#include "sqlconnection.h"

SqlConnection* SqlConnection::instance = NULL;


SqlConnection::SqlConnection()
{
    database = QSqlDatabase::addDatabase("QSQLITE");
    database.setDatabaseName("Database.sqlite");  // Placez le fichier  Database.sqlite dans le répertoire de l'exécutable !
    database.open();
}

SqlConnection *SqlConnection::getInstance()
{
    if(instance == NULL){
        instance = new SqlConnection;
    }

    return instance;
}

QSqlDatabase SqlConnection::getDatabase()
{
    return getInstance()->database;
}

SqlConnection::~SqlConnection()
{
    database.close();
    delete instance;
}
