#include "sqlconnection.h"

SqlConnection* SqlConnection::instance = NULL;

QList<Task*>SqlConnection::getAllTasks(){
    QList<Task*> list;

    QSqlQuery myQuery("SELECT *, "
                      "Type.name as typeName "
                      "FROM Task "
                      "INNER JOIN Type "
                      "ON Task.typeId = Type.id");
    int fieldId = myQuery.record().indexOf("id");
    int fieldName = myQuery.record().indexOf("name");
    int fieldDesc = myQuery.record().indexOf("description");
    int fieldTermDate = myQuery.record().indexOf("termDate");
    int fieldNote = myQuery.record().indexOf("note");
    int fieldPriority = myQuery.record().indexOf("priority");
    int fieldFinished = myQuery.record().indexOf("isFinished");
    int fieldCoefficient = myQuery.record().indexOf("coefficient");
    int fieldCourse = myQuery.record().indexOf("courseId");
    int fieldTypeName = myQuery.record().indexOf("typeName");
    int fieldWeight = myQuery.record().indexOf("weighting");
    while(myQuery.next()){
        Task* t = new Task(myQuery.value(fieldId).toInt(),
                           myQuery.value(fieldName).toString(),
                           myQuery.value(fieldDesc).toString(),
                           myQuery.value(fieldTermDate).toDate(),
                           myQuery.value(fieldNote).toDouble(),
                          myQuery.value(fieldPriority).toInt(),
                          myQuery.value(fieldFinished).toBool(),
                          myQuery.value(fieldCoefficient).toDouble(),
                           new TaskType(myQuery.value(fieldTypeName).toString(), myQuery.value(fieldWeight).toDouble()),
                           myQuery.value(fieldCourse).toInt());

        list.append(t);
    }

    return list;

}


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


