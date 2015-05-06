#include "termdate.h"

TermDate::TermDate(QWidget *parent) : QWidget(parent)
{
//    layout = new QHBoxLayout(this);
//    label = new QLabel("date",this);
//    layout->addWidget(label);
//    setLayout(layout);
}

TermDate::~TermDate()
{
    delete label;
    delete layout;
}
QDateTime TermDate::getTermDate() const
{
    return termDate;
}

void TermDate::setTermDate(const QDateTime &value)
{
    termDate = value;
    label->setText(termDate.toString());
}

//void TermDate::termDateChanged()
//{
//
//}


