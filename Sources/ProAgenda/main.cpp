#include "mainwindow.h"
#include <QApplication>
#include <QFont>

#include "vsummary.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setAttribute(Qt::AA_UseHighDpiPixmaps);

    VSummary s;
    s.show();

    /*
    MainWindow w;
    w.show();
    */

    return a.exec();
}
