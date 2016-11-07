#ifndef INFORMATIONCLASS_H
#define INFORMATIONCLASS_H
#include <iostream>
#include <QString>

class Stadium
{
    private:
        QString teamName;
        QString stadiumName;
        double seatingCapacity;
        QString location;
        QString conference;
        QString surfaceType;
        QString roofType;
        QString starPlayer;

    public:
        Stadium();

        Stadium(QString name, QString sName,double num, QString newLocation, QString newConf, QString type,
                QString roof, QString playerName);

        ~Stadium();

        void setTeamName(QString name);

        void setStadiumName(QString sName);

        void setSeatingCapacity(double num);

        void setLocation(QString newLocation);

        void setConference(QString newConf);

        void setSurfaceType(QString type);

        void setRootType(QString roof);

        void setStarPlayer(QString playerName);

        QString getTeamName() const;

        QString getStadiumName() const;

        double getSeatingCapacity() const;

        QString getLocation() const;

        QString getConference() const;

        QString getSurfaceType() const;

        QString getRootType() const;

        QString getStarPlayer() const;

        // Overload assignment operator
        Stadium operator=(Stadium const &rhs);


};

#endif // INFORMATIONCLASS_H
