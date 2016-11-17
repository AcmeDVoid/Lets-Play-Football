#include "SortedLists.h"

// alphabetCheckFromAtoZ functor
// This functor checks the alphabet order based on the team name
// From A to Z
bool alphabetCheckFromAtoZ(Stadium const &a, Stadium const &b)
{
    return a.getTeamName().toLower() < b.getTeamName().toLower();
}

// stadiumNameAlphabetCheckFromAtoZ functor
// This functor checks the alphabet order based on the stadium name
// From A to Z
bool stadiumNameAlphabetCheckFromAtoZ(Stadium const &a, Stadium const &b)
{
    return a.getStadiumName().toLower() < b.getStadiumName().toLower();
}

// seatingCapacityCheckFromSmallesttoLargest functor
// This functor checks the order based on the seating capacity
// From smallest to largest
bool seatingCapacityCheckFromSmallesttoLargest(Stadium const &a, Stadium const &b)
{
    return a.getSeatingCapacity() < b.getSeatingCapacity();
}

// Default constructor
// This contructor instantiates an object
SortedLists::SortedLists()
{
    ReadFromFile("NFL Information.txt", myMap);
    myMap.getAllStadiums(myStadiumList);
}

// Destructor
// This destructor terminates the object when out of scope
SortedLists::~SortedLists(){}

// isEmpty method
// This methods check if the list is empty
bool SortedLists::isEmpty() const
{
    return myStadiumList.empty();
}

// byTeamName method
// this method creates a list of the NFL teams sorted by team name.
QVector<Stadium> SortedLists::byTeamName()
{
    // Using qSort to sort the list
    // Use alphabetCheckFromAtoZ as the comparator
    qSort(myStadiumList.begin(),myStadiumList.end(),alphabetCheckFromAtoZ);

    return myStadiumList;
}

// stadiumbyTeamName method
// this method creates a list of NFL stadiums and their corresponding team name sorted by team name.
QVector<Stadium> SortedLists::stadiumbyTeamName()
{
    // Sorting the stadium based on the name
    QVector<Stadium> stadiumSortedList;
    stadiumSortedList = byTeamName();
    return stadiumSortedList;
}

// AFCbyTeamName method
// This method creates a list of American Football Conference teams sorted by team name.
QVector<Stadium> SortedLists::AFCbyTeamName()
{
    // Create a tempList and an iterator for the list
    QVector<Stadium> tempList;
    QVector<Stadium>::iterator it;

    // Check if stadium has the matching conference
    // If yes, push into the list
    for(it = myStadiumList.begin(); it < myStadiumList.end(); it++)
    {
        if (it->getConference() == "American Football Conference")
        {
            tempList.push_back(*it);
        }
    }

    // Using qSort to sort the list
    // Use alphabetCheckFromAtoZ as the comparator
    qSort(tempList.begin(),tempList.end(),alphabetCheckFromAtoZ);

    return tempList;
}

// NFCbyTeamName method
// This method creates a list of National Football Conference teams sorted by team name.
QVector<Stadium> SortedLists::NFCbyTeamName()
{
    // Create a tempList and an iterator for the list
    QVector<Stadium> tempList;
    QVector<Stadium>::iterator it;

    // Check if stadium has the matching conference
    // If yes, push into the list
    for(it = myStadiumList.begin(); it < myStadiumList.end(); it++)
    {
        if (it->getConference() == "National Football Conference")
        {
            tempList.push_back(*it);
        }
    }

    // Using qSort to sort the list
    // Use alphabetCheckFromAtoZ as the comparator
    qSort(tempList.begin(),tempList.end(),alphabetCheckFromAtoZ);

    return tempList;
}

// openTypebyStadiumName method
// This method creates a list of stadiums that have an “open” stadium roof type and
QVector<Stadium> SortedLists::openTypebyStadiumName()
{
    // Create a tempList and an iterator for the list
    QVector<Stadium> tempList;
    QVector<Stadium>::iterator it;

    // Check if stadium has the matching roof type
    // If yes, push into the list
    for(it = myStadiumList.begin(); it < myStadiumList.end(); it++)
    {
        if (it->getRoofType() == "Open")
        {
            tempList.push_back(*it);
        }
    }

    // Using qSort to sort the list
    // Use alphabetCheckFromAtoZ as the comparator
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
    // Using qSort to sort the list
    // Use seatingCapacityCheckFromSmallesttoLargest as the comparator
    qSort(myStadiumList.begin(),myStadiumList.end(), seatingCapacityCheckFromSmallesttoLargest);
    return myStadiumList;
}

// AllbySeatCap2
/* This method creates a list of NFL teams, their stadium names, their surface type,
 * their corresponding location sorted by seating capacity. */
QVector<Stadium> SortedLists::AllbySeatCap2()
{
    // Using qSort to sort the list
    // Use seatingCapacityCheckFromSmallesttoLargest as the comparator
    qSort(myStadiumList.begin(),myStadiumList.end(), seatingCapacityCheckFromSmallesttoLargest);
    return myStadiumList;
}

// GetStadiumList method
// This method return the lists of stadiums
QVector<Stadium> SortedLists::GetStadiumList() const
{
    return myStadiumList;
}
