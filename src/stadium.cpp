#include "include/stadium.h"

/*************************************************************************
* Constructors & Destructors
*************************************************************************/
Stadium::Stadium(std::string newName, std::string newTeamName, std::string newStreetAddress, string newCityStateZip, std::string newPhoneNumber, std::string newTeamType, Date newDate, int newCapacity, std::string newSurface, std::string newTypology, std::string newStarPlayer)
{
    // set the values from the parameters
    stadiumName = newName;
    teamName = newTeamName;
    stadiumStreetAddress = newStreetAddress;
    stadiumCityStateZip = newCityStateZip;
    stadiumPhoneNumber = newPhoneNumber;
    leagueType = newTeamType;
    stadiumDateOpened = newDate;
    stadiumCapacity = newCapacity;
    stadiumSurface = newSurface;
    stadiumRevenue = 0.0;
    stadiumSalesCount = 0;
    stadiumTypology = newTypology;
    starPlayer = newStarPlayer;
}

// destructor
Stadium::~Stadium()
{

}

/*************************************************************************
* Mutators
*************************************************************************/
void Stadium::setTeam(string newTeamName)
{
    // set the team
    teamName = newTeamName;
}

void Stadium::addSouvenir(Souvenir newSouvenir)
{
    // insert the souvenir into the map
    souvenirMap.insert(std::make_pair(souvenirMap.size(), newSouvenir));
}

void Stadium::removeSouvenir(int index)
{
    // erase the souvenir at the index in the map
    souvenirMap.erase(index);
}

void Stadium::purchase(int index, int quantity)
{
    // pointer to souvenir
    Souvenir* souvenirPtr = souvenir(index);

    // add to the revenue the price times the quantity
    stadiumRevenue += souvenirPtr->price() * quantity;

    // add to the quantity
    stadiumSalesCount += quantity;
}

/*************************************************************************
* Accessors
*************************************************************************/
std::string Stadium::name() const
{
    return stadiumName;
}

std::string Stadium::team() const
{
    return teamName;
}

std::string Stadium::address() const
{
    std::ostringstream os;
    os << stadiumStreetAddress << " " << stadiumCityStateZip;

    return os.str();
}

std::string Stadium::streetAddress() const
{
    // return street address
    return stadiumStreetAddress;
}

std::string Stadium::cityStateZip() const
{
    // return city, state, zip
    return stadiumCityStateZip;
}

std::string Stadium::phoneNumber() const
{
    // return phone number
    return stadiumPhoneNumber;
}

std::string Stadium::type() const
{
    // return league type
    return leagueType;
}

Date Stadium::dateOpened() const
{
    // return the date opened
    return stadiumDateOpened;
}

int Stadium::capacity() const
{
    // return capacity
    return stadiumCapacity;
}

std::string Stadium::surface() const
{
    // return surface
    return stadiumSurface;
}

Souvenir *Stadium::souvenir(int index)
{
    // return a pointer to the souvenir at the index in the map
     return &souvenirMap.at(index);
}

std::map<int, Souvenir> *Stadium::souvenirList()
{
    // return the map of souvenirs
    return &souvenirMap;
}

double Stadium::revenue() const
{
    // return revenue
    return stadiumRevenue;
}

int Stadium::salesCount() const
{
    // return sales count
    return stadiumSalesCount;
}
std::string Stadium::typology() const{
    // return typology
    return stadiumTypology;
}
void Stadium::addRevenue(double rev){
    // add revenue to preexisting revenue
    this->stadiumRevenue += rev;
}
void Stadium::addSalesCount(int count){
    // add sales count to existing sales count
    this->stadiumSalesCount += count;
}

std::string Stadium::league(){
    // return the league type
    return this->leagueType;
}

void Stadium::updateStadium(std::string newStadiumName,
                   std::string newTeamName,
                   std::string newTypology,
                   Date newDateOpened,
                   int newStadiumCapacity,
                   std::string newLeagueType,
                   std::string newSurfaceType,
                   std::string newCity,
                   std::string newState,
                   std::string newZipCode,
                   std::string newStreetAddress,
                   std::string newPhoneNumber)
{
    // update stadium parameter values
    this->stadiumName = newStadiumName;
    this->teamName = newTeamName;
    this->stadiumTypology = newTypology;
    this->stadiumDateOpened = newDateOpened;
    this->stadiumCapacity = newStadiumCapacity;
    this->leagueType = newLeagueType;
    this->stadiumSurface = newSurfaceType;
    this->stadiumCityStateZip = newCity + ", " + newState + " " + newZipCode;
    this->stadiumStreetAddress = newStreetAddress;
    this->stadiumPhoneNumber = newPhoneNumber;

}

void Stadium::updateSouvenirList(std::map<int,Souvenir> newList){
    // replace the map with the parameter map
    this->souvenirMap = newList;
}
std::string Stadium::getStarPlayer() const
{
    return starPlayer;
}

