/********************************************************************************
** Form generated from reading UI file 'log_in.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOG_IN_H
#define UI_LOG_IN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Log_In
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *passwordLine;
    QPushButton *signInButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *Log_In)
    {
        if (Log_In->objectName().isEmpty())
            Log_In->setObjectName(QStringLiteral("Log_In"));
        Log_In->resize(400, 300);
        label = new QLabel(Log_In);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 40, 151, 21));
        label_2 = new QLabel(Log_In);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(70, 80, 251, 31));
        passwordLine = new QLineEdit(Log_In);
        passwordLine->setObjectName(QStringLiteral("passwordLine"));
        passwordLine->setGeometry(QRect(90, 150, 201, 21));
        passwordLine->setEchoMode(QLineEdit::Password);
        signInButton = new QPushButton(Log_In);
        signInButton->setObjectName(QStringLiteral("signInButton"));
        signInButton->setGeometry(QRect(100, 230, 75, 23));
        cancelButton = new QPushButton(Log_In);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));
        cancelButton->setGeometry(QRect(200, 230, 75, 23));

        retranslateUi(Log_In);

        QMetaObject::connectSlotsByName(Log_In);
    } // setupUi

    void retranslateUi(QDialog *Log_In)
    {
        Log_In->setWindowTitle(QApplication::translate("Log_In", "Dialog", 0));
        label->setText(QApplication::translate("Log_In", "Administration Page", 0));
        label_2->setText(QApplication::translate("Log_In", "You must input the password in order to proceed", 0));
        passwordLine->setPlaceholderText(QApplication::translate("Log_In", "Enter the password", 0));
        signInButton->setText(QApplication::translate("Log_In", "Sign In", 0));
        cancelButton->setText(QApplication::translate("Log_In", "Cancel", 0));
    } // retranslateUi

};

namespace Ui {
    class Log_In: public Ui_Log_In {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOG_IN_H
