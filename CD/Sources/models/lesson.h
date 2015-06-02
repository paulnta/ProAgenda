#ifndef LESSON_H
#define LESSON_H

#include <QString>
#include <QTime>
#include <QObject>
#include <QSqlRecord>
#include <QSqlRelationalTableModel>
#include "sqlconnection.h"

/*! \class Lesson
 * \brief Modèle pour les leçons
 *
 * Modèle qui est utilisé comme lien entre la table
 * "Lesson" de la base de données et le programme.
 */
class Lesson : public QObject
{
    Q_OBJECT
public:
    enum Sorting {DAY_OF_WEEK};

private:
    // Instance unique du modèle
    static Lesson *instance;

    /*!
     * \brief Constructeur vide
     */
    Lesson();

    // Index du champ de la Foreign Key
    int courseIndex;

    // Modèle de liaison entre cette classe et la base de données
    QSqlRelationalTableModel *model;

    // Tri actuel
    Sorting currentSort;


public:
    /*!
     * \brief Constructeur de copie
     * \param l Leçon de base pour la copie
     */
    Lesson(const Lesson& l) { }

    /*!
     * \brief Mettre à jour les données
     * \param needClear Variable de contrôle pour savoir s'il faut réinitialiser
     */
    void update(bool needClear = false);
    /*!
     * \brief Récupérer l'instance
     * \return L'instance unique (singleton)
     */
    static Lesson* getInstance();
    /*!
     * \brief Récupérer le modèle de liaison
     * \return Le modèle sur lequele effectuer les requêtes
     */
    QSqlRelationalTableModel *getModel() const;

    /*!
     * \brief Récupérer l'index du champ de la Foreign Key
     * \return L'index de la colonne courseId
     */
    int getCourseIndex() const;
    /*!
     * \brief Trier les données
     * \param sort Le type de tri à utiliser
     * \param order Dans quel ordre trier
     */
    void sortBy(Sorting sort, const Qt::SortOrder &order = Qt::AscendingOrder);

    bool needRefreshView;

    /*!
     * \brief Récupérer l'ordre dans lequel les données sont actuellement triés
     * \return L'ordre de tri
     */
    Sorting getCurrentSort() const;
    /*!
     * \brief Configurer l'ordre dans lequel les données seront triés
     * \param value L'ordre de tri voulu
     */
    void setCurrentSort(const Sorting &value);
    /*!
     * \brief Retourne le nombre de leçons dans la base de données
     * \return nombre de leçons dans la base de données
     */
    int rowCount() const;

    /*!
     * \brief Destructeur
     */
    ~Lesson();
};

#endif // LESSON_H
