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

    QGroupBox *groupBoxVisit = new QGroupBox(tr("Stadium To Visit"));
    QGridLayout *vBoxVisit = new QGridLayout;
    for (unsigned int i = 0; i < stadiumList->size(); i++) {
        Stadium *currStadium = stadiumList->stadium(i);
        QCheckBox *checkbox = new QCheckBox();
        checkbox->setText(QString::fromStdString(currStadium->name()));
        vBoxVisit->addWidget(checkbox, i, 0, 2, 1);
        checkboxes.push_back(checkbox);

        ui->comboBoxStarting->addItem(QString::fromStdString(currStadium->name()));
    }
    checkboxes.at(1)->setChecked(true);
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
    for (int i = 0; i < checkboxes.size(); i++) {
        if (checkboxes.at(i)->isEnabled()) {
            checkboxes.at(i)->setChecked(select);
        }
    }
}


void TripPlanner::on_buttonStartTrip_clicked()
{
    QMessageBox msg;
    if (checkedBoxes().size() <= 0) {
        msg.setText("You must select at least one destination.");
        msg.exec();
        return;
    }

    QStringList selectedStadiums = checkedBoxes();
    QStringList path;
    std::stack<string> totalPathStack;

    //get current text from the combo box and store it in a startign city variable
    string startingCity = ui->comboBoxStarting->currentText().toStdString();

    Vertex *startVertex = stadiumList->graph()->findVertex(startingCity);

    path.push_back(QString::fromStdString(startVertex->name()));

    while (!selectedStadiums.empty()) {
        Vertex *nextStadium = stadiumList->graph()->findClosest(startVertex, selectedStadiums);
        std::stack<string> pathStack = stadiumList->graph()
                ->findShortestPath(startVertex, nextStadium);

        while (!pathStack.empty()) {
            if (pathStack.top() != startVertex->name()) {
                path.push_back(QString::fromStdString(pathStack.top()));
            }

            qDebug() << QString::fromStdString(pathStack.top());
            pathStack.pop();
        }

        selectedStadiums.removeOne(QString::fromStdString(nextStadium->name()));
        startVertex = nextStadium;
    }

    //    for (int i = 0; i < path.size(); i++) {
    //        qDebug() << path.at(i);
    //    }
    for (int i = path.size() - 1; i >= 0; i--) {
        totalPathStack.push(path.at(i).toStdString());
    }
    //qDebug() << "\n";
    //    for (int i = 0; i < path.size(); i++) {
    //        qDebug() << QString::fromStdString(totalPathStack.top());
    //        totalPathStack.pop();
    //    }
    // qDebug() << "\n";

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
    QMessageBox msg;
    std::vector<Edge *> mst = stadiumList->graph()->kruskals();
    ostringstream os;
    os << "Minimum Spanning Tree:\n";
    int mileage = 0;

    // output the edges in the mst
    for (unsigned int i = 0; i < mst.size(); i++) {
        mileage += mst.at(i)->length();
        os << mst.at(i)->origin()->name() << " <-> "
           << mst.at(i)->destination()->name() << " ("
           << mst.at(i)->length() << " miles)\n";
    }

    os << "Total Mileage: " << mileage << " Miles\n";

    msg.setText(QString::fromStdString(os.str()));
    msg.exec();
}

QStringList TripPlanner::checkedBoxes()
{
    QStringList locationList;
    for (int i = 0; i < checkboxes.size(); i++) {
        QCheckBox *checkbox = checkboxes[i];
        if (checkbox->isChecked()) {
            locationList.push_back(checkbox->text());
        }
    }
    return locationList;
}

void TripPlanner::on_buttonCancel_clicked()
{
    this->close();
}
