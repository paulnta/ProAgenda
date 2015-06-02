#ifndef VSEMESTERFILL_H
#define VSEMESTERFILL_H

#include <QWidget>

#include "summaryutils.h"

namespace Ui {
class VSemesterFill;
}

class VSummary;

/*! \class VSemesterFill
 * \brief Classe representant la zone de modification des
 *      données d'un semestre.
 *
 *  La classe affiche le semestre séléctionné dans la SideBar
 *  et permet également de créer ainsi que de modifier un semestre
 */
class VSemesterFill : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la classe VSemestreFill
     *
     * \param parent : Le widget parent.
     * \param summary : Fenêtre contenant le VSemesterFill (vue résumé).
     *
     */
    explicit VSemesterFill(QWidget *parent = 0, VSummary *vSummary = 0);

    /*!
     * \brief Destructeur de la classe VSemestreFill
     */
    ~VSemesterFill();

    /*!
     * \brief Rempli les champs de l'interface.
     *
     *  \param id : Identifiant du semestre
     *  \param name : Nom du semestre
     *  \param starDate : Date de début du semestre
     *  \param endDate : Date de fin du semestre
     */
    void setFieldsValue(int id, QString name, QDate startDate, QDate endDate);

    /*!
     * \brief Modifie l'état de la vue (ajout ou édition).
     *
     *  \param value : Est-ce qu'on est en modification (true) ou en ajout (false).
     */
    void setEditionMode(bool value);

private slots:
    // Actions lors du clique sur les boutons
    void on_btnAdd_clicked();
    void on_btnDelete_clicked();

private:
    Ui::VSemesterFill *ui;
    bool editionMode = false;
    int currentSemesterId;
    VSummary *vSummary;
};

#endif // VSEMESTERFILL_H
