#include "sidebartask.h"
#include "ui_sidebartask.h"
#include "models/task.h"
#include "QDebug"
#include <QSqlQuery>


SideBarTask::SideBarTask(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::sideBarTask)
{
    ui->setupUi(this);
    setupModel();
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

    QSqlTableModel *relModel = model->relationModel(typeIndex);
    courseDropDown->setModel(relModel);
    courseDropDown->setModelColumn(relModel->fieldIndex("name"));

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
//    mapper->addMapping(nameEdit, model->fieldIndex("name"));
//    mapper->addMapping(addressEdit, model->fieldIndex("course"));
    mapper->addMapping(courseDropDown, typeIndex);

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

void SideBarTask::setupModel(){

    QSqlQuery query("SELECT* FROM course");
    query.exec();
    model = new QSqlRelationalTableModel(this, SqlConnection::getInstance()->getDatabase());
    model->setTable("task");
    model->setEditStrategy(QSqlTableModel::OnManualSubmit);
    typeIndex = model->fieldIndex("courseId");
    model->setRelation(typeIndex, QSqlRelation("course", "id", "name"));
    model->select();


}

void SideBarTask::loadTask(Task* task)
{
    this->taskName->setText(task->getName());
    this->description->setText(task->getDescription());
    this->termDate->setDate(task->getTermDate());
    this->priority->setChoice(task->getPriority());
}
