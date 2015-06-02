#ifndef VCOURSEFILL_H
#define VCOURSEFILL_H

#include <QColorDialog>
#include <QComboBox>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlRecord>
#include <QWidget>

#include "summaryutils.h"

namespace Ui {
class VCourseFill;
}

class VSummary;


/*! \class VCourseFill
 * \brief Classe representant la zone de modification des
 *      données d'un cours.
 *
 *  La classe affiche le cours séléctionné dans la SideBar
 *  et permet également de créer ainsi que de modifier un cours.
 */
class VCourseFill : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la classe VCourseFill
     *
     * \param parent : Le widget parent.
     * \param summary : Fenêtre contenant le VCourseFill (vue résumé).
     *
     */
    explicit VCourseFill(QWidget *parent = 0, VSummary *vSummary = 0);

    /*!
     * \brief Destructeur de la classe VCourseFill
     */
    ~VCourseFill();

    /*!
     * \brief Rempli les champs de l'interface.
     *
     *  \param id : Identifiant du cours
     *  \param name : Nom du cours
     *  \param description : Description du cours.
     *  \param threshold : Seuil du cours.
     *  \param weighting : Poids du cours.
     *  \param semesterId : Identifiant du semestre correspondant au cours.
     *  \param moduleId : Identifiant du module correspondant au cours.
     */
    void setFieldsValue(int id, QString name, QString description, float threshold, float weighting, QString color, int semesterId, int moduleId);

    /*!
     * \brief Modifie l'état de la vue (ajout ou édition).
     *
     *  \param value : Est-ce qu'on est en modification (true) ou en ajout (false).
     */
    void setEditionMode(bool value);

private:
    Ui::VCourseFill *ui;
    bool editionMode = false;
    int currentCourseId;
    QColor currentColor;
    VSummary *vSummary;

    QSqlTableModel *semesterModel = 0;
    QSqlTableModel *moduleModel = 0;

    // Sélectionne la ligne correspondant à l'objet dans la DB correspondant à dbId dans le combobox cbx
    void setCbxSelectedItem(QComboBox *cbx, int dbId);
    // Récupère l'id de l'objet sélectionné dans le combobox cbx
    int getCbxSelectedItemDbIndex(QComboBox *cbx);
    // Rempli les combobox
    void fillComboBox();

private slots:
    // Actions lors du clique sur les boutons
    void on_btnAdd_clicked();
    void on_btnDelete_clicked();
    void on_btnColor_clicked();
};

#endif // VCOURSEFILL_H
