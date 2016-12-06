/********************************************************************************
** Form generated from reading UI file 'viewstadiumwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWSTADIUMWINDOW_H
#define UI_VIEWSTADIUMWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewStadiumWindow
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vlTeamBase;
    QWidget *verticalLayoutWidget_2;
    QVBoxLayout *vlSorts;

    void setupUi(QDialog *ViewStadiumWindow)
    {
        if (ViewStadiumWindow->objectName().isEmpty())
            ViewStadiumWindow->setObjectName(QStringLiteral("ViewStadiumWindow"));
        ViewStadiumWindow->resize(661, 645);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ViewStadiumWindow->setWindowIcon(icon);
        verticalLayoutWidget = new QWidget(ViewStadiumWindow);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 371, 621));
        vlTeamBase = new QVBoxLayout(verticalLayoutWidget);
        vlTeamBase->setObjectName(QStringLiteral("vlTeamBase"));
        vlTeamBase->setContentsMargins(0, 0, 0, 0);
        verticalLayoutWidget_2 = new QWidget(ViewStadiumWindow);
        verticalLayoutWidget_2->setObjectName(QStringLiteral("verticalLayoutWidget_2"));
        verticalLayoutWidget_2->setGeometry(QRect(390, 10, 261, 621));
        vlSorts = new QVBoxLayout(verticalLayoutWidget_2);
        vlSorts->setObjectName(QStringLiteral("vlSorts"));
        vlSorts->setContentsMargins(0, 0, 0, 0);

        retranslateUi(ViewStadiumWindow);

        QMetaObject::connectSlotsByName(ViewStadiumWindow);
    } // setupUi

    void retranslateUi(QDialog *ViewStadiumWindow)
    {
        ViewStadiumWindow->setWindowTitle(QApplication::translate("ViewStadiumWindow", "View Stadiums", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewStadiumWindow: public Ui_ViewStadiumWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWSTADIUMWINDOW_H
