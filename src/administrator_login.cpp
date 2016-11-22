#include "include/administrator_login.h"
#include "ui_administrator_login.h"
#include "include/administrator.h"

administrator_login::administrator_login(StadiumList* masterList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrator_login)
{
    ui->setupUi(this);

    this->masterList = masterList;

    this->setWindowTitle("Login");
    // set palette color to red text
    invalidPalette.setColor(QPalette::WindowText, Qt::red);
    // Default message color is red for error
    ui->labelErrorMessage->setPalette(invalidPalette);
    this->masterList = masterList;
}

administrator_login::~administrator_login()
{
    delete ui;
}


void administrator_login::on_buttonLogIn_clicked()
{

    // by default not valid
    bool valid = false;
    ui->labelErrorMessage->setText("");

    // if the username and password are correct its valid
    if (ui->account->text() == "admin" && ui->password->text() == "password") {
        valid = true;
    }

    // if valid clear the fields and then bring up the admin menu window
    if(valid){
        ui->account->clear();
        ui->password->clear();
        administrator* window = new administrator(this->masterList);
        window->exec();
    }
    else {
        // set the label
        ui->labelErrorMessage->setText("Invalid username/password");
    }
}

void administrator_login::on_buttonCancel_clicked()
{
    // close the window
    this->close();
}
