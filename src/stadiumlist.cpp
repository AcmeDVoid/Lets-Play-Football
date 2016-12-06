#include "include/stadiumlist.h"
#include <QDebug>
/*************************************************************************
* Constructors & Destructors
*************************************************************************/
StadiumList::StadiumList()
{
    theGraph = new Graph();
}

StadiumList::~StadiumList()
{

}

/*************************************************************************
* Mutators
*************************************************************************/
void StadiumList::addStadium(Stadium newStadium)
{
    stadiumList.push_back(newStadium);
}

void StadiumList::initialize()
{
    // load restaurants
    if (InFileExistsAndIsNotEmpty("data/SavedStadiumList.txt")) {
        loadStadiumListFromFile("data/SavedStadiumList.txt");

        // load souvenirs if save data exists
        if (InFileExistsAndIsNotEmpty("data/SavedSouvenirs.txt")) {
            loadSouvenirs("data/SavedSouvenirs.txt");
        }

        // load revenue if save data exists
        if (InFileExistsAndIsNotEmpty("data/SavedRevenue.txt")) {
            loadRevenue("data/SavedRevenue.txt");
        }

//        theGraph->loadSavedGraph();
    }
    else {
        // if save file doesnt exist load the default restaurants
        loadStadiumListFromFile("data/DefaultStadiumList.txt");
        addDefaultSouvenirs();
//        theGraph->loadDefaultGraph();
    }
}

void StadiumList::addDefaultSouvenirs()
{
    for (unsigned int i = 0; i < size(); i++) {
        stadium(i)->addSouvenir(*new Souvenir("Signed Helmets", 72.99));
        stadium(i)->addSouvenir(*new Souvenir("Autographed Football", 49.39));
        stadium(i)->addSouvenir(*new Souvenir("Team pennant", 17.99));
        stadium(i)->addSouvenir(*new Souvenir("Team picture", 19.99));
        stadium(i)->addSouvenir(*new Souvenir("Team jersey", 185.99));
    }
}

/**
 * @brief StadiumList::loadStadiumListFromFile
 * @param filename
 */
void StadiumList::loadStadiumListFromFile(string filename)
{
    // DECLARE/INITIALIZE
    // input file stream
    ifstream inFile;

    std::string stadiumName = "";
    std::string teamName = "";
    std::string starPlayer = "";
    std::string stadiumStreetAddress = "";
    std::string stadiumCityStateZip = "";
    std::string stadiumPhoneNumber = "";
    std::string leagueType = "";
    std::string typology = "";
    int month = 0;
    int day = 0;
    int year = 0;
    Date *dateOpened;
    int stadiumCapacity = 0;
    std::string surfaceType = "";
    Stadium* newStadium;
    std::string traversalString = "";

    // open file
    inFile.open(filename.c_str());

    // while in the file
    while (!inFile.eof()) {
        getline(inFile, stadiumName);
        getline(inFile, teamName);
        getline(inFile, starPlayer);
//        qDebug () << QString::fromStdString(starPlayer) << " ";
        getline(inFile, stadiumStreetAddress);
        getline(inFile, stadiumCityStateZip);
        getline(inFile, stadiumPhoneNumber);

        inFile >> month;
        inFile >> day;
        inFile >> year;
        dateOpened = new Date(month, day, year);
        inFile >> stadiumCapacity;
        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        getline(inFile, surfaceType);
        getline(inFile, leagueType);
        getline(inFile, typology);

        newStadium = new Stadium(stadiumName, teamName, stadiumStreetAddress,
                                 stadiumCityStateZip, stadiumPhoneNumber,
                                 leagueType, *dateOpened, stadiumCapacity,
                                 surfaceType, typology, starPlayer);
        addStadium(*newStadium);

        getline(inFile, traversalString);
    }

    // close the file
    inFile.close();
}

void StadiumList::loadSouvenirs(string filename)
{
    this->sortByAlphabeticalOrder();
    // DECLARE/INITIALIZE
    // input file stream
    ifstream inFile;

    std::string traversalString = "";
    int souvenirCount = 0;
    int currentStadiumIndex = 0;
    std::string souvenirName;
    double souvenirPrice;

    // open file
    inFile.open(filename.c_str());


    // while in the file
    while (!inFile.eof()) {
        Stadium *currentStadium = stadium(currentStadiumIndex);
        inFile >> souvenirCount;

        for (int i = 0; i < souvenirCount; i++) {
            inFile.ignore(numeric_limits<streamsize>::max(), '\n');
            getline(inFile, souvenirName);
            inFile >> souvenirPrice;

            Souvenir *newSouvenir = new Souvenir(souvenirName, souvenirPrice);

            currentStadium->addSouvenir(*newSouvenir);
        }

        inFile.ignore(numeric_limits<streamsize>::max(), '\n');
        // pass over blank line
        getline(inFile, traversalString);
        currentStadiumIndex++;
    }

    // close the file
    inFile.close();
}

void StadiumList::loadDefaultGraph()
{

}

