#include "Stadium.h"

Stadium::Stadium(){}

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

Stadium::~Stadium(){}

void Stadium::setTeamName(QString name)
{
    this->teamName = name;
}

void Stadium::setStadiumName(QString sName)
{
    this->stadiumName = sName;
}

void Stadium::setSeatingCapacity(double num)
{
    this->seatingCapacity = num;
}

void Stadium::setLocation(QString newLocation)
{
    this->location = newLocation;
}

void Stadium::setConference(QString newConf)
{
    this->conference = newConf;
}

void Stadium::setSurfaceType(QString type)
{
    this->surfaceType = type;
}

void Stadium::setRootType(QString roof)
{
    this->roofType = roof;
}

void Stadium::setStarPlayer(QString playerName)
{
    this->starPlayer = playerName;
}

QString Stadium::getTeamName() const
{
    return teamName;
}

QString Stadium::getStadiumName() const
{
    return stadiumName;
}

double Stadium::getSeatingCapacity() const
{
    return seatingCapacity;
}

QString Stadium::getLocation() const
{
    return location;
}

QString Stadium::getConference() const
{
    return conference;
}

QString Stadium::getSurfaceType() const
{
    return surfaceType;
}

QString Stadium::getRoofType() const
{
    return roofType;
}

QString Stadium::getStarPlayer() const
{
    return starPlayer;
}

// Overloading assignment operator
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
