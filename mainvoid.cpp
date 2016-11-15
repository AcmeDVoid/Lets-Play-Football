#include "mainvoid.h"
#include "ui_mainvoid.h"

MainVoid::MainVoid(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainVoid)
{
    ui->setupUi(this);
    ui->comboBox->addItem(" ");
    ui->comboBox->addItem("NFL teams sorted by team name");
    ui->comboBox->addItem("NFL stadiums and their corresponding team name sorted by team name");
    ui->comboBox->addItem("American Football Conference teams sorted by team name");
    ui->comboBox->addItem("National Football Conference teams sorted by team name.");
    ui->comboBox->addItem("Stadiums that have an “open” stadium roof type and their corresponding team name sorted by stadium name");
    ui->comboBox->addItem("NFL star players and their corresponding team name sorted by team name");
    ui->comboBox->addItem("NFL teams, their stadium names, their seating capacity, their corresponding location sorted by seating capacity");
    ui->comboBox->addItem("NFL teams, their stadium names, their surface type, and their corresponding location sorted by seating capacity");

}

MainVoid::~MainVoid()
{
    delete ui;
}

void MainVoid::on_userButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainVoid::on_closeButton_clicked()
{
    connect(ui->closeButton,SIGNAL(clicked()), this, SLOT(close()));
}

void MainVoid::on_viewListButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainVoid::on_adminButton_clicked()
{
    Log_In logIn;
    logIn.setModal(true);
    logIn.exec();
}

void MainVoid::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}

void MainVoid::on_importFileButton_clicked()
{
    SortedLists mySortedList;

    if (!mySortedList.isEmpty())
    {
        QMessageBox::information(this,"Information", "Successful!!!","OK");


    }
    else
    {
        QMessageBox::warning(this,"Information","Empty, Unknown or Missing File", "OK");
    }
}

void MainVoid::on_goBackButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}

