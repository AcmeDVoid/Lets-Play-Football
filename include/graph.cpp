#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include "Vertex.h"
#include "Edge.h"
#include <iostream>
#include <queue> // priority queue
#include <map> // map
#include <iomanip>
#include <sstream>
#include <algorithm>
#include <string>
#include <stack>
#include <climits>
#include <QStringList>
#include <QDebug>
#include <fstream>
#include <limits> // numeric limits

/*************************************************************************
 * Class Graph
 * This class is a representation of a graph with vertices and edges.
 *************************************************************************/
class Graph {
public:
    /*************************************************************************
     * Constructors & Destructors
     *************************************************************************/
    Graph();			//Graph class constructor
    /**
     * Graph
     * Constructor that initializes reversed to false and also adds a vertice to the
     * graph.
     */
    Graph(Vertex *v);	// Graph constructor that initializes with one vertex
    ~Graph();			//Graph class destructor

    /*************************************************************************
     * Accessors
     *************************************************************************/
    //*********************************************************************
    // edges
    //@return std::vector<Edge*>- a list of edges
    std::vector<Edge*> edges();

    //*********************************************************************
    // vertices
    //@return std::vector<Vertex*> - a list of vertices
    std::vector<Vertex*> vertices();

    /**
     * printOutgoingEdges
     * Print out the vertices of the graph and their outgoing edges.
     */
    void printOutgoingEdges();

    /**
     * printIncidentEdges
     * Print out the vertices of the graph and their incident edges.
     */
    void printIncidentEdges();

    /**
     * printVertices
     * Print out the vertices of the graph.
     */
    void printVertices();

    //*********************************************************************
    // findVertex
    //@param name - the name of vertex object whose pointer we will return
    //@return - a pointer to the vertex with the passed in name attribute
    //@NOTE - returns null if we don't find anything!
    Vertex* findVertex(std::string name);

    //*********************************************************************
    // findVertexByIndex
    //this method takes in an int and performs a sequential search
    //to return a pointer to the vertex that is of that index
    //@param name - the index of vertex object whose pointer we will return
    //@return - a pointer to the vertex with the passed in index attribute
    //@NOTE - returns null if we don't find anything!
    Vertex* findVertexByIndex(int index);

    Vertex *findClosest(Vertex *startingVertex, QStringList possibleVertices);

    /**
     * djikstra
     * Performs djikstra's algorithm from the starting vertex to find the
     * shortest path/distance to all nodes from this starting vertex.
     * Returns nothing but outputs the paths
     */
    void djikstra(Vertex *startVertex, int dist[], int parents[], bool output = false);

    std::stack<std::string> findShortestPath(Vertex* src, Vertex* dest);

    /**
     * length
     * Returns the length of the edge containing the parameter endpoints
     */
    double length(Vertex *endpointA, Vertex *endpointB);

    /**
     * findIndex
     * Finds the index in the vertex vector that has the element key.
     */
    int findIndex(Vertex *key);

    /**
     * size
     * Returns the number of vertices in the graph.
     */
    unsigned int size() const;

    /**
     * findMin
     * Finds the vertex with the shortest distance in the array, that hasnt been
     * visited yet, return the vertex
     */
    Vertex *findMin(int array[], bool visited[], int arraySize);

    /**
     * kruskals
     * Performs kruskal's algorithm to find the minimum spanning tree. Uses
     * subgraphs to temporarily hold vertices and then joins subgraphs where
     * appropriate.
     */
    std::vector<Edge*> kruskals();

    /**
     * findGraph
     * Finds the subgraph in the list of subgraphs that has the key vertex.
     * Returns the index of the list of the subgraph that has it
     */
    int findGraph(std::vector<Graph> graphs, Vertex *searchVertex);

    /**
     * joinUnion
     * Helper for kruskal's algorithm that takes subgraphs and joins them together.
     * Since we are joining them we have to delete one from the list of subgraphs.
     * Returns the modified list of subgraphs.
     */
    std::vector<Graph> joinUnion(std::vector<Graph> graphs, int indexA,
            int indexB);

    /*************************************************************************
     * Mutators
     *************************************************************************/
    //*********************************************************************
    // insertVertex
    //@param newName - the name of the vertex to add
    //@return nothing - void
    void insertVertex(std::string newName);

    //*********************************************************************
    //insertEdge
    //@param endPoint [in] - the 1st Vertex end point of the edge
    //@param otherEndPoint [in] - the 2nd Vertex end point of the edge
    //@param length [in] - the Double length of the edge (in miles)
    //@return - nothing: void
    void insertEdge(Vertex *

                    , Vertex *destination, double length,
            bool isDirected = true);

    //*********************************************************************
    //dfs (depth-first-search)
    //@param startVertex - the vertex to start the search at
    //@return - nothing void
    void dfs(Vertex *v);



    /**
     * bfs
     * Performs a breadth-first traversal, outputting the discovery, back,
     * forward and cross edges while doing so.
     */
    void bfs(Vertex *v);

    /**
     * reverseEdges
     * Reverses all edges in the list, making their origin their destinatin and
     * vice-versa
     */
    void reverseEdges();

    /**
     * unvisitAll
     * Set all vertices in the graph as unvisited and set their parents to null and
     * set their level to 0
     */
    void unvisitAll();

    /**
     * sortEdges
     * Sorts the edges in ascending order where you start with the edge with the
     * smallest weight.
     */
    void sortEdges();

    /**
     * initializeUSAMap
     * initializes the graph to have the vertices and edges from the assignment.
     */
    void initializeUSAMap();

    /**
     * insertVertex
     * Inserts a vertex into graph, returns nothing.
     */
    void insertVertex(Vertex *v);

    void loadDefaultGraph();
    void loadSavedGraph();

    void saveVertices();
    void saveEdges();
    void saveAll();


private:
    std::vector<Edge*> listOfEdges;		 //a list of edges in the graph
    std::vector<Vertex*> listOfVertices; //a list of vertices in the graph
    bool reversed;						 //whether the edges in the graph are
                                         // reversed.
};

#endif /* GRAPH_H_ */
