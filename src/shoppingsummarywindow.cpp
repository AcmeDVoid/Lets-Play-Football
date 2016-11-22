

#include "shoppingsummarywindow.h"
#include "ui_shoppingsummarywindow.h"

/** shoppingSummaryWindow Constructor
 * @brief shoppingSummaryWindow::shoppingSummaryWindow
 * @param choices a vector of choices from the previous window
 * @param masterList the master restaurant list instantiated from main.cpp
 * @param distance the total distance traveled
 * @param visitHistory a vector of QStrings which is a history of all visited restaurants
 * @param parent qt paretn window (defaults to null)
 */
shoppingSummaryWindow::shoppingSummaryWindow(std::vector<purchaseChoices*> choices,
                                             StadiumList *masterList,
                                             double distance,
                                             vector<QString> visitHistory,
                                             QWidget *parent) :
    QDialog(parent),
    ui(new Ui::shoppingSummaryWindow)
{
    ui->setupUi(this);

    this->masterList = masterList;
    //set cart headers and column sizes
    QStringList cartHeaders;
    cartHeaders.push_back("Item");
    cartHeaders.push_back("Price");
    cartHeaders.push_back("Quantity");
    cartHeaders.push_back("Sub-Total");
    ui->cart->setColumnCount(cartHeaders.count());
    ui->cart->setHeaderLabels(cartHeaders);
    ui->cart->expandAll();
    ui->cart->setContextMenuPolicy(Qt::CustomContextMenu);


    //i changed summary into a list rather than a table
    ui->summaryWindow->addWidget(new QLabel("Stadium Name"), 0, 0);
    ui->summaryWindow->addWidget(new QLabel("Item Count"), 0, 1);
    ui->summaryWindow->addWidget(new QLabel("Sub-Total"), 0, 2);

//    ui->summary->setRowCount(0);
//    ui->summary->setHorizontalHeaderItem(0,new QTableWidgetItem("Stadium Name"));
//    ui->summary->setHorizontalHeaderItem(1,new QTableWidgetItem("Item Count"));
//    ui->summary->setHorizontalHeaderItem(2,new QTableWidgetItem("Sub-Total"));

    ui->distance->setText("Total Distance Traveled: " + QString::number(distance));

    for(unsigned int i = 0; i < visitHistory.size(); i++){
        //add Restaurant Name to the visit history
        ui->visitHistory->addItem(visitHistory.at(i));
    }

    loadCartFromVector  (choices);
    loadTotalsFromVector(choices);

}

/** shoppingSummaryWindow Destructor
 * @brief shoppingSummaryWindow::~shoppingSummaryWindow
 */
shoppingSummaryWindow::~shoppingSummaryWindow()
{
    delete ui;
}

/** loadCartFromVector
 * @brief shoppingSummaryWindow::loadCartFromVector
 * This method loads items from the choices vector passed into the constructor
 * @param choices a vector of restaurantChoices structs
 */
void shoppingSummaryWindow::loadCartFromVector(std::vector<purchaseChoices*> choices){

    double total = 0;

    for(unsigned int i = 0; i < choices.size(); i++){

        //save a reference
        purchaseChoices* topItem = choices.at(i);

        //add a root-level item to the cart
        QTreeWidgetItem* root = new QTreeWidgetItem(ui->cart);
        root->setText(0,topItem->restaurantName);

        for(unsigned int j = 0; j < topItem->purchases.size(); j++){

            //save a reference to the purchase at this iteration
            purchase* menuPurchase = topItem->purchases.at(j);

            QTreeWidgetItem* child = new QTreeWidgetItem(root);

            child->setText(0,menuPurchase->itemName);
            child->setText(1,QString::number(menuPurchase->price));
            child->setText(2,QString::number(menuPurchase->quantity));

            //calculate sub-total
            double subTotal = menuPurchase->quantity * menuPurchase->price;
            child->setText(3,QString::number(subTotal));

            total += subTotal;
        }//end inner-for

        ui->cart->addTopLevelItem(root);
    } //end outter-for

    ui->cart->expandAll();

}


/** loadTotalsFromVector
 * @brief shoppingSummaryWindow::loadTotalsFromVector
 * Similarily to the loadCartFromVector this method does accounting in regards to the
 * master list class, so that it adds a vector of restuarantChoices up and accumulates
 * them into the list
 * @param choices a vector of choices passed in from the constructor
 */
void shoppingSummaryWindow::loadTotalsFromVector(std::vector<purchaseChoices*> choices){
    std::vector<total*>* totals = new std::vector<total*>;

    double grandTotal = 0;
    int    totalCount = 0;
    for(unsigned int i = 0; i < choices.size(); i++){
        QString restName = choices.at(i)->restaurantName;
        int itemCount     = 0;
        double subRevenue = 0;

        for(unsigned int j = 0; j < choices.at(i)->purchases.size(); j++){
            purchase* thisPurchase = choices.at(i)->purchases.at(j);

            itemCount  += thisPurchase->quantity;
            subRevenue += thisPurchase->price * thisPurchase->quantity;
        }
        totalCount += itemCount;
        grandTotal += subRevenue;

        total* rTotal = new total;


        rTotal->restaurantName = restName;
        rTotal->purchaseCount  = itemCount;
        rTotal->revenue        = subRevenue;

        totals->push_back(rTotal);

    } //end outter-for loop

    //get rid of duplicates in the totals vector
    makeVectorUnique(totals);

    //output them to the table
    int rowIdx = 1;
//    /ui->summary->setRowCount( totals->size()); //change to rowIdx + 1 if having problems. I had problems..
    for(unsigned int i = 0; i < totals->size(); i++){
        if(totals->at(i)->restaurantName != "no"){
            QString restName   = totals->at(i)->restaurantName;
            int     itemCount  = totals->at(i)->purchaseCount;
            double  subRevenue = totals->at(i)->revenue;

            //row, col, item
            //0 = restaurant name
            //1 = quantity
            //2 = revenue

            //QTextStream ss;
            //ss << qSetFieldWidth(60) << restName << qSetFieldWidth(20) <<"Quantity: " + QString::number(itemCount) << "Sub-Total: " + QString::number(subRevenue);
            //QString lineItem = restName + "\t Quantity: " + QString::number(itemCount) + "\tSub-Total: " + QString::number(subRevenue);
            //ui->summaryWindow->addItem(lineItem);

            ui->summaryWindow->addWidget(new QLabel(restName), rowIdx, 0);
            ui->summaryWindow->addWidget(new QLabel(QString::number(itemCount)), rowIdx, 1);
            ui->summaryWindow->addWidget(new QLabel( QString::number(subRevenue)), rowIdx, 2);

            rowIdx++;
        }
    }

    //accounthing method - we take the original restaurant List and now add each item count
    //and sub-revenue to each restaurant object out of the unique totals vector
    updateMasterListTotals(totals);
    //masterList->(grandTotal,totalCount);

    ui->totalCount->setText(QString::number(totalCount));
    QString formattedTotal = QString("$%L1").arg(grandTotal, 0, 'f', 2);
    ui->grandTotal->setText(formattedTotal);

}

//this method got out of hand, should ideally be refactored. It's bad spaghetti code, sorry
//but it works and it does what its suppose to do.. kind of, also its O(n^2).. :(
/** makeVectorUnique
 * @brief shoppingSummaryWindow::makeVectorUnique
 * @param totals a pointer to a vector of total struct pointers
 * @return that same vector but made unique via a grouping algorithm
 */
std::vector<total*> shoppingSummaryWindow::makeVectorUnique(std::vector<total*>* totals){

    //the idea is that we are going to iterate the vector and compare each element by name
    //if we have a match, we group the quantity and revenue into the firstTotal (uses i index)
    //and nullify the secondTotal (uses j index)
    //look below to see why we are using "no"
    for(unsigned int i = 0; i < totals->size(); i++){
        total* firstTotal = totals->at(i);

        for(unsigned int j = i + 1; j < totals->size(); j++){
            total* secondTotal = totals->at(j);
            if(firstTotal->restaurantName == secondTotal->restaurantName){

                //combine
                firstTotal->revenue       += secondTotal->revenue;
                firstTotal->purchaseCount += secondTotal->purchaseCount;

                //let me explain, what happens is that we are trying to "group"
                //the structs together and make them unique, this algo follows
                //an insert sort style algorithm, but instead of moving the element
                //it sets the name to "no" so that we can select to not
                //choose "no" when we iterate this vector again.
                secondTotal->restaurantName = "no";
                //erase
//                std::vector<total*>::iterator it = totals->begin() + j;
//                totals->erase(it);

                int innerSize = totals->size();
            } //end inner if
        } //end inner for
    } //end outter for
} //end method

//O(n)
/** updateMasterListTotals
 * @brief shoppingSummaryWindow::updateMasterListTotals
 * This method adds everything up after the vector has been made unique. It
 * accounts for every restaurant and accurately inserts this info back into
 * the restaurant list.
 * @param totals a pointer to a vector of total pointers
 */
void shoppingSummaryWindow::updateMasterListTotals(std::vector<total *> *totals){
    for(unsigned int i = 0; i < totals->size(); i++){
        if(totals->at(i)->restaurantName != "no"){
            Stadium* rest = masterList->stadium(totals->at(i)->restaurantName.toStdString());
            if(rest != NULL){
                //revenue
                //purchaseCount
                double revenue    = totals->at(i)->revenue;
                int purchaseCount = totals->at(i)->purchaseCount;


                rest->addRevenue(revenue);
                rest->addSalesCount(purchaseCount);
            }
        }
    }
    masterList->saveRevenue();
}
