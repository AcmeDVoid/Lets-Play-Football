#include "tripplanner.h"
#include "ui_tripplanner.h"

#include <QFormLayout>
#include <QGroupBox>
#include <QMessageBox>
#include <QVBoxLayout>
#include "include/shoppingmenu.h"
#include <sstream>

TripPlanner::TripPlanner(StadiumList *sList, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::TripPlanner)
{
    ui->setupUi(this);
    stadiumList = sList;
    stadiumList->sortByAlphabeticalOrder();

    // make a new group box containing possible stadiums to visit
    QGroupBox *groupBoxVisit = new QGroupBox(tr("Stadium To Visit"));

    // make a gridlayout with checkboxes of stadiums to visit
    QGridLayout *vBoxVisit = new QGridLayout;

    // for every stadium
    for (unsigned int i = 0; i < stadiumList->size(); i++) {
        // make a checkbox for every stadium with its name as the text
        Stadium *currStadium = stadiumList->stadium(i);
        QCheckBox *checkbox = new QCheckBox();
        checkbox->setText(QString::fromStdString(currStadium->name()));

        // add the widget to the display widget
        vBoxVisit->addWidget(checkbox, i, 0, 2, 1);
        checkboxes.push_back(checkbox);

        // add the stadium to the combo box as a starting stadium choice
        ui->comboBoxStarting->addItem(QString::fromStdString(currStadium->name()));
    }

    // default select checkbox 1 to visit
    checkboxes.at(1)->setChecked(true);

    // set the layouts
    groupBoxVisit->setLayout(vBoxVisit);
    ui->vlVisit->addWidget(groupBoxVisit);
}

TripPlanner::~TripPlanner()
{
    delete ui;
}

void TripPlanner::on_comboBoxStarting_currentIndexChanged(int index)
{
    for (int i = 0; i < checkboxes.size(); i++) {
        if (i == index) {
            if (checkboxes.at(i)->isChecked()) {
                if (i + 1 < checkboxes.size()) {
                    checkboxes.at(i + 1)->setChecked(true);
                }
                else {
                    checkboxes.at(0)->setChecked(true);
                }
            }
            checkboxes.at(i)->setEnabled(false);
            checkboxes.at(i)->setChecked(false);
        }
        else {
            checkboxes.at(i)->setEnabled(true);
        }
    }
}

void TripPlanner::on_checkBoxSelectAll_clicked()
{
    bool select = ui->checkBoxSelectAll->isChecked() ? true : false;
    // for every checkbox check/uncheck it if enabled
    for (int i = 0; i < checkboxes.size(); i++) {
        if (checkboxes.at(i)->isEnabled()) {
            checkboxes.at(i)->setChecked(select);
        }
    }
}


void TripPlanner::on_buttonStartTrip_clicked()
{
    // if they didn't select at least one other stadium to visit display a m
    // message saying so and return
    QMessageBox msg;
    if (checkedBoxes().size() <= 0) {
        msg.setText("You must select at least one destination.");
        msg.exec();
        return;
    }

    // the names of the stadiums selected
    QStringList selectedStadiums = checkedBoxes();

    // the names of the stadiums to visit in a path
    QStringList path;
    std::stack<string> totalPathStack;

    //get current text from the combo box and store it in a startign city variable
    string startingCity = ui->comboBoxStarting->currentText().toStdString();

    // a pointer to the starting stadium selected
    Vertex *startVertex = stadiumList->graph()->findVertex(startingCity);

    // add starting staddium to path
    path.push_back(QString::fromStdString(startVertex->name()));

    // for every selected stadium
    while (!selectedStadiums.empty()) {
        // find the closest to the currently processed stadium
        Vertex *nextStadium = stadiumList->graph()->findClosest(startVertex, selectedStadiums);

        // make a stack of names of the shortest path from stadium to stadium
        std::stack<string> pathStack = stadiumList->graph()
                ->findShortestPath(startVertex, nextStadium);

        // for every name in the shortest path add to the path
        while (!pathStack.empty()) {
            if (pathStack.top() != startVertex->name()) {
                path.push_back(QString::fromStdString(pathStack.top()));
            }

            pathStack.pop();
        }

        // remove duplicates from the selected stadium list
        selectedStadiums.removeOne(QString::fromStdString(nextStadium->name()));

        // set the next stadium
        startVertex = nextStadium;
    }

    // reverse iterate to the path stack the path
    for (int i = path.size() - 1; i >= 0; i--) {
        totalPathStack.push(path.at(i).toStdString());
    }

    //build a list of selected items that we want to visit - used for logic inside the
    //shopping menu
    QStringList tripSelectedStadiums = checkedBoxes();
    tripSelectedStadiums.push_front(QString::fromStdString(startingCity));

    //run the shopping menu window with the shortest path we calculated
    shoppingMenu* tripWindow = new shoppingMenu(totalPathStack, stadiumList, tripSelectedStadiums);
    tripWindow->exec();
}


void TripPlanner::on_buttonMST_clicked()
{
    // the message window
    QMessageBox msg;

    // get the edges from the mst
    std::vector<Edge *> mst = stadiumList->graph()->kruskals();
    ostringstream os;
    os << "Minimum Spanning Tree:\n";
    int mileage = 0;

    // output the edges in the mst
    for (unsigned int i = 0; i < mst.size(); i++) {
        mileage += mst.at(i)->length();
        // output origin, destination and length
        os << mst.at(i)->origin()->name() << " <-> "
           << mst.at(i)->destination()->name() << " ("
           << mst.at(i)->length() << " miles)\n";
    }

    // output the total mileage
    os << "Total Mileage: " << mileage << " Miles\n";

    // set the mst description text to the window
    msg.setText(QString::fromStdString(os.str()));
    msg.exec();
}

QStringList TripPlanner::checkedBoxes()
{
    QStringList locationList;
    // for every checkbox
    for (int i = 0; i < checkboxes.size(); i++) {
        QCheckBox *checkbox = checkboxes[i];
        // if checked add to the list of selected stadiums
        if (checkbox->isChecked()) {
            locationList.push_back(checkbox->text());
        }
    }
    // returns string list of selected stadiums
    return locationList;
}

void TripPlanner::on_buttonCancel_clicked()
{
    // close the window
    this->close();
}
