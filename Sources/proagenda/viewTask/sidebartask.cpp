#include "sidebartask.h"
#include "ui_sidebartask.h"
#include "models/task.h"
#include "QDebug"

SideBarTask::SideBarTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sideBarTask)
{
    ui->setupUi(this);
    layout = new QVBoxLayout();

    // task course
    courseDropDown = new QComboBox();

    // task type
    taskType = new TriStateButton("Type: ", "TE","Devoir", "Labo");

    // Task name
    taskName = new QLineEdit();
    taskName->setPlaceholderText("Titre de la tache");

    // Task description
    description = new QTextEdit();
    description->setPlaceholderText("Description");
    description->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);
    description->setMinimumHeight(20);
    description->setMaximumHeight(100);

    // task priority
    priority = new TriStateButton("Priorité: ", "Haute", "Moyenne", "Basse");

    // task term
    termDate = new QDateTimeEdit(QDate(QDate::currentDate()));
    hasTerm = new QCheckBox("Echéance");
    hasTerm->setChecked(false);
    connect(hasTerm, SIGNAL(clicked(bool)), termDate, SLOT(setEnabled(bool)) );
    termDate->setEnabled(false);

    layout->addWidget(courseDropDown);
    layout->addWidget(taskType);
    layout->addSpacing(10);
    layout->addWidget(taskName);
    layout->addWidget(description);
    layout->addSpacing(10);
    layout->addWidget(hasTerm);
    layout->addWidget(termDate);
    layout->addSpacing(10);
    layout->addWidget(priority);
    layout->addStretch();
    this->setLayout(layout);
}

SideBarTask::~SideBarTask()
{
    delete layout;
    delete courseDropDown;
    delete taskName;
    delete description;
    delete hasTerm;
    delete termDate;
    delete priority;
    delete taskType;
    delete ui;
}

void SideBarTask::loadTask(Task* task)
{
    this->taskName->setText(task->getName());
    this->description->setText(task->getDescription());
    this->termDate->setDate(task->getTermDate());
    this->priority->setChoice(task->getPriority());
}
