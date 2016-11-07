#include "StadiumList.h"

StadiumList::StadiumList()
{
    // Initialize all property
    head = NULL;
    tail = NULL;
    tail = head;
    mapSize = 0;
}

StadiumList::~StadiumList()
{

    StadiumNote *delPtr;

    // Check if the list is not empty
    if (head !=NULL)
    {
        delPtr = head;
        while (delPtr != NULL)
        {
            head->next = head;
            head->prev = NULL;
            delete delPtr;
            delPtr = NULL;
            mapSize--;

            // Re-point delPtr to head for next deletion
            delPtr = head;
        }

        // Once the deletion is complete, set tail and head to NULL;
        tail = NULL;
        head = NULL;
    }
}

int StadiumList::size() const
{
    // return the size
    return mapSize;
}

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

StadiumNote* StadiumList::find(int aKey)
{
    StadiumNote *findPtr;
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

StadiumNote *StadiumList::insert(int aKey, Stadium aValue)
{
    // Create a node
    StadiumNote *tempPtr;
    tempPtr = new StadiumNote;

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

    return tempPtr;
}

StadiumNote *StadiumList::put(int aKey, Stadium aValue)
{
    StadiumNote *tempPtr;
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

void StadiumList::removeNode(int aKey)
{
    StadiumNote *delPtr;

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
            StadiumNote *tempPtr;

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


    }
}

void StadiumList::remove(int aKey)
{
    StadiumNote *tempPtr;
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

StadiumNote* StadiumList::begin() const
{
    return head;
}

StadiumNote* StadiumList::end() const
{
    return tail;
}


void StadiumList::print() const
{
    StadiumNote *tempPtr;

    if (head != NULL)
    {
        tempPtr = head;

        qDebug() << "key" << " | " << "team name | stadium name"
                    << " | Seating Capacity | Location | Conference "
                    << "| Surface Type | Stadium Roof Type | Star Player";

        while (tempPtr != NULL)
        {
            qDebug() << tempPtr->key << " | " << tempPtr->value.getTeamName()
                     << " | " << tempPtr->value.getStadiumName() << " | "
                     << tempPtr->value.getSeatingCapacity() << " | "
                     << tempPtr->value.getLocation() << " | "
                     << tempPtr->value.getConference() << " | "
                     << tempPtr->value.getSurfaceType() << " | "
                     << tempPtr->value.getRootType() << " | "
                     << tempPtr->value.getStarPlayer();

            tempPtr = tempPtr->next;
        }
    }

}
