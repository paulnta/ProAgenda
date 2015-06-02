#include "ui_mainwindow.h"
#include "toolbartask.h"
#include "utils/spacer.h"
#include <QDebug>
#include <QFile>

ToolBarTask::ToolBarTask(Ui::MainWindow* ui) : ui(ui)
{

    initStyleSheet();

    modelTask = Task::getInstance();
    // Paramètres généraux de la ToolBar
    setIconSize(QSize(20,20));

    // Création du bouton avec Icone
    QButtonGroup* sorting = new QButtonGroup(this);

    sortButtonCourse = new QPushButton("Matières");
    sortButtonDate = new QPushButton("Date");

    sorting->addButton(sortButtonCourse);
    sorting->addButton(sortButtonDate);

    QButtonGroup* filters = new QButtonGroup(this);
    filterButtonDone = new QPushButton("Achevé");
    filterButtonToDo = new QPushButton("A faire");
    filters->addButton(filterButtonDone);
    filters->addButton(filterButtonToDo);

    addButton = new QPushButton("Nouvelle Tâche",this);
    addButton->setIcon(QIcon(":/icons/img/icons/button_plus_dark.svg"));

    sortButtonCourse->setCheckable(true);
    sortButtonDate->setCheckable(true);
    filterButtonDone->setCheckable(true);
    filterButtonToDo->setCheckable(true);

    setUpLayout();

    // Reaction des boutons
    connect(addButton, SIGNAL(clicked()), this, SLOT(onAddtaskTriggered()));
    connect(sortButtonDate, SIGNAL(clicked()), this, SLOT(onSortButtonDateClicked()));
    connect(sortButtonCourse, SIGNAL(clicked()),this, SLOT(onSortButtonCourseClicked()));
    connect(filterButtonDone, SIGNAL(clicked()),this, SLOT(onFilterButtonDoneClicked()));
    connect(filterButtonToDo, SIGNAL(clicked()),this, SLOT(onFilterButtonToDoClicked()));

    initFilters();
    initSorting();

}

void ToolBarTask::initSorting(){

    switch (modelTask->getCurrentSort()) {
    case Task::BY_DATE:
        sortButtonDate->setChecked(true);
        sortButtonCourse->setChecked(false);
        break;
    case Task::BY_COURSE:
        sortButtonDate->setChecked(false);
        sortButtonCourse->setChecked(true);
        break;
    }
}

void ToolBarTask::initFilters(){

    switch (modelTask->getCurrentFilter()) {
    case Task::DONE:
        filterButtonDone->setChecked(true);
        filterButtonToDo->setChecked(false);
        break;
    case Task::TODO:
        filterButtonDone->setChecked(false);
        filterButtonToDo->setChecked(true);
        break;
    }
}


void ToolBarTask::setUpLayout(){

    addWidget(new Spacer(Spacer::MARGIN_SMALL));

    addWidget(sortButtonDate);
    addWidget(sortButtonCourse);

    addWidget(new Spacer(Spacer::MARGIN_SMALL));

    addWidget(filterButtonToDo);
    addWidget(filterButtonDone);
    addWidget(new Spacer());

    addWidget(addButton);
    addWidget(new Spacer(Spacer::MARGIN_XSMALL));
}

void ToolBarTask::onSortButtonDateClicked(){

    if(modelTask->getCurrentSort() != Task::BY_DATE){
        modelTask->sortBy(Task::BY_DATE);
    }
}

void ToolBarTask::onSortButtonCourseClicked()
{
    if(modelTask->getCurrentSort() != Task::BY_COURSE){
        Task::getInstance()->sortBy(Task::BY_COURSE);
    }
}

void ToolBarTask::onFilterButtonDoneClicked()
{
    if(modelTask->getCurrentFilter() != Task::DONE){
        Task::getInstance()->filterBy(Task::DONE);
    }
}

void ToolBarTask::onFilterButtonToDoClicked()
{
    if(modelTask->getCurrentFilter() != Task::TODO){
        Task::getInstance()->filterBy(Task::TODO);
    }
}

void ToolBarTask::onAddtaskTriggered()
{
   Task::getInstance()->addTask();
}

void ToolBarTask::initStyleSheet(){
    QFile file(":/css/css/toolbar.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    file.close();
}

ToolBarTask::~ToolBarTask()
{
    delete addButton;

}
