#include "SortedLists.h"

bool alphabetCheckFromAtoZ(Stadium const &a, Stadium const &b)
{
    return a.getTeamName().toLower() < b.getTeamName().toLower();
}

bool stadiumNameAlphabetCheckFromAtoZ(Stadium const &a, Stadium const &b)
{
    return a.getStadiumName().toLower() < b.getStadiumName().toLower();
}

bool seatingCapacityCheckFromSmallesttoLargest(Stadium const &a, Stadium const &b)
{
    return a.getSeatingCapacity() < b.getSeatingCapacity();
}

SortedLists::SortedLists()
{
    ReadFromFile("NFL Information.txt", myMap);
    myMap.getAllStadiums(mySortedList);
}

SortedLists::~SortedLists(){}

bool SortedLists::isEmpty() const
{
    return mySortedList.empty();
}

// byTeamName method
// this method creates a list of the NFL teams sorted by team name.
QVector<Stadium> SortedLists::byTeamName()
{
    qSort(mySortedList.begin(),mySortedList.end(),alphabetCheckFromAtoZ);
    return mySortedList;
}

// stadiumbyTeamName method
// this method creates a list of NFL stadiums and their corresponding team name sorted by team name.
QVector<Stadium> SortedLists::stadiumbyTeamName()
{
    QVector<Stadium> stadiumSortedList;
    stadiumSortedList = byTeamName();
    return stadiumSortedList;
}

// AFCbyTeamName method
// This method creates a list of American Football Conference teams sorted by team name.
QVector<Stadium> SortedLists::AFCbyTeamName()
{
    QVector<Stadium> tempList;

    QVector<Stadium>::iterator it;
    for(it = mySortedList.begin(); it < mySortedList.end(); it++)
    {
        if (it->getConference() == "American Football Conference")
        {
            tempList.push_back(*it);
        }
    }

    qSort(tempList.begin(),tempList.end(),alphabetCheckFromAtoZ);

    return tempList;
}

// NFCbyTeamName method
// This method creates a list of National Football Conference teams sorted by team name.
QVector<Stadium> SortedLists::NFCbyTeamName()
{
    QVector<Stadium> tempList;

    QVector<Stadium>::iterator it;
    for(it = mySortedList.begin(); it < mySortedList.end(); it++)
    {
        if (it->getConference() == "National Football Conference")
        {
            tempList.push_back(*it);
        }
    }

    qSort(tempList.begin(),tempList.end(),alphabetCheckFromAtoZ);

    return tempList;
}

// openTypebyStadiumName method
// This method creates a list of stadiums that have an “open” stadium roof type and
QVector<Stadium> SortedLists::openTypebyStadiumName()
{
    QVector<Stadium> tempList;

    QVector<Stadium>::iterator it;
    for(it = mySortedList.begin(); it < mySortedList.end(); it++)
    {
        if (it->getRoofType() == "Open")
        {
            tempList.push_back(*it);
        }
    }

    qSort(tempList.begin(),tempList.end(),stadiumNameAlphabetCheckFromAtoZ);

    return tempList;
}

// starPlayerbyTeamName method
/* This method creates a list of NFL star players and their corresponding team name .
 * sorted by team name */
QVector<Stadium> SortedLists::starPlayerbyTeamName()
{
    QVector<Stadium> starPlayerSortedList;
    starPlayerSortedList = byTeamName();
    return starPlayerSortedList;
}

// AllbySeatCap1 method
/* This method creates a list of NFL teams, their stadium names, their seating capacity,
 *  their corresponding location sorted by seating capacity.*/
QVector<Stadium> SortedLists::AllbySeatCap1()
{
    qSort(mySortedList.begin(),mySortedList.end(), seatingCapacityCheckFromSmallesttoLargest);
    return mySortedList;
}

// AllbySeatCap2
/* This method creates a list of NFL teams, their stadium names, their surface type,
 * their corresponding location sorted by seating capacity. */
QVector<Stadium> SortedLists::AllbySeatCap2()
{
    qSort(mySortedList.begin(),mySortedList.end(), seatingCapacityCheckFromSmallesttoLargest);
    return mySortedList;
}

QVector<Stadium> SortedLists::GetStadiumList() const
{
    return mySortedList;
}
