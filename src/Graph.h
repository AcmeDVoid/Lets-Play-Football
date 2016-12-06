#include "include/Graph.h"


/**
 * Graph
 * Constructor initializes reversed to false.
 */
Graph::Graph() {
    reversed = false;
}

/**
 * Graph
 * Constructor that initializes reversed to false and also adds a vertice to the
 * graph.
 */
Graph::Graph(Vertex *v) {
    reversed = false;
    listOfVertices.push_back(v);
}

//*********************************************************************
// Graph::Destructor
//empty destructor method for now
Graph::~Graph() {
    //destructor
}

/*************************************************************************
 * Accessors
 *************************************************************************/
//*********************************************************************
// edges
//this method returns a list of edges that are currently
//in the graph
//@return std::vector<Edge*>- a list of edges
std::vector<Edge*> Graph::edges() {
    return listOfEdges;
}

//*********************************************************************
// vertices
//this method returns a vector full of vertices that
//are currently saved in the graph.
//@return std::vector<Vertex*> - a list of vertices
std::vector<Vertex*> Graph::vertices() {
    return listOfVertices;
}

/**
 * printOutgoingEdges
 * Print out the vertices of the graph and their outgoing edges.
 */
void Graph::printOutgoingEdges() {
    std::cout << "Printing out textual representation of the map:\n";

    // for all vertices
    for (unsigned int i = 0; i < listOfVertices.size(); i++) {
        Vertex *vertex = listOfVertices[i];

        // get the outgoing edges for this vertex. An outgoing edge is an edge
        // that has this vertex as its origin.
        std::vector<Edge *> outgoingEdges = vertex->outgoingEdges();

        // output vertex name
        std::cout << "Location: " << vertex->name() << std::endl;

        // output all of its outgoing edges
        std::cout << "Outgoing Edges To: \n";
        for (unsigned int j = 0; j < outgoingEdges.size(); j++) {
            Edge *edge = outgoingEdges[j];
            // output the destination of the outgoing edge and its cost
            std::cout << edge->destination()->name() << " (" << edge->length()
                      << " Miles)\n";
        }
        std::cout << std::endl;
    }
}

/**
 * printIncidentEdges
 * Print out the vertices of the graph and their outgoing edges.
 */
void Graph::printIncidentEdges() {
    std::cout << "Printing out textual representation of the map:\n";

    // for all vertices
    for (unsigned int i = 0; i < listOfVertices.size(); i++) {
        Vertex *vertex = listOfVertices[i];

        // get the incident edges for this vertex.
        std::vector<Edge *> incidentEdges = vertex->incidentEdges();

        // output vertex name
        std::cout << "Location: " << vertex->name() << std::endl;

        // output all of its outgoing edges
        std::cout << "Incident Edges: \n";
        for (unsigned int j = 0; j < incidentEdges.size(); j++) {
            Edge *edge = incidentEdges[j];
            Vertex *incidentVertex = edge->opposite(vertex);
            std::cout << incidentVertex->name() << " (" << edge->length()
                      << " Miles)\n";
        }
        std::cout << std::endl;
    }
}

/**
 * printVertices
 * Print out the vertices of the graph.
 */
void Graph::printVertices() {
    std::cout << "Printing out vertices:\n";

    // for all vertices
    for (unsigned int i = 0; i < listOfVertices.size(); i++) {
        Vertex *vertex = listOfVertices[i];

        // output vertex name
        std::cout << "Location: " << vertex->name() << std::endl;
    }
}

//*********************************************************************
// findVertex
//this method takes in a string and performs a sequential search
//to return a pointer to the vertex that has that passed in name.
//@param name - the name of vertex object whose pointer we will return
//@return - a pointer to the vertex with the passed in name attribute
//@NOTE - returns null if we don't find anything!
Vertex* Graph::findVertex(std::string name) {
    for (unsigned int i = 0; i < this->listOfVertices.size(); i++) {
        if (listOfVertices.at(i)->name() == name) {
            return listOfVertices.at(i);
        }
    }
    //if we get here, return null
    return 0;
}

