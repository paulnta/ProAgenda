#include "mainwindow.h"
#include <QApplication>

#include "viewSummary/testtreeview.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setAttribute(Qt::AA_UseHighDpiPixmaps);

//    MainWindow w;
//    w.show();

    TestTreeView t;
    t.show();

    return a.exec();
}
