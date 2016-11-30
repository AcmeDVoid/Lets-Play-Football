#ifndef MAP_H
#define MAP_H

#include "include/stadiumnode.h"

/*!
 * \brief The Map class - This class stores the Stadium informtion using the MAP
 * The MAP is a Doubly Linked List with the MAP functionality
 */
class Map
{
    private:
        StadiumNode *head;              /// Point to the first Node
        StadiumNode *tail;              /// Point to the last Node
        int mapSize;                    /// Size of the map

    public:

        /*!
         * \brief Map - Default constructor
         * This constructor instantiates an object
         */
        Map();

        /*!
         * \brief Map - Destructor
         * This destructor terminates the object when out of scope
         */
        ~Map();


        /*!
         * \brief size
         * \return return the size of the map
         */
        int size() const;


        /*!
         * \brief empty
         * \return a bool type if the map is empty or not
         */
        bool empty() const;


        /*!
         * \brief find
         * \param aKey - key of the pair from the StadiumNode
         * \return Node based on the key of that Node
         */
        StadiumNode *find(QString aKey);


        /*!
         * \brief put
         * \param aKey - key of the pair from StadiumNode
         * \param aValue - value of the pair from StadiumNode
         * \return insert/put a Node into the map and return that Node
         */
        StadiumNode *put(QString aKey, Stadium &aValue);


        /*!
         * \brief remove
         * \param aKey - key of the pair from StadiumNode
         *  This methods remove the Node based on the key
         */
        void remove(QString aKey);


        /*!
         * \brief begin
         * \return the first Node of the map
         */
        StadiumNode *begin() const;


        /*!
         * \brief end
         * \return the last Node of the map
         */
        StadiumNode *end() const;


        /*!
         * \brief getAllStadiums
         * \param valueList - list of item of Stadium type
         *  This method gets all of the stadiums which is from the value of each Node
         */
        void getAllStadiums(QVector <Stadium> &valueList) const;


        /*!
         * \brief getTotalSeatingCapacity
         * \return the total seating capacity from all stadiums
         */
        double getTotalSeatingCapacity() const;

    protected:

        /*!
         * \brief insert - helper function
         * \param aKey - key of the pair from StadiumNode
         * \param aValue - value of the pair from StadiumNode
         * \return a Node that was inserted into the doubly linked list
         */
        StadiumNode *insert(QString aKey, Stadium aValue);


        /*!
         * \brief removeNode - helper function
         * \param aKey - key of the pair from StadiumNode
         * This method removes a Node from the doubly linked list based on the key
         */
        void removeNode(QString aKey);

};

#endif // MAP_H
