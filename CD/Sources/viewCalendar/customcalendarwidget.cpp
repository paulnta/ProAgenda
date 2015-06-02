#include "customcalendarwidget.h"
#include <QDebug>
#include <QFile>
#include <QTextFormat>

CustomCalendarWidget::CustomCalendarWidget()
{
    initStyleSheet();
    setNavigationBarVisible(false);
    setVerticalHeaderFormat(QCalendarWidget::NoVerticalHeader);
    setHorizontalHeaderFormat(QCalendarWidget::ShortDayNames);

    QTextCharFormat format;
    format.setForeground(QColor("#6e6e6d"));
    setWeekdayTextFormat(Qt::Sunday,format);
    setWeekdayTextFormat(Qt::Saturday,format);
}

void CustomCalendarWidget::initStyleSheet()
{
    QFile file(":/css/css/calendarWidget.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    file.close();
}

CustomCalendarWidget::~CustomCalendarWidget()
{

}

void CustomCalendarWidget::paintCell(QPainter *painter, const QRect &rect, const QDate &date) const
{
    if(date == selectedDate()) {
        painter->save();
        painter->setBrush(QColor("#3ab3e2"));
        painter->setPen(QColor(0,0,0,0));
        QPoint c;
        c.setX(rect.center().rx());
        c.setY(rect.center().ry()+1);
        painter->drawEllipse(c, ((rect.width() / 2) - 3), (rect.height() / 2) -3);
        painter->setPen(QColor("#ffffff"));
        painter->drawText(rect, Qt::TextSingleLine | Qt::AlignCenter, QString::number(date.day()));
        painter->restore();

    } else {

    QCalendarWidget::paintCell(painter,rect,date);
    }
}