//*********************************************************************
// findVertexByIndex
//this method takes in an int and performs a sequential search
//to return a pointer to the vertex that is of that index
//@param name - the index of vertex object whose pointer we will return
//@return - a pointer to the vertex with the passed in index attribute
//@NOTE - returns null if we don't find anything!
Vertex *Graph::findVertexByIndex(int index)
{
    return listOfVertices.at(index);
}

Vertex *Graph::findClosest(Vertex *startingVertex, QStringList possibleVertices)
{
    int dist[size()];
    int parents[size()];
    int minDist = 999999;
    int minIndex = 0;

    this->djikstra(startingVertex, dist, parents);

    for (int i = 0; i < size(); i++) {
        Vertex *curVertex = listOfVertices.at(i);
        if (dist[i] < minDist && curVertex != startingVertex
                && possibleVertices.contains(QString::fromStdString(curVertex->name()))) {
            minDist = dist[i];
            minIndex = i;
        }
    }

    return listOfVertices.at(minIndex);
}

/**
 * size
 * Returns the number of vertices in the graph.
 */
unsigned int Graph::size() const {
    return listOfVertices.size();
}

/**
 * findMin
 * Finds the vertex with the shortest distance in the array, that hasnt been
 * visited yet, return the vertex
 */
Vertex* Graph::findMin(int array[], bool visited[], int arraySize) {
    // initialize
    int index = 0;
    int smallest = INT_MAX;

    // for the entire array
    for (int i = 0; i < arraySize; i++) {
        // if this is the smallest distance so far
        if (array[i] < smallest && visited[i] == false) {
            smallest = array[i];
            index = i;
        }
    }

    // return the vertex with the shortest distance
    return listOfVertices[index];
}

/**
 * findGraph
 * Finds the subgraph in the list of subgraphs that has the key vertex.
 * Returns the index of the list of the subgraph that has it
 */
int Graph::findGraph(std::vector<Graph> graphs, Vertex *searchVertex) {
    int index = -1;

    // for the list of subgraphs keep going until out of bounds or found
    for (unsigned int i = 0; i < graphs.size() && index == -1; i++) {
        // for the list of vertices keep going until out of bounds or found
        for (unsigned int j = 0;
             j < graphs.at(i).vertices().size() && index == -1; j++) {
            Vertex *graphVertex = graphs.at(i).vertices()[j];

            // if found set the index
            if (graphVertex == searchVertex) {
                index = i;
            }
        }
    }

    // return the index of the subgraph that has the vertex
    return index;
}

/**
 * GraphEdgeCompare
 * Function for sorting edges from ascending order for the vector list.
 */
bool GraphEdgeCompare(const Edge* edge1, const Edge* edge2) {
    return ((edge1->length()) < (edge2->length()));
}

/**
 * length
 * Returns the length of the edge containing the parameter endpoints
 */
double Graph::length(Vertex *endpointA, Vertex *endpointB) {
    if (endpointA == endpointB) {
        return -1;
    }
    bool found = false;
    double distance = -1;
    for (unsigned int i = 0; i < listOfEdges.size() && !found; i++) {
        Edge *edge = listOfEdges[i];

        if (edge->hasEndpoints(endpointA, endpointB)) {
            found = true;
            distance = edge->length();
        }
    }

    return distance;
}

/**
 * kruskals
 * Performs kruskal's algorithm to find the minimum spanning tree. Uses
 * subgraphs to temporarily hold vertices and then joins subgraphs where
 * appropriate.
 */
