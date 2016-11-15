#ifndef INFORMATIONCLASS_H
#define INFORMATIONCLASS_H
#include <QString>

// This class creates a Stadium object
class Stadium
{
    private:
        QString teamName;               // Team name
        QString stadiumName;            // Stadium name
        double seatingCapacity;         // Stadium's Seating capacity
        QString location;               // Stadium's Location
        QString conference;             // The team's Conference
        QString surfaceType;            // Stadium Surface Type
        QString roofType;               // Stadium Roof Type
        QString starPlayer;             // The team's Star Player

    public:
        // Default constructor
        // This contructor instantiates the object
        Stadium();

        // User-defined constructor
        // This contructor instantiates the object with the user-defined parameter
        Stadium(QString name, QString sName,double num, QString newLocation, QString newConf, QString type,
                QString roof, QString playerName);

        // Destructor
        // This contructor eleminates the object when it goes out of scope
        ~Stadium();

        // setTeamName method
        // This method set the team name
        void setTeamName(QString name);

        // setTeamName method
        // This method set the stadium name
        void setStadiumName(QString sName);

        // setTeamName method
        // This method set the stadium seating capacity
        void setSeatingCapacity(double num);

        // setTeamName method
        // This method set the stadium location
        void setLocation(QString newLocation);

        // setTeamName method
        // This method set the team conference
        void setConference(QString newConf);

        // setTeamName method
        // This method set the stadium surface type
        void setSurfaceType(QString type);

        // setTeamName method
        // This method set the stadium roof type
        void setRootType(QString roof);

        // setTeamName method
        // This method set the team start player
        void setStarPlayer(QString playerName);

        // setTeamName method
        // This method get the team name
        QString getTeamName() const;

        // setTeamName method
        // This method get the stadium name
        QString getStadiumName() const;

        // setTeamName method
        // This method get the stadium seating capacity
        double getSeatingCapacity() const;

        // setTeamName method
        // This method get the stadium location
        QString getLocation() const;

        // setTeamName method
        // This method get the team conference
        QString getConference() const;

        // setTeamName method
        // This method get the tstadium surface type
        QString getSurfaceType() const;

        // setTeamName method
        // This method get the stadium roof type
        QString getRoofType() const;

        // setTeamName method
        // This method get the team star player
        QString getStarPlayer() const;

        // Overload assignment operator
        // This method overload the "=" operator between 2 object Stadium type
        Stadium& operator=(Stadium const &rhs);

};

#endif // INFORMATIONCLASS_H
