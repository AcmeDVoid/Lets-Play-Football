#include "mainwindow.h"
#include <QApplication>
#include <StadiumList.h>
#include "MyHeader.h"
#include "StadiumListUI.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    StadiumListUI b;

    b.show();





//    return 0;
    return a.exec();
}
