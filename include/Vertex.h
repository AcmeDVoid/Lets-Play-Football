#ifndef VERTEX_H_
#define VERTEX_H_

#include <string>
#include <vector>
#include <iostream> //cout

// Declare but don't define Edge, because the Vertex and Edge classes have
// members of the type of each other
class Edge;

/*************************************************************************
 * Class Vertex
 * This class is a representation of a location vertex that has incident
 * edges and therefore adjacent vertices. It has a data member name that
 * represents the location name.
 *************************************************************************/
class Vertex {
public:
    /*************************************************************************
    * Constructors & Destructors
    *************************************************************************/
    /**
     * Vertex
     * The constructor for Vertex. It sets the location name and initializes
     * the data member visited to false, because it has not been visited yet.
     */
    Vertex(std::string newName);

    /**
     * ~Vertex
     * The destructor for Vertex.
     */
    ~Vertex();

    /*************************************************************************
    * Accessors
    *************************************************************************/
    /**
     * name
     * Returns the location name of the vertex.
     */
    std::string name() const;

    /**
     * @brief setName sets the vertex's name  the inputName param
     * @param inputName the name to change the vertex to
     */
    void setName(std::string inputName);

    /**
     * incidentEdges
     * Returns the incident edges of the vertex.
     */
    std::vector<Edge*> incidentEdges();

    /**
     * outgoingEdges
     * Returns the outgoing edges of the vertex.
     */
    std::vector<Edge*> outgoingEdges();

    /**
     * adjacentVertices
     * Returns the adjacent vertices of the vertex.
     */
    std::vector<Vertex*> adjacentVertices();

    /**
     * isAdjacentTo
     * Returns whether this vertex is adjacent to the Vertex pointer parameter
     * key.
     */
    bool isAdjacentTo (Vertex *key);

    /**
     * hasIncidentEdgeStored
     * Returns whether this vertex has already stored the Edge pointer
     * parameter in its list of incident edges.
     */
    bool hasIncidentEdgeStored (Edge* key);

    /**
     * distanceFrom
     * Returns the distance between this vertex and the other vertex parameter.
     */
    double distanceFrom(Vertex *otherVertex) const;

    /**
     * isVisited
     * Returns whether this vertex has been visited.
     */
    bool isVisited();

    /**
     * level
     * Returns the level of the vertex in the search.
     */
    int level() const;

    /**
     * parent
     * Returns the parent of the vertex in the search.
     */
    Vertex* parent();

    /*************************************************************************
    * Mutators
    *************************************************************************/
    /**
     * sortIncidentEdges
     * Sorts the incident edges of the vertex by length.
     */
    void sortIncidentEdges();

    /**
     * addIncidentEdge
     * Adds an incident edge to the list of incident edges of the vertex.
     */
    void addIncidentEdge(Edge* newEdge);

    /**
     * addAdjacentVertex
     * Adds an adjacent vertex to the list of adjacent vertices of the vertex.
     */
    void addAdjacentVertex(Vertex* newVertex);

    /**
     * visit
     * Sets this vertex as having been visited.
     */
    void visit();

    /**
     * setLevel
     * Sets the level of the vertex in the search
     */
    void setLevel(int newLevel);

    /**
     * setParent
     * Sets the parent of the vertex in the search
     */
    void setParent(Vertex *newParent);

    /**
     * setVisited
     * Sets the vertex as visited or not visited in the search
     */
    void setVisited(bool isVisited);

private:
    std::string locationName;						// The name of the vertex.
    std::vector<Edge*> listOfIncidentEdges;			// The incident edges of
                                                    // the vertex.
    std::vector<Vertex*> listOfAdjacentVertices;	// The adjacent vertices of
                                                    // the vertex.
    bool visited;									// whether the vertex has
                                                    // been visited.
    int vertexLevel;								// level of the vertex
                                                    // in the search

    Vertex *vertexParent;							// parent of the vertex in
                                                    // the search
};


#endif /* VERTEX_H_ */
