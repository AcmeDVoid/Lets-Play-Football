#ifndef STADIUMS_H
#define STADIUMS_H

#include "StadiumNode.h"
#include <QDebug>

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

        StadiumNode *find(int aKey);

        StadiumNode *put(int aKey, Stadium &aValue);

        void remove(int aKey);

//        void remove(StadiumNote *entry);

        StadiumNode *begin() const;

        StadiumNode *end() const;

        void print() const;

    protected:
        // Helper function - insert
        StadiumNode *insert(int aKey, Stadium aValue);

        // Helper function - delete
        void removeNode(int aKey);



};

#endif // STADIUMS_H
