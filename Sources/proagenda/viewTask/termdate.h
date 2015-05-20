#ifndef TERMDATE_H
#define TERMDATE_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QDateTimeEdit>

/**
 * Indication de la date d'échance d'une tâche
 * nb jours  = 1 : demain
 * nb jours  = 2 : après-demain
 * nb jours > 2  : lundi, mardi, etc..
 *
 * @brief The TermDate class
 */
class TermDate : public QWidget
{
    Q_OBJECT

    Q_PROPERTY(QString termDate READ getTermDate WRITE setTermDate USER true)

public:
    explicit TermDate(QWidget *parent = 0);
    ~TermDate();

    QString termDate;
    QLabel* label;
    QHBoxLayout* layout;
    QFont font;

    QString getTermDate() const;
    void setTermDate(QString value);


public slots:

};

#endif // TERMDATE_H
