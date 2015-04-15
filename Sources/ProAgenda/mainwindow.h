#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QDebug>
#include <QToolButton>
#include <toolbutton.h>
#include <edittoolbar.h>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

    EditToolBar* editToolBar;


public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void initMainToolbar();
    void initEditToolBar();

private slots:


private:
    Ui::MainWindow *ui;
};


#endif // MAINWINDOW_H
