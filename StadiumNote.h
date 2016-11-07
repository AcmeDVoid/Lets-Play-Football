#ifndef STADIUMNOTE_H
#define STADIUMNOTE_H

#include "Stadium.h"

class StadiumNote
{
    public:
        int key;
        Stadium value;
        StadiumNote *next;
        StadiumNote *prev;

        StadiumNote()
        {
            key = 0;
            Stadium();
            next = NULL;
            prev = NULL;
        }

        void printNode() const
        {
            // Output node
        }

};

#endif // STADIUMNOTE_H
