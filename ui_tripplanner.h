/********************************************************************************
** Form generated from reading UI file 'tripplanner.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_TRIPPLANNER_H
#define UI_TRIPPLANNER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_TripPlanner
{
public:
    QWidget *verticalLayoutWidget;
    QVBoxLayout *vlVisit;
    QComboBox *comboBoxStarting;
    QLabel *label;
    QPushButton *buttonStartTrip;
    QPushButton *buttonCancel;
    QCheckBox *checkBoxSelectAll;
    QPushButton *buttonMST;

    void setupUi(QDialog *TripPlanner)
    {
        if (TripPlanner->objectName().isEmpty())
            TripPlanner->setObjectName(QStringLiteral("TripPlanner"));
        TripPlanner->resize(485, 649);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        TripPlanner->setWindowIcon(icon);
        verticalLayoutWidget = new QWidget(TripPlanner);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 60, 291, 581));
        vlVisit = new QVBoxLayout(verticalLayoutWidget);
        vlVisit->setObjectName(QStringLiteral("vlVisit"));
        vlVisit->setSizeConstraint(QLayout::SetNoConstraint);
        vlVisit->setContentsMargins(0, 0, 0, 0);
        comboBoxStarting = new QComboBox(TripPlanner);
        comboBoxStarting->setObjectName(QStringLiteral("comboBoxStarting"));
        comboBoxStarting->setGeometry(QRect(10, 31, 69, 20));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(comboBoxStarting->sizePolicy().hasHeightForWidth());
        comboBoxStarting->setSizePolicy(sizePolicy);
        comboBoxStarting->setSizeAdjustPolicy(QComboBox::AdjustToContents);
        label = new QLabel(TripPlanner);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 151, 16));
        label->setAlignment(Qt::AlignCenter);
        buttonStartTrip = new QPushButton(TripPlanner);
        buttonStartTrip->setObjectName(QStringLiteral("buttonStartTrip"));
        buttonStartTrip->setGeometry(QRect(310, 30, 75, 21));
        buttonCancel = new QPushButton(TripPlanner);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));
        buttonCancel->setGeometry(QRect(390, 30, 75, 21));
        checkBoxSelectAll = new QCheckBox(TripPlanner);
        checkBoxSelectAll->setObjectName(QStringLiteral("checkBoxSelectAll"));
        checkBoxSelectAll->setEnabled(true);
        checkBoxSelectAll->setGeometry(QRect(310, 60, 91, 17));
        buttonMST = new QPushButton(TripPlanner);
        buttonMST->setObjectName(QStringLiteral("buttonMST"));
        buttonMST->setGeometry(QRect(300, 100, 141, 41));

        retranslateUi(TripPlanner);

        QMetaObject::connectSlotsByName(TripPlanner);
    } // setupUi

    void retranslateUi(QDialog *TripPlanner)
    {
        TripPlanner->setWindowTitle(QApplication::translate("TripPlanner", "Trip Planner", 0));
        label->setText(QApplication::translate("TripPlanner", "Starting Stadium", 0));
        buttonStartTrip->setText(QApplication::translate("TripPlanner", "Start Trip", 0));
        buttonCancel->setText(QApplication::translate("TripPlanner", "Cancel", 0));
        checkBoxSelectAll->setText(QApplication::translate("TripPlanner", "Select All", 0));
        buttonMST->setText(QApplication::translate("TripPlanner", "Minimum Spanning  Tree", 0));
    } // retranslateUi

};

namespace Ui {
    class TripPlanner: public Ui_TripPlanner {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_TRIPPLANNER_H
