#ifndef STADIUMLIST_H
#define STADIUMLIST_H

#include "include/stadium.h"
#include "include/errorcheck.h"
#include <vector>
#include <fstream> // files
#include <limits> // numeric limits
#include <QDebug>
//#include "include/Graph.h"

class StadiumList {
public:
    /*************************************************************************
    * Constructors & Destructors
    *************************************************************************/
    /**
     * @brief StadiumList: Default no-arg constructor. Does not initialize.
     */
    StadiumList();

    /**
     * @brief ~StadiumList: Destructor.
     */
    ~StadiumList();

//    /**
//     * @brief Stadium
//     * @param otherStadium - the stadium to copy this object from
//     */
//    Stadium (const Stadium &otherStadium);

    /*************************************************************************
    * Mutators
    *************************************************************************/
    /**
     * @brief addStadium: Adds a stadium to the stadium list.
     * @param newStadium: The new stadium to add to the stadium list.
     */
    void addStadium(Stadium newStadium);

    void initialize();

    void addDefaultSouvenirs();

    /*************************************************************************
     * Accessors
     *************************************************************************/
    /**
     * @brief stadium: Returns a pointer to the stadium at the parameter index in
     * the stadium list.
     * @param index: The index in the stadium list to return a pointer of the
     * stadium.
     * @return A pointer to the stadium at the parameter index in the stadium list.
     */
    Stadium* stadium(int index);

    Stadium* stadium(string stadiumName){
        for(unsigned int i = 0; i < this->stadiumList.size(); i++){
            Stadium* stad = stadium(i);
            if(stad->name() == stadiumName){
                return stad;
            }
        }
        return NULL;
    }


    /**
     * @return Returns the size of the stadium list.
     */
    unsigned int size() const;

    /**
     * @return Returns the sum of the revenues of all stadiums in the stadium list.
     */
    double totalRevenue() const;

    /*************************************************************************
    * Utility
    *************************************************************************/
    /**
     * @brief Saves to an output file the stadium list, so it can be
     * loaded in another execution.
     */
    void saveStadiumList();

    void saveSouvenirs();

    /**
     * @brief Saves to an output file the revenue of each stadium, so it can be
     * loaded in another execution.
     */
    void saveRevenue();

    /**
     * @brief Prints to the console the stadiums.
     */
    void print();

    bool teamNameExists(std::string teamName);
    bool stadiumNameExists(std::string stadiumName);



    // SORTS -----------------------------------------------------------------
    void sortByAlphabeticalOrder();
    void sortByTeamName();
    void sortByGrassSurface();
    void sortByDateOpened();
    void sortBySeatingCapacity();
    void sortByParkTypology();

//        Graph* graph();

protected:
    /*************************************************************************
    * Mutators
    *************************************************************************/
    /**
     * @brief loadStadiumListFromFile
     * This method loads data from an input file and puts that information into the
     * stadium list
     * @param filename the filename to load from
     */
    void loadStadiumListFromFile(string filename);

    void loadSouvenirs(string filename);

    void loadDefaultGraph();

    /**
     * @brief loadRevenue
     * This method loads revenue data from the specified file.
     * @param filename the file to load from.
     */
    void loadRevenue(string filename);


private:
    vector<Stadium> stadiumList;    ///a vector of Stadium objects that represents the underlying list of stadiums
//    Graph *theGraph;                ///a pointer to the instantiated graph from main
};

#endif // STADIUMLIST_H
