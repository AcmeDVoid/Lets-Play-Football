/********************************************************************************
** Form generated from reading UI file 'viewrevenue.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VIEWREVENUE_H
#define UI_VIEWREVENUE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_viewRevenue
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_4;
    QHBoxLayout *horizontalLayout_2;
    QTableWidget *reportTable;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_3;
    QLabel *totalCount;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *totalRevenue;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *viewRevenue)
    {
        if (viewRevenue->objectName().isEmpty())
            viewRevenue->setObjectName(QStringLiteral("viewRevenue"));
        viewRevenue->resize(912, 608);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        viewRevenue->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(viewRevenue);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_4 = new QGroupBox(viewRevenue);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        horizontalLayout_2 = new QHBoxLayout(groupBox_4);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        reportTable = new QTableWidget(groupBox_4);
        reportTable->setObjectName(QStringLiteral("reportTable"));

        horizontalLayout_2->addWidget(reportTable);


        verticalLayout->addWidget(groupBox_4);

        groupBox = new QGroupBox(viewRevenue);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        horizontalLayout = new QHBoxLayout(groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_2 = new QGroupBox(groupBox);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout_3 = new QVBoxLayout(groupBox_2);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        totalCount = new QLabel(groupBox_2);
        totalCount->setObjectName(QStringLiteral("totalCount"));

        verticalLayout_3->addWidget(totalCount);


        horizontalLayout->addWidget(groupBox_2);

        groupBox_3 = new QGroupBox(groupBox);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        verticalLayout_2 = new QVBoxLayout(groupBox_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        totalRevenue = new QLabel(groupBox_3);
        totalRevenue->setObjectName(QStringLiteral("totalRevenue"));

        verticalLayout_2->addWidget(totalRevenue);


        horizontalLayout->addWidget(groupBox_3);


        verticalLayout->addWidget(groupBox);

        buttonBox = new QDialogButtonBox(viewRevenue);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(viewRevenue);
        QObject::connect(buttonBox, SIGNAL(accepted()), viewRevenue, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), viewRevenue, SLOT(reject()));

        QMetaObject::connectSlotsByName(viewRevenue);
    } // setupUi

    void retranslateUi(QDialog *viewRevenue)
    {
        viewRevenue->setWindowTitle(QApplication::translate("viewRevenue", "View Revenue", 0));
        groupBox_4->setTitle(QApplication::translate("viewRevenue", "Revenue by Stadium", 0));
        groupBox->setTitle(QString());
        groupBox_2->setTitle(QApplication::translate("viewRevenue", "Total Item Count", 0));
        totalCount->setText(QString());
        groupBox_3->setTitle(QApplication::translate("viewRevenue", "Total Revenue", 0));
        totalRevenue->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class viewRevenue: public Ui_viewRevenue {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VIEWREVENUE_H
