#include "SortedLists.h"

bool alphabetCheckFromAtoZ(Stadium const &a, Stadium const &b)
{
    return a.getTeamName() < b.getTeamName();
}

SortedLists::SortedLists()
{

    ReadFromFile("NFL Information.txt", mySortedList);
}

// byTeamName method
// this method creates a list of the NFL teams sorted by team name.
StadiumList SortedLists::byTeamName()
{
    qSort(mySortedList.begin(),mySortedList.end(),alphabetCheckFromAtoZ);

    return mySortedList;
}

// stadiumbyTeamName method
// this method creates a list of NFL stadiums and their corresponding team name sorted by team name.
StadiumList SortedLists::stadiumbyTeamName(QVector <Stadium*> StadiumList, QString conference)
{

}

// AFCbyTeamName method
// This method creates a list of American Football Conference teams sorted by team name.
StadiumList SortedLists::AFCbyTeamName(QVector <Stadium*> StadiumList, QString conference)
{

}

// NFCbyTeamName method
// This method creates a list of National Football Conference teams sorted by team name.
StadiumList SortedLists::NFCbyTeamName(QVector <Stadium*> StadiumList, QString conference)
{

}

// openTypebyStadiumName method
// This method creates a list of stadiums that have an “open” stadium roof type and
StadiumList SortedLists::openTypebyStadiumName(QVector <Stadium*> StadiumList, QString type)
{

}

// starPlayerbyTeamName method
/* This method creates a list of NFL star players and their corresponding team name .
 * sorted by team name */
StadiumList SortedLists::starPlayerbyTeamName(QVector <Stadium*> StadiumList, QString playerName)
{

}

// AllbySeatCap1 method
/* This method creates a list of NFL teams, their stadium names, their seating capacity,
 *  their corresponding location sorted by seating capacity.*/
StadiumList SortedLists::AllbySeatCap1(QVector <Stadium*> StadiumList)
{

}

// AllbySeatCap2
/* This method creates a list of NFL teams, their stadium names, their surface type,
 * their corresponding location sorted by seating capacity. */
StadiumList SortedLists::AllbySeatCap2(QVector <Stadium*> StadiumList)
{

}
