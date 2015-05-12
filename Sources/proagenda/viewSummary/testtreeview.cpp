#include "custommodel.h"
#include "testtreeview.h"
#include <QLabel>
#include <QListView>
#include <QSqlTableModel>
#include <QStandardItemModel>
#include <QTableView>
#include <QTableWidget>
#include <QVBoxLayout>
#include "sqlconnection.h"
#include "treemodel.h"
#include "treeview.h"
#include "treedelegate.h"

TestTreeView::TestTreeView(QWidget *parent) : QWidget(parent)
{
    SqlConnection::getInstance();

    /**
     * Vue représentant l'arbre
     * Envoi les signaux Datachanged pour mettre à jour la base de donnée
     * La vue n'est pas directement connectée au model
     */
    TreeView* treeView = new TreeView;

    /**
     * Création du model
     */
    QSqlRelationalTableModel*model = new QSqlRelationalTableModel();
    model->setTable("Course");
    int semesterIndex = model->fieldIndex("semesterId");
    int courseIndex = model->fieldIndex("name");

    // Relation (Liste des semestre)
    model->setRelation(semesterIndex, QSqlRelation("Semester", "id", "name"));
    model->select();

    QSqlTableModel* relmodel = model->relationModel(semesterIndex);
    TreeModel* treeModel = new TreeModel(0,1);

    /**
      Construction de l'arbre (treeView)
      */
    for(int row=0; row < relmodel->rowCount(); row++){

        // Parcours de la liste les semestre
        QString SemesterName = relmodel->index(row,1).data().toString();
        QStandardItem* semester = new QStandardItem(SemesterName);
        treeModel->appendRow(semester);

        // Ajout des fils (cours)
        for(int i=0; i < model->rowCount(); i++){
            QString s = model->index(i,semesterIndex).data().toString();

            if(s == SemesterName){
                QStandardItem* course = new QStandardItem(model->index(i,courseIndex).data().toString());
                semester->appendRow(course);
            }
        }
    }

    /**
     * ces signaux ne marche pas forcément
     * le but est de détecté si le model change depuis un autre widget
     * Il faudra mettre à jour l'arbre dans ce cas;
     */
    // Si le model change
    connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(update(QModelIndex,QModelIndex)));
    // si la relation change (ne  marche pas !?)
    connect(relmodel, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(update(QModelIndex,QModelIndex)));


    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
    treeView->setItemDelegate(new TreeDelegate );
    treeView->setModel(treeModel);
    layout->addWidget(treeView);

    resize(800,300);
}

TestTreeView::~TestTreeView()
{

}

void TestTreeView::update(QModelIndex index1, QModelIndex index2)
{
    qDebug() << "ModelChanged " << index1.data().toString() << " at " << index1.row();
}