void MainVoid::on_selectButton_clicked()
{
    SortedLists mySortedList;

    QVector<Stadium> myStadiumList;

    QVector<Stadium>::iterator it;

    if (ui->comboBox->currentIndex() != 0)
    {
        // Clears table before get new info
        int rowCount = ui->tableWidget->rowCount();
        for(int i = 0; i < rowCount; i++)
        {
            ui->tableWidget->removeRow(0);
        }

        int colCount = ui->tableWidget->columnCount();

        for(int i = 0; i < colCount; i++)
        {
            ui->tableWidget->removeColumn(0);
        }
    }

    // List of the NFL teams sorted by team name.
    if (ui->comboBox->currentIndex() == 1)
    {
        myStadiumList = mySortedList.byTeamName();

        // Create the column header for the information
        ui->tableWidget->insertColumn(0);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));

        int counter = 0;

        // Fill the information
        for(it = myStadiumList.begin(); it < myStadiumList.end();it++)
        {
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter,0,new QTableWidgetItem(it->getTeamName()));
            counter++;
        }
    }
    // List of NFL stadiums and their corresponding team name sorted by team name.
    else if (ui->comboBox->currentIndex() == 2)
    {
        myStadiumList = mySortedList.byTeamName();
        // Create the column header for the information
        ui->tableWidget->insertColumn(0);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadium Name"));
        ui->tableWidget->insertColumn(1);
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Team Name"));

        int counter = 0;

        // Fill the information
        for(it = myStadiumList.begin(); it < myStadiumList.end();it++)
        {
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter,0,new QTableWidgetItem(it->getStadiumName()));
            ui->tableWidget->setItem(counter,1,new QTableWidgetItem(it->getTeamName()));
            counter++;
        }
    }

    // List of American Football Conference teams sorted by team name.
    else if (ui->comboBox->currentIndex() == 3)
    {
        myStadiumList = mySortedList.AFCbyTeamName();
        // Create the column header for the information
        ui->tableWidget->insertColumn(0);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->tableWidget->insertColumn(1);
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Conference"));

        int counter = 0;

        // Fill the information
        for(it = myStadiumList.begin(); it < myStadiumList.end();it++)
        {
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter,0,new QTableWidgetItem(it->getTeamName()));
            ui->tableWidget->setItem(counter,1,new QTableWidgetItem(it->getConference()));
            counter++;
        }
    }

    // List of National Football Conference teams sorted by team name
    else if(ui->comboBox->currentIndex() == 4)
    {
        myStadiumList = mySortedList.NFCbyTeamName();
        // Create the column header for the information
        ui->tableWidget->insertColumn(0);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->tableWidget->insertColumn(1);
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Conference"));

        int counter = 0;

        // Fill the information
        for(it = myStadiumList.begin(); it < myStadiumList.end();it++)
        {
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter,0,new QTableWidgetItem(it->getTeamName()));
            ui->tableWidget->setItem(counter,1,new QTableWidgetItem(it->getConference()));
            counter++;
        }

    }

    /* List of stadiums that have an “open” stadium roof type and their corresponding
     * team name sorted by stadium name. */
    else if (ui->comboBox->currentIndex() == 5)
    {
        myStadiumList = mySortedList.openTypebyStadiumName();

        // Create the column header for the information
        ui->tableWidget->insertColumn(0);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Stadium Name"));
        ui->tableWidget->insertColumn(1);
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Team Name"));
        ui->tableWidget->insertColumn(2);
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Stadium Roof Type"));

        int counter = 0;

        // Fill the information
        for(it = myStadiumList.begin(); it < myStadiumList.end();it++)
        {
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter,0,new QTableWidgetItem(it->getStadiumName()));
            ui->tableWidget->setItem(counter,1,new QTableWidgetItem(it->getTeamName()));
            ui->tableWidget->setItem(counter,2,new QTableWidgetItem(it->getRoofType()));
            counter++;
        }

    }
    // List of NFL star players and their corresponding team name sorted by team name.
    else if (ui->comboBox->currentIndex() == 6)
    {
        myStadiumList = mySortedList.starPlayerbyTeamName();

        // Create the column header for the information
        ui->tableWidget->insertColumn(0);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->tableWidget->insertColumn(1);
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Star Player"));

        int counter = 0;

        // Fill the information
        for(it = myStadiumList.begin(); it < myStadiumList.end();it++)
        {
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter,0,new QTableWidgetItem(it->getTeamName()));
            ui->tableWidget->setItem(counter,1,new QTableWidgetItem(it->getStarPlayer()));
            counter++;
        }
    }
    /* List of NFL teams, their stadium names, their seating capacity, their corresponding
     * location sorted by seating capacity. */
    else if (ui->comboBox->currentIndex() == 7)
    {
        myStadiumList = mySortedList.AllbySeatCap1();

        // Create the column header for the information
        ui->tableWidget->insertColumn(0);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->tableWidget->insertColumn(1);
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Stadium Name"));
        ui->tableWidget->insertColumn(2);
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Seating Capacity"));
        ui->tableWidget->insertColumn(3);
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Location"));

        int counter = 0;

        // Fill the information
        for(it = myStadiumList.begin(); it < myStadiumList.end();it++)
        {
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter,0,new QTableWidgetItem(it->getTeamName()));
            ui->tableWidget->setItem(counter,1,new QTableWidgetItem(it->getStadiumName()));
            ui->tableWidget->setItem(counter,2,new QTableWidgetItem(QString::number(it->getSeatingCapacity())));
            ui->tableWidget->setItem(counter,3,new QTableWidgetItem(it->getLocation()));
            counter++;
        }
    }

    /* List of NFL teams, their stadium names, their surface type, and their corresponding
     *  location sorted by seating capacity. */
    else if (ui->comboBox->currentIndex() == 8)
    {
        myStadiumList = mySortedList.AllbySeatCap2();

        // Create the column header for the information
        ui->tableWidget->insertColumn(0);
        ui->tableWidget->setHorizontalHeaderItem(0, new QTableWidgetItem("Team Name"));
        ui->tableWidget->insertColumn(1);
        ui->tableWidget->setHorizontalHeaderItem(1, new QTableWidgetItem("Stadium Name"));
        ui->tableWidget->insertColumn(2);
        ui->tableWidget->setHorizontalHeaderItem(2, new QTableWidgetItem("Seating Capacity"));
        ui->tableWidget->insertColumn(3);
        ui->tableWidget->setHorizontalHeaderItem(3, new QTableWidgetItem("Location"));
        ui->tableWidget->insertColumn(4);
        ui->tableWidget->setHorizontalHeaderItem(4, new QTableWidgetItem("Surface Type"));

        int counter = 0;

        // Fill the information
        for(it = myStadiumList.begin(); it < myStadiumList.end();it++)
        {
            ui->tableWidget->insertRow(counter);
            ui->tableWidget->setItem(counter,0,new QTableWidgetItem(it->getTeamName()));
            ui->tableWidget->setItem(counter,1,new QTableWidgetItem(it->getStadiumName()));
            ui->tableWidget->setItem(counter,2,new QTableWidgetItem(QString::number(it->getSeatingCapacity())));
            ui->tableWidget->setItem(counter,3,new QTableWidgetItem(it->getLocation()));
            ui->tableWidget->setItem(counter,4,new QTableWidgetItem(it->getSurfaceType()));
            counter++;
        }

    }
    else
    {
        // Clears table before get new info
        int rowCount = ui->tableWidget->rowCount();
        for(int i = 0; i < rowCount; i++)
        {
            ui->tableWidget->removeRow(0);
        }

        int colCount = ui->tableWidget->columnCount();
        for(int i = 0; i < colCount; i++)
        {
            ui->tableWidget->removeColumn(0);
        }

        QMessageBox::warning(this,"Error","Please select one type of list","OK");
    }
}

void MainVoid::on_aboutUsButton_clicked()
{
    QMessageBox::about(this,"About Us", "<h4><font color=red>Saddleback College"
                                        "</font><br><font color=blue>Fall 2016"
                                        "</font><br><font color=green>CS1D Final "
                                        "Project</font><br>Made by team: "
                                        "<font color=#996600>The Brogrammer</font></h4>");
}

void MainVoid::on_pushButton_clicked()
{
    StadiumList myMap;

    ReadFromFile("NFL Information.txt", myMap);

    QMessageBox::information(this, "Detail", "Total Seating Capacity is " +
                             QString::number(myMap.getTotalSeatingCapacity(),'f',0),"OK");
}

void MainVoid::on_pushButton_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}
