#include "include/souvenir.h"

/*************************************************************************
 * Constructors & Destructors
 *************************************************************************/
Souvenir::Souvenir(std::string newName, double newPrice)
{
    itemName = newName;
    itemPrice = newPrice;
}

Souvenir::Souvenir(const Souvenir &otherSouvenir)
{
    this->itemPrice = otherSouvenir.itemPrice;
    this->itemName  = otherSouvenir.itemName;
}

Souvenir::~Souvenir()
{

}

/*************************************************************************
 * Mutators
 *************************************************************************/

void Souvenir::setPrice(double newPrice)
{
    itemPrice = newPrice;
}

void Souvenir::setName(string newName)
{
    itemName = newName;
}

/*************************************************************************
 * Accessors
 *************************************************************************/
std::string Souvenir::name() const
{
    return itemName;
}

double Souvenir::price() const
{
    return itemPrice;
}

