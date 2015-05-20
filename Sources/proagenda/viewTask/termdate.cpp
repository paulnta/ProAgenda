#include "termdate.h"
#include <QDebug>

TermDate::TermDate(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    label = new QLabel;
    layout->addWidget(label);
    setLayout(layout);
}

TermDate::~TermDate()
{
    delete label;
    delete layout;
}
QString TermDate::getTermDate() const
{
    return termDate;
}

void TermDate::setTermDate(QString value)
{
    qDebug() << "SetTermdate" << value;
    termDate = value;

    QDateTime dateTime = QDateTime::fromString(value, "yyyy-MM-ddTHH:mm:ss.z");
    label->setText(dateTime.daysTo(QDateTime::currentDateTime()));
}

//void TermDate::termDateChanged()
//{
//
//}


