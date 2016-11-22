#ifndef TRIPPLANNER_H
#define TRIPPLANNER_H

#include <QDialog>
#include "include/stadiumlist.h"
#include <QCheckBox>
#include <QComboBox>
#include <QRadioButton>

namespace Ui {
class TripPlanner;
}

class TripPlanner : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief TripPlanner Constructor for trip planner that sets the layouts
     * including the combo box, checkboxes and buttons
     * @param sList The stadium list
     * @param parent The parent window
     */
    explicit TripPlanner(StadiumList *sList, QWidget *parent = 0);

    /**
     * @brief ~TripPlanner The destructor for the window
     */
    ~TripPlanner();

private slots:
    /**
     * @brief on_comboBoxStarting_currentIndexChanged Slot where if you choose
     * a different starting stadium it goes through the checkboxes and disables
     * the starting stadium so we don't have duplicates
     * @param index
     */
    void on_comboBoxStarting_currentIndexChanged(int index);

    /**
     * @brief on_checkBoxSelectAll_clicked
     * Slot where you select all enabled checkboxes of stadiums to visit
     */
    void on_checkBoxSelectAll_clicked();

    /**
     * @brief on_buttonStartTrip_clicked Whn you click this button it takes the
     * list of selected stadiums and uses it to build the path sent to the
     * shopping window to take the trip.
     */
    void on_buttonStartTrip_clicked();

    /**
     * @brief on_buttonMST_clicked
     * Opens up a window that displays MST's edges and total mileage.
     */
    void on_buttonMST_clicked();

    /**
     * @brief Closes the window
     */
    void on_buttonCancel_clicked();

private:
    Ui::TripPlanner *ui;
    StadiumList *stadiumList;
    QList<QCheckBox*> checkboxes;
    QComboBox comboBoxStartingStadium;
    /**
     * @brief Returns the list of names from the list of checkboxes checked
     * @return Returns the list of names from the list of checkboxes checked
     */
    QStringList checkedBoxes();
};

#endif // TRIPPLANNER_H
