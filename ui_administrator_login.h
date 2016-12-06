/********************************************************************************
** Form generated from reading UI file 'administrator_login.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADMINISTRATOR_LOGIN_H
#define UI_ADMINISTRATOR_LOGIN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_administrator_login
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QGridLayout *gridLayout;
    QLineEdit *account;
    QLabel *label;
    QLineEdit *password;
    QLabel *label_2;
    QPushButton *buttonCancel;
    QPushButton *buttonLogIn;
    QLabel *labelErrorMessage;

    void setupUi(QDialog *administrator_login)
    {
        if (administrator_login->objectName().isEmpty())
            administrator_login->setObjectName(QStringLiteral("administrator_login"));
        administrator_login->resize(445, 154);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        administrator_login->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(administrator_login);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(administrator_login);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        gridLayout = new QGridLayout(groupBox);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        account = new QLineEdit(groupBox);
        account->setObjectName(QStringLiteral("account"));

        gridLayout->addWidget(account, 1, 1, 1, 1);

        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 1, 0, 1, 1);

        password = new QLineEdit(groupBox);
        password->setObjectName(QStringLiteral("password"));
        password->setEchoMode(QLineEdit::Password);

        gridLayout->addWidget(password, 2, 1, 1, 1);

        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));

        gridLayout->addWidget(label_2, 2, 0, 1, 1);

        buttonCancel = new QPushButton(groupBox);
        buttonCancel->setObjectName(QStringLiteral("buttonCancel"));

        gridLayout->addWidget(buttonCancel, 3, 0, 1, 1);

        buttonLogIn = new QPushButton(groupBox);
        buttonLogIn->setObjectName(QStringLiteral("buttonLogIn"));
        buttonLogIn->setDefault(true);

        gridLayout->addWidget(buttonLogIn, 3, 1, 1, 1);

        labelErrorMessage = new QLabel(groupBox);
        labelErrorMessage->setObjectName(QStringLiteral("labelErrorMessage"));

        gridLayout->addWidget(labelErrorMessage, 0, 0, 1, 2);


        verticalLayout->addWidget(groupBox);

        QWidget::setTabOrder(account, password);
        QWidget::setTabOrder(password, buttonLogIn);
        QWidget::setTabOrder(buttonLogIn, buttonCancel);

        retranslateUi(administrator_login);

        QMetaObject::connectSlotsByName(administrator_login);
    } // setupUi

    void retranslateUi(QDialog *administrator_login)
    {
        administrator_login->setWindowTitle(QApplication::translate("administrator_login", "Login", 0));
        groupBox->setTitle(QApplication::translate("administrator_login", "Enter your Login Credentials", 0));
        label->setText(QApplication::translate("administrator_login", "Account:", 0));
        label_2->setText(QApplication::translate("administrator_login", "Password:", 0));
        buttonCancel->setText(QApplication::translate("administrator_login", "Cancel", 0));
        buttonLogIn->setText(QApplication::translate("administrator_login", "Log in", 0));
        labelErrorMessage->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class administrator_login: public Ui_administrator_login {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADMINISTRATOR_LOGIN_H
