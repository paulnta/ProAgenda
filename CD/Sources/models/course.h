#ifndef COURSE_H
#define COURSE_H

#include <QString>
#include "QDate"
#include <QObject>
#include <QSqlRecord>
#include <QSqlRelationalTableModel>
#include "sqlconnection.h"

/*! \class Course
 * \brief Modèle pour les cours
 *
 * Modèle qui est utilisé comme lien entre la table
 * "Course" de la base de données et le programme.
 */
class Course : public QObject
{
    Q_OBJECT
private:
    /*!
     * \brief Constructeur vide
     */
    Course();
    // Instance unique du modèle
    static Course *instance;

    // Index du champ de la Foreign Key
    int moduleIndex;
    int semesterIndex;

    // Modèle de liaison entre cette classe et la base de données
    QSqlRelationalTableModel *model;

public:
    /*!
     * \brief Récupérer l'instance
     * \return L'instance unique (singleton)
     */
    static Course* getInstance();
    /*!
     * \brief Mettre à jour les données
     */
    void update();
    /*!
     * \brief Récupérer le modèle de liaison
     * \return Le modèle sur lequele effectuer les requêtes
     */
    QSqlRelationalTableModel *getModel() const;

    /*!
     * \brief Récupérer l'index du champ de la Foreign Key
     * \return L'index de la colonne "moduleId"
     */
    int getModuleIndex() const;
    /*!
     * \brief Récupérer l'index du champ de la Foreign Key
     * \return L'index de la colonne "semesterId"
     */
    int getSemesterIndex() const;

    /*!
     * \brief Retourne le nombre de cours dans la base de données
     * \return nombre de cours dans la base de données
     */
    int rowCount() const;

    /*!
     * \brief Destructeur
     */
    ~Course();
};

#endif // COURSE_H
