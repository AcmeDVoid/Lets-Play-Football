#ifndef SORTEDLISTS_H
#define SORTEDLISTS_H

#include "MyHeader.h"

class SortedLists
{
    private:
        StadiumList myMap;                  // The map
        QVector<Stadium> myStadiumList;      // List of stadium

    public:
        // Default constructor
        // This contructor instantiates an object
        SortedLists();

        // Destructor
        // This destructor terminates the object when out of scope
        ~SortedLists();

        // byTeamName method
        // this method creates a list of the NFL teams sorted by team name.
        QVector<Stadium> byTeamName();

        // stadiumbyTeamName method
        // this method creates a list of NFL stadiums and their corresponding team name sorted by team name.
        QVector<Stadium> stadiumbyTeamName();

        // AFCbyTeamName method
        // This method creates a list of American Football Conference teams sorted by team name.
        QVector<Stadium> AFCbyTeamName();

        // NFCbyTeamName method
        // This method creates a list of National Football Conference teams sorted by team name.
        QVector<Stadium> NFCbyTeamName();

        // openTypebyStadiumName method
        // This method creates a list of stadiums that have an “open” stadium roof type and
        QVector<Stadium> openTypebyStadiumName();

        // starPlayerbyTeamName method
        /* This method creates a list of NFL star players and their corresponding team name .
         * sorted by team name */
        QVector<Stadium> starPlayerbyTeamName();

        // AllbySeatCap1 method
        /* This method creates a list of NFL teams, their stadium names, their seating capacity,
         *  their corresponding location sorted by seating capacity.*/
        QVector<Stadium> AllbySeatCap1();

        // AllbySeatCap2
        /* This method creates a list of NFL teams, their stadium names, their surface type,
         * their corresponding location sorted by seating capacity. */
        QVector<Stadium> AllbySeatCap2();

        // GetStadiumList method
        // This method return the lists of stadiums
        QVector<Stadium> GetStadiumList() const;

        // isEmpty method
        // This methods check if the list is empty
        bool isEmpty() const;

};

#endif // SORTEDLISTS_H
