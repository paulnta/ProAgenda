#include "sqlconnection.h"

SqlConnection* SqlConnection::instance = NULL;



void SqlConnection::modifyTask(Task* task){

    QSqlQuery query;
    query.prepare("INSERT INTO Task (name,description,termdate,priority,isfinished, typeid, courseid) "\
                  "VALUES (:name, :description, :termdate, :priority, :isfinished, :typeid, :courseid)");
    query.bindValue(":name", 'TE PCO');
    query.bindValue(":description", "TE Mutex");
    query.bindValue(":termdate", "2015-04-27 12:00");
    query.bindValue(":priority", "3");
    query.bindValue(":isfinished", "true");
    query.bindValue(":typeid", "2");
    query.bindValue(":courseid", "3");
    query.exec();

}


