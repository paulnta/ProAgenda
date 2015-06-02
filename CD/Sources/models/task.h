#ifndef TASK_H
#define TASK_H

#include <QObject>
#include <QDate>
#include <QString>
#include <QLayout>
#include <QSqlRecord>
#include <QSqlRelationalTableModel>

/*! \class Task
 * \brief Modèle pour les tâches
 *
 * Modèle qui est utilisé comme lien entre la table
 * "Task" de la base de données et le programme.
 */
class Task : public QObject

{
    Q_OBJECT

public:
    enum Sorting {BY_DATE, BY_COURSE};
    enum Filter {TODO, DONE};

private:
    // Instance unique du modèle
    static Task *instance;
    /*!
     * \brief Constructeur vide
     */
    Task();

    // Index du champ de la Foreign Key
    int courseIndex;
    int typeIndex;

    // Modèle de liaison entre cette classe et la base de données
    QSqlRelationalTableModel *model;

    Sorting currentSort;
    Filter currentFilter;

public:
    /*!
     * \brief Destructeur
     */
    ~Task();

    /*!
     * \brief Mettre à jour les données
     * \param needClear Variable de contrôle pour savoir s'il faut réinitialiser
     */
    void update(bool needClear = false);
    /*!
     * \brief Récupérer l'instance unique (singleton)
     * \return instance unique
     */
    static Task* getInstance();
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
     * \brief Récupérer l'index du champ de la Foreign Key
     * \return L'index de la colonne typeId
     */
    int getTypeIndex() const;
    /*!
     * \brief Ajouter une tâche
     */
    void addTask();
    /*!
     * \brief Supprimer une tâche
     * \param row tâche à supprimer
     */
    void removeTask(const int row);
    /*!
     * \brief Nombre de tâches
     * \return nombre de tâches
     */
    int rowCount() const;

    /*!
     * \brief Trier les données
     * \param sort Selon quel champs les trier
     * \param order Ordre croissant/décroissant
     */
    void sortBy(Sorting sort, const Qt::SortOrder &order = Qt::AscendingOrder);

    /*!
     * \brief Ajouter des filtres aux données
     * \param filter Le filtre à appliquer
     */
    void filterBy(Filter filter);

    bool needRefreshView;

    /*!
     * \brief Récupérer le filtre actuellement utilisé
     * \return filtre actuel
     */
    Filter getCurrentFilter() const;
    /*!
     * \brief Configurer le filtre à utiliser
     * \param value Filtre à utiliser
     */
    void setCurrentFilter(const Filter &value);

    /*!
     * \brief Récupérer le tri actuellement utilisé
     * \return trie acteul
     */
    Sorting getCurrentSort() const;
    /*!
     * \brief Configurer le tri à utiliser
     * \param value Tri à utiliser
     */
    void setCurrentSort(const Sorting &value);

    /*!
     * \brief Trouver une tâche en utilisant l'index
     * \param id L'index de la tâche
     * \return La ligne à laquelle la tâche se trouve
     */
    int findRowById(int id);
signals:
    /*!
     * \brief Signal pour une nouvelle tâche
     */
    void newTask(int);
    /*!
     * \brief Signal pour actualiser le modèle
     */
    void modelUpdated();
    /*!
     * \brief Signal pour appliquer des filtres
     */
    void modelFiltered();
};

#endif // TASK_H
