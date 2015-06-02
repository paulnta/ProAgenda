#ifndef TESTTREEVIEW_H
#define TESTTREEVIEW_H

#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QVBoxLayout>
#include <QWidget>

#include "sqlconnection.h"
#include "treemodel.h"
#include "treeview.h"
#include "vsummary.h"


/*! \class SideBarTreeView
 * \brief Classe créeant et contenant le TreeView
 *
 * Crée et contient le TreeView. Ce widget sera ajouté
 * dans la SideBarSummary.
 */
class SideBarTreeView : public QWidget
{
    Q_OBJECT
public:
    /*!
     * \brief Constructeur de la classe SideBarTreeView
     *
     * \param parent : Le widget parent.
     * \param summary : Fenêtre contenant le SideBarTreeView (vue résumé).
     *
     */
    explicit SideBarTreeView(QWidget *parent = 0, VSummary* vSummary = 0);

    /*!
     * \brief Rafraîchit la SideBar et le TreeView
     */
    void refresh();

    /*!
     * \brief Getter sur le TreeView
     *
     * \return Le TreeView
     */
    TreeView* getTreeView() {
        return treeView;
    }

    /*!
     * \brief Getter sur le TreeModel
     *
     * \return Le TreeModel
     */
    TreeModel* getTreeModel() {
        return treeModel;
    }

private:
    TreeView* treeView = NULL;
    TreeModel* treeModel = NULL;
};

#endif // TESTTREEVIEW_H
