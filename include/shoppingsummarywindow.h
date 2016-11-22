#ifndef SHOPPINGSUMMARYWINDOW_H
#define SHOPPINGSUMMARYWINDOW_H

#include <QDialog>
#include <QTreeWidget>
#include <vector>
#include "stadiumlist.h"
#include "stadium.h"

/**
 * @brief The purchase struct
 */
struct purchase{
    QString itemName;   ///the item name of the purchase
    double price;       ///the price fo the purchase
    int quantity;       ///the quantity of items bought
};

/**
 * @brief The total struct
 */
struct total{
    QString restaurantName; ///The name of the restaurant
    double  revenue;        ///The revene generated at that restaurant
    int     purchaseCount;  ///the count of items bought at this restaurant
};

/**
 * @brief The purchaseChoices struct
 */
struct purchaseChoices{
    QString restaurantName;             ///the name of the restaurant
    std::vector<purchase*> purchases;   ///a vector of purchases at that restaurant
};

namespace Ui {
class shoppingSummaryWindow;
}

class shoppingSummaryWindow : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief shoppingSummaryWindow
     * @param choices a vector of restaurntChoices
     * @param masterList the master restaurant list
     * @param distance the total distance traveled
     * @param visitHistory a vector of QStrings representing the restaurants visited
     * @param parent the parent window
     */
    explicit shoppingSummaryWindow(std::vector<purchaseChoices*> choices, StadiumList* masterList, double distance, vector<QString> visitHistory, QWidget *parent = 0);
    ~shoppingSummaryWindow();

    /**
     * @brief loadCartFromVector
     * @param choices a vector of restaurant choices
     */
    void loadCartFromVector  (std::vector<purchaseChoices*> choices);
    /**
     * @brief loadTotalsFromVector
     * @param choices a vector of restaurant choices
     */
    void loadTotalsFromVector(std::vector<purchaseChoices*> choices);
    /**
     * @brief makeVectorUnique
     * @param totals the vector to make unique
     * @return a unique vector (grouped together by totals.name)
     */
    std::vector<total*>  makeVectorUnique(std::vector<total *> *totals);
    /**
     * @brief updateMasterListTotals
     * @param totals a vector of totals (total structs)
     */
    void updateMasterListTotals(std::vector<total *> *totals);

private:
    Ui::shoppingSummaryWindow *ui;  /// ui pointer
    StadiumList* masterList;     ///the masterList pointer
};

#endif // SHOPPINGSUMMARYWINDOW_H
