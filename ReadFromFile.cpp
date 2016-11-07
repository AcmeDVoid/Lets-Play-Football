#include "StadiumList.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>

void ReadFromFile(QString fileName, StadiumList &aMap)
{
    QFile myFile(fileName);
    QString tempQStr;
    double tempDouble;
    QTextStream in(&myFile);
    Stadium aStadium;

    StadiumNote *aStadiumNote;
    aStadiumNote = new StadiumNote;

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
            tempQStr = in.readLine();
            aStadiumNote->value.setTeamName(tempQStr);

            // Read stadium name
            tempQStr = in.readLine();
            aStadiumNote->value.setStadiumName(tempQStr);

            // Read seating capacity and clear buffer after that
            in >> tempDouble;
            aStadiumNote->value.setSeatingCapacity(tempDouble);
            in.readLine();


            // Read location
            tempQStr = in.readLine();
            aStadiumNote->value.setLocation(tempQStr);

            // Read conference
            tempQStr = in.readLine();
            aStadiumNote->value.setConference(tempQStr);

            // Read surface type
            tempQStr = in.readLine();
            aStadiumNote->value.setSurfaceType(tempQStr);

            // Read stadium roof type
            tempQStr = in.readLine();
            aStadiumNote->value.setRootType(tempQStr);

            // Read star player
            tempQStr = in.readLine();
            aStadiumNote->value.setStarPlayer(tempQStr);

            aStadium = aStadiumNote->value;

            aMap.put(1,aStadium);

            aStadiumNote = aStadiumNote->next;
        }

        delete aStadiumNote;
    }

    myFile.close();
}

