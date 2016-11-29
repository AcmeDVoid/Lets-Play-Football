/********************************************************************************
** Form generated from reading UI file 'viewteamwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWTEAMWINDOW_H
#define UI_VIEWTEAMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>

QT_BEGIN_NAMESPACE

class Ui_ViewTeamWindow
{
public:

    void setupUi(QDialog *ViewTeamWindow)
    {
        if (ViewTeamWindow->objectName().isEmpty())
            ViewTeamWindow->setObjectName(QStringLiteral("ViewTeamWindow"));
        ViewTeamWindow->resize(400, 300);

        retranslateUi(ViewTeamWindow);

        QMetaObject::connectSlotsByName(ViewTeamWindow);
    } // setupUi

    void retranslateUi(QDialog *ViewTeamWindow)
    {
        ViewTeamWindow->setWindowTitle(QApplication::translate("ViewTeamWindow", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewTeamWindow: public Ui_ViewTeamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTEAMWINDOW_H
