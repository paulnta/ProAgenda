#include "form.h"
#include "ui_form.h"

#include <QLabel>

Form::Form(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Form)
{
    ui->setupUi(this);
    this->setUpModel();

    // name
    name = new QLineEdit;
    name->setPlaceholderText("Nom de la tâche");
    QLineEdit * result = new QLineEdit;

    // ComboBox
    course = new QComboBox;
    QSqlTableModel* relmodel = model->relationModel(courseIndex);
//    relmodel->setEditStrategy(QSqlTableModel::OnFieldChange);

    course->setModel(relmodel);
    course->setModelColumn(relmodel->fieldIndex("name"));

    // Buttons next/prev
    next = new QPushButton("Next");
    prev = new QPushButton("prev");
    submit = new QPushButton("Save");

    // Types
    types = new TriStateButton("Type: ", "Devoir noté", "TE", "Laboratoire");


    // Mapping
    mapper = new QDataWidgetMapper(this);
    mapper->setModel(model);
    mapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    mapper->setItemDelegate(new QSqlRelationalDelegate(this));
    mapper->addMapping(name, model->fieldIndex("name"));
    mapper->addMapping(course, courseIndex);
    mapper->addMapping(result, model->fieldIndex("name"));
    mapper->addMapping(types, model->fieldIndex("typeId"));

    connect(mapper, SIGNAL(currentIndexChanged(int)),
            this, SLOT(updateButton(int)));

    connect(next, SIGNAL(clicked()),
            mapper, SLOT(toNext()));

    connect(prev, SIGNAL(clicked()),
            mapper, SLOT(toPrevious()));

    this->ui->formLayout->addRow(name);
    this->ui->formLayout->addRow(course);
    this->ui->formLayout->addRow(types);
    this->ui->formLayout->addRow(prev);
    this->ui->formLayout->addRow(next);
    this->ui->formLayout->addRow(submit);
    this->ui->formLayout->addRow(result);

    mapper->toFirst();

    connect(submit,SIGNAL(clicked()), this, SLOT(submitTask()));
}



void Form::setUpModel()
{
    SqlConnection::getDatabase();

    // Set Model
    model = new QSqlRelationalTableModel(this);
    model->setTable("Task");
    model->setEditStrategy(QSqlTableModel::OnFieldChange);

    // Set Relations
    courseIndex = model->fieldIndex("courseId");
    model->setRelation(courseIndex,QSqlRelation("Course","id","name"));


    // Select
    model->select();

}

void Form::updateButton(int index)
{
    next->setEnabled(index < model->rowCount()-1);
    prev->setEnabled(index > 0);
}

void Form::submitTask()
{
    // We save the current index because model->select() set it to -1;
    int index = mapper->currentIndex();
    mapper->submit();

    model->select();
    mapper->setCurrentIndex(index);

}

