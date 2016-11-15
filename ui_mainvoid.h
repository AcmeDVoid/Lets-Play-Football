/********************************************************************************
** Form generated from reading UI file 'mainvoid.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINVOID_H
#define UI_MAINVOID_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainVoid
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QLabel *logo;
    QLabel *label_2;
    QPushButton *adminButton;
    QPushButton *userButton;
    QPushButton *closeButton;
    QPushButton *aboutUsButton;
    QWidget *page_2;
    QLabel *label;
    QPushButton *viewListButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QWidget *page_3;
    QVBoxLayout *verticalLayout_2;
    QLabel *label_3;
    QComboBox *comboBox;
    QTableWidget *tableWidget;
    QPushButton *pushButton;
    QPushButton *selectButton;
    QPushButton *goBackButton;
    QWidget *page_4;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainVoid)
    {
        if (MainVoid->objectName().isEmpty())
            MainVoid->setObjectName(QStringLiteral("MainVoid"));
        MainVoid->resize(849, 542);
        MainVoid->setUnifiedTitleAndToolBarOnMac(false);
        centralwidget = new QWidget(MainVoid);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayout = new QVBoxLayout(centralwidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        stackedWidget = new QStackedWidget(centralwidget);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        page = new QWidget();
        page->setObjectName(QStringLiteral("page"));
        logo = new QLabel(page);
        logo->setObjectName(QStringLiteral("logo"));
        logo->setGeometry(QRect(10, 10, 821, 501));
        logo->setFrameShape(QFrame::Box);
        logo->setPixmap(QPixmap(QString::fromUtf8(":/image/image/Let's play football !!!.jpg")));
        label_2 = new QLabel(page);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(109, -10, 621, 151));
        QFont font;
        font.setFamily(QStringLiteral("Times New Roman"));
        font.setPointSize(40);
        font.setBold(true);
        font.setWeight(75);
        label_2->setFont(font);
        adminButton = new QPushButton(page);
        adminButton->setObjectName(QStringLiteral("adminButton"));
        adminButton->setGeometry(QRect(50, 340, 151, 51));
        userButton = new QPushButton(page);
        userButton->setObjectName(QStringLiteral("userButton"));
        userButton->setGeometry(QRect(250, 362, 151, 51));
        closeButton = new QPushButton(page);
        closeButton->setObjectName(QStringLiteral("closeButton"));
        closeButton->setGeometry(QRect(649, 418, 151, 51));
        aboutUsButton = new QPushButton(page);
        aboutUsButton->setObjectName(QStringLiteral("aboutUsButton"));
        aboutUsButton->setGeometry(QRect(450, 390, 151, 51));
        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName(QStringLiteral("page_2"));
        label = new QLabel(page_2);
        label->setObjectName(QStringLiteral("label"));
        label->setEnabled(true);
        label->setGeometry(QRect(14, 40, 621, 400));
        QSizePolicy sizePolicy(QSizePolicy::Maximum, QSizePolicy::Maximum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(label->sizePolicy().hasHeightForWidth());
        label->setSizePolicy(sizePolicy);
        label->setBaseSize(QSize(0, 0));
        label->setPixmap(QPixmap(QString::fromUtf8(":/image/image/random ball.jpg")));
        viewListButton = new QPushButton(page_2);
        viewListButton->setObjectName(QStringLiteral("viewListButton"));
        viewListButton->setGeometry(QRect(420, 60, 141, 51));
        pushButton_2 = new QPushButton(page_2);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(420, 160, 141, 51));
        pushButton_3 = new QPushButton(page_2);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setGeometry(QRect(420, 260, 141, 51));
        pushButton_4 = new QPushButton(page_2);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setGeometry(QRect(420, 360, 141, 51));
        stackedWidget->addWidget(page_2);
        page_3 = new QWidget();
        page_3->setObjectName(QStringLiteral("page_3"));
        verticalLayout_2 = new QVBoxLayout(page_3);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        label_3 = new QLabel(page_3);
        label_3->setObjectName(QStringLiteral("label_3"));
        QFont font1;
        font1.setPointSize(8);
        label_3->setFont(font1);

        verticalLayout_2->addWidget(label_3);

        comboBox = new QComboBox(page_3);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout_2->addWidget(comboBox);

        tableWidget = new QTableWidget(page_3);
        tableWidget->setObjectName(QStringLiteral("tableWidget"));

        verticalLayout_2->addWidget(tableWidget);

        pushButton = new QPushButton(page_3);
        pushButton->setObjectName(QStringLiteral("pushButton"));

        verticalLayout_2->addWidget(pushButton);

        selectButton = new QPushButton(page_3);
        selectButton->setObjectName(QStringLiteral("selectButton"));

        verticalLayout_2->addWidget(selectButton);

        goBackButton = new QPushButton(page_3);
        goBackButton->setObjectName(QStringLiteral("goBackButton"));

        verticalLayout_2->addWidget(goBackButton);

        stackedWidget->addWidget(page_3);
        page_4 = new QWidget();
        page_4->setObjectName(QStringLiteral("page_4"));
        stackedWidget->addWidget(page_4);

        verticalLayout->addWidget(stackedWidget);

        MainVoid->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainVoid);
        statusbar->setObjectName(QStringLiteral("statusbar"));
        MainVoid->setStatusBar(statusbar);

        retranslateUi(MainVoid);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainVoid);
    } // setupUi

    void retranslateUi(QMainWindow *MainVoid)
    {
        MainVoid->setWindowTitle(QApplication::translate("MainVoid", "Footbal Mania", 0));
        logo->setText(QString());
        label_2->setText(QApplication::translate("MainVoid", "<html><head/><body><p align=\"justify\"><span style=\" color:#ffff7f;\">Welcome to Football Mania</span></p></body></html>", 0));
        adminButton->setText(QApplication::translate("MainVoid", "Administrator Access", 0));
        userButton->setText(QApplication::translate("MainVoid", "User Access", 0));
        closeButton->setText(QApplication::translate("MainVoid", "Close", 0));
        aboutUsButton->setText(QApplication::translate("MainVoid", "About Us", 0));
        label->setText(QString());
        viewListButton->setText(QApplication::translate("MainVoid", "View Lists", 0));
        pushButton_2->setText(QApplication::translate("MainVoid", "View My Favorite Team", 0));
        pushButton_3->setText(QApplication::translate("MainVoid", "Button 3", 0));
        pushButton_4->setText(QApplication::translate("MainVoid", "Back", 0));
        label_3->setText(QApplication::translate("MainVoid", "View the list of ", 0));
        pushButton->setText(QApplication::translate("MainVoid", "Total Seating Capacity", 0));
        selectButton->setText(QApplication::translate("MainVoid", "Select", 0));
        goBackButton->setText(QApplication::translate("MainVoid", "Go Back", 0));
    } // retranslateUi

};

namespace Ui {
    class MainVoid: public Ui_MainVoid {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINVOID_H
