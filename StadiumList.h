#ifndef STADIUMS_H
#define STADIUMS_H

#include "StadiumNode.h"
#include <QDebug>
#include <QVector>

// This class creates map based on a doubly linked list
// Using the information of the stadium
class StadiumList
{
    private:
        StadiumNode *head;
        StadiumNode *tail;
        int mapSize;                    // Size of the map

    public:


        StadiumList();

        ~StadiumList();

        int size() const;

        bool empty() const;

        StadiumNode *find(QString aKey);

        StadiumNode *put(QString aKey, Stadium &aValue);

        void remove(QString aKey);

        StadiumNode *begin() const;

        StadiumNode *end() const;

        void getAllStadiums(QVector <Stadium> &valueList) const;

        double getTotalSeatingCapacity() const;

    protected:
        // Helper function - insert
        StadiumNode *insert(QString aKey, Stadium aValue);

        // Helper function - delete
        void removeNode(QString aKey);






};

#endif // STADIUMS_H
