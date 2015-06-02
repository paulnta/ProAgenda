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

//    setStyleSheet("border: 1px solid red;");
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
    priority = new TriStateButton("Priorité: ", "Basse", "Moyenne", "Haute");

    // task term
    termDate = new QDateTimeEdit;
    termDate->setCalendarPopup(true);
    hasTerm = new QCheckBox("Echéance");
    connect(hasTerm, SIGNAL(clicked(bool)), termDate, SLOT(setEnabled(bool)) );
    hasTerm->setChecked(false);
    termDate->setEnabled(false);

    // Task Submit
    btnSubmit = new QPushButton();
    btnSubmit->setText("Sauver");
    btnSubmit->setDefault(false);
    btnSubmit->setAutoDefault(true);

    model = Task::getInstance()->getModel();
    courseIndex = Task::getInstance()->getCourseIndex();

    //SQLRelation set dropdown to search course name in DB
    relModel = model->relationModel(courseIndex);
    courseDropDown->setModel(relModel);
    courseDropDown->setModelColumn(relModel->fieldIndex("name"));

    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));

    // Mapping
    mapper->addMapping(taskName, model->fieldIndex("name"));
    mapper->addMapping(description, model->fieldIndex("description"));

    mapper->addMapping(courseDropDown, courseIndex);
    mapper->addMapping(priority, model->fieldIndex("priority"));
    mapper->addMapping(taskType, model->fieldIndex("typeId"));
    mapper->addMapping(termDate, model->fieldIndex("termDate"));


    // Ajout des widgets au layout
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
    layout->addWidget(btnSubmit, QDialogButtonBox::AcceptRole,Qt::AlignBottom);
    layout->setContentsMargins(12,12,12,0);

    connect(btnSubmit, SIGNAL(clicked()), this , SLOT(submitTask()));

    debugRow = new QLabel;
    mapper->toFirst();

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

QDataWidgetMapper *SideBarTask::getMapper()
{
    return mapper;
}

void SideBarTask::keyReleaseEvent(QKeyEvent* event)
{
    switch (event->key()) {

    case Qt::Key_Return:
        submitTask();
        break;
    default:
        break;
    }
}

void SideBarTask::loadTask(int row)
{
    mapper->setCurrentIndex(row);
    emit changeSelection(row);
    qDebug() << "loading" << mapper->currentIndex();
}

void SideBarTask::submitTask()
{
    // On sauvegarde l'index courant
    // car mis à -1 après un model->select()
    int oldIndex = mapper->currentIndex();

    mapper->submit();
    model->submitAll();
    mapper->setCurrentIndex(oldIndex);

    if(Task::getInstance()->needRefreshView){
        emit needRefresh();
        Task::getInstance()->needRefreshView = false;
    } else {
        emit isUpdated();
    }
}