std::vector<Edge *> Graph::kruskals() {
    // the minimum spanning tree
    std::vector<Edge*> mst;

    // the list of subgraphs
    std::vector<Graph> subgraphs;

    // each subgraph initially contains one vertex
    for (unsigned int i = 0; i < vertices().size(); i++) {
        Vertex *v = vertices()[i];
        subgraphs.push_back(Graph(v));
    }

    // sort edges ascending order from smallest weight to highest
    this->sortEdges();

    //
    //	// for all edges
    for (unsigned int i = 0; i < edges().size(); i++) {
        Edge *e = edges()[i];
        Vertex *v = e->origin();
        Vertex *u = e->destination();

        // find the subgraph indices containing v & u
        int vIndex = findGraph(subgraphs, v);
        int uIndex = findGraph(subgraphs, u);

        // if they arent in the same subgraph then we can add the edge
        if (uIndex != vIndex) {
            mst.push_back(e);

            // join the two subgraphs together, deleting one
            subgraphs = joinUnion(subgraphs, vIndex, uIndex);
        }
    }

    return mst;

    //        std::cout << "\nMinimum Spanning Tree:\n";

    //        int mileage = 0;

    // output the edges in the mst
    //    for (unsigned int i = 0; i < mst.size(); i++) {
    //        mileage += mst.at(i)->length();
    //        std::cout << mst.at(i)->origin()->name() << " <-> "
    //                << mst.at(i)->destination()->name() << " ("
    //                << mst.at(i)->length() << " miles)\n";
    //    }

    //    std::cout << "Total Mileage: " + mileage << "\n";
}

/**
 * djikstra
 * Performs djikstra's algorithm from the starting vertex to find the
 * shortest path/distance to all nodes from this starting vertex.
 * Returns nothing but outputs the paths
 */
void Graph::djikstra(Vertex *startVertex, int dist[], int parents[], bool output) {
    // adapted referenced from http://www.geeksforgeeks.org/greedy-algorithms-
    // set-6-dijkstras-shortest-path-algorithm/ adds functionality to keep
    // track of parents so we can also know the path not just the distance

    int startIndex = findIndex(startVertex);
    //int dist[size()];
    bool visited[size()];

    // this array holds the index of the parent of a node in a path.
    //int parents[size()];

    // initialize
    for (unsigned int i = 0; i < size(); i++) {
        // you should initialize to a large number "infinity"
        dist[i] = INT_MAX;

        // initialize the index to -1
        parents[i] = -1;

        // initialize index of visited array to false
        visited[i] = false;
    }

    // the distance from the start vertex from itself is 0
    dist[startIndex] = 0;

    // for all vertices in the graph
    for (unsigned int j = 0; j < size() - 1; j++) {

        // find the vertex with the shortest distance
        Vertex *u = findMin(dist, visited, size());

        // find the index of u in the graph
        int uIndex = findIndex(u);

        // this vertex has now been visited
        visited[uIndex] = true;

        // for all adjacent vertices of u
        for (unsigned int i = 0; i < u->adjacentVertices().size(); i++) {
            // store this neighbor as v
            Vertex *v = u->adjacentVertices()[i];

            // find the index of v in the graph
            int vIndex = findIndex(v);

            // check the distance of this path
            double alt = dist[uIndex] + length(v, u);

            // if this is new short path
            if (!visited[vIndex] && dist[uIndex] != INT_MAX
                    && alt < dist[vIndex]) {
                // set new distance
                dist[vIndex] = alt;

                // set the parents so we can reference later for the path
                parents[vIndex] = uIndex;
            }
        }
    }

    if (!output) {
        return;
    }

    std::cout << "Djikstra's Algorithm For Shortest Paths From "
              << startVertex->name() << ": \n";

    // for all vertices
    for (unsigned int i = 0; i < size(); i++) {
        // store destination as variable
        Vertex *destination = listOfVertices[i];

        // find the index of the destination
        int destinationIndex = findIndex(destination);

        // use an output string stream for a somewhat better output
        std::ostringstream os;
        os << "A path from " << startVertex->name() << " to "
           << destination->name() << ": ";
        std::cout << std::setw(38) << std::left << os.str();

        // store destination index in variable
        int j = destinationIndex;

        // make a stack so we can output the path in the correct order
        std::stack<Vertex*> order;

        // while the path does not lead to a dead end or back to the
        // starting vertex
        while (parents[j] != -1 && j != startIndex) {
            // find value in parents array
            int parentIndex = parents[j];
            Vertex *parent = listOfVertices[parentIndex];

            // push the parent vertex onto the stack
            order.push(parent);

            // change loop variable to the parent index
            j = parentIndex;
        }


        // while stack isnt empty output the contents (vertices) in the correct
        // order
        while (!order.empty()) {
            Vertex *v = order.top();
            order.pop();
            std::cout << v->name() << " -> ";
        }

        // output the path distance
        std::cout << destination->name() << " (" << dist[i] << " miles)";

        std::cout << "\n";
    }

}

