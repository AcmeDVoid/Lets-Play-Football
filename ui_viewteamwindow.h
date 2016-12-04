/********************************************************************************
** Form generated from reading UI file 'viewteamwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
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
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_ViewTeamWindow
{
public:
    QWidget *horizontalLayoutWidget;
    QHBoxLayout *horizontalLayout;
    QTextBrowser *textBrowser;
    QVBoxLayout *verticalLayout_3;
    QSpacerItem *verticalSpacer_2;
    QLabel *label;
    QRadioButton *radioButton_6;
    QRadioButton *radioButton_2;
    QRadioButton *radioButton_4;
    QRadioButton *radioButton_3;
    QRadioButton *radioButton_5;
    QRadioButton *radioButton;
    QSpacerItem *verticalSpacer_3;
    QLabel *label_2;
    QCheckBox *checkBox_2;
    QCheckBox *checkBox;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;

    void setupUi(QDialog *ViewTeamWindow)
    {
        if (ViewTeamWindow->objectName().isEmpty())
            ViewTeamWindow->setObjectName(QStringLiteral("ViewTeamWindow"));
        ViewTeamWindow->resize(706, 537);
        horizontalLayoutWidget = new QWidget(ViewTeamWindow);
        horizontalLayoutWidget->setObjectName(QStringLiteral("horizontalLayoutWidget"));
        horizontalLayoutWidget->setGeometry(QRect(9, 9, 691, 511));
        horizontalLayout = new QHBoxLayout(horizontalLayoutWidget);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        textBrowser = new QTextBrowser(horizontalLayoutWidget);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));

        horizontalLayout->addWidget(textBrowser);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_2);

        label = new QLabel(horizontalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_3->addWidget(label);

        radioButton_6 = new QRadioButton(horizontalLayoutWidget);
        radioButton_6->setObjectName(QStringLiteral("radioButton_6"));

        verticalLayout_3->addWidget(radioButton_6);

        radioButton_2 = new QRadioButton(horizontalLayoutWidget);
        radioButton_2->setObjectName(QStringLiteral("radioButton_2"));

        verticalLayout_3->addWidget(radioButton_2);

        radioButton_4 = new QRadioButton(horizontalLayoutWidget);
        radioButton_4->setObjectName(QStringLiteral("radioButton_4"));

        verticalLayout_3->addWidget(radioButton_4);

        radioButton_3 = new QRadioButton(horizontalLayoutWidget);
        radioButton_3->setObjectName(QStringLiteral("radioButton_3"));

        verticalLayout_3->addWidget(radioButton_3);

        radioButton_5 = new QRadioButton(horizontalLayoutWidget);
        radioButton_5->setObjectName(QStringLiteral("radioButton_5"));

        verticalLayout_3->addWidget(radioButton_5);

        radioButton = new QRadioButton(horizontalLayoutWidget);
        radioButton->setObjectName(QStringLiteral("radioButton"));

        verticalLayout_3->addWidget(radioButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout_3->addItem(verticalSpacer_3);

        label_2 = new QLabel(horizontalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_3->addWidget(label_2);

        checkBox_2 = new QCheckBox(horizontalLayoutWidget);
        checkBox_2->setObjectName(QStringLiteral("checkBox_2"));

        verticalLayout_3->addWidget(checkBox_2);

        checkBox = new QCheckBox(horizontalLayoutWidget);
        checkBox->setObjectName(QStringLiteral("checkBox"));

        verticalLayout_3->addWidget(checkBox);

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
        label->setText(QApplication::translate("ViewTeamWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Sort</span></p></body></html>", 0));
        radioButton_6->setText(QApplication::translate("ViewTeamWindow", "Roof Type", 0));
        radioButton_2->setText(QApplication::translate("ViewTeamWindow", "Stadium Capacity", 0));
        radioButton_4->setText(QApplication::translate("ViewTeamWindow", "Stadium Name", 0));
        radioButton_3->setText(QApplication::translate("ViewTeamWindow", "Star Player", 0));
        radioButton_5->setText(QApplication::translate("ViewTeamWindow", "Surface Type", 0));
        radioButton->setText(QApplication::translate("ViewTeamWindow", "Team Name", 0));
        label_2->setText(QApplication::translate("ViewTeamWindow", "<html><head/><body><p><span style=\" font-weight:600;\">Filter</span></p></body></html>", 0));
        checkBox_2->setText(QApplication::translate("ViewTeamWindow", "National Football Conference", 0));
        checkBox->setText(QApplication::translate("ViewTeamWindow", "American Football Conference", 0));
    } // retranslateUi

};

namespace Ui {
    class ViewTeamWindow: public Ui_ViewTeamWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWTEAMWINDOW_H
