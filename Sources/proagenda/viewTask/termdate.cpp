#include "termdate.h"
#include <QDebug>

TermDate::TermDate(QWidget *parent) : QWidget(parent)
{
    layout = new QHBoxLayout(this);
    label = new QLabel;
    font = label->font();
    font.setPixelSize(12);
    label->setStyleSheet("QLabel {color : #2ba3dd}");
    label->setFont(font);
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
            label->setStyleSheet("QLabel {color : #2ba3dd}");
            label->setText(QString("dans %1 jours").arg(nbDays));
            label->setFont(font);
        }
        else{
            label->setStyleSheet("QLabel {color : #dc4144}");
            label->setText(QString("en retard de %1 jour%2").arg(-nbDays).arg(-nbDays > 1 ? "s": ""));
            label->setFont(font);
        }

        break;
    }

}


