#include "termdate.h"
#include <QDebug>

TermDate::TermDate(QWidget *parent) :
    QWidget(parent),
    STYLE_DEFAULT("QLabel {color : #2ba3dd; font-size: 12px}"),  // Tâche Pas en retard
    STYLE_WARNING("QLabel {color : #dc4144; font-size: 12px}")  // Tâche En retard
{
    setContentsMargins(0,0,0,0);
    layout = new QHBoxLayout(this);
    label = new QLabel;
    label->setStyleSheet(STYLE_DEFAULT);
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
    termDate = value;

    // Création d'un objet date à partir d'une string
    QDateTime dateTime = QDateTime::fromString(value, "yyyy-MM-ddTHH:mm:ss.z");

    // Différence entre aujourd'hui et la date d'échance (nb jours)
    int nbDays = QDateTime::currentDateTime().daysTo(dateTime);

    switch (nbDays) {

    case 0:
        label->setText("aujourd'hui");
        break;
    case 1:
        label->setText("demain");
        break;
    case 2:
        label->setText("après-demain");
        break;
    default:

        if(nbDays > 0){
            label->setStyleSheet(STYLE_DEFAULT);
            label->setText(QString("dans %1 jours").arg(nbDays));
            label->setFont(font);
        }
        else{
            label->setStyleSheet(STYLE_WARNING);
            label->setText(QString("en retard de %1 jour%2").arg(-nbDays).arg(-nbDays > 1 ? "s": ""));
            label->setFont(font);
        }

        break;
    }
}


