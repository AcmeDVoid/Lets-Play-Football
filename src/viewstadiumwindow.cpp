#include "viewstadiumwindow.h"
#include "ui_viewstadiumwindow.h"

ViewStadiumWindow::ViewStadiumWindow(StadiumList *sList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ViewStadiumWindow)
{
    ui->setupUi(this);

    // default values of what to display
    stadiumList = sList;
    displayGrassSurfaces = true;
    displayAstroturfSurfaces = true;
    displayNationalLeague = true;
    displayAmericanLeague = true;

    // add group boxes of radio buttons and checkboxes to the layout
    ui->vlSorts->addWidget(createSortRadioButtonGroupBox());
    ui->vlSorts->addWidget(createFilterCheckBoxGroupBox());

    // after building the displayed stadium list add the widget to the layout
    stadiumListBrowser = new QTextBrowser();
    renderStadiumList();
    ui->vlTeamBase->addWidget(stadiumListBrowser);

}

ViewStadiumWindow::~ViewStadiumWindow()
{
    delete ui;
}

QGroupBox *ViewStadiumWindow::createSortRadioButtonGroupBox()
{
    QStringList sortNames;
    // list of sort types
    sortNames << "Stadium Name" << "Team Name" << "Player Name(WIP)"
              << "Seating Capacity" << "Surface" << "Roof Type";

    QGroupBox *groupBox = new QGroupBox(tr("Sort"));
    QVBoxLayout *vbox = new QVBoxLayout;

    // for every sort type make a new radio button and connect it to a slot
    // activated on click
    for (int i = 0; i < sortNames.size(); i++) {
        QString buttonName = sortNames[i];
        QRadioButton *newButton = new QRadioButton(buttonName);
        connect(newButton, SIGNAL(clicked(bool)), this, SLOT(onRadioButtonClick(bool)));
        vbox->addWidget(newButton);
    }

    // return the group box
    groupBox->setLayout(vbox);
    return groupBox;
}

QGroupBox *ViewStadiumWindow::createFilterCheckBoxGroupBox()
{
    QStringList filterNames;
    // list of possible filters
    filterNames << "American Football Conference" << "National Football Conference" << "Synthetic Surface Stadiums"
                << "Grass Surface Stadiums";

    // label group filters
    QGroupBox *groupBox = new QGroupBox(tr("Filter"));
    QVBoxLayout *vbox = new QVBoxLayout;

    // for every filter type
    for (int i = 0; i < filterNames.size(); i++) {
        QString buttonName = filterNames[i];

        // make a new checkbox
        QCheckBox *newCheckBox = new QCheckBox(buttonName);

        // connct the checkbox to a slot activated on click
        connect(newCheckBox, SIGNAL(clicked(bool)), this, SLOT(onCheckBoxClick(bool)));

        // by default check the checkbox
        newCheckBox->setChecked(true);

        // add checkbox to groupbox
        vbox->addWidget(newCheckBox);
    }

    // return the group box
    groupBox->setLayout(vbox);
    return groupBox;
}


void ViewStadiumWindow::renderStadiumList()
{
    // clear the view displaying the stadium list
    stadiumListBrowser->clear();

    // for every stadium
    for (unsigned int i = 0; i < stadiumList->size(); i++) {
        Stadium *currentStadium = stadiumList->stadium(i);

        // if the stadium has grass surface and grass is filtered out continue
        if (!displayGrassSurfaces && currentStadium->surface() == "Grass") {
            continue;
        }

        // if the stadium has astro turf surface and it is filtered out continue
        if (!displayAstroturfSurfaces && currentStadium->surface() == "Astro turf") {
            continue;
        }

        // if the stadium is national and its filtered out continue
        if (!displayNationalLeague && currentStadium->type() == "National") {
            continue;
        }

        // if the stadium is american and its filtered out continue
        if (!displayAmericanLeague && currentStadium->type() == "American") {
            continue;
        }

        QStringList detailList;
        // build the qstring list of stadium attributes to display
        detailList << QString::fromStdString("Stadium Name: " + currentStadium->name());
        detailList << QString::fromStdString("Team Name    : " + currentStadium->team());
        detailList << QString::fromStdString("Address          : " + currentStadium->streetAddress() + ", " + currentStadium->cityStateZip());
        detailList << QString::fromStdString("Phone Number: " + currentStadium->phoneNumber());
        detailList << QString::fromStdString("Conference     : " + currentStadium->type());
        detailList << QString::fromStdString("Date Opened  : " + currentStadium->dateOpened().DisplayDate());
        detailList << "Capacity         : " + QString::number(currentStadium->capacity());
        detailList << QString::fromStdString("Surface type  : " + currentStadium->surface());
        detailList << QString::fromStdString("Roof type       : " + currentStadium->typology());

        // add all strings in the list to the display
        for (int j = 0; j < detailList.size(); j++) {
            QString currentDetail = detailList[j];
            stadiumListBrowser->append(currentDetail);
        }
        stadiumListBrowser->append("");
    }
}

void ViewStadiumWindow::onCheckBoxClick(bool)
{
    // check the sender object and its text
    QCheckBox* checkBox = qobject_cast<QCheckBox*>(sender());

    // set a bool according to the associated checkbox's state
    if (checkBox->text() == "American League Stadiums") {
        displayAmericanLeague = checkBox->isChecked();
    }
    else if (checkBox->text() == "National League Stadiums") {
        displayNationalLeague = checkBox->isChecked();
    }
    else if (checkBox->text() == "Astro turf Surface Stadiums") {
        displayAstroturfSurfaces = checkBox->isChecked();
    }
    else if (checkBox->text() == "Grass Surface Stadiums") {
        displayGrassSurfaces = checkBox->isChecked();
    }

    // redisplay the stadium list
    renderStadiumList();
}

void ViewStadiumWindow::onRadioButtonClick(bool)
{
    // get sender widget
    QRadioButton* radioButton = qobject_cast<QRadioButton*>(sender());

    // sort stadium list according to the text of the radio button clicked
    if (radioButton->text() == "Team Name") {
        stadiumList->sortByTeamName();
    }
    else if (radioButton->text() == "Stadium Name") {
        stadiumList->sortByAlphabeticalOrder();
    }
    else if (radioButton->text() == "Date Opened") {
        stadiumList->sortByDateOpened();
    }
    else if (radioButton->text() == "Seating Capacity") {
        stadiumList->sortBySeatingCapacity();
    }
    else if (radioButton->text() == "Surface") {
        stadiumList->sortByGrassSurface();
    }
    else if (radioButton->text() == "Roof Type") {
        stadiumList->sortByParkTypology();
    }

    // redisplay stadium list
    renderStadiumList();
}
