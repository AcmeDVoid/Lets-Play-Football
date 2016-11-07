#include "ui_stadiumlistui.h"
#include "StadiumListUI.h"
#include <QDebug>

StadiumListUI::StadiumListUI(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StadiumListUI)
{
    ui->setupUi(this);

    StadiumList aMap;

    ReadFromFile("NFL Information.txt",aMap);

    StadiumNode *iterator;
    iterator = aMap.begin();

    ui->tableWidget->setColumnCount(8);
    ui->tableWidget->setRowCount(31);
    QTableWidgetItem *header1 = new QTableWidgetItem("Team Name");
    ui->tableWidget->setHorizontalHeaderItem(0,header1);
    QTableWidgetItem *header2 = new QTableWidgetItem("Stadium Name");
    ui->tableWidget->setHorizontalHeaderItem(1,header2);
    QTableWidgetItem *header3 = new QTableWidgetItem("Seating Capacity");
    ui->tableWidget->setHorizontalHeaderItem(2,header3);
    QTableWidgetItem *header4 = new QTableWidgetItem("Location");
    ui->tableWidget->setHorizontalHeaderItem(3,header4);
    QTableWidgetItem *header5 = new QTableWidgetItem("Conference");
    ui->tableWidget->setHorizontalHeaderItem(4,header5);
    QTableWidgetItem *header6 = new QTableWidgetItem("Surface Type");
    ui->tableWidget->setHorizontalHeaderItem(5,header6);
    QTableWidgetItem *header7 = new QTableWidgetItem("Stadium Roof Type");
    ui->tableWidget->setHorizontalHeaderItem(6,header7);
    QTableWidgetItem *header8 = new QTableWidgetItem("Star Player");
    ui->tableWidget->setHorizontalHeaderItem(7,header8);

    for (int i = 0; i < aMap.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(iterator->value.getTeamName()));
        qDebug() << iterator->value.getTeamName();
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(iterator->value.getStadiumName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(iterator->value.getSeatingCapacity()));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(iterator->value.getLocation()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(iterator->value.getConference()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(iterator->value.getSurfaceType()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(iterator->value.getSurfaceType()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(iterator->value.getRootType()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(iterator->value.getStarPlayer()));
        iterator = iterator->next;
    }
}

StadiumListUI::~StadiumListUI()
{
    delete ui;
}
