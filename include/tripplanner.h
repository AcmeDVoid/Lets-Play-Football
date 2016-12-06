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
    explicit TripPlanner(StadiumList *sList, QWidget *parent = 0);
    ~TripPlanner();

private slots:
    void on_comboBoxStarting_currentIndexChanged(int index);
    void on_checkBoxSelectAll_clicked();
    void on_buttonStartTrip_clicked();
    void on_buttonMST_clicked();

    void on_buttonCancel_clicked();

private:
    Ui::TripPlanner *ui;
    StadiumList *stadiumList;
    QList<QCheckBox*> checkboxes;
    QComboBox comboBoxStartingStadium;
    QStringList checkedBoxes();
};

#endif // TRIPPLANNER_H
