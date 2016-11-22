#include "include\administrator.h"
#include "ui_administrator.h"
#include "include\addstadium.h"
#include "changesouvenir.h"
#include "ui_changesouvenir.h"
#include "include/viewrevenue.h"
#include "include/modifystadium.h"
#include "include/modifystadiumselector.h"

/**
 * @brief administrator::administrator
 * @param masterList pass in the stadiumList so we can save a reference to it
 * inside the class
 * @param parent the window parent
 */
administrator::administrator(StadiumList* masterList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::administrator)
{
    ui->setupUi(this);
    this->masterList = masterList;
}

/**
 * @brief administrator::~administrator
 */
administrator::~administrator()
{
    delete ui;
}

/**
 * @brief administrator::on_pushButton_3_clicked
 * opens the add stadium window
 */
void administrator::on_pushButton_3_clicked()
{
    addstadium* popUp = new addstadium(masterList);
    popUp->exec();
}
/**
 * @brief administrator::on_pushButton_clicked
 * opens the change souvenir window
 */
void administrator::on_pushButton_clicked()
{
    changesouvenir* window = new changesouvenir(masterList);
    window->exec();
}

/**
 * @brief administrator::on_viewRevenue_clicked
 * opens the view revenue window
 */
void administrator::on_viewRevenue_clicked()
{
    viewRevenue* window = new viewRevenue(masterList);
    window->exec();
}

/**
 * @brief administrator::on_pushButton_4_clicked
 * opens the modify stadium selection window
 */
void administrator::on_pushButton_4_clicked()
{
    modifyStadiumSelector* window = new modifyStadiumSelector(masterList);
    window->exec();
}
