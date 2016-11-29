#include "include/addstadium.h"
#include "ui_addstadium.h"
#include "include/Date.h"

/**
 * @brief addstadium::addstadium
 * @param masterList a pointer to the master stadium list
 * @param parent
 */
addstadium::addstadium(StadiumList* masterList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addstadium)
{
    // set palette color to red text
    invalidPalette.setColor(QPalette::WindowText, Qt::red);
    validPalette.setColor(QPalette::WindowText, Qt::black);


    ui->setupUi(this);
    ui->labelErrorMessage->setPalette(invalidPalette);
    this->masterList = masterList;

    //init object here
    ui->nationalLeagueRadioButton->setChecked(true);
    ui->grassRadioButton->setChecked(true);
    ui->capacity->setMaximum(999999);
    ui->capacity->setMinimum(1);
    QDate today = QDate::currentDate();
    ui->dateOpened->setDate(today);
    this->loadStates();
    this->loadDefaultSouvenirList();

    //zip-code validtor
    ui->zip->setValidator(new QRegExpValidator(QRegExp("(^\\d{5}(?:[-\\s]\\d{4})?$)")));
    ui->phoneNumber->setValidator(new QRegExpValidator(QRegExp("[\\d-()]{1,}")));

    for (unsigned int i = 0; i < masterList->size(); i++) {
//        ui->comboBoxEdge->addItem(QString::fromStdString(masterList->graph()->vertices().at(i)->name()));
        edgeLengths.push_back(0);
    }
}

addstadium::~addstadium()
{
    delete ui;
}

/**
 * @brief loadStates
 * this method loads all the 50 states in the US into a combo box
 */
void addstadium::loadStates(){
    ui->state->addItem("AL");
    ui->state->addItem("AK");
    ui->state->addItem("AZ");
    ui->state->addItem("AR");
    ui->state->addItem("CA");
    ui->state->addItem("CO");
    ui->state->addItem("CT");
    ui->state->addItem("DE");
    ui->state->addItem("FL");
    ui->state->addItem("GA");
    ui->state->addItem("HI");
    ui->state->addItem("DD");
    ui->state->addItem("IL");
    ui->state->addItem("IN");
    ui->state->addItem("IA");
    ui->state->addItem("KS");
    ui->state->addItem("KY");
    ui->state->addItem("LA");
    ui->state->addItem("ME");
    ui->state->addItem("MD");
    ui->state->addItem("MA");
    ui->state->addItem("MI");
    ui->state->addItem("MN");
    ui->state->addItem("MS");
    ui->state->addItem("MO");
    ui->state->addItem("MT");
    ui->state->addItem("NE");
    ui->state->addItem("NV");
    ui->state->addItem("NH");
    ui->state->addItem("NJ");
    ui->state->addItem("NM");
    ui->state->addItem("NY");
    ui->state->addItem("NC");
    ui->state->addItem("ND");
    ui->state->addItem("OH");
    ui->state->addItem("OK");
    ui->state->addItem("OR");
    ui->state->addItem("PA");
    ui->state->addItem("RI");
    ui->state->addItem("SC");
    ui->state->addItem("SD");
    ui->state->addItem("TN");
    ui->state->addItem("TX");
    ui->state->addItem("UT");
    ui->state->addItem("VT");
    ui->state->addItem("VA");
    ui->state->addItem("WA");
    ui->state->addItem("WV");
    ui->state->addItem("WI");
    ui->state->addItem("WY");
    ui->state->addItem("GU");
    ui->state->addItem("PR");
    ui->state->addItem("VI");
}

/**
 * @brief addstadium::loadDefaultSouvenirList
 * loads the defautl souvenir list based on the original
 * data that was given to us in the project
 */
