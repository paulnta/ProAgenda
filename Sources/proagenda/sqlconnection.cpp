#include "sqlconnection.h"

SqlConnection* SqlConnection::instance = NULL;

QList<Task*>SqlConnection::getAllTasks(){
    QList<Task*> list;
    int rc;

    QSqlQuery myQuery("SELECT * FROM Task");
    int fieldName = myQuery.record().indexOf("name");
    int fieldDesc = myQuery.record().indexOf("description");
    int fieldTermDate = myQuery.record().indexOf("termdate");
    while(myQuery.next()){
        Task* t = new Task(myQuery.value(fieldName).toString(), myQuery.value(fieldDesc).toString(),myQuery.value(fieldTermDate).toDate());
        qDebug() << myQuery.value(fieldName).toString().toLatin1();
        list.append(t);
    }

    return list;

}


void SqlConnection::modifyTask(Task* task){
    int rc;
    char *zErrMsg = 0;

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
