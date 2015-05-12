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


    TreeView* treeView = new TreeView;
    QTableView* tableView = new QTableView;


    QSqlRelationalTableModel*model = new QSqlRelationalTableModel();
    model->setTable("Course");
    int semesterIndex = model->fieldIndex("semesterId");
    int courseIndex = model->fieldIndex("name");
    model->setRelation(semesterIndex, QSqlRelation("Semester", "id", "name"));
    model->select();

    QSqlTableModel* relmodel = model->relationModel(semesterIndex);
    TreeModel* treeModel = new TreeModel(0,2);

    for(int row=0; row < relmodel->rowCount(); row++){

        QString SemesterName = relmodel->index(row,1).data().toString();
        QStandardItem* semester = new QStandardItem(SemesterName);
        treeModel->appendRow(semester);

        for(int i=0; i < model->rowCount(); i++){
            QString s = model->index(i,semesterIndex).data().toString();

            if(s == SemesterName){
                QStandardItem* course = new QStandardItem(model->index(i,courseIndex).data().toString());
                semester->appendRow(course);
            }
        }
    }

    connect(model, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(update(QModelIndex,QModelIndex)));
    connect(relmodel, SIGNAL(dataChanged(QModelIndex,QModelIndex)), this, SLOT(update(QModelIndex,QModelIndex)));


    QVBoxLayout* layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);
    tableView->setSizePolicy(QSizePolicy::Expanding,QSizePolicy::Expanding);
    treeView->setSelectionBehavior(QAbstractItemView::SelectRows);
    treeView->setItemDelegate(new TreeDelegate );
    treeView->setModel(treeModel);
    treeView->hideColumn(1);
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

