#ifndef SPLASHSCREEN_H
#define SPLASHSCREEN_H

#include <QDialog>

///***********************************************************
/// Splashe Screen
/// The splash screen is the very first screen that the user will
/// see when the program opens. It does very little in terms of any
/// logic. It simply outputs a message to the user and a nice picture.
/// It says the authors of the program and the title of the project

namespace Ui {
class splashscreen;
}

/**
 * @brief The splashscreen class
 */
class splashscreen : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief splashscreen
     * @param parent the parent of the window
     */
    explicit splashscreen(QWidget *parent = 0);
    ~splashscreen();

private:
    Ui::splashscreen *ui;   ///a pointer to the user interface
};

#endif // SPLASHSCREEN_H
