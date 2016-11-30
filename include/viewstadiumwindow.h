#ifndef VIEWSTADIUMWINDOW_H
#define VIEWSTADIUMWINDOW_H

#include <QDialog>
#include <QGroupBox>
#include <QRadioButton>
#include <QStringList>
#include <QDebug>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>
#include <QTextBrowser>
#include <QMessageBox>
#include "include/stadiumlist.h"
#include "include/stadium.h"

namespace Ui {
class ViewStadiumWindow;
}

class ViewStadiumWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief Constructor for view stadium window
     * @param sList
     * @param parent
     */
    explicit ViewStadiumWindow(StadiumList *sList, QWidget *parent = 0);
    ~ViewStadiumWindow();

private:
    Ui::ViewStadiumWindow *ui;
    /**
     * @brief Make the group box for the radio buttons
     * @return The group box made for the radio buttons
     */
    QGroupBox* createSortRadioButtonGroupBox();
    /**
     * @brief Make the group box for the checkboxes
     * @return The group box made for the checkboxes
     */
    QGroupBox* createFilterCheckBoxGroupBox();
    StadiumList *stadiumList;
    QTextBrowser *stadiumListBrowser;
    /**
     * @brief Display the list of stadium lists according to the checked radio
     * button filters and checkbox sorts
     */
    void renderStadiumList();
    bool displayGrassSurfaces;
    bool displayAstroturfSurfaces;
    bool displayNationalLeague;
    bool displayAmericanLeague;

private slots:
    /**
     * @brief onCheckBoxClick Changes window's boolean attributes based on which
     * checkbox you clicked, then redisplays the stadium list
     */
    void onCheckBoxClick(bool);

    /**
     * @brief onRadioButtonClick Sorts stadium list based on which radio button
     * you clicked and then redisplays the stadium list
     */
    void onRadioButtonClick(bool);
};

#endif // VIEWSTADIUMWINDOW_H
