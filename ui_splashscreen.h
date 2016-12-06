/********************************************************************************
** Form generated from reading UI file 'splashscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SPLASHSCREEN_H
#define UI_SPLASHSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_splashscreen
{
public:
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_3;
    QLabel *splash_pic;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *slpash_text;
    QDialogButtonBox *buttonBox;

    void setupUi(QDialog *splashscreen)
    {
        if (splashscreen->objectName().isEmpty())
            splashscreen->setObjectName(QStringLiteral("splashscreen"));
        splashscreen->resize(789, 346);
        QIcon icon;
        icon.addFile(QStringLiteral(":/logo.jpg"), QSize(), QIcon::Normal, QIcon::Off);
        splashscreen->setWindowIcon(icon);
        verticalLayout = new QVBoxLayout(splashscreen);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox = new QGroupBox(splashscreen);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_3 = new QVBoxLayout(groupBox);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        splash_pic = new QLabel(groupBox);
        splash_pic->setObjectName(QStringLiteral("splash_pic"));
        splash_pic->setMinimumSize(QSize(751, 202));
        splash_pic->setPixmap(QPixmap(QString::fromUtf8(":/logo.jpg")));
        splash_pic->setScaledContents(true);

        verticalLayout_3->addWidget(splash_pic);


        verticalLayout->addWidget(groupBox);

        groupBox_2 = new QGroupBox(splashscreen);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setMaximumSize(QSize(16777215, 100));
        verticalLayout_2 = new QVBoxLayout(groupBox_2);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout_2->addWidget(label, 0, Qt::AlignHCenter);

        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout_2->addWidget(label_2, 0, Qt::AlignHCenter);

        slpash_text = new QLabel(groupBox_2);
        slpash_text->setObjectName(QStringLiteral("slpash_text"));
        slpash_text->setMaximumSize(QSize(16777215, 150));
        slpash_text->setBaseSize(QSize(0, 0));

        verticalLayout_2->addWidget(slpash_text, 0, Qt::AlignHCenter);


        verticalLayout->addWidget(groupBox_2);

        buttonBox = new QDialogButtonBox(splashscreen);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        verticalLayout->addWidget(buttonBox);


        retranslateUi(splashscreen);
        QObject::connect(buttonBox, SIGNAL(accepted()), splashscreen, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), splashscreen, SLOT(reject()));

        QMetaObject::connectSlotsByName(splashscreen);
    } // setupUi

    void retranslateUi(QDialog *splashscreen)
    {
        splashscreen->setWindowTitle(QApplication::translate("splashscreen", "Football Stadium Project", 0));
        groupBox->setTitle(QString());
        splash_pic->setText(QString());
        groupBox_2->setTitle(QString());
        label->setText(QApplication::translate("splashscreen", "Football Stadiums Project", 0));
        label_2->setText(QApplication::translate("splashscreen", "CS1D: Data Structures", 0));
        slpash_text->setText(QApplication::translate("splashscreen", "Software Created by: Nhan Phan, John Zavala, Sina,  Kayvon", 0));
    } // retranslateUi

};

namespace Ui {
    class splashscreen: public Ui_splashscreen {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SPLASHSCREEN_H
