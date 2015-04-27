#include "taskdisplay.h"
#include "ui_taskdisplay.h"

#include <QStandardItemModel>
#include <QTableView>
#include "mainwindow.h"
#include "sqlconnection.h"

#include <QDebug>

taskDisplay::taskDisplay( MainWindow* main_ui, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskDisplay),
    main_ui(main_ui)
{
    ui->setupUi(this);

    layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);

    tasks = new QList<QWidget*>;

    QList<Task*>taskList = SqlConnection::getInstance()->getAllTasks();

    for(int i = 0; i < taskList.size(); i++){
         tasks->append( new taskWidget(main_ui->getSideBarTask(), 0, taskList.at(i) ));
    }

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