void addstadium::loadDefaultSouvenirList(){

    //set stretch policy
    ui->souvenirsTable->horizontalHeader()->setSectionResizeMode(QHeaderView::Stretch);

    //set column and row count
    ui->souvenirsTable->setColumnCount(2);
    ui->souvenirsTable->setRowCount(5);

    //set the headers of the table
    ui->souvenirsTable->setHorizontalHeaderItem(0, new QTableWidgetItem("Souvenir Name"));
    ui->souvenirsTable->setHorizontalHeaderItem(1, new QTableWidgetItem("Price"));


    //now load the defaults:
    ui->souvenirsTable->setItem(0,0,new QTableWidgetItem("Signed Helmets"));
    QDoubleSpinBox* priceEdit1 = new QDoubleSpinBox();
    priceEdit1->setValue(29.99);
    ui->souvenirsTable->setCellWidget(0,1,priceEdit1);

    ui->souvenirsTable->setItem(1,0,new QTableWidgetItem("Autographed Football"));
    QDoubleSpinBox* priceEdit2 = new QDoubleSpinBox();
    priceEdit2->setValue(45.39);
    ui->souvenirsTable->setCellWidget(1,1,priceEdit2);

    ui->souvenirsTable->setItem(2,0,new QTableWidgetItem("Team pennant"));
    QDoubleSpinBox* priceEdit3 = new QDoubleSpinBox();
    priceEdit3->setValue(15.99);
    ui->souvenirsTable->setCellWidget(2,1,priceEdit3);

    ui->souvenirsTable->setItem(3,0,new QTableWidgetItem("Team picture"));
    QDoubleSpinBox* priceEdit4 = new QDoubleSpinBox();
    priceEdit4->setValue(19.99);
    ui->souvenirsTable->setCellWidget(3,1,priceEdit4);

    ui->souvenirsTable->setItem(4,0,new QTableWidgetItem("Team jersey"));
    QDoubleSpinBox* priceEdit5 = new QDoubleSpinBox();
    priceEdit5->setValue(85.99);
    ui->souvenirsTable->setCellWidget(4,1,priceEdit5);
}
void addstadium::buildSouvenirList(Stadium& stadium /* IN & OUT */){
    vector<Souvenir> stadiumSouvenirList;

    for(int i = 0; i < ui->souvenirsTable->rowCount(); i++ ) {

        string name = ui->souvenirsTable->item(i,0)->text().toStdString();
        if (name.length() > 0) {
            QDoubleSpinBox* priceEdit = qobject_cast<QDoubleSpinBox*>(ui->souvenirsTable->cellWidget(i,1));
            double price = priceEdit->value();

            stadium.addSouvenir(Souvenir(name, price) );
        }
    }
}

/**
 * @brief addstadium::buildStadiumObject
 * @return a stadium object with all of the attribtues set to the
 * values represented on the UI
 */
Stadium addstadium::buildStadiumObject(){

    std::string stadiumName = ui->stadiumName->text().toStdString();
    std::string teamName = ui->teamName->text().toStdString();
    std::string stadiumStreetAddress = ui->address->text().toStdString();

    //Seattle, WA 98134
    std::string city  = ui->city->text().toStdString();
    std::string state = ui->state->currentText().toStdString();
    std::string zip   = ui->zip->text().toStdString();
    std::string stadiumCityStateZip = city + ", " + state + " " + zip;
    std::string stadiumPhoneNumber = ui->phoneNumber->text().toStdString();

    std::string leagueType;
    if(ui->americanLeagueRadioButton->isChecked()){
        leagueType = "American";
    }
    else if(ui->nationalLeagueRadioButton->isChecked()){
        leagueType = "National";
    }

    //set the date
    unsigned short month = ui->dateOpened->date().month();
    unsigned short day = ui->dateOpened->date().day();
    unsigned short year = ui->dateOpened->date().year();
    Date stadiumDateOpened = Date(month, day, year);

    int stadiumCapacity = ui->capacity->text().toInt();

    std::string stadiumSurface;
    if(ui->grassRadioButton->isChecked()){
        stadiumSurface = "Grass";
    }
    else if(ui->astroTurfRadioButton->isChecked()){
        stadiumSurface = "Astro turf";
    }

    std::string stadiumTypology = ui->stadiumTypology->text().toStdString();

    //build the stadium
    Stadium newStadium = Stadium
            (stadiumName,
             teamName,
             stadiumStreetAddress,
             stadiumCityStateZip,
             stadiumPhoneNumber,
             leagueType,
             stadiumDateOpened,
             stadiumCapacity,
             stadiumSurface,
             stadiumTypology);

    this->buildSouvenirList(newStadium);

    return newStadium;
}

/**
 * @brief addstadium::buildVertex
 * @return a verte based on the stadiumName ui field
 */
//Vertex *addstadium::buildVertex()
//{
//    Vertex *newVertex = new Vertex(ui->stadiumName->text().toStdString());
//    return newVertex;
//}

/**
 * @brief addstadium::addEdges
 * @param newVertex the vertex to add the edges to
 */
