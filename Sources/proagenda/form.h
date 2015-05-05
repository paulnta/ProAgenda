#ifndef FORM_H
#define FORM_H

#include <QDebug>
#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QDataWidgetMapper>
#include <QSqlRelationalTableModel>
#include "viewTask/tristatebutton.h"

#include "sqlconnection.h"

namespace Ui {
class Form;
}

class Form : public QWidget
{
    Q_OBJECT

public:

    explicit Form(QWidget *parent = 0);
    void setUpModel();

    ~Form(){

        delete ui;
        delete name;
        delete course;
        delete mapper;
        delete model;
        delete prev;
        delete next;
        delete types;
    }

public slots:
    void updateButton(int);
    void submitTask();
private:
    QLineEdit* name;
    QComboBox* course;
    QSqlRelationalTableModel* model;
    QDataWidgetMapper* mapper;
    int courseIndex;
    QPushButton* next;
    QPushButton* prev;
    QPushButton* submit;
    TriStateButton* types;

    Ui::Form *ui;
};

#endif // FORM_H
