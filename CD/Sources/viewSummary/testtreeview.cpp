#include "testtreeview.h"

SideBarTreeView::SideBarTreeView(QWidget *parent, VSummary* vSummary) : QWidget(parent)
{
    SqlConnection::getInstance();

    // On supprime l'arbre s'il existe déja
    if(treeView != NULL)
        delete treeView;

    treeView = new TreeView(0, vSummary);

    // On crée le modèle pour les cours
    QSqlRelationalTableModel* model = new QSqlRelationalTableModel;
    model->setTable("Course");
    int semesterIndex = model->fieldIndex("semesterId");
    int courseIndex = model->fieldIndex("name");

    // Relation (Liste des semestre)
    model->setRelation(semesterIndex, QSqlRelation("Semester", "id", "name"));
    model->select();

    // On crée le modèle pour les semestres
    QSqlTableModel* relmodel = model->relationModel(semesterIndex);

    // On supprime le modèle de l'arbre
    if(treeModel != NULL)
        delete treeModel;

    treeModel = new TreeModel(0, 1);

    // On construit l'arbre
    for(int row=0; row < relmodel->rowCount(); row++){

        // Parcours de la liste les semestre
        QString SemesterName = relmodel->index(row,1).data().toString();
        QStandardItem* semester = new QStandardItem(SemesterName);
        treeModel->appendRow(semester);


        // Ajout des fils (cours)
        for(int i=0; i < model->rowCount(); i++){
            QString s = model->index(i,semesterIndex).data().toString();

            if(s == SemesterName){
                QStandardItem* course = new QStandardItem(model->index(i, courseIndex).data().toString());
                semester->appendRow(course);
            }
        }
    }

    // On configure le treeView et on l'ajoute au layout
    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    treeView->setSqlTableModel(relmodel);
    treeView->setHeaderHidden(true);
    treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
    treeView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    treeView->setModel(treeModel);
    layout->addWidget(treeView);

    resize(800,300);
}
