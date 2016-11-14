#include "log_in.h"
#include "ui_log_in.h"

Log_In::Log_In(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log_In)
{
    ui->setupUi(this);
}

Log_In::~Log_In()
{
    delete ui;
}

void Log_In::on_cancelButton_clicked()
{
    connect(ui->cancelButton,SIGNAL(clicked(bool)),this,SLOT(close()));
}

void Log_In::on_signInButton_clicked()
{
    if (ui->passwordLine->text() != "TheBrogrammer")
    {
        QMessageBox::warning(this, "Error", "Incorrect password. Please try again!","OK");
        ui->passwordLine->clear();
    }
    else
    {
        QMessageBox::about(this, "Successful", "Correct password. Proceeding...");
        QMessageBox::information(this, "Oops...", "Administrator page is under construction.", "OK");
        this->close();
    }
}
