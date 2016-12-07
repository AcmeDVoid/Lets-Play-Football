#include "viewteamwindow.h"
#include "ui_viewteamwindow.h"

ViewTeamWindow::ViewTeamWindow(StadiumList *sList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewTeamWindow)
{
    stadiumList = sList;
    ui->setupUi(this);
    renderTeamList();

}

ViewTeamWindow::~ViewTeamWindow()
{
    delete ui;
}


void ViewTeamWindow::renderTeamList()
{
    ui->teamTable->clear();
    this->setColumns();
    ui->teamTable->setRowCount(stadiumList->size());
    // for every stadium
    for (int i = 0; i < (signed)stadiumList->size(); i++) {
        Stadium *currentStadium = stadiumList->stadium(i);

        if(ui->checkBox_openRoof->isChecked() && !(currentStadium->typology() == "Open"))
        {
            continue;
        }
        // if the stadium is national and its filtered out continue
        if (!ui->checkBox_NFC->isChecked() && currentStadium->type() == "National") {
            continue;
        }

        // if the stadium is american and its filtered out continue
        if (!ui->checkBox_AFC->isChecked() && currentStadium->type() == "American") {
            continue;
        }

        // build the qstring list of stadium attributes to display
        ui->teamTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(currentStadium->team())));
        ui->teamTable->setItem(i, 1, new QTableWidgetItem(QString::fromStdString(currentStadium->name())));
        ui->teamTable->setItem(i, 2, new QTableWidgetItem(QString::fromStdString(currentStadium->getStarPlayer())));
        ui->teamTable->setItem(i, 3, new QTableWidgetItem(QString::fromStdString(currentStadium->type())));
        ui->teamTable->setItem(i, 4, new QTableWidgetItem(QString::number(currentStadium->capacity())));
        ui->teamTable->setItem(i, 5, new QTableWidgetItem(QString::fromStdString(currentStadium->surface())));
        ui->teamTable->setItem(i, 6, new QTableWidgetItem(QString::fromStdString(currentStadium->typology())));
    }
}


void ViewTeamWindow::setColumns()
{
    ui->teamTable->setColumnCount(7);
    ui->teamTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
    ui->teamTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Stadium Name"));
    ui->teamTable->setHorizontalHeaderItem(2, new QTableWidgetItem("Star Player"));
    ui->teamTable->setHorizontalHeaderItem(3, new QTableWidgetItem("Conference"));
    ui->teamTable->setHorizontalHeaderItem(4, new QTableWidgetItem("Seating Capacity"));
    ui->teamTable->setHorizontalHeaderItem(5, new QTableWidgetItem("Surface Type"));
    ui->teamTable->setHorizontalHeaderItem(6, new QTableWidgetItem("Roof Type"));

}

void ViewTeamWindow::on_checkBox_AFC_clicked()
{
    this->renderTeamList();
}

void ViewTeamWindow::on_checkBox_NFC_clicked()
{
    this->renderTeamList();
}

void ViewTeamWindow::on_radioButton_clicked()
{
    stadiumList->sortByTeamName();
    this->renderTeamList();
}

void ViewTeamWindow::on_radioButton_5_clicked()
{
    stadiumList->sortByGrassSurface();
    this->renderTeamList();
}

void ViewTeamWindow::on_radioButton_2_clicked()
{
    stadiumList->sortBySeatingCapacity();
    this->renderTeamList();
}

void ViewTeamWindow::on_radioButton_6_clicked()
{
    stadiumList->sortByParkTypology();
    this->renderTeamList();
}

void ViewTeamWindow::on_checkBox_openRoof_clicked()
{
    this->renderTeamList();
}

void ViewTeamWindow::on_radioButton_3_clicked()
{
    stadiumList->sortByStarPlayer();
    this->renderTeamList();
}
