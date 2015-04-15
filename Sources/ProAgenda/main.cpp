#include "mainwindow.h"
#include <QApplication>
#include <QFont>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    a.setAttribute(Qt::AA_UseHighDpiPixmaps);

    MainWindow w;
    w.show();


    return a.exec();
}
