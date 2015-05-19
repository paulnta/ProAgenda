#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QSqlRelationalTableModel>
#include <QTableView>
#include <QListView>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
    void printModel();

public slots:
    void updateModel();
    void confirmation();
    void on_actionAddTask_triggered();
    void on_actionClear_All_triggered();
    void on_actionUpdateModel_triggered();

private:
    Ui::MainWindow *ui;
    QSqlRelationalTableModel* model;
    QTableView* viewTable;
    QListView* viewList;
    void setUpModel();
};

#endif // MAINWINDOW_H
