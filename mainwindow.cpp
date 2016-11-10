#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "MyHeader.h"
#include "StadiumList.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
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
    /*
    ui->tableWidget->clear();
    ui->tableWidget->setColumnCount(<DATA FIELDS (This should be constant)>);
    ui->tableWidget->setRowCount(<AMT OF DATA>);

    */
}
