#ifndef VSUMMARY_H
#define VSUMMARY_H

#include <QWidget>

namespace Ui {
class VSummary;
}

class MainWindow;

class VSummary : public QWidget
{
    Q_OBJECT

public:
    explicit VSummary(MainWindow* mainWindow, QWidget *parent = 0);
    ~VSummary();

    void refreshSemestersList();

private:
    Ui::VSummary *ui;
    MainWindow* mainWindow;

private:
    void deleteAllWidgetsInSideBarLayout();
};

#endif // VSUMMARY_H
