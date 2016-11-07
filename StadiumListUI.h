#ifndef STADIUMLISTUI_H
#define STADIUMLISTUI_H

#include <QDialog>
#include <QtCore>
#include <QWidget>
#include <QString>
#include <QtGui>
#include "StadiumListUI.h"
#include "MyHeader.h"

namespace Ui {
class StadiumListUI;
}

class StadiumListUI : public QDialog
{
    Q_OBJECT


public:
    explicit StadiumListUI(QWidget *parent = 0);
    ~StadiumListUI();

private:
    Ui::StadiumListUI *ui;
    QStandardItemModel *model;

};

#endif // STADIUMLISTUI_H
