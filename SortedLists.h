#ifndef SORTEDLISTS_H
#define SORTEDLISTS_H

#include <QVector>
#include <QString>
#include <Stadium.h>

class SortedLists
{
    private:
        QVector <Stadium*> StadiumList;

    public:
        SortedLists(QVector <Stadium*> StadiumList);

        ~SortedLists();

        // byTeamName method
        // this method creates a list of the NFL teams sorted by team name.
        QVector <Stadium*> byTeamName(QVector <Stadium*> StadiumList);

        // stadiumbyTeamName method
        // this method creates a list of NFL stadiums and their corresponding team name sorted by team name.
        QVector <Stadium*> stadiumbyTeamName(QVector <Stadium*> StadiumList, QString conference);

        // AFCbyTeamName method
        // This method creates a list of American Football Conference teams sorted by team name.
        QVector <Stadium*> AFCbyTeamName(QVector <Stadium*> StadiumList, QString conference);

        // NFCbyTeamName method
        // This method creates a list of National Football Conference teams sorted by team name.
        QVector <Stadium*> NFCbyTeamName(QVector <Stadium*> StadiumList, QString conference);

        // openTypebyStadiumName method
        // This method creates a list of stadiums that have an “open” stadium roof type and
        QVector <Stadium*> openTypebyStadiumName(QVector <Stadium*> StadiumList, QString type);

        // starPlayerbyTeamName method
        /* This method creates a list of NFL star players and their corresponding team name .
         * sorted by team name */
        QVector <Stadium*> starPlayerbyTeamName(QVector <Stadium*> StadiumList, QString playerName);

        // AllbySeatCap1 method
        /* This method creates a list of NFL teams, their stadium names, their seating capacity,
         *  their corresponding location sorted by seating capacity.*/
        QVector <Stadium*> AllbySeatCap1(QVector <Stadium*> StadiumList);

        // AllbySeatCap2
        /* This method creates a list of NFL teams, their stadium names, their surface type,
         * their corresponding location sorted by seating capacity. */
        QVector <Stadium*> AllbySeatCap2(QVector <Stadium*> StadiumList);

};

#endif // SORTEDLISTS_H
