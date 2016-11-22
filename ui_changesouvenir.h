/********************************************************************************
** Form generated from reading UI file 'changesouvenir.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHANGESOUVENIR_H
#define UI_CHANGESOUVENIR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_changesouvenir
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QComboBox *selectStadium;
    QGroupBox *groupBox_2;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *souvenirEditTable;
    QLabel *errorLabel;
    QPushButton *deleteButton;
    QPushButton *addSouvenir;
    QHBoxLayout *horizontalLayout;
    QPushButton *save;
    QPushButton *cancel;

    void setupUi(QDialog *changesouvenir)
    {
        if (changesouvenir->objectName().isEmpty())
            changesouvenir->setObjectName(QStringLiteral("changesouvenir"));
        changesouvenir->resize(393, 588);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        changesouvenir->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(changesouvenir);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(changesouvenir);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        selectStadium = new QComboBox(groupBox);
        selectStadium->setObjectName(QStringLiteral("selectStadium"));

        verticalLayout_2->addWidget(selectStadium);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(changesouvenir);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_2);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        souvenirEditTable = new QTableWidget(groupBox_2);
        souvenirEditTable->setObjectName(QStringLiteral("souvenirEditTable"));
        souvenirEditTable->horizontalHeader()->setStretchLastSection(true);

        horizontalLayout_2->addWidget(souvenirEditTable);


        verticalLayout->addWidget(groupBox_2);

        errorLabel = new QLabel(changesouvenir);
        errorLabel->setObjectName(QStringLiteral("errorLabel"));
        errorLabel->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(errorLabel);

        deleteButton = new QPushButton(changesouvenir);
        deleteButton->setObjectName(QStringLiteral("deleteButton"));

        verticalLayout->addWidget(deleteButton);

        addSouvenir = new QPushButton(changesouvenir);
        addSouvenir->setObjectName(QStringLiteral("addSouvenir"));

        verticalLayout->addWidget(addSouvenir);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        save = new QPushButton(changesouvenir);
        save->setObjectName(QStringLiteral("save"));

        horizontalLayout->addWidget(save);

        cancel = new QPushButton(changesouvenir);
        cancel->setObjectName(QStringLiteral("cancel"));

        horizontalLayout->addWidget(cancel);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(changesouvenir);

        QMetaObject::connectSlotsByName(changesouvenir);
    } // setupUi

    void retranslateUi(QDialog *changesouvenir)
    {
        changesouvenir->setWindowTitle(QApplication::translate("changesouvenir", "Change Souvenirs", 0));
        groupBox->setTitle(QApplication::translate("changesouvenir", "Select Stadium", 0));
        groupBox_2->setTitle(QApplication::translate("changesouvenir", "Edit Souvenirs", 0));
        errorLabel->setText(QString());
        deleteButton->setText(QApplication::translate("changesouvenir", "Delete Selected Souvenir", 0));
        addSouvenir->setText(QApplication::translate("changesouvenir", "Add Souvenier", 0));
        save->setText(QApplication::translate("changesouvenir", "Save", 0));
        cancel->setText(QApplication::translate("changesouvenir", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class changesouvenir: public Ui_changesouvenir {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHANGESOUVENIR_H
