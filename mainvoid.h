#ifndef MAINVOID_H
#define MAINVOID_H

#include <QMainWindow>
#include <QWidget>
#include <QLayout>
#include <QDialog>
#include "log_in.h"
#include "password.h"
#include "SortedLists.h"

namespace Ui {
class MainVoid;
}

class MainVoid : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainVoid(QWidget *parent = 0);
    ~MainVoid();

private slots:
    void on_userButton_clicked();

    void on_closeButton_clicked();

    void on_viewListButton_clicked();

    void on_adminButton_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_clicked();

    void on_importFileButton_clicked();

    void on_goBackButton_clicked();

    void on_selectButton_clicked();

    void on_aboutUsButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::MainVoid *ui;
};

#endif // MAINVOID_H
