#include "StadiumList.h"

// Default constructor
// This constructor instantiates an object
StadiumList::StadiumList()
{
    // Initialize all property
    head = NULL;
    tail = NULL;
    tail = head;
    mapSize = 0;
}

// Destructor
// This destructor terminates the object when out of scope
StadiumList::~StadiumList()
{

    StadiumNode *delPtr;

    // Check if the list is not empty
    if (head !=NULL)
    {
        while (delPtr != NULL)
        {
            delPtr = head;

            head->next = head;
            head->prev = NULL;
            delete delPtr;
            delPtr = NULL;
            mapSize--;
        }

        // Once the deletion is complete, set tail and head to NULL;
        tail = NULL;
        head = NULL;
    }
}

// size method
// This methods return the size of the map
int StadiumList::size() const
{
    // return the size
    return mapSize;
}

// empty method
// This method returns a bool type if the map is empty or not
bool StadiumList::empty() const
{
    // Check if the list is empty
    if(head == NULL)
    {
        // If yes, return true
        return true;
    }
    //If not, return false
    else
    {
        return false;
    }
}

// find method
// This method finds return the Node based on the key of that Node
StadiumNode* StadiumList::find(QString aKey)
{
    StadiumNode *findPtr;
    findPtr = head;
    bool check = false;

    // Check if the list is empty
    if (head == NULL)
    {
        return NULL;
    }
    // If not, find the key
    else
    {
        while(!check && findPtr != NULL)
        {
            if (findPtr->key == aKey)
            {
                check = true;
            }
            else
            {
                findPtr = findPtr->next;
            }
        }
    }

    // Check if the searching is success
    if (check)
    {
        // If yes, return that pointer
        return findPtr;
    }
    else
    {
        // If not, return NULL
        return NULL;
    }


}

// Helper function - insert
// This function inserts a Node into the doubly linked list
StadiumNode *StadiumList::insert(QString aKey, Stadium aValue)
{
    // Create a node
    StadiumNode *tempPtr;
    tempPtr = new StadiumNode;

    tempPtr->key = aKey;
    tempPtr->value = aValue;

    // Check if the head is empty
    if (head == NULL)
    {
        head = tempPtr;
        tempPtr->next = NULL;
        tempPtr->prev = NULL;
    }
    // If not, add to the rear;
    else
    {
        // Make tail point to the last node
        tail = head;
        while(tail->next != NULL)
        {
            tail = tail->next;
        }

        // Add tempPtr to the rear
        tail->next = tempPtr;
        tempPtr->next = NULL;
        tempPtr->prev = tail;
        tail = tempPtr;
    }

    mapSize++;
    return tempPtr;
}

// put method
// This methods insert/put a Node into the map
StadiumNode *StadiumList::put(QString aKey, Stadium &aValue)
{
    StadiumNode *tempPtr;
    tempPtr = head;

    bool check = false;

    // Check if the list is empty
    if (head != NULL)
    {
        // Check if aKey is already exist in the list
        while(!check && tempPtr != NULL)
        {
            if (tempPtr->key == aKey)
            {
                check = true;
            }
            else
            {
                tempPtr = tempPtr->next;
            }
        }
    }

    // If exist, override the current value
    if (check)
    {
        tempPtr->value = aValue;
    }
    // If not, insert the new node
    else
    {\
        tempPtr = insert(aKey, aValue);
    }

    return tempPtr;
}

// Helper function - delete
// This method removes a Node from the doubly linked list
void StadiumList::removeNode(QString aKey)
{
    StadiumNode *delPtr;

    if (head != NULL)
    {
        // Make tail point to the last node
        while(tail->next != NULL)
        {
            tail = tail->next;
        }

        // Check if the first node is the one to delete
        if (head->key == aKey)
        {
            // Point delPtr to head
            delPtr = head;

            // Shift head while keeping delPtr at the same position
            head = head->next;

            // Remove
            head->prev = NULL;
            delete delPtr;
            delPtr = NULL;
        }
        // Check if the last node is the one to delete
        else if (tail->key == aKey)
        {
            // Point delPtr to heads
            delPtr = tail;

            // Shift back tail while keeping delPtr at the same position
            tail = tail->prev;

            // Remove
            tail->next = NULL;
            delete delPtr;
            delPtr = NULL;
        }
        // If not, check in the middle for deletion
        else
        {
            // Create 2nd pointer for deletion
            StadiumNode *tempPtr;

            // Check if aKey is already exist in the list
            while(delPtr != NULL)
            {
                if (delPtr->key == aKey)
                {
                    // Make tempPtr point to the delete position
                    tempPtr = delPtr;

                    // Remove
                    tempPtr->prev->next = tempPtr;
                    tempPtr = tempPtr->next;
                    tempPtr->prev = tempPtr->prev->prev;
                    delete delPtr;
                    delPtr = NULL;
                }
                else
                {
                    delPtr = delPtr->next;
                }
            }
        }

        mapSize--;
    }

}

// remove method
// This methods remove the Node based on the key
void StadiumList::remove(QString aKey)
{
    StadiumNode *tempPtr;
    tempPtr = head;

    bool check = false;

    // Check if aKey is already exist in the list
    while(!check && tempPtr != NULL)
    {
        if (tempPtr->key == aKey)
        {
            check = true;
        }
        else
        {
            tempPtr = tempPtr->next;
        }
    }
    // If exist, remove that node
    if (check)
    {
        removeNode(aKey);
    }
    // If not, output error
    else
    {\
        // Output error
    }
}

// begin method
// This methods returns the first Node of the map
StadiumNode* StadiumList::begin() const
{
    return head;
}

// end method
// This method returns the last Node of the map
StadiumNode* StadiumList::end() const
{
    return tail;
}

// getAllStadiums method
// This method gets all of the stadiums which is from the value of each Node
void StadiumList::getAllStadiums(QVector <Stadium> &valueList) const
{
    // Push every stadium information into the list
    for(StadiumNode *tempPtr = head; tempPtr != NULL; tempPtr = tempPtr->next)
    {
        valueList.push_back(tempPtr->value);
    }

}

// getTotalSeatingCapacity method
// This methods gets the total seating capacity from all stadiums
double StadiumList::getTotalSeatingCapacity() const
{
    double accumulator = 0;

    StadiumNode *tempPtr;

    tempPtr = head;

    // Accumulating all of the seating capacity from each stadium
    while (tempPtr != NULL)
    {
        accumulator += tempPtr->value.getSeatingCapacity();
        tempPtr = tempPtr->next;
    }

    return accumulator;
}

//void StadiumList::print() const
//{
//    StadiumNode *tempPtr;

//    if (head != NULL)
//    {
//        tempPtr = head;

//        qDebug() << "key" << " | " << "team name | stadium name"
//                    << " | Seating Capacity | Location | Conference "
//                    << "| Surface Type | Stadium Roof Type | Star Player";

//        while (tempPtr != NULL)
//        {
//            qDebug() << tempPtr->key << " |||| " << tempPtr->value.getTeamName()
//                     << " | " << tempPtr->value.getStadiumName() << " | "
//                     << tempPtr->value.getSeatingCapacity() << " | "
//                     << tempPtr->value.getLocation() << " | "
//                     << tempPtr->value.getConference() << " | "
//                     << tempPtr->value.getSurfaceType() << " | "
//                     << tempPtr->value.getRootType() << " | "
//                     << tempPtr->value.getStarPlayer();

//            tempPtr = tempPtr->next;
//        }
//    }
//}
