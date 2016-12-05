/********************************************************************************
** Form generated from reading UI file 'modifystadiumselector.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYSTADIUMSELECTOR_H
#define UI_MODIFYSTADIUMSELECTOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_modifyStadiumSelector
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *stadiumTable;
    QPushButton *modifyButton;
    QLabel *errorLabel;
    QPushButton *cancelButton;

    void setupUi(QDialog *modifyStadiumSelector)
    {
        if (modifyStadiumSelector->objectName().isEmpty())
            modifyStadiumSelector->setObjectName(QStringLiteral("modifyStadiumSelector"));
        modifyStadiumSelector->resize(367, 471);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        modifyStadiumSelector->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(modifyStadiumSelector);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(modifyStadiumSelector);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        stadiumTable = new QTableWidget(groupBox);
        stadiumTable->setObjectName(QStringLiteral("stadiumTable"));
        stadiumTable->setEditTriggers(QAbstractItemView::NoEditTriggers);

        verticalLayout_2->addWidget(stadiumTable);

        modifyButton = new QPushButton(groupBox);
        modifyButton->setObjectName(QStringLiteral("modifyButton"));

        verticalLayout_2->addWidget(modifyButton);

        errorLabel = new QLabel(groupBox);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));

        verticalLayout_2->addWidget(errorLabel);


        verticalLayout->addWidget(groupBox);

        cancelButton = new QPushButton(modifyStadiumSelector);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        verticalLayout->addWidget(cancelButton);


        retranslateUi(modifyStadiumSelector);

        QMetaObject::connectSlotsByName(modifyStadiumSelector);
    } // setupUi

    void retranslateUi(QDialog *modifyStadiumSelector)
    {
        modifyStadiumSelector->setWindowTitle(QApplication::translate("modifyStadiumSelector", "Modify Stadium Selection", 0));
        groupBox->setTitle(QApplication::translate("modifyStadiumSelector", "Modify A Stadium", 0));
        modifyButton->setText(QApplication::translate("modifyStadiumSelector", "Modify Selected Stadium", 0));
        errorLabel->setText(QString());
        cancelButton->setText(QApplication::translate("modifyStadiumSelector", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class modifyStadiumSelector: public Ui_modifyStadiumSelector {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYSTADIUMSELECTOR_H
