#include "log_in.h"
#include "ui_log_in.h"

Log_In::Log_In(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Log_In)
{
    ui->setupUi(this);
    adminHash.SetRawHash("sQnzu7wkTrgkQZF+0G1hi5AI3Qmzvv0bXgc5THBqi7mAsdd4Xll27ASbRt9fEyavWi6m0QP9B8lThf+rDKy8hg==");
}

Log_In::~Log_In()
{
    delete ui;
}

void Log_In::on_cancelButton_clicked()
{
   this->hide();
}

void Log_In::on_signInButton_clicked()
{
    Password tempPass = Password(ui->passwordLine->text());
    if (adminHash == tempPass)
    {
        QMessageBox::about(this, "Successful", "Correct password. Proceeding...");
        QMessageBox::information(this, "Oops...", "Administrator page is under construction.", "OK");
        this->close();
    }
    else
    {
        QMessageBox::warning(this, "Error", "Incorrect password. Please try again!","OK");
        ui->passwordLine->clear();
    }
}

void Log_In::on_checkBox_clicked(bool checked)
{
    if(!checked) { ui->passwordLine->setEchoMode(QLineEdit::Password);
    }else{ ui->passwordLine->setEchoMode(QLineEdit::Normal);}
}
