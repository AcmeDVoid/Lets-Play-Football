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
    ui->textBrowser->clear();
    int totalCapacity = 0;
    // for every stadium
    for (unsigned int i = 0; i < stadiumList->size(); i++) {
        Stadium *currentStadium = stadiumList->stadium(i);

        // if the stadium is national and its filtered out continue
        if (!ui->checkBox_NFC->isChecked() && currentStadium->type() == "National") {
            continue;
        }

        // if the stadium is american and its filtered out continue
        if (!ui->checkBox_AFC->isChecked() && currentStadium->type() == "American") {
            continue;
        }

        totalCapacity += currentStadium->capacity();

        QStringList detailList;
        // build the qstring list of stadium attributes to display
        detailList << QString::fromStdString("Team Name    : " + currentStadium->team());
        detailList << QString::fromStdString("Stadium Name: " + currentStadium->name());
        detailList << QString::fromStdString("Conference     : " + currentStadium->type());
        detailList << "Capacity         : " + QString::number(currentStadium->capacity());
        detailList << QString::fromStdString("Surface type  : " + currentStadium->surface());
        detailList << QString::fromStdString("Roof type       : " + currentStadium->typology());

        // add all strings in the list to the display
        for (int j = 0; j < detailList.size(); j++) {
            QString currentDetail = detailList[j];
            ui->textBrowser->append(currentDetail);

        }
         ui->textBrowser->append("");
    }
}

void ViewTeamWindow::on_checkBox_AFC_clicked()
{
    this->renderTeamList();
}

void ViewTeamWindow::on_checkBox_NFC_clicked()
{
    this->renderTeamList();
}
