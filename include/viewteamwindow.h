#ifndef VIEWTEAMWINDOW_H
#define VIEWTEAMWINDOW_H

#include <QDialog>
#include "include/stadiumlist.h"
#include "include/stadium.h"

namespace Ui {
class ViewTeamWindow;
}

class ViewTeamWindow : public QDialog
{
    Q_OBJECT

public:
    explicit ViewTeamWindow(StadiumList *sList, QWidget *parent = 0);
    ~ViewTeamWindow();

private slots:
    void on_checkBox_AFC_clicked();

    void on_checkBox_NFC_clicked();

private:
    Ui::ViewTeamWindow *ui;
    StadiumList *stadiumList;
    void renderTeamList();
};

#endif // VIEWTEAMWINDOW_H