std::stack<std::string> Graph::findShortestPath(Vertex* src, Vertex* dest) {
    int dist[size()];
    int parents[size()];
    std::stack<std::string> myStack;    //a path containing the path from the src to dest

    this->djikstra(src, dist, parents);
    int u = findIndex(dest);

    while(parents[u] != -1){
        myStack.push(listOfVertices.at(u)->name());
        u = parents[u];
    }
    myStack.push(listOfVertices.at(u)->name());
    return myStack;
}

/**
 * findIndex
 * Finds the index in the vertex vector that has the element key.
 */
int Graph::findIndex(Vertex *key) {
    // default to -1 if not found
    int index = -1;

    // break loop if found
    for (unsigned int i = 0; i < listOfVertices.size() && index == -1; i++) {
        if (listOfVertices[i] == key) {
            index = i;
        }
    }

    // return index
    return index;
}

/**
 * joinUnion
 * Helper for kruskal's algorithm that takes subgraphs and joins them together.
 * Since we are joining them we have to delete one from the list of subgraphs.
 * Returns the modified list of subgraphs.
 */
std::vector<Graph> Graph::joinUnion(std::vector<Graph> graphs, int indexA,
                                    int indexB) {
    // for all vertices in graph B
    for (unsigned int i = 0; i < graphs.at(indexB).vertices().size(); i++) {
        // store as pointer the current vertex
        Vertex *v = graphs.at(indexB).vertices()[i];

        // add the vertex to graph A
        graphs.at(indexA).insertVertex(v);
    }

    // erase the subgraph whose vertices we transferred to the other one
    graphs.erase(graphs.begin() + indexB);

    // return the modified list of graphs
    return graphs;
}

/*************************************************************************
 * Mutators
 *************************************************************************/
/**
 * initializeUSAMap
 * initializes the graph to have the vertices and edges from the assignment.
 */
void Graph::initializeUSAMap() {

    reversed = false;

    int size = 12;

    //an array of strings representing the vertices
    std::string vertices[12] = { "Atlanta",     //0
                                 "Boston",        //1
                                 "Chicago",       //2
                                 "Dallas",        //3
                                 "Denver",        //4
                                 "Houston",       //5
                                 "Kansas City",   //6
                                 "Los Angeles",   //7
                                 "Miami",         //8
                                 "New York",      //9
                                 "San Francisco", //10
                                 "Seattle"        //11
                               };

    for (int i = 0; i < size; i++) {
        insertVertex(vertices[i]);
    }

    //a 2d-array that represents the adjacency matrix to store
    //the edges of the matrix. note: adjacency matrices are O(n^2)
    int edges[size][size] = {
        /*0 Atlanta*/{ 0, 0, 0, 781, 0, 810, 864, 0, 661, 888, 0, 0 },
        /*1 Boston*/{ 0, 0, 983, 0, 0, 0, 0, 0, 0, 214, 0, 0 },
        /*2 Chicago*/{ 0, 983, 0, 0, 1003, 0, 533, 0, 0, 787, 0, 2097 },
        /*3 Dallas*/{ 781, 0, 0, 0, 0, 239, 496, 1435, 0, 0, 0, 0 },
        /*4 Denver*/{ 0, 0, 1003, 0, 0, 0, 599, 1015, 0, 0, 1267, 1331 },
        /*5 Houston*/{ 810, 0, 0, 239, 0, 0, 0, 0, 1187, 0, 0, 0 },
        /*6 Kansas City*/{ 864, 0, 553, 496, 599, 0, 0, 1663, 0, 1260, 0, 0 },
        /*7 Los Angeles*/{ 0, 0, 0, 1435, 1015, 0, 1663, 0, 0, 0, 381, 0 },
        /*8 Miami*/{ 661, 0, 0, 0, 0, 1187, 0, 0, 0, 0, 0, 0 },
        /*9 New York*/{ 888, 214, 787, 0, 0, 0, 1260, 0, 0, 0, 0, 0 },
        /*10 San Fran*/{ 0, 0, 0, 0, 1267, 0, 0, 381, 0, 0, 0, 807 },
        /*11 Seattle*/{ 0, 0, 0, 0, 1331, 0, 0, 0, 0, 0, 807, 0 } };

    // traverse 2d array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int edge = edges[i][j];
            int inverseEdge = edges[j][i];
            if (edge != 0) {
                // store origin and destination
                Vertex *origin = listOfVertices.at(i);
                Vertex *destination = listOfVertices.at(j);

                // it is directed if the inverse edge is not the same
                bool directed = edge != inverseEdge;

                // insert the edge into the graph
                insertEdge(origin, destination, edge, directed);
            }
        }
    }
}

