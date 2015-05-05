#include "sidebartask.h"
#include "ui_sidebartask.h"
#include "models/task.h"
#include "QDebug"
#include <QSqlQuery>
#include <QMessageBox>
#include <QDialogButtonBox>


SideBarTask::SideBarTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sideBarTask)
{
    ui->setupUi(this);

    Task::setupModel();

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

    //Task Submit
    btnSubmit = new QPushButton();
    btnSubmit->setText("Sauver");


    QSqlRelationalTableModel *model = Task::getModel();
    int courseIndex = Task::getTypeIndex();

    //SQLRelation set dropdown to search course name in DB
    QSqlTableModel *relModel = model->relationModel(courseIndex);
    courseDropDown->setModel(relModel);
    courseDropDown->setModelColumn(relModel->fieldIndex("name"));

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(taskName, model->fieldIndex("name"));
    mapper->addMapping(description, model->fieldIndex("description"));
    mapper->addMapping(courseDropDown, courseIndex);

    connect(btnSubmit, SIGNAL(clicked()), this , SLOT(submitTask()));
    mapper->toFirst();

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
    layout->addWidget(btnSubmit, QDialogButtonBox::AcceptRole);
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
    delete btnSubmit;
    delete ui;
}



void SideBarTask::loadTask(Task* task)
{
    mapper->setCurrentIndex(task->getRow());
}

void SideBarTask::submitTask()
{
    int oldIndex = mapper->currentIndex();
    mapper->submit();
    Task::getModel()->select();
    mapper->setCurrentIndex(oldIndex);
}

