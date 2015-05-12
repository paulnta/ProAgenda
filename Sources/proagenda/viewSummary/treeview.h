#ifndef TREEVIEW
#define TREEVIEW

#include <QTreeView>
#include <QDebug>

class TreeView : public QTreeView{

    Q_OBJECT

public:

    explicit TreeView(QWidget* parent = 0) :QTreeView(parent){

    }

    ~TreeView(){}


signals:

public slots:


    // QAbstractItemView interface
protected slots:
    void dataChanged(const QModelIndex &topLeft, const QModelIndex &bottomRight, const QVector<int> &roles)
    {

        if(!topLeft.parent().isValid()){
            qDebug() << "SEMESTRE" << topLeft.row() << " UPDATED to" << topLeft.data().toString();
        } else {
            qDebug() << "COUSE" << topLeft.row() << " UPDATED to" << topLeft.data().toString();
        }

    }
    void currentChanged(const QModelIndex &current, const QModelIndex &previous)
    {
        // SEMESTRE
        if(!current.parent().isValid()){
            qDebug() << "SEMESTRE: "<< current.row() << current.data().toString();
        } else {
            qDebug() << "COURSE: " << current.row() << current.data().toString();
        }
    }
    void updateEditorData()
    {
        qDebug() << "updateEditorData";
    }
};

#endif // TREEVIEW

