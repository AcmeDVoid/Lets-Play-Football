#include "mainwindow.h"
#include <QApplication>
#include <StadiumList.h>
#include "MyHeader.h"

int main(int argc, char *argv[])
{
//    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

    StadiumList myMap;

    ReadFromFile("NFL Information.txt",myMap);

    myMap.print();




    return 0;
//    return a.exec();
}
