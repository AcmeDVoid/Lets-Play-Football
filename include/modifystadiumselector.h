#ifndef MODIFYSTADIUMSELECTOR_H
#define MODIFYSTADIUMSELECTOR_H

#include <QDialog>
#include "stadiumlist.h"

namespace Ui {
class modifyStadiumSelector;
}

class modifyStadiumSelector : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief modifyStadiumSelector::modifyStadiumSelector
     * @param inputList the master list to move through the windows, should be
     * the master stadium list from main()
     * @param parent    primarily a qt widget thing - leave this blank for now
     */
    explicit modifyStadiumSelector(StadiumList* inputList, QWidget *parent = 0);
    ~modifyStadiumSelector();

    /**
     * @brief modifyStadiumSelector::loadTable
     * this method loads the stadiumTable with all the stadium names
     * note: we are only using one column, the stadium name.
     */
    void loadTable();

private slots:
    /**
     * @brief modifyStadiumSelector::on_modifyButton_clicked
     * when the modify stadium button is clicked, we load the modify staidum window
     * while passing the master list through the window and passing a pointer to the
     * stadium that is selected form the ui->stadiumTable
     */
    void on_modifyButton_clicked();

    /**
     * @brief modifyStadiumSelector::on_cancelButton_clicked
     * cancel button handler, we just close the window when called
     */
    void on_cancelButton_clicked();
    /**
     * @brief modifyStadiumSelector::getSelectedRow
     * @return the currently selected row's stadium name.
     */
    std::string getSelectedRow();
    /**
     * @brief modifyStadiumSelector::isValid
     * @return true if a row is selected in the ui->stadiumTable
     * and false if no row is selected.
     */
    bool isValid();

private:
    Ui::modifyStadiumSelector *ui;
    StadiumList* masterList;
};

#endif // MODIFYSTADIUMSELECTOR_H
