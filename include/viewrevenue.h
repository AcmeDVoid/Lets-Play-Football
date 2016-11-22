

#ifndef VIEWREVENUE_H
#define VIEWREVENUE_H

#include <QDialog>
#include "stadium.h"
#include "stadiumlist.h"

namespace Ui {
class viewRevenue;
}

class viewRevenue : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief viewRevenue
     * @param masterList masterList from main
     * @param parent qt defaults to 0
     */
    explicit viewRevenue(StadiumList* masterList, QWidget *parent = 0);
    ~viewRevenue();

private:
    Ui::viewRevenue *ui;        ///ui pointer
    StadiumList* masterList; ///masterList of all restaurants
};

#endif // VIEWREVENUE_H
