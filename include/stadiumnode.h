#ifndef STADIUMNOTE_H
#define STADIUMNOTE_H

#include "include/stadium.h"
#include <QString>

/*!
 * \brief The StadiumNote class - represent a node stadium type
 */
class StadiumNode
{

    public:
        QString key;                    /// the key of the stadium node
        Stadium value;                  /// the value of the stadium node
        StadiumNode *next;              /// points to the next node
        StadiumNode *prev;              /// points to the previous node

        /*!
         * \brief StadiumNode - default constructor of the StadiumNode
         */
        StadiumNode();

        /*!
         * \brief ~StadiumNode - destructor of the StadiumNode
         */
        ~StadiumNode();

        /*!
         * \brief printNode - print the key and value of the stadium Node
         */
        void printNode() const
        {
            // Output node
        }

};

#endif // STADIUMNOTE_H
