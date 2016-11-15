#ifndef STADIUMNOTE_H
#define STADIUMNOTE_H

#include "Stadium.h"

// This class creates a pair based on a stadium information
class StadiumNode
{
    public:

        // Property
        QString key;            // Name of the Stadium
        Stadium value;          // Information about the stadium
        StadiumNode *next;      // Point to next Node
        StadiumNode *prev;      // Point to the Node before

        // Default constructor
        // This method instantiate the node
        StadiumNode()
        {
            key.clear();
            Stadium();
            next = NULL;
            prev = NULL;
        }

        // print method
        // This method outputs the Node
        void printNode() const
        {
            // Output node
        }

};

#endif // STADIUMNOTE_H
