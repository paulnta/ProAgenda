#ifndef HOURCAL
#define HOURCAL

#include <QLabel>
#include <QPaintEvent>
#include <QPainter>
#include <QWidget>

class HourCal : public QWidget{

    Q_OBJECT

public:

    explicit HourCal(QWidget* parent = 0) : QWidget(parent){
    }

    ~HourCal(){

    }


    void paintEvent(QPaintEvent *event)
    {
        event->accept();
        QPainter painter(this);
        painter.setRenderHint(QPainter::Antialiasing);
        painter.setPen(QColor(230,230, 230, 255));
        painter.drawLine(0,0, width(),0);

//        painter.drawText(0,0,width(),height(),0,"lesson");
    }

};

#endif // HOURCAL

