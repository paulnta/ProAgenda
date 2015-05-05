#ifndef SIDEBARTASK_H
#define SIDEBARTASK_H

#include <QWidget>
#include <QComboBox>
#include <QGroupBox>
#include <QRadioButton>
#include <QLineEdit>
#include <QFormLayout>
#include <QTextEdit>
#include <QCheckBox>
#include <QDateTimeEdit>
#include "sqlconnection.h"
#include <QSqlRelationalTableModel>
#include <QDataWidgetMapper>
#include <QItemSelectionModel>
#include <QSqlRelationalDelegate>

#include "viewTask/tristatebutton.h"

class Task;

namespace Ui {
class sideBarTask;
}

class SideBarTask : public QWidget
{
    Q_OBJECT

public:
    explicit SideBarTask(QWidget *parent = 0);
    ~SideBarTask();

private:
    Ui::sideBarTask *ui;
    QVBoxLayout* layout;
    QComboBox *courseDropDown ;

    QLineEdit *taskName;
    QWidget *radioButtons;
    QTextEdit *description;
    QCheckBox *hasTerm;
    QDateTimeEdit *termDate;
    TriStateButton* priority;
    TriStateButton* taskType;

    // TEST SQL RELATIONAL
    QSqlRelationalTableModel *model;
       QItemSelectionModel *selectionModel;
       QDataWidgetMapper *mapper;
       int typeIndex;

       void setupModel();

private slots:
    void loadTask(Task*);
};

#endif // SIDEBARTASK_H
