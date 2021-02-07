#include "mainwindow.h"
#include "loginview.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    loginview lv;
    lv.show();
    database db;
    db.openConnection();
    //MainWindow w;
    //w.show();
    return a.exec();
}
