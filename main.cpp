#include "mainwindow.h"
#include <QApplication>
#include <StadiumList.h>
#include "MyHeader.h"
#include "StadiumListUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow x;
    x.show();

    StadiumListUI w;

    //w.show();

//    StadiumList aMap;

//    ReadFromFile("NFL Information.txt",aMap);

//    aMap.print();



//    return 0;
    return a.exec();
}
