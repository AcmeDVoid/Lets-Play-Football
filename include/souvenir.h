#ifndef SOUVENIR_H
#define SOUVENIR_H

#include <string>
using namespace std;

class Souvenir {
public:
    /*************************************************************************
     * Constructors & Destructors
     *************************************************************************/
    /**
     * @brief Souvenir
     * This is the non-default constructor with arguments that set the name and
     * price of the souvenir
     * @param newName: the name of the souvenir
     * @param newPrice: the price of the souvenir
     */
    Souvenir(std::string newName, double newPrice);

    /**
     * @brief Souvenir
     * This is the copy constructor for the souvenir that allows for a deep copy
     * of the souvenir
     * @param otherSouvenir: the souvenir to copy from
     */
    Souvenir(const Souvenir& otherSouvenir);

    /**
     * @brief ~Souvenir
     * This is the destructor for the menu item
     */
    ~Souvenir();

    /*************************************************************************
     * Mutators
     *************************************************************************/
    /**
     * @brief setPrice
     * This method sets the price of the souvenir from the parameter
     * @param newPrice The price to set of the souvenir
     */
    void setPrice(double newPrice);

    /**
     * @brief setName
     * This method sets the name of the souvenir from the parameter
     * @param newName
     */
    void setName(string newName);

    /*************************************************************************
     * Accessors
     *************************************************************************/
    /**
     * @brief name
     * @return Returns the name of the souvenir
     */
    std::string name() const;

    /**
     * @brief price
     * @return Returns the price of the souvenir
     */
    double price() const;
private:
    double itemPrice;
    std::string itemName;
};

#endif // SOUVENIR_H
