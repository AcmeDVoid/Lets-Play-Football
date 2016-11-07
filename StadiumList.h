#ifndef STADIUMS_H
#define STADIUMS_H

#include "StadiumNote.h"
#include <QDebug>

class StadiumList
{
    private:
        StadiumNote *head;
        StadiumNote *tail;
        int mapSize;

    public:
        StadiumList();

        ~StadiumList();

        int size() const;

        bool empty() const;

        StadiumNote *find(int aKey);

        StadiumNote *put(int aKey, Stadium aValue);

        void remove(int aKey);

//        void remove(StadiumNote *entry);

        StadiumNote *begin() const;

        StadiumNote *end() const;

        void print() const;

    protected:
        // Helper function - insert
        StadiumNote *insert(int aKey, Stadium aValue);

        // Helper function - delete
        void removeNode(int aKey);



};

#endif // STADIUMS_H
