#include "include/modifystadiumselector.h"
#include "include/modifystadium.h"
#include "ui_modifystadiumselector.h"
#include <QPalette>

/**
 * @brief modifyStadiumSelector::modifyStadiumSelector
 * @param inputList the master list to move through the windows, should be
 * the master stadium list from main()
 * @param parent    primarily a qt widget thing - leave this blank for now
 */
modifyStadiumSelector::modifyStadiumSelector(StadiumList* inputList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyStadiumSelector)
{
    //save the master list
    this->masterList = inputList;
    ui->setupUi(this);

    //init the table fully
    //we are setting the proper column count and header items.
    //also we make sure that the selection mode is set to only be a single seleciton
    ui->stadiumTable->setColumnCount(1);
    ui->stadiumTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadium Name"));
    ui->stadiumTable->horizontalHeader()->setStretchLastSection(true);  //stretch the column to the full width of the table
    ui->stadiumTable->setSelectionMode(QAbstractItemView::SingleSelection);
    this->loadTable();
}

/**
 * @brief modifyStadiumSelector::loadTable
 * this method loads the stadiumTable with all the stadium names
 * note: we are only using one column, the stadium name.
 */
void modifyStadiumSelector::loadTable(){
    //save a reference to the number of teams in the stadium list
    int listSize = this->masterList->size();

    for( int i = 0; i < listSize; i++){
        //note: 0 = stadium name column
        //note: 1 = team name column
        ui->stadiumTable->insertRow(i);
        //get the stadium pointer from the master stadium list, convert it to a q string and insert it the ith row in the 0th column
        ui->stadiumTable->setItem(i, 0, new QTableWidgetItem(QString::fromStdString(this->masterList->stadium(i)->name())));
    }
}

//void modifyStadiumSelector::clearTable(){
//    for(unsigned int i = 0; i < ui->stadiumTable->rowCount(); i++ ){

//    }
//}

modifyStadiumSelector::~modifyStadiumSelector()
{
    delete ui;
}

/**
 * @brief modifyStadiumSelector::getSelectedRow
 * @return the currently selected row's stadium name.
 */
std::string modifyStadiumSelector::getSelectedRow(){
    return ui->stadiumTable->selectedItems().at(0)->text().toStdString();
}

/**
 * @brief modifyStadiumSelector::on_modifyButton_clicked
 * when the modify stadium button is clicked, we load the modify staidum window
 * while passing the master list through the window and passing a pointer to the
 * stadium that is selected form the ui->stadiumTable
 */
void modifyStadiumSelector::on_modifyButton_clicked()
{
    //check to make sure that we are not passing null value to the window
    //if we don't check this condition the program will crash if nothing is selected
    if(isValid()){
        //launch modify stadium window
        modifyStadium* window = new modifyStadium(masterList, this->masterList->stadium(getSelectedRow()));
        window->exec();
    }
    else{
        QPalette invalidPalette;
        invalidPalette.setColor(QPalette::WindowText, Qt::red);
        ui->errorLabel->setPalette(invalidPalette);
        ui->errorLabel->setText("Please Select a Stadium.");
    }

    //clear and re-load table
    ui->stadiumTable->clear();
    ui->stadiumTable->setRowCount(0);
    this->loadTable();
}

/**
 * @brief modifyStadiumSelector::on_cancelButton_clicked
 * cancel button handler, we just close the window when called
 */
void modifyStadiumSelector::on_cancelButton_clicked()
{
    //close the window - handled by qt
    this->close();
}

/**
 * @brief modifyStadiumSelector::isValid
 * @return true if a row is selected in the ui->stadiumTable
 * and false if no row is selected.
 */
bool modifyStadiumSelector::isValid(){
    //check the size of the selecedItems() on the tableWidget
    //note: this size should only every be 0 or 1 due to the
    //fact that we are limiting the user to select only ONE
    //row ever at a time!
    return(ui->stadiumTable->selectedItems().size() == 1);
}
