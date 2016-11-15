#ifndef STADIUMS_H
#define STADIUMS_H

#include "StadiumNode.h"
#include <QDebug>
#include <QVector>

// This class creates a MAP based on a doubly linked list
// Using the information of the stadium
class StadiumList
{
    private:
        StadiumNode *head;              // Point to the first Node
        StadiumNode *tail;              // Point to the last Node
        int mapSize;                    // Size of the map

    public:

        // Default constructor
        // This constructor instantiates an object
        StadiumList();

        // Destructor
        // This destructor terminates the object when out of scope
        ~StadiumList();

        // size method
        // This methods return the size of the map
        int size() const;

        // empty method
        // This method returns a bool type if the map is empty or not
        bool empty() const;

        // find method
        // This method finds return the Node based on the key of that Node
        StadiumNode *find(QString aKey);

        // put method
        // This methods insert/put a Node into the map
        StadiumNode *put(QString aKey, Stadium &aValue);

        // remove method
        // This methods remove the Node based on the key
        void remove(QString aKey);

        // begin method
        // This methods returns the first Node of the map
        StadiumNode *begin() const;

        // end method
        // This method returns the last Node of the map
        StadiumNode *end() const;

        // getAllStadiums method
        // This method gets all of the stadiums which is from the value of each Node
        void getAllStadiums(QVector <Stadium> &valueList) const;

        // getTotalSeatingCapacity method
        // This methods gets the total seating capacity from all stadiums
        double getTotalSeatingCapacity() const;

    protected:
        // Helper function - insert
        // This function inserts a Node into the doubly linked list
        StadiumNode *insert(QString aKey, Stadium aValue);

        // Helper function - delete
        // This method removes a Node from the doubly linked list
        void removeNode(QString aKey);






};

#endif // STADIUMS_H
