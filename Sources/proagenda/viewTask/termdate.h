#ifndef TERMDATE_H
#define TERMDATE_H

#include <QWidget>
#include <QLabel>
#include <QLayout>
#include <QHBoxLayout>
#include <QDateTimeEdit>

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

    QString getTermDate() const;
    void setTermDate(QString value);

signals:
    void termDateChanged();

public slots:

};

#endif // TERMDATE_H
