#include "taskdisplay.h"
#include "ui_taskdisplay.h"

#include <QStandardItemModel>
#include <QTableView>
#include "mainwindow.h"
#include "sqlconnection.h"



taskDisplay::taskDisplay( MainWindow* main_ui, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskDisplay),
    main_ui(main_ui)
{
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);

    tasks = new QList<QWidget*>;

    Task* pco = new Task("TE PCO", "Mutex, Semaphore Echec", QDate(2015,05,9));
    pco->setPriority(1);

    taskWidget* t1 = new taskWidget(main_ui->getSideBarTask(), 0, pco );
    taskWidget* t2 = new taskWidget(main_ui->getSideBarTask(), 0, new Task("PRO", "Rapport Interme", QDate(2015,05,20)));
    taskWidget* t3 = new taskWidget(main_ui->getSideBarTask(), 0, new Task("TE MBT", "Intégrales", QDate(2015,05,11)));
    taskWidget* t4 = new taskWidget(main_ui->getSideBarTask(), 0, new Task("TE SLO", "Piratage", QDate(2015,05,12)));

//    QList<TaskModel*>taskList = SqlConnection::getInstance()->getAllTasks();

//    for(int i = 0; i < taskList.size(); i++){
//         tasks->append( new taskWidget(main_ui->getSideBarTask(), 0, taskList.at(i) ));
//    }

    tasks->append(t1);
    tasks->append(t2);
    tasks->append(t2);
    tasks->append(t3);
    tasks->append(t4);

    foreach(QWidget* task, *tasks) {
        layout->addWidget(task,0, Qt::AlignTop);
    }

    layout->addStretch(1);
    layout->setSpacing(0);

}

taskDisplay::~taskDisplay()
{
    delete ui;
    delete layout;
    delete tasks;
}