#include "include/splashscreen.h"
#include "ui_splashscreen.h"

/**
 * @brief splashscreen::splashscreen
 * see corresponding header file for details on what this class does
 * @param parent the parent of the window
 */
splashscreen::splashscreen(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::splashscreen)
{
    ui->setupUi(this);
}

/**
 * @brief splashscreen::~splashscreen
 * splash screend destructor
 * largely non-implemented right now
 */
splashscreen::~splashscreen()
{
    delete ui;
}
