#include "include/modifystadium.h"
#include "ui_modifystadium.h"

/**
 * @brief modifyStadium::modifyStadium
 * @param inputList the master StadiumList that was passed from main
 * @param stadiumToEdit the stadium pointer which we will edit the attribtues of
 * @param parent the parent of the window
 */
modifyStadium::modifyStadium(StadiumList* inputList, Stadium* stadiumToEdit, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::modifyStadium)
{
    this->masterList = inputList;
    this->stadiumToEdit = stadiumToEdit;
//    this->stadiumVertex = this->masterList->graph()->findVertex(stadiumToEdit->name());
    ui->setupUi(this);

    // set palette color to red text
    invalidPalette.setColor(QPalette::WindowText, Qt::red);
    validPalette.setColor(QPalette::WindowText, Qt::black);

    ui->capacity->setMaximum(999999);
    ui->capacity->setMinimum(1);


    loadStates();
    loadDefaults();


}

modifyStadium::~modifyStadium()
{
    delete ui;
}



/**
 * @brief modifyStadium::loadDefaults
 * loads all the data from the Stadium object with the given stadiumName
 * into the matching ui elements on the window.
 */
void modifyStadium::loadDefaults(){

    //get the stadium object based on the stadiums name
    Stadium* thisStadium = stadiumToEdit;

    //now load all the data into QStrings for readability
    QString stadiumNameFormData = QString::fromStdString(thisStadium->name());
    QString teamNameFormData    = QString::fromStdString(thisStadium->team());
    QString typologyFormData    = QString::fromStdString(thisStadium->typology());
    QDate dateOpenedFormData    = QDate(thisStadium->dateOpened().GetYear(), thisStadium->dateOpened().GetMonth(), thisStadium->dateOpened().GetDay() ); //ymd
    int seatingCapacityFormData = thisStadium->capacity();
    QString leagueTypeFormData  = QString::fromStdString(thisStadium->league());
    QString surfaceTypeFormData = QString::fromStdString(thisStadium->surface());

    //parse city, state and zip -> ex: Detroit, MI 48201
    std::stringstream ss(thisStadium->cityStateZip());

    string city;
    string state;
    string zipCode;
    string ignoreme;

    getline(ss,city, ',');
    getline(ss, ignoreme, ' ');
    getline(ss, state, ' ');
    getline(ss, zipCode, ' ');

    QString cityFormData    = QString::fromStdString(city);
    QString stateFormData   = QString::fromStdString(state);
    QString zipCodeFormData = QString::fromStdString(zipCode);

    QString streetAddressFormData = QString::fromStdString(thisStadium->address());
    QString phoneNumberFormData = QString::fromStdString(thisStadium->phoneNumber());


    //set text on the ui
    ui->stadiumName->setText(stadiumNameFormData);
    ui->teamName->setText(teamNameFormData);
    ui->stadiumTypology->setText(typologyFormData);
    ui->dateOpened->setDate(dateOpenedFormData);
    ui->capacity->setValue(seatingCapacityFormData);
    ui->city->setText(cityFormData);
    ui->state->setCurrentIndex(ui->state->findText(stateFormData));
    ui->zip->setText(zipCodeFormData);
    ui->address->setText(streetAddressFormData);
    ui->phoneNumber->setText(phoneNumberFormData);


    //league types
    if(leagueTypeFormData == "American"){
        ui->americanLeagueRadioButton->setChecked(true);
        ui->nationalLeagueRadioButton->setChecked(false);
    }
    else{
        ui->americanLeagueRadioButton->setChecked(false);
        ui->nationalLeagueRadioButton->setChecked(true);
    }

    //surface types
    if(surfaceTypeFormData == "Grass"){
        ui->grassRadioButton->setChecked(true);
        ui->astroTurfRadioButton->setChecked(false);
    }
    else{
        ui->grassRadioButton->setChecked(false);
        ui->astroTurfRadioButton->setChecked(true);
    }
}

/**
 * @brief modifyStadium::loadStates
 * load all 50 united states into the combo box
 * note: we are using abbreviations
 */
void modifyStadium::loadStates(){
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
 * @brief modifyStadium::on_cancelButton_clicked
 * the click handler for the cancel button
 */
void modifyStadium::on_cancelButton_clicked()
{
    this->close();
}

/**
 * @brief modifyStadium::on_updateStadiumButton_clicked
 * the stadiumButton on click hanlder - calls code that will
 * update the stadium object so we can re-insert it into the
 * stadium list
 */
void modifyStadium::on_updateStadiumButton_clicked()
{
    bool valid = true;

    std::string stadiumName = ui->stadiumName->text().toStdString();
    std::string teamName = ui->teamName->text().toStdString();
    std::string stadiumTypology = ui->stadiumTypology->text().toStdString();
    std::string city  = ui->city->text().toStdString();
    std::string zip   = ui->zip->text().toStdString();
    std::string stadiumPhoneNumber = ui->phoneNumber->text().toStdString();
    std::string stadiumStreetAddress = ui->address->text().toStdString();
    std::string stadiumStarPlayer = ui->starPlayer->text().toStdString();

    ui->labelErrorMessage->setText("");
    ui->labelErrorMessage->setPalette(invalidPalette);
    ui->labelTeamName->setPalette(validPalette);
    ui->labelStadiumName->setPalette(validPalette);
    ui->labelPhone->setPalette(validPalette);
    ui->labelZipCode->setPalette(validPalette);
    ui->labelTypology->setPalette(validPalette);
    ui->labelCity->setPalette(validPalette);
    ui->labelAddress->setPalette(validPalette);

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
    if (valid) {
        std::string leagueType;
        std::string roofType;

        if(ui->americanLeagueRadioButton->isChecked()){
            leagueType = "American";
        }
        else{
            leagueType = "National";
        }

        if(ui->grassRadioButton->isChecked()){
            roofType = "Open";
        }
        else if(ui->astroTurfRadioButton->isChecked()){
            roofType = "Fixed";
        }
        else
        {
            roofType = "Retractable";
        }

        //update the vertex's name
//        this->stadiumVertex->setName(ui->stadiumName->text().toStdString());

        //update the entire stadium object
        stadiumToEdit->updateStadium(/*stadiumName,//*/ui->stadiumName->text().toStdString(),
                                    /*teamName,//*/ui->teamName->text().toStdString(),
                                    roofType,
                                    /*stadiumStarPlayer,//*/ui->starPlayer->text().toStdString(),
                                    /*m, d, y*/
                                    Date(ui->dateOpened->date().month(),
                                         ui->dateOpened->date().day(),
                                         ui->dateOpened->date().year()),
                                    ui->capacity->text().toInt(),
                                    leagueType,
                                    stadiumTypology,//ui->stadiumTypology->text().toStdString(),roofType,
                                    ui->city->text().toStdString(),
                                    ui->state->currentText().toStdString(),
                                    ui->zip->text().toStdString(),
                                    ui->address->text().toStdString(),
                                    ui->phoneNumber->text().toStdString()
                                    );
        //make it persistent
        masterList->saveStadiumList();
        masterList->saveSouvenirs();
        masterList->saveRevenue();
//        masterList->graph()->saveAll();

        masterList->sortByAlphabeticalOrder();

        this->close();

    } //end if valid
    else {
        ui->labelErrorMessage->setText("Empty fields are disallowed.");
    }
}
