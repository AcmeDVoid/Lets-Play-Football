/********************************************************************************
** Form generated from reading UI file 'administrator.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_H
#define UI_ADMINISTRATOR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_administrator
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *pushButton;
    QPushButton *viewRevenue;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *administrator)
    {
        if (administrator->objectName().isEmpty())
            administrator->setObjectName(QStringLiteral("administrator"));
        administrator->resize(318, 406);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        administrator->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(administrator);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(administrator);
        label->setObjectName(QStringLiteral("label"));
        label->setPixmap(QPixmap(QString::fromUtf8(":/admin.png")));

        verticalLayout->addWidget(label, 0, Qt::AlignHCenter);

        pushButton_4 = new QPushButton(administrator);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));

        verticalLayout->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(administrator);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));

        verticalLayout->addWidget(pushButton_3);

        pushButton = new QPushButton(administrator);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout->addWidget(pushButton);

        viewRevenue = new QPushButton(administrator);
        viewRevenue->setObjectName(QStringLiteral("viewRevenue"));

        verticalLayout->addWidget(viewRevenue);

        buttonBox = new QDialogButtonBox(administrator);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        buttonBox->setCenterButtons(true);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(administrator);
        QObject::connect(buttonBox, SIGNAL(accepted()), administrator, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), administrator, SLOT(reject()));

        QMetaObject::connectSlotsByName(administrator);
    } // setupUi

    void retranslateUi(QDialog *administrator)
    {
        administrator->setWindowTitle(QApplication::translate("administrator", "Admin Menu", 0));
        label->setText(QString());
        pushButton_4->setText(QApplication::translate("administrator", "Modify Stadium", 0));
        pushButton_3->setText(QApplication::translate("administrator", "Add A Stadium", 0));
        pushButton->setText(QApplication::translate("administrator", "Add/Modify Souvenirs", 0));
        viewRevenue->setText(QApplication::translate("administrator", "View Revenue", 0));
    } // retranslateUi

};

namespace Ui {
    class administrator: public Ui_administrator {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_H
