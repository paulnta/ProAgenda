#include "gradedialogbox.h"

gradedialogbox::gradedialogbox(QWidget *parent): QDialog(parent)
{
    grade = 4;
    coeff = 1;
    layout = new QFormLayout(this);
    ok = new QPushButton("Ok");
    cancel = new QPushButton("Annuler");
    noteBox = new QDoubleSpinBox;
    coeffBox = new QDoubleSpinBox;
    noteBox->setValue(4.0);
    coeffBox->setValue(1.0);


    layout->addRow(tr("Note :"), noteBox);
    layout->addRow(tr("Coefficient :"), coeffBox);
    layout->addRow(ok, cancel);
    setLayout(layout);
    connect( noteBox, SIGNAL(valueChanged(double)), this, SLOT(setGrade( double    )));
    connect( coeffBox, SIGNAL(valueChanged ( double  )), this, SLOT(setCoeff( double    )));
    connect( ok, SIGNAL(clicked()), this, SLOT(changedValue()));
    connect(cancel, SIGNAL(clicked()), this , SLOT(canceled()));
}

gradedialogbox::~gradedialogbox()
{

}

