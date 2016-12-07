#ifndef VIEWTEAMWINDOW_H
#define VIEWTEAMWINDOW_H

#include <QDialog>
#include "include/stadiumlist.h"
#include "include/stadium.h"

namespace Ui {

class ViewTeamWindow;
}
/*!
 * \brief The ViewTeamWindow class
 * UI class containing the relevant information list about teams. Called from mainwindow()
 * Does not modify data except for sorting. Allows user to have a more refined way of viewing
 * info about the relevant team. Must be created with access to the StadiumList passed by parameter.
 */
class ViewTeamWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTeamWindow(StadiumList *sList, QWidget *parent = 0);
    ~ViewTeamWindow();

private slots:
    void on_checkBox_AFC_clicked();

    void on_checkBox_NFC_clicked();

    void on_radioButton_clicked();

    void on_radioButton_5_clicked();

    void on_radioButton_2_clicked();

    void on_radioButton_6_clicked();

    void on_checkBox_openRoof_clicked();

    void on_radioButton_3_clicked();

private:
    Ui::ViewTeamWindow *ui;


    StadiumList *stadiumList;

    /*!
     * \brief renderTeamList
     * Pulls current input settings from GUI and updates the list with new sorting and filtering methods
     * Clears input each time (has to call setColumns())
     */
    void renderTeamList();

    /*!
     * \brief setColumns
     * Internal private function for GUI handling. Sets the columns in table widget:
     * Team Name    Stadium Name    Star Player     Conference  Seating capacity    Surface Type    Roof Type
     * Sets column count and headers, used by renderTeamList every time ui->teamTable->clear is called
     */
    void setColumns();
};

#endif // VIEWTEAMWINDOW_H
