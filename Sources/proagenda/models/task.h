#ifndef TASK_H
#define TASK_H

#include "taskType.h"
#include <QDate>
#include <QString>
#include <QLayout>
#include <QSqlRecord>

#include <QSqlRelationalTableModel>

class Task : public QObject
{
    Q_OBJECT
private:
    // Instance unique du modèle
    static Task *instance;
    // Constructeur
    Task();
    // Index du champ de la Foreign Key
    int courseIndex;

    // Modèle de liaison entre cette classe et la base de données
    QSqlRelationalTableModel *model;

public:
    ~Task();

    // Mettre à jour les données
    void update();
    // Récupérer l'instance
    static Task* getInstance();
    // Récupérer le modèle de liaison
    QSqlRelationalTableModel *getModel() const;

    // Récupérer l'index du champ de la Foreign Key
    int getCourseIndex() const;

    // Ajouter une tâche
    void addTask();

    void removeTask(int);
    int rowCount();

    // Trier les données
    void sortBy(const QString &field, const Qt::SortOrder &order);
    // Ajouter des filtres aux données
    void filterBy(const QString &filter);


signals:
    void newTask();

};

#endif // TASK_H
