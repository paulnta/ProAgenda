#ifndef TREEVIEW
#define TREEVIEW

#include <QSqlRecord>
#include <QSqlTableModel>
#include <QTreeView>

#include "vsummary.h"

/*! \class TreeView
 * \brief Classe héritée de QTreeView représentant un TreeView
 *
 *  Représente l'affichage des jours et semestres dans la vue résumé.
 */
class TreeView : public QTreeView {

    Q_OBJECT

private:
    VSemesterFill* vSemesterFill;
    VCourseFill* vCourseFill;
    VSummary* vSummary;
    QSqlTableModel* sqlTableModel;

public:
    /*!
     * \brief Constructeur de la classe TreeView
     *
     * \param parent : Le widget parent.
     * \param summary : Fenêtre contenant le TreeView (vue résumé).
     *
     */
    explicit TreeView(QWidget* parent = 0, VSummary* vSummary = 0) : QTreeView(parent), vSummary(vSummary) {}

    /*!
     * \brief Destructeur de la classe TreeView
     */
    ~TreeView(){}

    /*!
     * \brief Setter pour le champs sqlTableModel
     *
     *  \param sqlTableModel : Nouvelle valeur
     */
    void setSqlTableModel(QSqlTableModel* sqlTableModel) {
        this->sqlTableModel = sqlTableModel;
    }

signals:


protected slots:

    // Fonction appelé à chaque clique sur un élément du TreeView
    void currentChanged(const QModelIndex &current, const QModelIndex &previous)
    {
        // On récupère le semestre sélectionné
        QSqlRecord semester = sqlTableModel->record(current.row());

        if(!current.parent().isValid()) {
            // Lorsqu'on est dans un semestre, on modifie les vues en conséquences
            vSummary->switchViews(true);
            vSummary->vSemesterFill->setEditionMode(true);
            vSummary->vSemesterFill->setFieldsValue(semester.value("id").toInt(), semester.value("name").toString(), QDate::fromString(semester.value("startDate").toString(), "dd.MM.yyyy"), QDate::fromString(semester.value("endDate").toString(), "dd.MM.yyyy"));
        }
        else {
            // Lorsqu'on est dans un cours, on sélectionne le cours correspondant
            vSummary->switchViews(false);
            semester = sqlTableModel->record(current.parent().row());
            QSqlQueryModel queryModel;
            queryModel.setQuery("SELECT * FROM Course WHERE semesterId = " + semester.value("id").toString() + " AND name = '" + current.data().toString() + "'");
            QSqlRecord course = queryModel.record(0);

            // et on modifie les vues en conséquences
            vSummary->vCourseFill->setEditionMode(true);
            vSummary->vCourseFill->setFieldsValue(course.value("id").toInt(), course.value("name").toString(), course.value("description").toString(), course.value("threshold").toFloat(), course.value("weighting").toFloat(), course.value("color").toString(), course.value("semesterId").toInt(), course.value("moduleId").toInt());
            vSummary->vCourseDetails->prepare(course);
        }
    }


};

#endif // TREEVIEW
