#ifndef TESTCALENDAR_H
#define TESTCALENDAR_H

#include <QWidget>
#include <QLabel>
#include <QDirModel>
#include <QTreeView>

namespace Ui {
class TestCalendar;
}

class TestCalendar : public QWidget
{
    Q_OBJECT

public:
    explicit TestCalendar(QWidget *parent = 0);
    ~TestCalendar();

    void DrawSimpleCal();
private:
    Ui::TestCalendar *ui;
};

#endif // TESTCALENDAR_H