//void addstadium::addEdges(Vertex *newVertex)
//{
//    //loop over the size of the dges
//    for (int i = 0; i < edgeLengths.size(); i++) {
//        int distance = edgeLengths.at(i);
//        //catch the condition where the distance is not the default (0)
//        if (distance > 0) {
//            Vertex *destination = masterList->graph()->findVertexByIndex(i);
//            masterList->graph()->insertEdge(newVertex, destination, distance, false);
//        }
//    }
//}

/**
 * @brief addstadium::on_addSouvenirItem_clicked
 * clicked handler for the add souvenir item button
 */
void addstadium::on_addSouvenirItem_clicked()
{
    ui->souvenirsTable->insertRow(ui->souvenirsTable->rowCount());

    QDoubleSpinBox* priceEdit = new QDoubleSpinBox();
    priceEdit->setMinimum(0.01);
    ui->souvenirsTable->setCellWidget(ui->souvenirsTable->rowCount() - 1,1,priceEdit);
}

/**
 * @brief addstadium::on_addStadiumButton_clicked
 */
void addstadium::on_addStadiumButton_clicked()
{
    bool valid = true;

    std::string stadiumName = ui->stadiumName->text().toStdString();
    std::string teamName = ui->teamName->text().toStdString();
    std::string stadiumTypology = ui->stadiumTypology->text().toStdString();
    std::string city  = ui->city->text().toStdString();
    std::string zip   = ui->zip->text().toStdString();
    std::string stadiumPhoneNumber = ui->phoneNumber->text().toStdString();
    std::string stadiumStreetAddress = ui->address->text().toStdString();

    ui->labelErrorMessage->setText("");
    ui->labelTeamName->setPalette(validPalette);
    ui->labelStadiumName->setPalette(validPalette);
    ui->labelPhone->setPalette(validPalette);
    ui->labelZipCode->setPalette(validPalette);
    ui->labelTypology->setPalette(validPalette);
    ui->labelCity->setPalette(validPalette);
    ui->labelAddress->setPalette(validPalette);
//    ui->labelEdges->setPalette(validPalette);


    //start validating
    if (masterList->teamNameExists(teamName) || teamName.length() == 0) {
        valid = false;
        ui->labelTeamName->setPalette(invalidPalette);
    }
    if (masterList->stadiumNameExists(stadiumName) || stadiumName.length() == 0) {
        valid = false;
        ui->labelStadiumName->setPalette(invalidPalette);
    }
    if (stadiumTypology.length() == 0) {
        valid = false;
        ui->labelTypology->setPalette(invalidPalette);
    }
    if (city.length() == 0) {
        valid = false;
        ui->labelCity->setPalette(invalidPalette);
    }
    if (stadiumStreetAddress.length() == 0) {
        valid = false;
        ui->labelAddress->setPalette(invalidPalette);
    }
    if (zip.length() == 0) {
        valid = false;
        ui->labelZipCode->setPalette(invalidPalette);
    }
    if (stadiumPhoneNumber.length() == 0) {
        valid = false;
        ui->labelPhone->setPalette(invalidPalette);
    }
//    if (edgeLengths.count(0) == edgeLengths.size()) {
//        valid = false;
//        ui->labelEdges->setPalette(invalidPalette);
//    }

    //finally its valid
    if (valid) {
        masterList->addStadium(this->buildStadiumObject());
        masterList->saveStadiumList();
        masterList->saveSouvenirs();
        //masterList->print();
//        Vertex *newVertex = buildVertex();
//        addEdges(newVertex);
//        masterList->graph()->insertVertex(newVertex);
//        masterList->graph()->saveAll();
        this->close();
    }
    else {
        ui->labelErrorMessage->setText("Duplicates disallowed, fields must be filled and there must be at least one edge.");
    }
}

/**
 * @brief addstadium::on_cancelButton_clicked
 */
void addstadium::on_cancelButton_clicked()
{
    this->close();
}

/**
 * @brief addstadium::on_comboBoxEdge_currentIndexChanged
 * @param index the index that has changed
 */
//void addstadium::on_comboBoxEdge_currentIndexChanged(int index)
//{
//    if (index < edgeLengths.size()) {
//        ui->spinnerEdge->setValue(edgeLengths.at(index));
//    }
//}

/**
 * @brief addstadium::on_spinnerEdge_valueChanged
 * @param arg1 the argument that has its value changed
 */
//void addstadium::on_spinnerEdge_valueChanged(int arg1 /* IN */)
//{
//    edgeLengths.replace(ui->comboBoxEdge->currentIndex(), arg1);
//}
