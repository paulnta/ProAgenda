#ifndef CUSTOMMODEL
#define CUSTOMMODEL

#include <QAbstractTableModel>
#include <QSqlTableModel>
#include <QDebug>

class CustomModel : public QAbstractTableModel
{


    Q_OBJECT

    QSqlTableModel* model;

public:
    explicit CustomModel(QWidget *parent = 0){

        model = new QSqlTableModel(this);
        model->setTable("Course");
        model->select();

        qDebug() << "DisplayRole =" << Qt::DisplayRole;
    }

    ~CustomModel(){

    }

    // QAbstractItemModel interface
public:

    int rowCount(const QModelIndex &parent) const{
        return model->rowCount();
    }

    int columnCount(const QModelIndex &parent) const{
        return model->columnCount();
    }



    QVariant data(const QModelIndex &index, int role) const{
        qDebug() << "role =" << role;
        model->index(index.row(),index.column(),QModelIndex());
        return model->data(index, role);
    }

signals:

public slots:


    // QAbstractItemModel interface
public:

    bool setData(const QModelIndex &index, const QVariant &value, int role)
    {
        if(index.isValid() && role == Qt::EditRole){

            model->setData(index,value,role);
            model->submit();

            QModelIndex topLeft = createIndex(0,0);
            QModelIndex bottomRight = createIndex(rowCount(index) - 1, columnCount(index) - 1);

            emit dataChanged(topLeft, bottomRight);

           return true;
        }
        return false;
    }

};


#endif // CUSTOMMODEL

