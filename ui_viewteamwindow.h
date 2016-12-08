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
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewTeamWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTableWidget *teamTable;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QSpacerItem *verticalSpacer_4;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton;
    QSpacerItem *verticalSpacer_5;
    QLabel *label_2;
    QSpacerItem *verticalSpacer_6;
    QCheckBox *checkBox_NFC;
    QCheckBox *checkBox_AFC;
    QCheckBox *checkBox_openRoof;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QButtonGroup *buttonGroup;

    void setupUi(QDialog *ViewTeamWindow)
    {
        if (ViewTeamWindow->objectName().isEmpty())
            ViewTeamWindow->setObjectName(QStringLiteral("ViewTeamWindow"));
        ViewTeamWindow->resize(828, 536);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        ViewTeamWindow->setWindowIcon(icon);
        horizontalLayoutWidget = new QWidget(ViewTeamWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 811, 511));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        teamTable = new QTableWidget(horizontalLayoutWidget);
        if (teamTable->columnCount() < 7)
            teamTable->setColumnCount(7);
        QTableWidgetItem *__qtablewidgetitem = new QTableWidgetItem();
        teamTable->setHorizontalHeaderItem(0, __qtablewidgetitem);
        QTableWidgetItem *__qtablewidgetitem1 = new QTableWidgetItem();
        teamTable->setHorizontalHeaderItem(1, __qtablewidgetitem1);
        QTableWidgetItem *__qtablewidgetitem2 = new QTableWidgetItem();
        teamTable->setHorizontalHeaderItem(2, __qtablewidgetitem2);
        QTableWidgetItem *__qtablewidgetitem3 = new QTableWidgetItem();
        teamTable->setHorizontalHeaderItem(3, __qtablewidgetitem3);
        QTableWidgetItem *__qtablewidgetitem4 = new QTableWidgetItem();
        teamTable->setHorizontalHeaderItem(4, __qtablewidgetitem4);
        QTableWidgetItem *__qtablewidgetitem5 = new QTableWidgetItem();
        teamTable->setHorizontalHeaderItem(5, __qtablewidgetitem5);
        QTableWidgetItem *__qtablewidgetitem6 = new QTableWidgetItem();
        teamTable->setHorizontalHeaderItem(6, __qtablewidgetitem6);
        teamTable->setObjectName(QStringLiteral("teamTable"));
        teamTable->horizontalHeader()->setDefaultSectionSize(85);

        horizontalLayout->addWidget(teamTable);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        verticalSpacer_4 = new QSpacerItem(20, 10, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_4);

        radioButton_6 = new QRadioButton(horizontalLayoutWidget);
        buttonGroup = new QButtonGroup(ViewTeamWindow);
        buttonGroup->setObjectName(QStringLiteral("buttonGroup"));
        buttonGroup->addButton(radioButton_6);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        verticalLayout_3->addWidget(radioButton_6);

        radioButton_2 = new QRadioButton(horizontalLayoutWidget);
        buttonGroup->addButton(radioButton_2);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        radioButton_3 = new QRadioButton(horizontalLayoutWidget);
        buttonGroup->addButton(radioButton_3);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);

        radioButton_5 = new QRadioButton(horizontalLayoutWidget);
        buttonGroup->addButton(radioButton_5);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout_3->addWidget(radioButton_5);

        radioButton = new QRadioButton(horizontalLayoutWidget);
        buttonGroup->addButton(radioButton);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_3->addWidget(radioButton);

        verticalSpacer_5 = new QSpacerItem(20, 20, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_5);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        verticalSpacer_6 = new QSpacerItem(20, 13, QSizePolicy::Minimum, QSizePolicy::Fixed);

        verticalLayout_3->addItem(verticalSpacer_6);

        checkBox_NFC = new QCheckBox(horizontalLayoutWidget);
        checkBox_NFC->setObjectName(QStringLiteral("checkBox_NFC"));
        checkBox_NFC->setChecked(true);

        verticalLayout_3->addWidget(checkBox_NFC);

        checkBox_AFC = new QCheckBox(horizontalLayoutWidget);
        checkBox_AFC->setObjectName(QStringLiteral("checkBox_AFC"));
        checkBox_AFC->setChecked(true);

        verticalLayout_3->addWidget(checkBox_AFC);

        checkBox_openRoof = new QCheckBox(horizontalLayoutWidget);
        checkBox_openRoof->setObjectName(QStringLiteral("checkBox_openRoof"));

        verticalLayout_3->addWidget(checkBox_openRoof);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));

        horizontalLayout->addLayout(verticalLayout_2);


        retranslateUi(ViewTeamWindow);

        QMetaObject::connectSlotsByName(ViewTeamWindow);
    } // setupUi

    void retranslateUi(QDialog *ViewTeamWindow)
    {
        ViewTeamWindow->setWindowTitle(QApplication::translate("ViewTeamWindow", "Dialog", 0));
        QTableWidgetItem *___qtablewidgetitem = teamTable->horizontalHeaderItem(0);
        ___qtablewidgetitem->setText(QApplication::translate("ViewTeamWindow", "Team Name", 0));
        QTableWidgetItem *___qtablewidgetitem1 = teamTable->horizontalHeaderItem(1);
        ___qtablewidgetitem1->setText(QApplication::translate("ViewTeamWindow", "Stadium", 0));
        QTableWidgetItem *___qtablewidgetitem2 = teamTable->horizontalHeaderItem(2);
        ___qtablewidgetitem2->setText(QApplication::translate("ViewTeamWindow", "Star Player", 0));
        QTableWidgetItem *___qtablewidgetitem3 = teamTable->horizontalHeaderItem(3);
        ___qtablewidgetitem3->setText(QApplication::translate("ViewTeamWindow", "Conference", 0));
        QTableWidgetItem *___qtablewidgetitem4 = teamTable->horizontalHeaderItem(4);
        ___qtablewidgetitem4->setText(QApplication::translate("ViewTeamWindow", "Capacity", 0));
        QTableWidgetItem *___qtablewidgetitem5 = teamTable->horizontalHeaderItem(5);
        ___qtablewidgetitem5->setText(QApplication::translate("ViewTeamWindow", "Surface Type", 0));
        QTableWidgetItem *___qtablewidgetitem6 = teamTable->horizontalHeaderItem(6);
        ___qtablewidgetitem6->setText(QApplication::translate("ViewTeamWindow", "Roof Type", 0));
        label->setText(QApplication::translate("ViewTeamWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Sort</span></p></body></html>", 0));
        radioButton_6->setText(QApplication::translate("ViewTeamWindow", "Roof Type", 0));
        radioButton_2->setText(QApplication::translate("ViewTeamWindow", "Seating Capacity", 0));
        radioButton_3->setText(QApplication::translate("ViewTeamWindow", "Star Player", 0));
        radioButton_5->setText(QApplication::translate("ViewTeamWindow", "Surface Type", 0));
        radioButton->setText(QApplication::translate("ViewTeamWindow", "Team Name", 0));
        label_2->setText(QApplication::translate("ViewTeamWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Filter</span></p></body></html>", 0));
        checkBox_NFC->setText(QApplication::translate("ViewTeamWindow", "National Football Conference", 0));
        checkBox_AFC->setText(QApplication::translate("ViewTeamWindow", "American Football Conference", 0));
        checkBox_openRoof->setText(QApplication::translate("ViewTeamWindow", "Open Roof Only", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewTeamWindow: public Ui_ViewTeamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTEAMWINDOW_H
