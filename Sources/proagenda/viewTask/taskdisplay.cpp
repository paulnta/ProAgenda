#include "taskdisplay.h"
#include "ui_taskdisplay.h"
#include "mainwindow.h"
#include "sqlconnection.h"

#include <QMessageBox>


taskDisplay::taskDisplay( MainWindow* main_ui, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::taskDisplay),
    main_ui(main_ui)
{
    ui->setupUi(this);
    selectedWidget = NULL;

    connect(main_ui->getSideBarTask(), SIGNAL(isUpdated()), this, SLOT(updateTaskWidget()));
    connect(main_ui->getSideBarTask()->getMapper(), SIGNAL(currentIndexChanged(int)), this, SLOT(selectWidget(int)));

    layout = new QVBoxLayout(this);
    layout->setContentsMargins(0,0,0,0);

    tasks = new QList<taskCheckBox*>;

    model = Task::getModel();


    for(int i = 0; i < model->rowCount();i++){
        taskCheckBox* TWidget = new taskCheckBox(main_ui->getSideBarTask(), 0, new Task(model->record(i), i) );
        tasks->append(TWidget);
        connect(this, SIGNAL(isUpdated()), TWidget, SLOT(updateTaskWidget()));
    }

    if(tasks->size() > 0)
        selectWidget(0);

    foreach(taskCheckBox* task, *tasks) {
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

void taskDisplay::updateTaskWidget()
{
    emit isUpdated();
}

void taskDisplay::selectWidget(int row)
{
    if(selectedWidget != NULL)
        selectedWidget->setSelected(false);

    selectedWidget = tasks->at(row);
    selectedWidget->setSelected(true);
}


void taskDisplay::keyReleaseEvent(QKeyEvent* event)
{
    switch (event->key()) {
    case Qt::Key_Down:
        main_ui->getSideBarTask()->getMapper()->toNext();
        break;
    case Qt::Key_Up:
        main_ui->getSideBarTask()->getMapper()->toPrevious();
        break;
    default:
        break;
    }
}

void taskDisplay::mouseReleaseEvent(QMouseEvent *event)
{
    if(event->button() == Qt::LeftButton)
        setFocus();

}

