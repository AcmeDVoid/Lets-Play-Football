#include "Stadium.h"

// Default constructor
// This contructor instantiates the object
Stadium::Stadium(){}

// User-defined constructor
// This contructor instantiates the object with the user-defined parameter
Stadium::Stadium(QString name, QString sName, double num, QString newLocation, QString newConf, QString type,
                 QString roof, QString playerName)
{
    this->teamName = name;
    this->stadiumName = sName;
    this->seatingCapacity = num;
    this->location = newLocation;
    this->conference = newConf;
    this->surfaceType = type;
    this->roofType = roof;
    this->starPlayer = playerName;
}

// Destructor
// This contructor eleminates the object when it goes out of scope
Stadium::~Stadium(){}

// setTeamName method
// This method set the team name
void Stadium::setTeamName(QString name)
{
    this->teamName = name;
}

// setTeamName method
// This method set the stadium name
void Stadium::setStadiumName(QString sName)
{
    this->stadiumName = sName;
}

// setSeatingCapacity method
// This method set the stadium seating capacity
void Stadium::setSeatingCapacity(double num)
{
    this->seatingCapacity = num;
}

// setTeamName method
// This method set the stadium location
void Stadium::setLocation(QString newLocation)
{
    this->location = newLocation;
}

// setConference method
// This method set the team conference
void Stadium::setConference(QString newConf)
{
    this->conference = newConf;
}

// setSurfaceType method
// This method set the stadium surface type
void Stadium::setSurfaceType(QString type)
{
    this->surfaceType = type;
}

// setRootType method
// This method set the stadium roof type
void Stadium::setRootType(QString roof)
{
    this->roofType = roof;
}

// setStarPlayer method
// This method set the team start player
void Stadium::setStarPlayer(QString playerName)
{
    this->starPlayer = playerName;
}

// getTeamName method
// This method get the team name
QString Stadium::getTeamName() const
{
    return teamName;
}

// getStadiumName method
// This method get the stadium name
QString Stadium::getStadiumName() const
{
    return stadiumName;
}

// getSeatingCapacity method
// This method get the stadium seating capacity
double Stadium::getSeatingCapacity() const
{
    return seatingCapacity;
}

// getLocation method
// This method get the stadium location
QString Stadium::getLocation() const
{
    return location;
}

// getConference method
// This method get the team conference
QString Stadium::getConference() const
{
    return conference;
}

// getSurfaceType method
// This method get the tstadium surface type
QString Stadium::getSurfaceType() const
{
    return surfaceType;
}

// getRoofType method
// This method get the stadium roof type
QString Stadium::getRoofType() const
{
    return roofType;
}

// getStarPlayer method
// This method get the team star player
QString Stadium::getStarPlayer() const
{
    return starPlayer;
}

// Overload assignment operator
// This method overload the "=" operator between 2 object Stadium type
Stadium& Stadium::operator= (Stadium const &rhs)
{
    teamName = rhs.getTeamName();
    stadiumName = rhs.getStadiumName();
    seatingCapacity = rhs.getSeatingCapacity();
    location = rhs.getLocation();
    conference = rhs.getConference();
    surfaceType = rhs.getSurfaceType();
    roofType = rhs.getRoofType();
    starPlayer = rhs.getStarPlayer();
    return *this;
}
