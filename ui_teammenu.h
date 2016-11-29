/********************************************************************************
** Form generated from reading UI file 'teammenu.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TEAMMENU_H
#define UI_TEAMMENU_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TeamMenu
{
public:
    QMenuBar *menubar;
    QWidget *centralwidget;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *TeamMenu)
    {
        if (TeamMenu->objectName().isEmpty())
            TeamMenu->setObjectName(QStringLiteral("TeamMenu"));
        TeamMenu->resize(800, 600);
        menubar = new QMenuBar(TeamMenu);
        menubar->setObjectName(QStringLiteral("menubar"));
        TeamMenu->setMenuBar(menubar);
        centralwidget = new QWidget(TeamMenu);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        TeamMenu->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(TeamMenu);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        TeamMenu->setStatusBar(statusbar);

        retranslateUi(TeamMenu);

        QMetaObject::connectSlotsByName(TeamMenu);
    } // setupUi

    void retranslateUi(QMainWindow *TeamMenu)
    {
        TeamMenu->setWindowTitle(QApplication::translate("TeamMenu", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class TeamMenu: public Ui_TeamMenu {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TEAMMENU_H
