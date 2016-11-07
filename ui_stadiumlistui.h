/********************************************************************************
** Form generated from reading UI file 'stadiumlistui.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STADIUMLISTUI_H
#define UI_STADIUMLISTUI_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_StadiumListUI
{
public:
    QVBoxLayout *verticalLayout_2;
    QTableWidget *tableWidget;

    void setupUi(QDialog *StadiumListUI)
    {
        if (StadiumListUI->objectName().isEmpty())
            StadiumListUI->setObjectName(QStringLiteral("StadiumListUI"));
        StadiumListUI->resize(579, 445);
        verticalLayout_2 = new QVBoxLayout(StadiumListUI);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        tableWidget = new QTableWidget(StadiumListUI);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);


        retranslateUi(StadiumListUI);

        QMetaObject::connectSlotsByName(StadiumListUI);
    } // setupUi

    void retranslateUi(QDialog *StadiumListUI)
    {
        StadiumListUI->setWindowTitle(QApplication::translate("StadiumListUI", "Dialog", 0));
    } // retranslateUi

};

namespace Ui {
    class StadiumListUI: public Ui_StadiumListUI {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STADIUMLISTUI_H
