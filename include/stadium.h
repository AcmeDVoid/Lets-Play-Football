#ifndef STADIUM_H
#define STADIUM_H

#include <string>
#include "include/Date.h"
#include "include/souvenir.h"
#include <vector>
#include <sstream>
#include <map>

class Stadium {
public:
    /*************************************************************************
    * Constructors & Destructors
    *************************************************************************/

    /**
     * @brief Stadium - The constructor for the Stadium class.
     */
    Stadium(std::string newName, std::string newTeamName, std::string newStreetAddress,
            std::string newCityStateZip, std::string newPhoneNumber, std::string newTeamType,
            Date newDate, int newCapacity, std::string newSurface, std::string newTypologyType, std::string newStarPlayer);

    /**
     * @brief ~Stadium - The destructor for the Stadium class.
     */
    ~Stadium();

    /*************************************************************************
    * Mutators
    *************************************************************************/
    /**
     * @brief Set newTeamName as the team name for the stadium.
     */
    void setTeam(std::string newTeamName);

    /**
     * @brief addSouvenir: Adds a new souvenir to the souvenir list.
     * @param newSouvenir: The new souvenir to add to the souvenir list.
     */
    void addSouvenir(Souvenir newSouvenir);

    /**
     * @brief removeSouvenir: Removes the souvenir in the souvenir list as the
     * parameter index.
     * @param index: The index of the souvenir to remove from the souvenir list.
     */
    void removeSouvenir(int index);

    /**
     * @brief purchase: Increases the revenue of the stadium depending on the
     * souvenir bought and its quantity. Revenus is increased by the price of the
     * souvenir multiplied by its quantity.
     * @param index: The index of the souvenir in the souvenir list to be bought.
     * @param quantity: The amount of the souvenir to be bought.
     */
    void purchase(int index, int quantity);

    /*************************************************************************
    * Accessors
    *************************************************************************/
    /**
     * @return Returns the name of the stadium as a string.
     */
    std::string name() const;

    /**
     * @return Returns the name of the team of the stadium as a string.
     */
    std::string team() const;

    /**
     * @return Returns the entire address of the team, with both the street
     * address and the city, state and zip code, as a string.
     */
    std::string address() const;

    /**
     * @return Returns the street address of the stadium as a string.
     */
    std::string streetAddress() const;

    /**
     * @return Returns the city, state and zip of the stadium as a string.
     */
    std::string cityStateZip() const;

    /**
     * @return Returns the phone number of the stadium as a string.
     */
    std::string phoneNumber() const;

    /**
     * @return Returns the team type of the stadium
     */
    std::string type() const;

    /**
     * @return Returns the team type of the stadium
     */
    Date dateOpened() const;

    /**
     * @return Returns the capacity of the stadium;
     */
    int capacity() const;

    /**
     * @return Returns the typology of the stadium
     */
    std::string surface() const;

    /**
     * @param index: The index of the souvenir in the souvenir list.
     * @return Returns a pointer to the souvenir at the parameter index of the
     * souvenir list.
     */
    Souvenir* souvenir(int index);

    /**
     * @return Returns a pointer to the souvenir list.
     */
    std::map<int, Souvenir> *souvenirList();

    /**
     * @return Returns the total revenue for the stadium.
     */
    double revenue() const;

    /**
     * @return Returns the total sales count for the stadium.
     */
    int salesCount() const;

    /**
     * @return  Returns the park typology type. Example:
     * "Retro modern", "Classic", "Jewel Box", etc..
     */
    std::string typology() const;

    /**
     * @brief addRevenue
     * @param rev - revenue to increase the total revenue by
     */
    void addRevenue(double rev);

    /**
     * @brief addSalesCount
     * @param count a count to increase the total sales count by
     */
    void addSalesCount(int count);

    /**
     * @brief league
     * @return the league type as a string
     */
    std::string league();

    /**
     * @brief updateStadium
     * @param newStadiumName - a new stadium name
     * @param newTeamName - a new team name
     * @param newTypology - a new park typoogy type
     * @param newDateOpened - set the opening date
     * @param newStadiumCapacity - set the stadium capacity
     * @param newLeagueType - set the league type
     * @param newSurfaceType - set the surface type
     * @param newCity - set the city name
     * @param newState - set the state name
     * @param newZipCode - set the zip code
     * @param newStreetAddress - set the street address
     * @param newPhoneNumber - set the phone number
     */
    void updateStadium(std::string newStadiumName,
                       std::string newTeamName,
                       std::string newTypology,
                       std::string newStarPlayer,
                       Date newDateOpened,
                       int newStadiumCapacity,
                       std::string newLeagueType,
                       std::string newSurfaceType,
                       std::string newCity,
                       std::string newState,
                       std::string newZipCode,
                       std::string newStreetAddress,
                       std::string newPhoneNumber);

    /**
     * @brief Overwrites the map of the souvenir list with the passed in map
     * @param newList the new map of souvenirs
     */
    void updateSouvenirList(std::map<int, Souvenir> newList);
    std::string getStarPlayer() const;
private:
    std::string stadiumName;            /// the name of the stadium
    std::string teamName;               /// the name of the team using the stadium
    std::string starPlayer;
    std::string stadiumStreetAddress;   /// the stadiums street adress
    std::string stadiumCityStateZip;    /// the city, state and zipcode of the stadium
    std::string stadiumPhoneNumber;     /// the phone number of the stadium
    std::string leagueType;             /// the mlb league the stadium is in
    Date stadiumDateOpened;             /// the date that the stadium opened
    int stadiumCapacity;                /// the capacity of visitors the stadium will hold
    std::string stadiumSurface;         /// the surface type - grass or astroturf
    std::string stadiumTypology;        /// the typology of the staidum, modern, retor, etc
    double stadiumRevenue;              /// a running accumulation of the revenu the stadium has generated
    int stadiumSalesCount;              /// the number of sales the stadium has made (quantity)
    unsigned int souvenirsCount;        /// that count of souvenirs a stadium has
    std::map<int, Souvenir> souvenirMap;/// a map that stores the stadium's souvenirs
};

#endif // STADIUM_H