/**
 * insertVertex
 * Inserts a vertex into graph, returns nothing.
 */
void Graph::insertVertex(Vertex *v) {
    listOfVertices.push_back(v);
}

void Graph::loadDefaultGraph()
{
    reversed = false;

    int size = 30;


    //an array of strings representing the vertices
    std::string vertices[] = {
        /* 1 */ "Angels Stadium of Anaheim",
        /* 2 */ "AT&T Park",
        /* 3 */ "Busch Stadium",
        /* 4 */ "Oriole Park at Camden Yards",
        /* 5 */ "Chase Field",
        /* 6 */ "Citi Field",
        /* 7 */ "Citizens Bank Park",
        /* 8 */ "Comerica Park",
        /* 9 */ "Coors Field",
        /* 10 */ "Dodger Stadium",
        /* 11 */ "Fenway Park",
        /* 12 */ "Great America Ball Park",
        /* 13 */ "Kauffman Stadium",
        /* 14 */ "Marlins Park",
        /* 15 */ "Miller Park",
        /* 16 */ "Minute Maid Park",
        /* 17 */ "Nationals Park",
        /* 18 */ "O.co Coliseum",
        /* 19 */ "Petco Park",
        /* 20 */ "PNC Park",
        /* 21 */ "Progressive Field",
        /* 22 */ "Globe Life Park in Arlington",
        /* 23 */ "Rogers Centre",
        /* 24 */ "SafeCo Field",
        /* 25 */ "Target Field",
        /* 26 */ "Tropicana Field",
        /* 27 */ "Turner Field",
        /* 28 */ "US Cellular Field",
        /* 29 */ "Wrigley Field",
        /* 30 */ "Yankee Stadium"
    };

    for (int i = 0; i < size; i++) {
        insertVertex(vertices[i]);
    }

    //a 2d-array that represents the adjacency matrix to store
    //the edges of the matrix. note: adjacency matrices are O(n^2)
    int edges[][30] = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 110, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 680, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 310, 235, 0, 0, 680, 0, 0, 0, 0, 0, 0, 0, 0, 465, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 580, 0, 0, 0, 0, 0, 0, 1115, 0, 650, 300, 0, 0, 870, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 195, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50},
        {0, 0, 0, 90, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 80},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 90, 0, 210, 0, 0, 0, 0, 240, 0, 0},
        {0, 0, 0, 0, 580, 0, 0, 0, 0, 0, 0, 0, 560, 0, 0, 0, 0, 0, 830, 0, 0, 650, 0, 0, 0, 0, 0, 0, 0, 0},
        {50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 340, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 195, 0, 0, 0, 0, 0, 0, 0, 1255, 0, 0, 0, 0, 0, 0, 0, 0, 430, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 310, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 260, 225, 0, 0, 0, 0, 790, 375, 250, 0, 0},
        {0, 0, 235, 0, 0, 0, 0, 0, 560, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 460, 0, 0, 0, 0, 0, 0, 415, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1255, 0, 0, 0, 0, 965, 930, 0, 0, 0, 0, 0, 0, 0, 0, 210, 600, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 430, 0, 300, 0, 0, 0, 80, 0},
        {0, 0, 680, 0, 1115, 0, 0, 0, 0, 0, 0, 0, 0, 965, 0, 0, 0, 0, 0, 0, 0, 230, 0, 0, 0, 790, 0, 0, 0, 0},
        {0, 0, 0, 50, 0, 0, 0, 0, 0, 0, 0, 0, 0, 930, 0, 0, 0, 0, 0, 195, 0, 0, 0, 0, 0, 0, 560, 0, 0, 0},
        {0, 50, 0, 0, 650, 0, 0, 0, 0, 340, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {110, 0, 0, 0, 300, 0, 0, 0, 830, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 260, 0, 0, 0, 0, 195, 0, 0, 0, 115, 0, 225, 0, 0, 0, 0, 0, 0, 315},
        {0, 0, 0, 0, 0, 0, 0, 90, 0, 0, 0, 225, 0, 0, 0, 0, 0, 0, 0, 115, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 870, 0, 0, 0, 650, 0, 0, 0, 460, 0, 0, 230, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 740, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 210, 0, 0, 430, 0, 0, 0, 430, 0, 0, 0, 0, 225, 0, 0, 0, 2070, 0, 0, 0, 0, 0, 0},
        {0, 680, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 2070, 0, 1390, 0, 0, 0, 0, 0},
        {0, 0, 465, 0, 0, 0, 0, 0, 0, 1500, 0, 0, 0, 0, 300, 0, 0, 0, 0, 0, 0, 0, 0, 1390, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 790, 0, 210, 0, 790, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 375, 0, 600, 0, 0, 560, 0, 0, 0, 0, 740, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 240, 0, 0, 0, 250, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 415, 0, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 50, 0, 0},
        {0, 0, 0, 0, 0, 50, 80, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 315, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0}
    };

    // traverse 2d array
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            int edge = edges[i][j];
            int inverseEdge = edges[j][i];
            if (edge != 0) {
                // store origin and destination
                Vertex *origin = listOfVertices.at(i);
                Vertex *destination = listOfVertices.at(j);
                //                qDebug() << "Origin: " << QString::fromStdString(listOfVertices.at(i)->name());
                //                qDebug() << "Destination: " << QString::fromStdString(listOfVertices.at(j)->name());
                //                qDebug() << "Length: " << edge;
                //                qDebug();

                // it is directed if the inverse edge is not the same
                bool directed = edge != inverseEdge;

                // insert the edge into the graph
                insertEdge(origin, destination, edge, directed);
            }
        }
    }
}

