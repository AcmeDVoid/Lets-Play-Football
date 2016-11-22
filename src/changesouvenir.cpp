

#include "changesouvenir.h"
#include "ui_changesouvenir.h"
#include <QLineEdit>
#include <QDoubleSpinBox>

const double MIN_PRICE = 0.01;

/** changesouvenir Constructor
 * @brief changesouvenir::changesouvenir
 * pass in the master list and this class will allow a window
 * to be made that allows editing of menu items.
 * @param sPtr the master list stadium pointer from main.cpp
 * @param parent qt parent defaults to null
 */
changesouvenir::changesouvenir(StadiumList *sPtr, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::changesouvenir)
{
    cellChanged = false;
    lastIndex = 0;
    sList = sPtr;
    ui->setupUi(this);
    setDropDownOptions(sPtr);
}

/** detectChange RECIEVER SLOT
 * @brief changesouvenir::detectChange
 * if a cell changes on the table we update a private attribute
 * to be true to signify this change occured
 */
void changesouvenir::detectChange(double){
    cellChanged = true;
}

/** changesouvenir Destructor
 * @brief changesouvenir::~changesouvenir
 */
changesouvenir::~changesouvenir()
{
    delete ui;
}

///SetDropDownOptions
///This method populates the combo (drop down)  box on the UI with all the stadium names in the list
///@param sPtr a pointer to the stadium list
void changesouvenir::setDropDownOptions(StadiumList *sPtr /* IN */)
{

    /*
     * NOTE: when i placed the drop down box in the ui i renamed it manually to selectStadium
     *     : the selectStadium is a combo box object API docs here: http://doc.qt.io/qt-4.8/qcombobox.html
     *
     * NOTE: when i placed the table in the ui i renamed it manually to souvenirEditTable
     *     : the souvenirEditTable is a table widget object. API docs here: http://doc.qt.io/qt-4.8/qtablewidget.html
     */


    //this acceses the drop down menu, since the drop down menu is a
    //combo box object, there are methods you can do on it

    for(unsigned int i = 0; i < sPtr->size(); i++)
    {
        ui->selectStadium->addItem(QString::fromStdString(sPtr->stadium(i)->name()));
    }
}


/** setTableView
 * @brief changesouvenir::setTableView
 * This method builds a basic qt table widget around the objects inside
 * the passed in restaurant objets menu items
 * @param rObject the restaurant object to build menu items for
 */
void changesouvenir::setTableView(Stadium *sObject){

    //store state of current index to the lastIndex attribute
    lastIndex = ui->selectStadium->currentIndex();
    //set menu size
    int  menuSize = sObject->souvenirList()->size();

    //sets table to have two columns (name and price)
    ui->souvenirEditTable->setColumnCount(2);

    //sets the amount of rows - taken from menu items vector
    ui->souvenirEditTable->setRowCount(menuSize);

    //set column count
    ui->souvenirEditTable->insertColumn(1);

    ui->souvenirEditTable->setHorizontalHeaderItem(0,new QTableWidgetItem("Souvenir"));
    ui->souvenirEditTable->setHorizontalHeaderItem(1,new QTableWidgetItem("Price"));

    for( int i = 0; i < menuSize; i++){
        //get name and price from vector
        QString name = QString::fromStdString(sObject->souvenirList()->at(i).name());
        double price = sObject->souvenirList()->at(i).price();

        //set first column
        //syntax: row, column, item
        ui->souvenirEditTable->setItem(i,0,new QTableWidgetItem(name));   //name

        //the way we handled double validation on the second column is by inserting
        //a double spin box into the column. We are already iterating over the list anyhow, so we just
        //instantiate a Double SpinBox and plop that sucker in.
        QDoubleSpinBox* priceEdit = new QDoubleSpinBox();
        priceEdit->setMinimum(MIN_PRICE);
        connect(priceEdit, SIGNAL(valueChanged(double)), this, SLOT(detectChange(double)));
        priceEdit->setValue(price);
        ui->souvenirEditTable->setCellWidget(i, 1, priceEdit);           //price

    }
    cellChanged = false;
}

/** SLOT
 * @brief changesouvenir::on_selectStadium_currentIndexChanged
 * when the current index changes from the top drop-down menu we update
 * the rest of the window to reflect the users wish to proceed to different
 * stadium. We ask if they want to save
 * @param index the index of the stadium that was changed
 */
void changesouvenir::on_selectStadium_currentIndexChanged(int index)
{
    Stadium* sPtr = sList->stadium(index);
    /* NOTE: i could not find a reliable slot to pick up cell changing, we just do it every time instead */
    if(cellChanged){
//    if(true){
        saveMenu(lastIndex);
        cellChanged = false;
    }
    setTableView(sPtr);
}

/**
 * @brief changesouvenir::saveMenu
 * This method allows us to save the current state of the tale on the UI
 * back into the stadium's souvenir list which is then propogated throughout
 * the stadium list ands is saved for persistence when the stadium list
 * is saved.
 * @param index the index of the stadium to save souvenirs for
 */
void changesouvenir::saveMenu(int index){

    Stadium* stadiumPtr = sList->stadium(index);
    QMessageBox msgBox;
    msgBox.setText("The Menu has been modified.");
    msgBox.setInformativeText("Do you want to save your changes?");
    msgBox.setStandardButtons(QMessageBox::Save | QMessageBox::Discard );
    msgBox.setDefaultButton(QMessageBox::Save);
    int ret = msgBox.exec();

    switch (ret) {
    case QMessageBox::Save:
        // Save was clicked
        if(tableIsValid()){
            saveTable(index);
        }
        else{
            ui->errorLabel->show();
            QPalette invalidPalette;
            invalidPalette.setColor(QPalette::WindowText, Qt::red);
            ui->errorLabel->setPalette(invalidPalette);
            ui->errorLabel->setText("Blank Souvenirs Are Not Allowed!");
        }
        break;
    case QMessageBox::Discard:
        // Don't Save was clicked
        break;
    default:
        // should never be reached
        break;
    }
}

