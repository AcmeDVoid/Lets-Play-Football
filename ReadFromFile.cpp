#include "StadiumList.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>
#include <QMessageBox>

// ReadFromFile function
// This function takes the file name QString typed and a List as its parameters
// The function will create a list from reading the file
void ReadFromFile(QString fileName, StadiumList &aMap)
{
    QFile myFile(fileName);
    QString tempQStr1, tempQStr2, tempQStr3, tempQStr4, tempQStr5, tempQStr6, tempQStr7;
    double tempDouble;
    QTextStream in(&myFile);
    Stadium aStadium;

    // Create new node for adding
    StadiumNode *aStadiumNote;
    aStadiumNote = new StadiumNode;

    // Check file is unreadable
    if(!myFile.open(QFile::ReadOnly | QFile::Text))
    {
        // Output error
    }
    // If not, read the file
    else
    {
        int i = 0;
        while(!in.atEnd() && i < aMap.size())
        {
            // Read team name
            tempQStr1 = in.readLine();
            aStadiumNote->value.setTeamName(tempQStr1);

            // Read stadium name
            tempQStr2 = in.readLine();
            aStadiumNote->value.setStadiumName(tempQStr2);

            // Read seating capacity and clear buffer after that
            in >> tempDouble;
            aStadiumNote->value.setSeatingCapacity(tempDouble);
            in.readLine();


            // Read location
            tempQStr3 = in.readLine();
            aStadiumNote->value.setLocation(tempQStr3);

            // Read conference
            tempQStr4 = in.readLine();
            aStadiumNote->value.setConference(tempQStr4);

            // Read surface type
            tempQStr5 = in.readLine();
            aStadiumNote->value.setSurfaceType(tempQStr5);

            // Read stadium roof type
            tempQStr6 = in.readLine();
            aStadiumNote->value.setRootType(tempQStr6);

            // Read star player
            tempQStr7 = in.readLine();
            aStadiumNote->value.setStarPlayer(tempQStr7);

            aStadium = aStadiumNote->value;

            // Add new node to the map
            aMap.put(i,aStadium);

            // Make a new node
            aStadiumNote = new StadiumNode;
            i++;

        }

        // Delete to avoid memory leak
        delete aStadiumNote;
    }

    myFile.close();
}