void Graph::loadSavedGraph()
{
    // DECLARE/INITIALIZE
    // input file stream
    std::ifstream inFile;

    // a string to traverse the file and read data
    std::string lineReader;

    std::string vertexName;

    int distance = 0;

    // open file
    inFile.open("data/SavedVertices.txt");

    // while in the file
    while (!inFile.eof()) {
        // get next line
        getline(inFile, vertexName);
        insertVertex(vertexName);
    }

    // close the file
    inFile.close();

    // open file
    inFile.open("data/SavedEdges.txt");

    for (int i = 0; i < size() && !inFile.eof(); i++) {
        for (int j = 0; j < size() && !inFile.eof(); j++) {
            Vertex *origin = findVertexByIndex(i);
            Vertex *destination = findVertexByIndex(j);
            inFile >> distance;

            if (distance > 0) {
                insertEdge(origin, destination, distance, false);
            }
        }
        if (!inFile.eof()) {
            // next line
            getline(inFile, lineReader);
        }
    }

    // close the file
    inFile.close();


}

void Graph::saveVertices()
{
    // output file stream to write to
    std::ofstream outFile;

    // open the save file
    outFile.open("data/SavedVertices.txt");

    for (int i = 0; i < size(); i++) {
        Vertex *v = listOfVertices.at(i);
        outFile << v->name();
        if (i + 1 < size()) {
            outFile << "\n";
        }
    }
    outFile.close();
}

