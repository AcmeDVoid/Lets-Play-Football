

#include "viewrevenue.h"
#include "ui_viewrevenue.h"

/** viewRevenue
 * @brief viewRevenue::viewRevenue
 * This generates a report for an administrator to view the revenue produced
 * by the restaurants in the program.
 * @param masterList the masterList form main.cpp
 * @param parent qt parent class defaults to 0
 */
viewRevenue::viewRevenue(StadiumList *masterList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::viewRevenue)
{
    ui->setupUi(this);
    this->masterList = masterList;

    //init table
    ui->reportTable->setColumnCount(3);
    ui->reportTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Restaurant Name"));
    ui->reportTable->setHorizontalHeaderItem(1,new QTableWidgetItem("Total Purchases"));
    ui->reportTable->setHorizontalHeaderItem(2,new QTableWidgetItem("Revenue"));
    ui->reportTable->setRowCount(masterList->size());


    double totalRevenue = 0;
    int totalItemCount = 0;
    //generate report
    for(unsigned int i = 0; i < masterList->size(); i++){
        Stadium* rest = masterList->stadium(i);
        QString name = QString::fromStdString(rest->name());
        double  revenue = rest->revenue();
        int     purchaseCount = rest->salesCount();

        totalRevenue += revenue;
        totalItemCount += purchaseCount;

        ui->reportTable->setItem(i,0,new QTableWidgetItem(name));
        ui->reportTable->setItem(i,1,new QTableWidgetItem(QString::number(purchaseCount)));
        QString formattedRevenue = QString("$%L1").arg(revenue, 0, 'f', 2);
        ui->reportTable->setItem(i,2,new QTableWidgetItem(formattedRevenue));

    }

    //set totals
    ui->totalCount->setText(QString::number(totalItemCount));
    QString totalRev = QString("$%L1").arg(totalRevenue, 0, 'f', 2);
    ui->totalRevenue->setText(totalRev);

}

/** viewRevenue Destructor
 * @brief viewRevenue::~viewRevenue
 */
viewRevenue::~viewRevenue()
{
    delete ui;
}
