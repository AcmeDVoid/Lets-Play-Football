#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "include/stadiumlist.h"
#include "include/tripplanner.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(StadiumList *sList, QWidget *parent = 0);
    ~MainWindow();

private slots:
    /**
     * @brief on_actionAdmin_Log_In_triggered
     * this is caleld by doing file->admin login.
     * this is the handler method for when admin login is clicked
     * from the menu specified above.
     */
    void on_actionAdmin_Log_In_triggered();

    /**
     * @brief on_buttonViewStadiums_clickede
     * when the view stadium button is clicked we open the
     * view stadium window which has sorting options
     */
    void on_buttonViewStadiums_clicked();


    void on_buttonViewTeams_clicked();

private:
    Ui::MainWindow *ui;
    StadiumList *stadiumList;   /// a reference to the master stadium list
};

#endif // MAINWINDOW_H
