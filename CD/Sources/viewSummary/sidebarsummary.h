#ifndef SIDEBARSUMMARY_H
#define SIDEBARSUMMARY_H

#include <QVBoxLayout>
#include <QWidget>

namespace Ui {
class SideBarSummary;
}


/*! \class SideBarSummary
 * \brief Classe représentant la side bar (barre à droite) dans la vue résumé
 *
 * Cette classe va contenir la SideBarTreeView et donc le TreeView
 */
class SideBarSummary : public QWidget
{
    Q_OBJECT

public:
    /*!
     * \brief Constructeur de la classe SideBarSummary
     *
     * \param parent : Le widget parent.
     *
     */
    explicit SideBarSummary(QWidget *parent = 0);

    /*!
     * \brief Destructeur de la classe SideBarSummary
     */
    ~SideBarSummary();

    /*!
     * \brief Getter pour le layout
     *
     *  \return Le layout correspondant
     */
    QVBoxLayout* getLayout();

private:
    Ui::SideBarSummary *ui;
};

#endif // SIDEBARSUMMARY_H
