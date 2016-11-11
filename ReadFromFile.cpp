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
    QString readLine;
    QString key;
    double readDouble;
    QTextStream in(&myFile);
    Stadium aStadium;

    // Create new node for adding
    StadiumNode aStadiumNote;

    // Check file is unreadable
    if(!myFile.open(QFile::ReadOnly | QFile::Text))
    {
        // Output error
    }
    // If not, read the file
    else
    {
        while(!in.atEnd())
        {
            // Read team name
            readLine = in.readLine();
            key = readLine;
            aStadiumNote.value.setTeamName(readLine);

            // Read stadium name
            readLine = in.readLine();
            aStadiumNote.value.setStadiumName(readLine);

            // Read seating capacity and clear buffer after that
            in >> readDouble;
            aStadiumNote.value.setSeatingCapacity(readDouble);
            in.readLine();


            // Read location
            readLine = in.readLine();
            aStadiumNote.value.setLocation(readLine);

            // Read conference
            readLine = in.readLine();
            aStadiumNote.value.setConference(readLine);

            // Read surface type
            readLine = in.readLine();
            aStadiumNote.value.setSurfaceType(readLine);

            // Read stadium roof type
            readLine = in.readLine();
            aStadiumNote.value.setRootType(readLine);

            // Read star player
            readLine = in.readLine();
            aStadiumNote.value.setStarPlayer(readLine);

            aStadium = aStadiumNote.value;

            // Add new node to the map
            aMap.put(key,aStadium);

            aMap.print();

        }

    }

    myFile.close();
}

