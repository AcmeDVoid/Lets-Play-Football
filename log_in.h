#ifndef LOG_IN_H
#define LOG_IN_H

#include <QDialog>
#include <QMessageBox>

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

private:
    Ui::Log_In *ui;
};

#endif // LOG_IN_H
