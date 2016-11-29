#include "viewteamwindow.h"
#include "ui_viewteamwindow.h"

ViewTeamWindow::ViewTeamWindow(StadiumList *sList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTeamWindow)
{
    stadiumList = sList;
    ui->setupUi(this);

}

ViewTeamWindow::~ViewTeamWindow()
{
    delete ui;
}
