/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.3.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionAdmin_Log_In;
    QAction *actionAdd_Stadium;
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QGroupBox *groupBox_2;
    QVBoxLayout *verticalLayout;
    QLabel *plan_a_trip_pic;
    QPushButton *buttonViewStadiums;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_2;
    QLabel *main_pic;
    QPushButton *buttonViewTeams;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1201, 465);
        QIcon icon;
        icon.addFile(QStringLiteral(":/nfl icon.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        actionAdmin_Log_In = new QAction(MainWindow);
        actionAdmin_Log_In->setObjectName(QStringLiteral("actionAdmin_Log_In"));
        actionAdd_Stadium = new QAction(MainWindow);
        actionAdd_Stadium->setObjectName(QStringLiteral("actionAdd_Stadium"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        verticalLayout = new QVBoxLayout(groupBox_2);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        plan_a_trip_pic = new QLabel(groupBox_2);
        plan_a_trip_pic->setObjectName(QStringLiteral("plan_a_trip_pic"));
        plan_a_trip_pic->setMinimumSize(QSize(537, 357));
        plan_a_trip_pic->setPixmap(QPixmap(QString::fromUtf8(":/map.jpg")));
        plan_a_trip_pic->setScaledContents(true);

        verticalLayout->addWidget(plan_a_trip_pic);

        buttonViewStadiums = new QPushButton(groupBox_2);
        buttonViewStadiums->setObjectName(QStringLiteral("buttonViewStadiums"));

        verticalLayout->addWidget(buttonViewStadiums);


        horizontalLayout->addWidget(groupBox_2);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        verticalLayout_2 = new QVBoxLayout(groupBox);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        main_pic = new QLabel(groupBox);
        main_pic->setObjectName(QStringLiteral("main_pic"));
        main_pic->setPixmap(QPixmap(QString::fromUtf8(":/main.jpg")));
        main_pic->setScaledContents(false);

        verticalLayout_2->addWidget(main_pic);

        buttonViewTeams = new QPushButton(groupBox);
        buttonViewTeams->setObjectName(QStringLiteral("buttonViewTeams"));

        verticalLayout_2->addWidget(buttonViewTeams);


        horizontalLayout->addWidget(groupBox);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1201, 21));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        menuBar->addAction(menuFile->menuAction());
        menuFile->addAction(actionAdmin_Log_In);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "NFL: Stadium Trip Planner", 0));
        actionAdmin_Log_In->setText(QApplication::translate("MainWindow", "Admin Log In", 0));
        actionAdd_Stadium->setText(QApplication::translate("MainWindow", "Add Stadium", 0));
        groupBox_2->setTitle(QString());
        plan_a_trip_pic->setText(QString());
        buttonViewStadiums->setText(QApplication::translate("MainWindow", "View Stadiums", 0));
        groupBox->setTitle(QString());
        main_pic->setText(QString());
        buttonViewTeams->setText(QApplication::translate("MainWindow", "View Teams", 0));
        menuFile->setTitle(QApplication::translate("MainWindow", "File", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
