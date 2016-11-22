/*************************************************************************
 * AUTHOR	     : Steve Fajardo
 * STUDENT ID    : 832032
 * ASSIGNMENT #14: Djikstra & MST
 * CLASS	     : CS1D
 * SECTION       : MW 4:30 P.M.
 * DUE DATE      : 4/25/16
 ************************************************************************/

#include "include/Vertex.h"
#include "include/Edge.h"
#include <algorithm>

/*************************************************************************
 * Class Vertex
 * This class is a representation of a location vertex that has incident
 * edges and therefore adjacent vertices. It has a data member name that
 * represents the location name.
 *************************************************************************/
/**
 * Vertex
 * The constructor for Vertex. It sets the location name and initializes
 * the data member visited to false, because it has not been visited yet.
 */
Vertex::Vertex(std::string newName) {
    visited = false;
    locationName = newName;
    vertexLevel = 0;
    vertexParent = NULL;
}

/**
 * ~Vertex
 * The destructor for Vertex.
 */
Vertex::~Vertex() {

}

/*************************************************************************
 * Accessors
 *************************************************************************/
/**
 * name
 * Returns the location name of the vertex.
 */
std::string Vertex::name() const {
    return locationName;
}

/**
 * @brief setName sets the vertex's name  the inputName param
 * @param inputName the name to change the vertex to
 */
void Vertex::setName(std::string inputName){
    this->locationName = inputName;
}

/**
 * incidentEdges
 * Returns the incident edges of the vertex.
 */
std::vector<Edge*> Vertex::incidentEdges() {
    return listOfIncidentEdges;
}


std::vector<Edge *> Vertex::outgoingEdges() {
    // for every edge add it to the list of outgoing edges if this vertex is the
    // origin for the edge (if directed) or just an endpoint (if not directed)
    std::vector<Edge *> outgoing;
    for (unsigned int i = 0; i < listOfIncidentEdges.size(); i++) {
        Edge *edge = listOfIncidentEdges[i];
        // if directed must be origin
        if (edge->isDirected()) {
            if (edge->origin() == this) {
                outgoing.push_back(edge);
            }
        }
        else if (edge->origin() == this || edge->destination() == this) {
            // if not directed just must be an endpoint
            outgoing.push_back(edge);
        }

    }

    return outgoing;
}

/**
 * adjacentVertices
 * Returns the adjacent vertices of the vertex.
 */
std::vector<Vertex*> Vertex::adjacentVertices() {
    std::vector<Vertex *> vertices;
    // for every edge
    for (unsigned int i = 0; i < listOfIncidentEdges.size(); i++) {
        Edge *edge = listOfIncidentEdges[i];

        Vertex *origin = edge->origin();
        Vertex *destination = edge->destination();

        // if the vertex is opposite of this vertex then its an adjacent vertex
        if (origin != this) {
            vertices.push_back(edge->origin());
        }
        if (destination != this) {
            vertices.push_back(edge->destination());
        }
    }

    return vertices;
}

/**
 * compare
 * Returns whether edge1's length is less than edge2's length.
 */
bool compare(const Edge* edge1, const Edge* edge2) {
    return ((edge1->length()) < (edge2->length()));
}

/**
 * isAdjacentTo
 * Returns whether this vertex is adjacent to the Vertex pointer parameter
 * key.
 */
bool Vertex::isAdjacentTo(Vertex *key) {
    // initialize found variable as false
    bool found = false;

    // iterate through the list of adjacent vertices
    for (unsigned int i = 0; i < listOfAdjacentVertices.size() && !found; i++) {
        // if the vertices are the same, it is adjacent
        if (listOfAdjacentVertices.at(i) == key) {
            found = true;
        }
    }

    return found;
}

/**
 * hasIncidentEdgeStored
 * Returns whether this vertex has already stored the Edge pointer
 * parameter in its list of incident edges.
 */
bool Vertex::hasIncidentEdgeStored(Edge* key) {
    // initialize found variable as false
    bool found = false;

    // iterate through the list of incident edges
    for (unsigned int i = 0; i < listOfIncidentEdges.size() && !found; i++) {
        // store the pointer to the current incident edge
        Edge *incEdge = listOfIncidentEdges.at(i);

        // check if the edges are the same
        if (incEdge->isSameEdge(key)) {
            // set found to true
            found = true;
        }

    }

    // return found variable
    return found;
}

/**
 * distanceFrom
 * Returns the distance between this vertex and the other vertex parameter.
 */
double Vertex::distanceFrom(Vertex *otherVertex) const {
    // initialize values
    bool found = false;
    double distance = 0.0;

    // check every edge, if it has the endpoints of this vertex and the paramter
    // vertex, set the distance and mark found
    for (unsigned int i = 0; i < listOfIncidentEdges.size() && !found; i++) {
        Edge *curEdge = listOfIncidentEdges.at(i);
        if (curEdge->hasEndPoint(otherVertex)) {
            found = true;
            distance = curEdge->length();
        }
    }

    // return the distance
    return distance;
}

/**
 * level
 * Returns the level of the vertex in the search.
 */
int Vertex::level() const {
    // return level
    return vertexLevel;
}

/**
 * parent
 * Returns the parent of the vertex in the search.
 */
Vertex* Vertex::parent() {
    return vertexParent;
}

/*************************************************************************
 * Mutators
 *************************************************************************/
/**
 * sortIncidentEdges
 * Sorts the incident edges of the vertex by length.
 */
void Vertex::sortIncidentEdges() {
    std::sort(listOfIncidentEdges.begin(), listOfIncidentEdges.end(), compare);
}

/**
 * addIncidentEdge
 * Adds an incident edge to the list of incident edges of the vertex.
 */
void Vertex::addIncidentEdge(Edge* newEdge) {
    // first check if the incident edge hasn't already been added
    if (!hasIncidentEdgeStored(newEdge)) {
        // if new add to the list
        listOfIncidentEdges.push_back(newEdge);
    }
}

/**
 * addAdjacentVertex
 * Adds an adjacent vertex to the list of adjacent vertices of the vertex.
 */
void Vertex::addAdjacentVertex(Vertex* newVertex) {
    if (!isAdjacentTo(newVertex)) {
        listOfAdjacentVertices.push_back(newVertex);
    }

}

//Sets the visited attribute to true. In turn "visiting" the vertex
void Vertex::visit() {
    this->visited = true;
}

//@return - true if the vertex has been visited, false if not
bool Vertex::isVisited() {
    return this->visited;
}

/**
 * setLevel
 * Sets the level of the vertex in the search
 */
void Vertex::setLevel(int newLevel) {
    vertexLevel = newLevel;
}

/**
 * setParent
 * Sets the parent of the vertex in the search
 */
void Vertex::setParent(Vertex *newParent) {
    vertexParent = newParent;
}

/**
 * setVisited
 * Sets the vertex as visited or not visited in the search
 */
void Vertex::setVisited(bool isVisited) {
    visited = isVisited;
}
