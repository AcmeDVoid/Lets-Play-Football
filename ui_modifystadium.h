/********************************************************************************
** Form generated from reading UI file 'modifystadium.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MODIFYSTADIUM_H
#define UI_MODIFYSTADIUM_H

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
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_modifyStadium
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout_4;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *groupBox;
    QGridLayout *gridLayout_2;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QRadioButton *radioRetrackableButton;
    QRadioButton *grassRadioButton;
    QRadioButton *astroTurfRadioButton;
    QGroupBox *groupBox_3;
    QHBoxLayout *horizontalLayout;
    QRadioButton *nationalLeagueRadioButton;
    QRadioButton *americanLeagueRadioButton;
    QLineEdit *teamName;
    QLabel *labelTypology;
    QLabel *labelStadiumName;
    QLineEdit *stadiumTypology;
    QLabel *labelTeamName;
    QLabel *label_9;
    QSpinBox *capacity;
    QLineEdit *stadiumName;
    QDateEdit *dateOpened;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_8;
    QLabel *label;
    QLineEdit *starPlayer_2;
    QGroupBox *groupBox_2;
    QGridLayout *gridLayout_3;
    QLabel *labelCity;
    QLineEdit *phoneNumber;
    QLineEdit *address;
    QComboBox *state;
    QLabel *labelPhone;
    QLineEdit *city;
    QLabel *labelAddress;
    QLabel *labelState;
    QLineEdit *zip;
    QLabel *labelZipCode;
    QLineEdit *starPlayer;
    QLabel *labelStarPlayer;
    QLabel *labelErrorMessage;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *updateStadiumButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *modifyStadium)
    {
        if (modifyStadium->objectName().isEmpty())
            modifyStadium->setObjectName(QStringLiteral("modifyStadium"));
        modifyStadium->resize(550, 516);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        modifyStadium->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(modifyStadium);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        groupBox = new QGroupBox(modifyStadium);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout_2 = new QGridLayout(groupBox);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        groupBox_4 = new QGroupBox(groupBox);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        radioRetrackableButton = new QRadioButton(groupBox_4);
        radioRetrackableButton->setObjectName(QStringLiteral("radioRetrackableButton"));

        horizontalLayout_2->addWidget(radioRetrackableButton);

        grassRadioButton = new QRadioButton(groupBox_4);
        grassRadioButton->setObjectName(QStringLiteral("grassRadioButton"));

        horizontalLayout_2->addWidget(grassRadioButton);

        astroTurfRadioButton = new QRadioButton(groupBox_4);
        astroTurfRadioButton->setObjectName(QStringLiteral("astroTurfRadioButton"));

        horizontalLayout_2->addWidget(astroTurfRadioButton);


        gridLayout_2->addWidget(groupBox_4, 10, 1, 1, 1);

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


        gridLayout_2->addWidget(groupBox_3, 7, 1, 1, 1);

        teamName = new QLineEdit(groupBox);
        teamName->setObjectName(QStringLiteral("teamName"));

        gridLayout_2->addWidget(teamName, 1, 1, 1, 1);

        labelTypology = new QLabel(groupBox);
        labelTypology->setObjectName(QStringLiteral("labelTypology"));

        gridLayout_2->addWidget(labelTypology, 2, 0, 1, 1);

        labelStadiumName = new QLabel(groupBox);
        labelStadiumName->setObjectName(QStringLiteral("labelStadiumName"));

        gridLayout_2->addWidget(labelStadiumName, 0, 0, 1, 1);

        stadiumTypology = new QLineEdit(groupBox);
        stadiumTypology->setObjectName(QStringLiteral("stadiumTypology"));

        gridLayout_2->addWidget(stadiumTypology, 2, 1, 1, 1);

        labelTeamName = new QLabel(groupBox);
        labelTeamName->setObjectName(QStringLiteral("labelTeamName"));

        gridLayout_2->addWidget(labelTeamName, 1, 0, 1, 1);

        label_9 = new QLabel(groupBox);
        label_9->setObjectName(QStringLiteral("label_9"));

        gridLayout_2->addWidget(label_9, 3, 0, 1, 1);

        capacity = new QSpinBox(groupBox);
        capacity->setObjectName(QStringLiteral("capacity"));

        gridLayout_2->addWidget(capacity, 5, 1, 1, 1);

        stadiumName = new QLineEdit(groupBox);
        stadiumName->setObjectName(QStringLiteral("stadiumName"));

        gridLayout_2->addWidget(stadiumName, 0, 1, 1, 1);

        dateOpened = new QDateEdit(groupBox);
        dateOpened->setObjectName(QStringLiteral("dateOpened"));

        gridLayout_2->addWidget(dateOpened, 3, 1, 1, 1);

        label_10 = new QLabel(groupBox);
        label_10->setObjectName(QStringLiteral("label_10"));

        gridLayout_2->addWidget(label_10, 5, 0, 1, 1);

        label_11 = new QLabel(groupBox);
        label_11->setObjectName(QStringLiteral("label_11"));

        gridLayout_2->addWidget(label_11, 10, 0, 1, 1);

        label_8 = new QLabel(groupBox);
        label_8->setObjectName(QStringLiteral("label_8"));

        gridLayout_2->addWidget(label_8, 7, 0, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout_2->addWidget(label, 4, 0, 1, 1);

        starPlayer_2 = new QLineEdit(groupBox);
        starPlayer_2->setObjectName(QStringLiteral("starPlayer_2"));

        gridLayout_2->addWidget(starPlayer_2, 4, 1, 1, 1);


        verticalLayout_3->addWidget(groupBox);

        groupBox_2 = new QGroupBox(modifyStadium);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 176));
        gridLayout_3 = new QGridLayout(groupBox_2);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        labelCity = new QLabel(groupBox_2);
        labelCity->setObjectName(QStringLiteral("labelCity"));

        gridLayout_3->addWidget(labelCity, 0, 0, 1, 1);

        phoneNumber = new QLineEdit(groupBox_2);
        phoneNumber->setObjectName(QStringLiteral("phoneNumber"));

        gridLayout_3->addWidget(phoneNumber, 4, 1, 1, 1);

        address = new QLineEdit(groupBox_2);
        address->setObjectName(QStringLiteral("address"));

        gridLayout_3->addWidget(address, 3, 1, 1, 1);

        state = new QComboBox(groupBox_2);
        state->setObjectName(QStringLiteral("state"));

        gridLayout_3->addWidget(state, 1, 1, 1, 1);

        labelPhone = new QLabel(groupBox_2);
        labelPhone->setObjectName(QStringLiteral("labelPhone"));

        gridLayout_3->addWidget(labelPhone, 4, 0, 1, 1);

        city = new QLineEdit(groupBox_2);
        city->setObjectName(QStringLiteral("city"));

        gridLayout_3->addWidget(city, 0, 1, 1, 1);

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

        starPlayer = new QLineEdit(groupBox_2);
        starPlayer->setObjectName(QStringLiteral("starPlayer"));

        gridLayout_3->addWidget(starPlayer, 5, 1, 1, 1);

        labelStarPlayer = new QLabel(groupBox_2);
        labelStarPlayer->setObjectName(QStringLiteral("labelStarPlayer"));

        gridLayout_3->addWidget(labelStarPlayer, 5, 0, 1, 1);


        verticalLayout_3->addWidget(groupBox_2);


        horizontalLayout_4->addLayout(verticalLayout_3);


        horizontalLayout_3->addLayout(horizontalLayout_4);


        verticalLayout->addLayout(horizontalLayout_3);

        labelErrorMessage = new QLabel(modifyStadium);
        labelErrorMessage->setObjectName(QStringLiteral("labelErrorMessage"));

        verticalLayout->addWidget(labelErrorMessage);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QStringLiteral("horizontalLayout_5"));
        updateStadiumButton = new QPushButton(modifyStadium);
        updateStadiumButton->setObjectName(QStringLiteral("updateStadiumButton"));

        horizontalLayout_5->addWidget(updateStadiumButton);

        cancelButton = new QPushButton(modifyStadium);
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
        QWidget::setTabOrder(phoneNumber, updateStadiumButton);
        QWidget::setTabOrder(updateStadiumButton, cancelButton);

        retranslateUi(modifyStadium);

        QMetaObject::connectSlotsByName(modifyStadium);
    } // setupUi

    void retranslateUi(QDialog *modifyStadium)
    {
        modifyStadium->setWindowTitle(QApplication::translate("modifyStadium", "Update Stadium", 0));
        groupBox->setTitle(QApplication::translate("modifyStadium", "Stadium Information", 0));
        groupBox_4->setTitle(QString());
        radioRetrackableButton->setText(QApplication::translate("modifyStadium", "Retractable", 0));
        grassRadioButton->setText(QApplication::translate("modifyStadium", "Open", 0));
        astroTurfRadioButton->setText(QApplication::translate("modifyStadium", "Fixed", 0));
        groupBox_3->setTitle(QString());
        nationalLeagueRadioButton->setText(QApplication::translate("modifyStadium", "National", 0));
        americanLeagueRadioButton->setText(QApplication::translate("modifyStadium", "American", 0));
        labelTypology->setText(QApplication::translate("modifyStadium", "Surface Type", 0));
        labelStadiumName->setText(QApplication::translate("modifyStadium", "Stadium Name", 0));
        labelTeamName->setText(QApplication::translate("modifyStadium", "Team Name", 0));
        label_9->setText(QApplication::translate("modifyStadium", "Date Opened", 0));
        label_10->setText(QApplication::translate("modifyStadium", "Seating Capacity", 0));
        label_11->setText(QApplication::translate("modifyStadium", "Roof Type", 0));
        label_8->setText(QApplication::translate("modifyStadium", "Football Conference", 0));
        label->setText(QApplication::translate("modifyStadium", "Star Player", 0));
        groupBox_2->setTitle(QApplication::translate("modifyStadium", "Address and Phone Number", 0));
        labelCity->setText(QApplication::translate("modifyStadium", "City", 0));
        labelPhone->setText(QApplication::translate("modifyStadium", "Phone Number", 0));
        labelAddress->setText(QApplication::translate("modifyStadium", "Street Address", 0));
        labelState->setText(QApplication::translate("modifyStadium", "State", 0));
        labelZipCode->setText(QApplication::translate("modifyStadium", "Zip Code", 0));
        labelStarPlayer->setText(QApplication::translate("modifyStadium", "Star Player", 0));
        labelErrorMessage->setText(QString());
        updateStadiumButton->setText(QApplication::translate("modifyStadium", "Update Stadium", 0));
        cancelButton->setText(QApplication::translate("modifyStadium", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class modifyStadium: public Ui_modifyStadium {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MODIFYSTADIUM_H
