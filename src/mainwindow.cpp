#include "include/mainwindow.h"
#include "include/splashscreen.h"
#include "include/administrator_login.h"
#include "include/viewstadiumwindow.h"
#include "include/modifystadiumselector.h"
#include "include/viewteamwindow.h"

#include "ui_mainwindow.h"

#include <addstadium.h>
#include <modifystadium.h>
#include <changesouvenir.h>
/**
 * @brief MainWindow::MainWindow
 * @param sList pass in the master stadium list
 * @param parent qt widget parent window
 */
MainWindow::MainWindow(StadiumList *sList, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    stadiumList = sList;
    //pop-up a splash screen window before the program starts
    splashscreen* splash = new splashscreen();
    splash->exec();

    ui->setupUi(this);

}

/**
 * @brief MainWindow::~MainWindow
 * destructor, empty for now
 */
MainWindow::~MainWindow()
{
    delete ui;
}

/** SLOT
 * @brief MainWindow::on_actionAdmin_Log_In_triggered
 * This method is called when a user clicks on the
 * menu bar on the main window. We start at file->
 * Admin Login.
 *
 * From there we call the administrator log-in window.
 */
void MainWindow::on_actionAdmin_Log_In_triggered()
{
    administrator_login* window = new administrator_login(this->stadiumList);
    window->exec();
}

/**
 * @brief MainWindow::on_buttonViewStadiums_clicked
 * open the view stadiums when which has sorting options.
 * We will display the window to the user when they click on it
 */
void MainWindow::on_buttonViewStadiums_clicked()
{
    ViewStadiumWindow vsw(stadiumList);
    vsw.exec();
}

/**
 * @brief MainWindow::on_buttonTripPlanner_clicked
 * this method is the on click handler for when the user
 * clicks the 'trip planner' window button
 */

void MainWindow::on_buttonTripPlanner_clicked()
{
    TripPlanner tp(stadiumList);
    tp.exec();
}

void MainWindow::on_buttonViewTeams_clicked()
{
    ViewTeamWindow vtw(stadiumList);
    vtw.exec();
}


