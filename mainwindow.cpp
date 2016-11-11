#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyHeader.h"
#include "StadiumList.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
//    QWidget* widget = new QWidget(MainWindow);
//    widget->setLayout(gridLayout);
//    MainWindow->setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_LoginButton_clicked()
{
    if(ui->lineEdit_PasswordField->text() == "password")
    {
        ui->stackedWidget->setCurrentIndex(1);
        ui->lineEdit_PasswordField->clear();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Incorrect password.", "Ok");
        ui->lineEdit_PasswordField->clear();
    }
}

void MainWindow::on_pushButton_4_clicked()
{
    ui->tableWidget->clearContents();
    StadiumList aMap;

    ReadFromFile("NFL Information.txt",aMap);

    StadiumNode *iterator;
    iterator = aMap.begin();

    for (int i = 0; i < aMap.size(); i++)
    {
        ui->tableWidget->insertRow(i);
        ui->tableWidget->setItem(i,0,new QTableWidgetItem(iterator->value.getTeamName()));
        ui->tableWidget->setItem(i,1,new QTableWidgetItem(iterator->value.getStadiumName()));
        ui->tableWidget->setItem(i,2,new QTableWidgetItem(QString::number(iterator->value.getSeatingCapacity())));
        ui->tableWidget->setItem(i,3,new QTableWidgetItem(iterator->value.getLocation()));
        ui->tableWidget->setItem(i,4,new QTableWidgetItem(iterator->value.getConference()));
        ui->tableWidget->setItem(i,5,new QTableWidgetItem(iterator->value.getSurfaceType()));
        ui->tableWidget->setItem(i,6,new QTableWidgetItem(iterator->value.getSurfaceType()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(iterator->value.getRootType()));
        ui->tableWidget->setItem(i,7,new QTableWidgetItem(iterator->value.getStarPlayer()));
        iterator = iterator->next;
    }
}
