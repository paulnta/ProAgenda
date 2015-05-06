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
#include <QKeyEvent>
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
    QDataWidgetMapper* getMapper();

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
    QPushButton *btnSubmit;
    QSqlTableModel *relModel;

    // SQL RELATIONAL
    QDataWidgetMapper *mapper;
    int courseIndex;

protected:
    void keyReleaseEvent(QKeyEvent* event);

signals:
    void isUpdated();

private slots:
    void loadTask(Task*);
    void submitTask();

};

#endif // SIDEBARTASK_H