void Graph::saveEdges()
{
    // output file stream to write to
    std::ofstream outFile;

    // open the save file
    outFile.open("data/SavedEdges.txt");

    for (int i = 0; i < size(); i++) {
        Vertex *currentVertex = listOfVertices.at(i);
        //int currentVertexIndex = findVertexByIndex(currentVertex);
        for (int j = 0; j < size(); j++) {
            Vertex *otherVertex = listOfVertices.at(j);

            int dist = length(currentVertex,otherVertex);

            if (dist != -1 && dist != 0 && currentVertex != otherVertex) {
                outFile << dist;
            }
            else {
                outFile << 0;
            }
            if (j + 1 < size()) {
                outFile << " ";
            }
        }
        if (i + 1 < size()) {
            outFile << "\n";
        }
    }
    outFile.close();
}

void Graph::saveAll()
{
    saveVertices();
    saveEdges();
}

/**
 * sortEdges
 * Sorts the edges in ascending order where you start with the edge with the
 * smallest weight
 */
void Graph::sortEdges() {
    std::sort(listOfEdges.begin(), listOfEdges.end(), GraphEdgeCompare);
}

//*********************************************************************
// insertVertex
// this method takes in a string and adds that string
//as a vertex. For now we are just representing a vertex
//as a string, but it could easily be extended to be
// an object or even a key, value etc.
//@param newName - the name of the vertex to add
//@return nothing - void
void Graph::insertVertex(std::string newName) {
    Vertex *newVector = new Vertex(newName);
    listOfVertices.push_back(newVector);
}

//*********************************************************************
//insertEdge
//this method takes in two vertices as end points to an
//edge as well as the length of the edge we are inserting
//into the graph. The best way to visualize this is to understand
//that each edge here is an object that has these required
//attributes (two vertices and a length).
//@param endPoint [in] - the 1st Vertex end point of the edge
//@param otherEndPoint [in] - the 2nd Vertex end point of the edge
//@param length [in] - the Double length of the edge (in miles)
//@return - nothing: void
void Graph::insertEdge(Vertex *origin, Vertex *destination, double length,
                       bool isDirected) {

    //instantiate new edge and push into the list
    Edge *newEdge = new Edge(origin, destination, length, isDirected);
    listOfEdges.push_back(newEdge);

    origin->addIncidentEdge(newEdge);
    destination->addIncidentEdge(newEdge);
}

/**
 * bfs
 * Performs a breadth-first traversal, outputting the discovery, back,
 * forward and cross edges while doing so.
 */
void Graph::bfs(Vertex *startVertex) {
    std::queue<Vertex*> queue;	// queue to store vertices
    int currentLevel = 0;		// current level of the search
    int visitedLocations = 0;	// the # of visited locatons
    // the total locations to visit
    int totalLocations = listOfVertices.size();

    // set the start vertex to be visited
    startVertex->visit();

    // since we are just starting, the level of the start vertex is 0
    startVertex->setLevel(0);

    // increment the amount of visited location
    visitedLocations++;

    // we start at level 0 and output that one location was visited
    std::cout << "Level 0:\n";
    std::cout << "Starting at " << startVertex->name() << " ("
              << visitedLocations << "/" << totalLocations
              << " locations visited)\n";

    // put the start vertex onto the queue
    queue.push(startVertex);

    while (!queue.empty()) {
        // the vertex we process for edges is popped from queue
        Vertex *vertex = queue.front();
        queue.pop();

        // sort the edges so we start with smallest cost
        vertex->sortIncidentEdges();

        // for all of the outgoing edges (the edges that have this vertex as
        // its origin
        for (unsigned int i = 0; i < vertex->outgoingEdges().size(); i++) {
            // current edge to be processed
            Edge *edge = vertex->outgoingEdges()[i];

            // this vertex is the other endpoint
            Vertex *vertex2 = edge->destination();

            if (!vertex2->isVisited()) {
                // if a new level output the new level so the output is neater
                // and more organized
                if (currentLevel != vertex->level() + 1) {
                    currentLevel = vertex->level() + 1;
                    std::cout << "\nLevel " << currentLevel << ":\n";
                }

                // the level of this vertex is one more than the level of the
                // parent
                vertex2->setLevel(vertex->level() + 1);

                // put this vertex into the queue
                queue.push(vertex2);

                // set the vertex to be visited
                vertex2->visit();

                // increment the amount of visited location
                visitedLocations++;

                // set the parent to be the origin
                vertex2->setParent(vertex);

                // since the vertex was unvisited it is a discovery edge
                std::cout << "Discovery edge ";
            } else {
                // referenced pseudocode from:
                // http://stackoverflow.com/questions/29631211/edge-
                // classification-during-breadth-first-search-on-a-directed-
                // graph
                Vertex *a = vertex;
                Vertex *b = vertex2;
                // keep going up the chain until you get to the same depth
                while (b->level() > a->level())
                    b = a->parent();
                while (a->level() > b->level())
                    a = a->parent();

                // and a and be are the same its a back edge
                if (a == b) {
                    std::cout << "Back edge ";
                } else {
                    // if not a back edge, then a cross edge. there are no
                    // forward edges in bfs
                    std::cout << "Cross edge ";
                }
            }

            // output edge information
            std::cout << "between " << vertex->name() << " and "
                      << vertex2->name() << " [" << edge->length() << " miles] ("
                      << visitedLocations << "/" << totalLocations
                      << " locations visited)\n";
        }
    }
    if (visitedLocations == totalLocations) {
        std::cout << "\nAll locations have been visited.\n";
        if (reversed) {
            // if reversed and still connected, then strongly connected
            std::cout << "\nThis graph is strongly connected because all "
                         "locations could also be visited when edge directions "
                         "were reversed.";
        }
    }

    // no forward edges in bfs
    std::cout << "\nThere are no forward edges in a BFS graph.\n\n";
}

