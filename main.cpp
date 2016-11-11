#include "mainwindow.h"
#include <QApplication>
#include <StadiumList.h>
#include "MyHeader.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow x;
    x.show();

    return a.exec();
}