void StadiumList::loadRevenue(string filename)
{
    this->sortByAlphabeticalOrder();

    // DECLARE/INITIALIZE
    // input file stream
    ifstream inFile;
    // revenue of restaurant
    double revenue = 0;
    // sales count of stadium
    unsigned int salesCount = 0;
    // a string to traverse the file and read data
    string lineReader;
    // the index of the restaurant
    unsigned int stadiumIndex = 0;

    // open file
    inFile.open(filename.c_str());

    // while in the file
    while (!inFile.eof()) {
        // get revenue
        inFile >> revenue;
        // get next line
        getline(inFile, lineReader);

        //get salesCount and nextLine
        inFile >> salesCount;
        getline(inFile,lineReader);

        // set revenue
        if (stadiumIndex < size()) {
            stadium(stadiumIndex)->addRevenue(revenue);
            stadium(stadiumIndex)->addSalesCount(salesCount);
        }

        // increment counter
        stadiumIndex++;
    }

    // close the file
    inFile.close();
}

Graph *StadiumList::graph()
{
    return theGraph;
}

/*************************************************************************
 * Accessors
 *************************************************************************/
Stadium *StadiumList::stadium(int index)
{
    return &stadiumList.at(index);
}

unsigned int StadiumList::size() const
{
    return stadiumList.size();
}

double StadiumList::totalRevenue() const
{
    double totalRevenue = 0.0;
    for (unsigned int i = 0; i < size(); i++) {
        totalRevenue += stadiumList.at(i).revenue();
    }

    return totalRevenue;
}

void StadiumList::saveStadiumList()
{
    this->sortByAlphabeticalOrder();
    // output file stream to write to
    ofstream outFile;

    // open the save file
    outFile.open("data/SavedStadiumList.txt");

    // for the number of stadiums
    for (unsigned int i = 0; i < size(); i++) {
        // line break if not first stadium
        if (i != 0) {
            outFile << endl;
        }

        // write stadium data to file
        outFile << stadium(i)->name() << endl;
        outFile << stadium(i)->team() << endl;
        outFile << stadium(i)->getStarPlayer() << endl;
        outFile << stadium(i)->streetAddress() << endl;
        outFile << stadium(i)->cityStateZip() << endl;
        outFile << stadium(i)->phoneNumber() << endl;
        Date date = stadium(i)->dateOpened();
        outFile << date.GetMonth() << " " << date.GetDay() << " " << date.GetYear() << endl;
        outFile << stadium(i)->capacity() << endl;
        outFile << stadium(i)->surface() << endl;
        outFile << stadium(i)->type() << endl;
        outFile << stadium(i)->typology() << endl;
    }

    outFile.close();
}

void StadiumList::saveSouvenirs()
{
        this->sortByAlphabeticalOrder();
    // output file stream to write to
    ofstream outFile;

    // open the save file
    outFile.open("data/SavedSouvenirs.txt");

    // for the number of stadiums
    for (unsigned int i = 0; i < size(); i++) {
        Stadium *currentStadium = stadium(i);
        int souvenirCount = currentStadium->souvenirList()->size();

        // output blank line if not first stadium
        if (i != 0) {
            outFile << endl;
        }
        outFile << souvenirCount << endl;
        for (int j = 0; j < souvenirCount; j++) {
            Souvenir *currentSouvenir = currentStadium->souvenir(j);

            outFile << currentSouvenir->name() << endl;
            outFile << currentSouvenir->price() << endl;
        }
    }

    outFile.close();
}

/**
 * @brief saveRevenue
 * This method saves to a file the revenue of all of the restaurants.
 */
void StadiumList::saveRevenue() {

    // the output file stream to write to
    ofstream outFile;

    // open the file
    outFile.open("data/SavedRevenue.txt");

    // write to the file the revenue and sales count of the restaurants
    for (unsigned int i = 0; i < size(); i++) {
        outFile << stadiumList.at(i).revenue() << endl;
        outFile << stadiumList.at(i).salesCount() << endl;
    }

    outFile.close();
}


void StadiumList::print()
{

    for (unsigned int i = 0; i < size(); i++) {
        qDebug() << QString::fromStdString(stadium(i)->name());
        qDebug() << QString::fromStdString(stadium(i)->team());
        qDebug() << QString::fromStdString(stadium(i)->streetAddress());
        qDebug() << QString::fromStdString(stadium(i)->cityStateZip());
        qDebug() << QString::fromStdString(stadium(i)->phoneNumber());
        qDebug() << QString::fromStdString(stadium(i)->type());
        qDebug() << QString::fromStdString(stadium(i)->dateOpened().DisplayDate());
        qDebug() << stadium(i)->capacity();
        qDebug() << QString::fromStdString(stadium(i)->surface());
        qDebug() << QString::fromStdString(stadium(i)->typology());
        qDebug() << "----------Souvenir List------------------";
        for (unsigned int j = 0; j < stadium(i)->souvenirList()->size(); j++) {
            qDebug() << QString::fromStdString(stadium(i)->souvenir(j)->name());
            qDebug() << stadium(i)->souvenir(j)->price();
        }
        qDebug() << "";
    }
}

