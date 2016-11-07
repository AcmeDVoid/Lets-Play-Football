#include "StadiumList.h"
#include <QTextStream>
#include <QFile>
#include <QDebug>

void ReadFromFile(QString fileName, StadiumList &aMap)
{
    Stadium aStadium;

    QFile myFile(fileName);
    QString tempQStr;
    int key = 9; // MUST CHANGE THIS BLOCK AFTER SPRINT 1
    double tempDouble;
    QTextStream in(&myFile);

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
            aStadium.setTeamName(tempQStr);

            // Read stadium name
            tempQStr = in.readLine();
            aStadium.setStadiumName(tempQStr);

            // Read seating capacity and clear buffer after that
            in >> tempDouble;
            aStadium.setSeatingCapacity(tempDouble);
            in.readLine();


            // Read location
            tempQStr = in.readLine();
            aStadium.setLocation(tempQStr);

            // Read conference
            tempQStr = in.readLine();
            aStadium.setConference(tempQStr);

            // Read surface type
            tempQStr = in.readLine();
            aStadium.setSurfaceType(tempQStr);

            // Read stadium roof type
            tempQStr = in.readLine();
            aStadium.setRootType(tempQStr);

            // Read star player
            tempQStr = in.readLine();
            aStadium.setStarPlayer(tempQStr);

            // Read blank line
            in.flush();

            aMap.put(1,aStadium);

        }
    }

    myFile.close();
}

