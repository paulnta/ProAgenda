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

    Q_PROPERTY(QDateTime termDate READ getTermDate WRITE setTermDate NOTIFY termDateChanged)

public:
    explicit TermDate(QWidget *parent = 0);
    ~TermDate();

    QDateTime termDate;
    QLabel* label;
    QHBoxLayout* layout;

    QDateTime getTermDate() const;
    void setTermDate(const QDateTime &value);

signals:
    void termDateChanged();

public slots:

};

#endif // TERMDATE_H
