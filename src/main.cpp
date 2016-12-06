#include "include/mainwindow.h"
#include "include/splashscreen.h"
#include "include/stadiumlist.h"
#include "include/Vertex.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    StadiumList *sList = new StadiumList();
    sList->initialize();
    sList->saveStadiumList();
    sList->saveSouvenirs();
    sList->saveRevenue();
//    sList->graph()->saveAll();

    MainWindow w(sList);
    w.show();

    return a.exec();
}
