/********************************************************************************
** Form generated from reading UI file 'addstadium.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDSTADIUM_H
#define UI_ADDSTADIUM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_addstadium
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QLabel *label_8;
    QLabel *labelTypology;
    QLineEdit *stadiumTypology;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QSpinBox *capacity;
    QDateEdit *dateOpened;
    QLineEdit *teamName;
    QLabel *labelStadiumName;
    QLineEdit *stadiumName;
    QLabel *labelTeamName;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *grassRadioButton;
    QRadioButton *astroTurfRadioButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *nationalLeagueRadioButton;
    QRadioButton *americanLeagueRadioButton;
    QGroupBox *groupBox_7;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLineEdit *address;
    QLineEdit *phoneNumber;
    QLabel *labelCity;
    QComboBox *state;
    QLineEdit *city;
    QLabel *labelPhone;
    QLabel *labelAddress;
    QLabel *labelState;
    QLineEdit *zip;
    QLabel *labelZipCode;
    QGroupBox *groupBox_5;
    QVBoxLayout *verticalLayout_2;
    QTableWidget *souvenirsTable;
    QPushButton *addSouvenirItem;
    QLabel *labelErrorMessage;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *addStadiumButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *addstadium)
    {
        if (addstadium->objectName().isEmpty())
            addstadium->setObjectName(QStringLiteral("addstadium"));
        addstadium->resize(987, 670);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        addstadium->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(addstadium);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(addstadium);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 6, 0, 1, 1);

        labelTypology = new QLabel(groupBox);
        labelTypology->setObjectName(QStringLiteral("labelTypology"));

        gridLayout_2->addWidget(labelTypology, 2, 0, 1, 1);

        stadiumTypology = new QLineEdit(groupBox);
        stadiumTypology->setObjectName(QStringLiteral("stadiumTypology"));

        gridLayout_2->addWidget(stadiumTypology, 2, 1, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 4, 0, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 9, 0, 1, 1);

        capacity = new QSpinBox(groupBox);
        capacity->setObjectName(QStringLiteral("capacity"));

        gridLayout_2->addWidget(capacity, 4, 1, 1, 1);

        dateOpened = new QDateEdit(groupBox);
        dateOpened->setObjectName(QStringLiteral("dateOpened"));

        gridLayout_2->addWidget(dateOpened, 3, 1, 1, 1);

        teamName = new QLineEdit(groupBox);
        teamName->setObjectName(QStringLiteral("teamName"));

        gridLayout_2->addWidget(teamName, 1, 1, 1, 1);

        labelStadiumName = new QLabel(groupBox);
        labelStadiumName->setObjectName(QStringLiteral("labelStadiumName"));

        gridLayout_2->addWidget(labelStadiumName, 0, 0, 1, 1);

        stadiumName = new QLineEdit(groupBox);
        stadiumName->setObjectName(QStringLiteral("stadiumName"));

        gridLayout_2->addWidget(stadiumName, 0, 1, 1, 1);

        labelTeamName = new QLabel(groupBox);
        labelTeamName->setObjectName(QStringLiteral("labelTeamName"));

        gridLayout_2->addWidget(labelTeamName, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        grassRadioButton = new QRadioButton(groupBox_4);
        grassRadioButton->setObjectName(QStringLiteral("grassRadioButton"));

        horizontalLayout_2->addWidget(grassRadioButton);

        astroTurfRadioButton = new QRadioButton(groupBox_4);
        astroTurfRadioButton->setObjectName(QStringLiteral("astroTurfRadioButton"));

        horizontalLayout_2->addWidget(astroTurfRadioButton);


        gridLayout_2->addWidget(groupBox_4, 9, 1, 1, 1);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        horizontalLayout = new QHBoxLayout(groupBox_3);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        nationalLeagueRadioButton = new QRadioButton(groupBox_3);
        nationalLeagueRadioButton->setObjectName(QStringLiteral("nationalLeagueRadioButton"));

        horizontalLayout->addWidget(nationalLeagueRadioButton);

        americanLeagueRadioButton = new QRadioButton(groupBox_3);
        americanLeagueRadioButton->setObjectName(QStringLiteral("americanLeagueRadioButton"));

        horizontalLayout->addWidget(americanLeagueRadioButton);


        gridLayout_2->addWidget(groupBox_3, 6, 1, 1, 1);

        groupBox_7 = new QGroupBox(groupBox);
        groupBox_7->setObjectName(QStringLiteral("groupBox_7"));

        gridLayout_2->addWidget(groupBox_7, 10, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(addstadium);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        address = new QLineEdit(groupBox_2);
        address->setObjectName(QStringLiteral("address"));

        gridLayout_3->addWidget(address, 3, 1, 1, 1);

        phoneNumber = new QLineEdit(groupBox_2);
        phoneNumber->setObjectName(QStringLiteral("phoneNumber"));

        gridLayout_3->addWidget(phoneNumber, 4, 1, 1, 1);

        labelCity = new QLabel(groupBox_2);
        labelCity->setObjectName(QStringLiteral("labelCity"));

        gridLayout_3->addWidget(labelCity, 0, 0, 1, 1);

        state = new QComboBox(groupBox_2);
        state->setObjectName(QStringLiteral("state"));

        gridLayout_3->addWidget(state, 1, 1, 1, 1);

        city = new QLineEdit(groupBox_2);
        city->setObjectName(QStringLiteral("city"));

        gridLayout_3->addWidget(city, 0, 1, 1, 1);

        labelPhone = new QLabel(groupBox_2);
        labelPhone->setObjectName(QStringLiteral("labelPhone"));

        gridLayout_3->addWidget(labelPhone, 4, 0, 1, 1);

        labelAddress = new QLabel(groupBox_2);
        labelAddress->setObjectName(QStringLiteral("labelAddress"));

        gridLayout_3->addWidget(labelAddress, 3, 0, 1, 1);

        labelState = new QLabel(groupBox_2);
        labelState->setObjectName(QStringLiteral("labelState"));

        gridLayout_3->addWidget(labelState, 1, 0, 1, 1);

        zip = new QLineEdit(groupBox_2);
        zip->setObjectName(QStringLiteral("zip"));

        gridLayout_3->addWidget(zip, 2, 1, 1, 1);

        labelZipCode = new QLabel(groupBox_2);
        labelZipCode->setObjectName(QStringLiteral("labelZipCode"));

        gridLayout_3->addWidget(labelZipCode, 2, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);


        horizontalLayout_4->addLayout(verticalLayout_3);

        groupBox_5 = new QGroupBox(addstadium);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setMinimumSize(QSize(500, 0));
        verticalLayout_2 = new QVBoxLayout(groupBox_5);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        souvenirsTable = new QTableWidget(groupBox_5);
        souvenirsTable->setObjectName(QStringLiteral("souvenirsTable"));

        verticalLayout_2->addWidget(souvenirsTable);

        addSouvenirItem = new QPushButton(groupBox_5);
        addSouvenirItem->setObjectName(QStringLiteral("addSouvenirItem"));

        verticalLayout_2->addWidget(addSouvenirItem);


        horizontalLayout_4->addWidget(groupBox_5);


        verticalLayout->addLayout(horizontalLayout_4);

        labelErrorMessage = new QLabel(addstadium);
        labelErrorMessage->setObjectName(QStringLiteral("labelErrorMessage"));

        verticalLayout->addWidget(labelErrorMessage);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        addStadiumButton = new QPushButton(addstadium);
        addStadiumButton->setObjectName(QStringLiteral("addStadiumButton"));

        horizontalLayout_5->addWidget(addStadiumButton);

        cancelButton = new QPushButton(addstadium);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setMaximumSize(QSize(480, 16777215));

        horizontalLayout_5->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout_5);

        QWidget::setTabOrder(stadiumName, teamName);
        QWidget::setTabOrder(teamName, stadiumTypology);
        QWidget::setTabOrder(stadiumTypology, dateOpened);
        QWidget::setTabOrder(dateOpened, capacity);
        QWidget::setTabOrder(capacity, nationalLeagueRadioButton);
        QWidget::setTabOrder(nationalLeagueRadioButton, americanLeagueRadioButton);
        QWidget::setTabOrder(americanLeagueRadioButton, grassRadioButton);
        QWidget::setTabOrder(grassRadioButton, astroTurfRadioButton);
        QWidget::setTabOrder(astroTurfRadioButton, city);
        QWidget::setTabOrder(city, state);
        QWidget::setTabOrder(state, zip);
        QWidget::setTabOrder(zip, address);
        QWidget::setTabOrder(address, phoneNumber);
        QWidget::setTabOrder(phoneNumber, souvenirsTable);
        QWidget::setTabOrder(souvenirsTable, addSouvenirItem);
        QWidget::setTabOrder(addSouvenirItem, addStadiumButton);
        QWidget::setTabOrder(addStadiumButton, cancelButton);

        retranslateUi(addstadium);

        QMetaObject::connectSlotsByName(addstadium);
    } // setupUi

    void retranslateUi(QDialog *addstadium)
    {
        addstadium->setWindowTitle(QApplication::translate("addstadium", "Add Stadiums", 0));
        groupBox->setTitle(QApplication::translate("addstadium", "Stadium Information", 0));
        label_8->setText(QApplication::translate("addstadium", "League Type", 0));
        labelTypology->setText(QApplication::translate("addstadium", "Stadium Typology", 0));
        label_9->setText(QApplication::translate("addstadium", "Date Opened", 0));
        label_10->setText(QApplication::translate("addstadium", "Seating Capacity", 0));
        label_11->setText(QApplication::translate("addstadium", "Grass Surface Type", 0));
        labelStadiumName->setText(QApplication::translate("addstadium", "Stadium Name", 0));
        labelTeamName->setText(QApplication::translate("addstadium", "Team Name", 0));
        groupBox_4->setTitle(QString());
        grassRadioButton->setText(QApplication::translate("addstadium", "Grass", 0));
        astroTurfRadioButton->setText(QApplication::translate("addstadium", "Synthetic", 0));
        groupBox_3->setTitle(QString());
        nationalLeagueRadioButton->setText(QApplication::translate("addstadium", "National League", 0));
        americanLeagueRadioButton->setText(QApplication::translate("addstadium", "American League", 0));
        groupBox_7->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("addstadium", "Address and Phone Number", 0));
        labelCity->setText(QApplication::translate("addstadium", "City", 0));
        labelPhone->setText(QApplication::translate("addstadium", "Phone Number", 0));
        labelAddress->setText(QApplication::translate("addstadium", "Street Address", 0));
        labelState->setText(QApplication::translate("addstadium", "State", 0));
        labelZipCode->setText(QApplication::translate("addstadium", "Zip Code", 0));
        groupBox_5->setTitle(QApplication::translate("addstadium", "Stadium Souvenirs", 0));
        addSouvenirItem->setText(QApplication::translate("addstadium", "Add New Souvenir Item", 0));
        labelErrorMessage->setText(QString());
        addStadiumButton->setText(QApplication::translate("addstadium", "Add Stadium", 0));
        cancelButton->setText(QApplication::translate("addstadium", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class addstadium: public Ui_addstadium {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDSTADIUM_H
