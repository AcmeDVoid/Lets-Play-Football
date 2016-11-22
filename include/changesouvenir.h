

#ifndef changesouvenir_H
#define changesouvenir_H

#include <QDialog>
#include "stadium.h"
#include "stadiumlist.h"
#include <QMessageBox>
#include <QTableWidgetItem>

namespace Ui {
class changesouvenir;
}

class changesouvenir : public QDialog
{
    Q_OBJECT

public:
    ///@param sPtr the a pointer to the stadium list we will use to access the stadium list
    explicit changesouvenir(StadiumList *sPtr, QWidget *parent = 0);
    //changesouvenir::changesouvenir(Stadium *sPtr, QWidget *parent);
    ~changesouvenir();

    ///SetDropDownOptions
    ///This method populates the combo box on the UI with all the stadium names in the list
    ///@param sPtr a pointer to the stadium list
    void setDropDownOptions(StadiumList *sPtr);
    void setTableView(Stadium* sObject);
    void saveMenu(int stadiumIndex);

private slots:
    /** SLOT
     * @brief on_selectStadium_currentIndexChanged
     * @param index the index of the stadium
     */
    void on_selectStadium_currentIndexChanged(int index);
    /** SLOT
     * @brief on_menuEditTable_cellChanged
     * @param row the row number of the edit
     * @param column the column number of the edit
     */
    void on_souvenirEditTable_cellChanged(int row, int column);

    /** SOT
     * @brief detectChange
     */
    void detectChange(double);
    /** SLOT
     * @brief on_addSouvenir_clicked
     */
    void on_addSouvenir_clicked();
    /**
     * @brief tableIsValid
     * @return true if table is valid, false if not
     */
    bool tableIsValid();
    /** SLOT
     * @brief on_save_clicked
     */
    void on_save_clicked();
    /** SLOT
     * @brief on_cancel_clicked
     */
    void on_cancel_clicked();
    /** SLOT
     * @brief saveTable
     * @param index the index of the stadium to save
     */
    void saveTable(int index);

    void on_deleteButton_clicked();
    bool deleteRequestIsValid();

private:
    Ui::changesouvenir *ui; ///a UI pointer
    StadiumList* sList;     ///the stadium list pointer
    bool cellChanged;       ///holds true/false if a cell on the menuEditTable has been changed
    int lastIndex;          ///the last index we visited
};

#endif // changesouvenir_H