bool StadiumList::teamNameExists(string teamName)
{
    bool found = false;
    for (unsigned int i = 0; i < size() && !found; i++) {
        if (stadium(i)->team() == teamName) {
            found = true;
        }
    }
    return found;
}

bool StadiumList::stadiumNameExists(string stadiumName)
{
    bool found = false;
    for (unsigned int i = 0; i < size() && !found; i++) {
        if (stadium(i)->name() == stadiumName) {
            found = true;
        }
    }
    return found;
}

//*********************************************************************
// ALL STADIUM SORTS
//--------------------------------------------------------------------
//Comparators:
//Every sort will use its own comparator based on what the sort is
//trying to accomplish. The comparator I chose to implement was based
//on the function style of a comparator. So essentially for every sort
//listed below we will be passing in its respecitive comparator that
//are defined directy below this block of code.
//************** STADIUM SORT COMPARATOR FUNCTIONS *******************
bool AlphabetCompare(const Stadium stadium1, const Stadium stadium2) {
    return ((stadium1.name()) < (stadium2.name()));
}
bool TeamNameCompare(const Stadium stadium1, const Stadium stadium2) {
    return ((stadium1.team()) < (stadium2.team()));
}
bool SurfaceCompare(const Stadium stadium1, const Stadium stadium2) {
    return ((stadium1.surface()) < (stadium2.surface()));
}
bool SeatingCapacityCompare(const Stadium stadium1, const Stadium stadium2) {
    return ((stadium1.capacity()) < (stadium2.capacity()));
}
bool TypologyCompare(const Stadium stadium1, const Stadium stadium2) {
    return ((stadium1.typology()) < (stadium2.typology()));
}
bool StarPlayerCompare(const Stadium stadium1, const Stadium stadium2){
    return ((stadium1.getStarPlayer()) < (stadium2.getStarPlayer()));
}
bool DateOpenedCompare(const Stadium stadium1, const Stadium stadium2) {
    //year1 < year2 ?
    if( stadium1.dateOpened().GetYear() < stadium2.dateOpened().GetYear() ){
        return true;
    }
    //same years and month1 < month2 ?
    else if( ( stadium1.dateOpened().GetYear() == stadium2.dateOpened().GetYear()  ) &&
             ( stadium1.dateOpened().GetMonth() < stadium2.dateOpened().GetMonth() )
             )
    {
        return true;
    }
    //same year, month, and dayOfMonth1 < dayOfMonth2 ?
    else if( ( stadium1.dateOpened().GetYear()  == stadium2.dateOpened().GetYear()  ) &&
             ( stadium1.dateOpened().GetMonth() == stadium2.dateOpened().GetMonth() ) &&
             ( stadium1.dateOpened().GetDay()    < stadium2.dateOpened().GetDay()      )
             )
    {
        return true;
    }
    //same year, month, and day ?
    else if( ( stadium1.dateOpened().GetYear()  == stadium2.dateOpened().GetYear()  ) &&
             ( stadium1.dateOpened().GetMonth() == stadium2.dateOpened().GetMonth() ) &&
             ( stadium1.dateOpened().GetDay()   == stadium2.dateOpened().GetDay()   )
             )
    {
        //then we'll just take a look at their names
        return stadium1.name() < stadium2.name();
    }
    else{
        return false;
    }
}

//*********** SORT METHODS (implement comparator functions) ***********
//Sort Methods:
//-----------------------------------------------------------------------
//All the methods listed below are a part of this class object, we are
//making use of the c++ template librarys sort function in the <algorithm>
//library. We pass in the comparators we defined above to sort the stadium
//list according to our specificaitons. Essentially we have sorts implemented
//by many different attributes.
//So to use any of these sorts affectivly, all you need to do is call
//one of these methods to sort by the attribute specified.

void StadiumList::sortByAlphabeticalOrder() {
    std::sort(stadiumList.begin(), stadiumList.end(), AlphabetCompare);
}
void StadiumList::sortByTeamName() {
    std::sort(stadiumList.begin(), stadiumList.end(), TeamNameCompare);
}
void StadiumList::sortByGrassSurface() {
    std::sort(stadiumList.begin(), stadiumList.end(), SurfaceCompare);
}
void StadiumList::sortByDateOpened() {
    std::sort(stadiumList.begin(), stadiumList.end(), DateOpenedCompare);
}
void StadiumList::sortBySeatingCapacity() {
    std::sort(stadiumList.begin(), stadiumList.end(), SeatingCapacityCompare);
}
void StadiumList::sortByParkTypology() {
    std::sort(stadiumList.begin(), stadiumList.end(), TypologyCompare);
}
void StadiumList::sortByStarPlayer()
{
    std::sort(stadiumList.begin(), stadiumList.end(), StarPlayerCompare);
}
