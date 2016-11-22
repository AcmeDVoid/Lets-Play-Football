#ifndef ADMINISTRATOR_LOGIN_H
#define ADMINISTRATOR_LOGIN_H

#include <QDialog>
#include "include/stadiumlist.h"

namespace Ui {
class administrator_login;
}

class administrator_login : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief administrator_login Constructor for admin login window sets the
     * layout
     * @param masterList The list of stadiums
     * @param parent The parent window
     */
    explicit administrator_login(StadiumList* masterList, QWidget *parent = 0);
    ~administrator_login();

private slots:
    /**
     * @brief on_buttonLogIn_clicked On log in button click, validate
     * username and password and move to admin menu if it validates
     */
    void on_buttonLogIn_clicked();

    /**
     * @brief on_buttonCancel_clicked Close the window
     */
    void on_buttonCancel_clicked();

private:
    Ui::administrator_login *ui;
    QPalette invalidPalette;
    StadiumList* masterList;
};

#endif // ADMINISTRATOR_LOGIN_H
