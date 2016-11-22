#ifndef ADMINISTRATOR_H
#define ADMINISTRATOR_H

#include <QDialog>
#include "include/stadiumlist.h"

namespace Ui {
class administrator;
}

class administrator : public QDialog
{
    Q_OBJECT

public:
    explicit administrator(StadiumList* masterList, QWidget *parent = 0);
    ~administrator();

private slots:
    /**
     * @brief on_pushButton_3_clicked
     */
    void on_pushButton_3_clicked();

    /**
     * @brief on_pushButton_clicked
     */
    void on_pushButton_clicked();

    /**
     * @brief on_viewRevenue_clicked
     */
    void on_viewRevenue_clicked();

    /**
     * @brief on_pushButton_4_clicked
     */
    void on_pushButton_4_clicked();

private:
    Ui::administrator *ui;      //a pointer to the UI
    StadiumList* masterList;    //a pointer to the stadiumList
};

#endif // ADMINISTRATOR_H
