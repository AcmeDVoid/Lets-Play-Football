#ifndef ADDSTADIUM_H
#define ADDSTADIUM_H

#include <QDialog>
#include <QPalette>
#include "include/stadium.h"
#include "include/stadiumlist.h"

namespace Ui {
class addstadium;
}

class addstadium : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief addstadium The constructor for the add stadium window that allows
     * the user to add a stadium to the list
     * @param masterList The list of stadiums
     * @param parent The parent window
     */
    explicit addstadium(StadiumList* masterList, QWidget *parent = 0);

    /**
      @brief Destructor for add stadium window
     */
    ~addstadium();

    /**
     * @brief Loads into the souvenir table a default list of souvenirs
     */
    void loadDefaultSouvenirList();

    /**
     * @brief buildSouvenirList
     * @param stadium the stadium to build the souvenir list for.
     */
    void buildSouvenirList(Stadium& stadium /* IN & OUT */);

    /**
     * @brief loadStates
     * this method loads all the 50 states in the US into a combo box
     */
    void loadStates();

    /**
     * @brief buildStadiumObject
     * builds a stadium object based on the fields on the ui
     * @return a Stadium with all the new attributes set
     */
    Stadium buildStadiumObject();

//    /**
//     * @brief buildVertex
//     * @return a Vertex pointer with the name of the stadium
//     * and corresponding edges specifid on the UI
//     */
//    Vertex *buildVertex();

//    /**
//     * @brief addEdges
//     * adds edges to the specified vertex passed intot the paramter
//     * @param newVertex the vertex to add the new edges to
//     */
//    void addEdges(Vertex *newVertex);

private slots:
    /**
     * @brief on_addSouvenirItem_clicked
     * button on click handler for when the add souvenir
     * button is clicked
     */
    void on_addSouvenirItem_clicked();

    /**
     * @brief on_addStadiumButton_clicked
     * button on clock handler for when the add stadium
     * butotn is clicked
     */
    void on_addStadiumButton_clicked();

    /**
     * @brief on_cancelButton_clicked
     * the handler function for the cancel button is clicked
     * closes the window by calling this->close();
     */
    void on_cancelButton_clicked();

private:
    Ui::addstadium *ui;         /// the ui pointer, reference the window
    StadiumList* masterList;    /// a pointer to the master stadiumList
    QPalette invalidPalette;    /// a palette for error text - its red
    QPalette validPalette;      /// a palette for vvalid text - its black
    QList<int> edgeLengths;     /// a QList of integers that representes edges
};

#endif // ADDSTADIUM_H