/** SLOT
 * @brief changesouvenir::on_souvenirEditTable_cellChanged
 * detects if the souvenir table had any modifications
 * @param row the row of the changed table cell
 * @param column the colulkmn of the changed table cell
 */
void changesouvenir::on_souvenirEditTable_cellChanged(int row, int column)
{
    //change private attribute to true if things changed
    cellChanged = true;
}

/** tableIsValid
 * @brief changesouvenir::tableIsValid
 * This method returns true/false if the tabel is valid.
 * @return true if the table is validated false if not
 */
bool changesouvenir::tableIsValid(){
    bool valid = true;
    for(int i = 0; i < ui->souvenirEditTable->rowCount(); i++){
        if(!ui->souvenirEditTable->item(i,0)){
            valid = false;
            break;
        }
        if(ui->souvenirEditTable->item(i,0)->text().isEmpty()){
            valid = false;
            break;
        }
        if(ui->souvenirEditTable->item(i,0)->text().trimmed() == ""){
            valid = false;
            break;
        }
    }
    return valid;
}

/** SLOT
 * @brief changesouvenir::on_addSouvenir_clicked
 * When the add menu item is clicked we will add a new cell
 * to the souvenir items so that the user can insert text and prices
 * that represents a new souvenir for the stadium
 */
void changesouvenir::on_addSouvenir_clicked()
{
    ui->souvenirEditTable->insertRow(ui->souvenirEditTable->rowCount());
    QDoubleSpinBox* priceEdit = new QDoubleSpinBox();
    priceEdit->setMinimum(MIN_PRICE);
    connect(priceEdit, SIGNAL(valueChanged(double)), this, SLOT(detectChange(double)));
    ui->souvenirEditTable->setCellWidget(ui->souvenirEditTable->rowCount() - 1, 1, priceEdit);
    ui->errorLabel->hide();
}

/** saveTable
 * @brief changesouvenir::saveTable
 * this method saves the state of the stadium table
 * @param index - the index of the stadium to save the table for
 */
void changesouvenir::saveTable(int index){
    Stadium* stadiumPtr = sList->stadium(index);

    //we simply iterate over the table, and rebuild the souvenir map
    //we then call the updateSouvenir method to force an update on the souvenir list
    std::map<int, Souvenir> souvenirMap;
    for(int i = 0; i < ui->souvenirEditTable->rowCount(); i++){

        //we get the souvenirItem List and set the name of each souvenirItem in the vector
        //NOTE: (i,0) is first column for name
        //NOTE: (i,1) is second column for price
        string name = ui->souvenirEditTable->item(i,0)->text().toStdString();
        QDoubleSpinBox* spinBox = qobject_cast<QDoubleSpinBox*>(ui->souvenirEditTable->cellWidget(i,1));
        double price = spinBox->value();

        Souvenir s = Souvenir(name,price);
        souvenirMap.insert(std::make_pair(souvenirMap.size(), s));
    }

    stadiumPtr->updateSouvenirList(souvenirMap);

}

/** SLOT
 * @brief changesouvenir::on_save_clicked
 * when the user clicks save, we check to see if the table is valid
 * if the table is verified to be valid we then save it back into the
 * master list that was passed into the constructor of this class
 */
void changesouvenir::on_save_clicked()
{
    //only do all of this if the souvenir items are valid.
    if(tableIsValid()){
        //hide error message
        ui->errorLabel->hide();

        //save the souvenirs table into the stadium list
        saveTable(ui->selectStadium->currentIndex());

        // save stadium list
        sList->saveStadiumList();
        sList->saveSouvenirs();

        //close window
        accept();
    }
    else{
        ui->errorLabel->show();
        QPalette invalidPalette;
        invalidPalette.setColor(QPalette::WindowText, Qt::red);
        ui->errorLabel->setPalette(invalidPalette);
        ui->errorLabel->setText("Blank Souvenirs Are Not Allowed!");
    }
}

/** SLOT
 * @brief changesouvenir::on_cancel_clicked
 * when the user clicks cancel we reject the window so that it closes
 */
void changesouvenir::on_cancel_clicked()
{
    reject();
}

/**
 * @brief changesouvenir::deleteRequestIsValid
 * @return true if the request to delete a selected index is valid
 * we make sure that the user has seleted at least one and not more than one
 * row in the table on the UI
 */
bool changesouvenir::deleteRequestIsValid(){
    QPalette invalidPalette;
    invalidPalette.setColor(QPalette::WindowText, Qt::red);
    ui->errorLabel->setPalette(invalidPalette);

    QItemSelectionModel *select = ui->souvenirEditTable->selectionModel();
    int size = select->selectedIndexes().size();
    if(size == 1){
        return true;
    }
    else if(size < 1){
        ui->errorLabel->setText("Select a row to delete.");
        return false;
    }
    else if(size > 1){
        ui->errorLabel->setText("Select only one row to delete.");
        return false;
    }
}
/**
 * @brief changesouvenir::on_deleteButton_clicked
 * when the deletion button is clicked
 */
void changesouvenir::on_deleteButton_clicked()
{
    if(deleteRequestIsValid()){
        QItemSelectionModel *select = ui->souvenirEditTable->selectionModel();
        int i =select->selectedIndexes().at(0).row();
        ui->souvenirEditTable->removeRow(i);


        this->sList->stadium(ui->selectStadium->currentIndex())->removeSouvenir(i);
        this->saveTable(ui->selectStadium->currentIndex());
    }
}
