#ifndef MODIFYSTADIUM_H
#define MODIFYSTADIUM_H

#include <QDialog>
#include "stadiumlist.h"

namespace Ui {
class modifyStadium;
}

class modifyStadium : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief modifyStadium::modifyStadium
     * @param inputList the master StadiumList that was passed from main
     * @param stadiumToEdit the stadium pointer which we will edit the attribtues of
     * @param parent the parent of the window
     */
    explicit modifyStadium(StadiumList* inputList, Stadium* stadiumToEdit, QWidget *parent = 0);
    ~modifyStadium();

    /**
     * @brief modifyStadium::loadDefaults
     * loads all the data from the Stadium object with the given stadiumName
     * into the matching ui elements on the window.
     */
    void loadDefaults();
    /**
     * @brief modifyStadium::loadStates
     * load all 50 united states into the combo box
     * note: we are using abbreviations
     */
    void loadStates();


private slots:

    /**
     * @brief modifyStadium::on_cancelButton_clicked
     * the click handler for the cancel button
     */
    void on_cancelButton_clicked();

    /**
     * @brief modifyStadium::on_updateStadiumButton_clicked
     * the stadiumButton on click hanlder - calls code that will
     * update the stadium object so we can re-insert it into the
     * stadium list
     */
    void on_updateStadiumButton_clicked();

private:
    Ui::modifyStadium *ui;      /// the ui pointer to the window
    StadiumList* masterList;    /// the stadium list pointer moved through the windows
    QPalette invalidPalette;    /// a red palette from error labels
    QPalette validPalette;      /// a black palette for valid labels
    Stadium* stadiumToEdit;     /// a pointer to the stadium to edit
//    Vertex* stadiumVertex;      /// save a reference to the vertex based on the stadiums name
};

#endif // MODIFYSTADIUM_H