//*********************************************************************
//dfs (Depth-First-Search)
//This method traverse through the graph of connected vertices by means
//of their edges. We start traversing at the startVertex passed into
//the method. We then decide to visit the vertex that has the shortest
//mileage. We will always discover new edges in the most efficient or
//(shortest) order.
//@param startVertex - the vertex to start the search at
//@return - nothing void
void Graph::dfs(Vertex *startVertex /* IN */) {

    //mark the vertex as visited
    startVertex->visit();

    startVertex->sortIncidentEdges();

    //for all incident edges of startVertex
    for (unsigned int i = 0; i < startVertex->incidentEdges().size(); i++) {
        Edge* edgeFromStartVertex = startVertex->incidentEdges().at(i);

        //is this edge visited?
        if (!edgeFromStartVertex->isVisited()) {
            edgeFromStartVertex->visit();

            //the vertex opposite of startVertex on this incident edge
            Vertex* oppositeVertex = edgeFromStartVertex->opposite(startVertex);

            //is the opposite vertex unvisited?
            if (!oppositeVertex->isVisited()) {
                //the edge is a discovery edge
                std::cout << "Edge Discovered between [" << startVertex->name()
                          << "] "
                             "and [" << oppositeVertex->name() << "]: "
                          << edgeFromStartVertex->length() << " Miles.\n";

                //keep searching and discovering new edges
                dfs(oppositeVertex);

                std::cout << "Backtracking to (" << startVertex->name()
                          << ")\n";
            }
        }
    }
}

/**
 * reverseEdges
 * Reverses all edges in the list, making their origin their destination and
 * vice-versa
 */
void Graph::reverseEdges() {
    std::cout << "Now reversing edges.\n";

    // mark the graph as opposite of current status
    reversed = reversed ? false : true;

    // for all edges in the graph
    for (unsigned int i = 0; i < listOfEdges.size(); i++) {
        // store the current in a pointer
        Edge *edge = listOfEdges[i];

        // call the reverse method for the edge
        edge->reverse();
    }
}

/**
 * unvisitAll
 * Set all vertices in the graph as unvisited and set their parents to null and
 * set their level to 0
 */
void Graph::unvisitAll() {
    // for all vertices in the graph set their parents to null and
    // set their level to 0
    for (unsigned int i = 0; i < listOfVertices.size(); i++) {
        Vertex *vertex = listOfVertices[i];
        vertex->setParent(NULL);
        vertex->setVisited(false);
        vertex->setLevel(0);
    }
}

