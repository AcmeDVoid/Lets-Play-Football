#ifndef LOG_IN_H
#define LOG_IN_H

#include <QDialog>
#include <QMessageBox>
#include "password.h"
#include <QDebug>

namespace Ui {
class Log_In;
}

class Log_In : public QDialog
{
    Q_OBJECT

public:
    explicit Log_In(QWidget *parent = 0);
    ~Log_In();

private slots:
    void on_cancelButton_clicked();

    void on_signInButton_clicked();

    void on_checkBox_clicked(bool checked);

private:
    Ui::Log_In *ui;
    Password adminHash;
};

#endif // LOG_IN_H
