#ifndef HEADERHOURS_H
#define HEADERHOURS_H

#include <QWidget>
#include <QPaintEvent>
#include <QPainter>
#include <QDebug>
#include <QString>
#include <QGridLayout>
#include <QLabel>

class HeaderHours : public QWidget
{


    Q_OBJECT
public:
    static int nbHoursPerDay;
    static int nbHoursPerPage;
    static int beginHour;

    explicit HeaderHours(QWidget *parent = 0);
    ~HeaderHours();

    void paintEvent(QPaintEvent *event)
    {
        event->accept();
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setBrush(QColor(255, 0, 0, 127));

    }

signals:

public slots:
};



#endif // HEADERHOURS_H
