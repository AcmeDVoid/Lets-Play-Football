#include "include/Edge.h"
#include "include/Vertex.h"

/**
 * Edge
 * The constructor for Edge. It sets the both end points of the edge and
 * the length of the edge. It also initializes the "visited" member to
 * false. Visited is whether the edge has been visited.
 */
Edge::Edge(Vertex* originVertex, Vertex* destinationVertex, double newLength, bool isDirected) {
    directed = isDirected;

    // Set the end points (vertices) of the edge
    endVertices[0] = originVertex;
    endVertices[1] = destinationVertex;

    // sets the length of the edge
    edgeLength = newLength;

    // initialize the edge has not having been visited
    visited = false;
}


/**
 * ~Edge
 * This is the destructor for the Edge class.
 */
Edge::~Edge() {

}

/*************************************************************************
* Mutators
*************************************************************************/
/**
 * visit
 * Sets the edge to have been visited, setting data member visited to true.
 */
void Edge::visit() {
    visited = true;
}

/**
 * reverse
 * Reverses the endpoints of the edge, making the origin the destination
 * vice-versa.
 */
void Edge::reverse() {
    Vertex *oldOrigin = endVertices[0];
    Vertex *oldDestination = endVertices[1];

    endVertices[0] = oldDestination;
    endVertices[1] = oldOrigin;
}

/*************************************************************************
* Accessors
*************************************************************************/
/**
 * length
 * Returns the length of the edge.
 */
double Edge::length() const {
    return edgeLength;
}

/**
 * hasEndPoint
 * Returns whether the Vertex type parameter key is one of the edge's
 * end points.
 */
bool Edge::hasEndPoint(Vertex *key) const {
    // check both end points and see if its equal to the key.
    return endVertices[0] == key || endVertices[1] == key;
}

/**
 * isVisited
 * Returns whether the edge has been visited.
 */
bool Edge::isVisited() const {
    return this->visited;
}

/**
 * destination
 * Returns the destination vertex of the edge, or one of the end points if not
 * directed.
 */
Vertex* Edge::destination() {
    return endVertices[1];
}

/**
 * origin
 * Returns the origin vertex of the edge, or one of the end points if not directed.
 */
Vertex* Edge::origin() {
    return endVertices[0];
}

/**
 * isSameEdge
 * Returns whether this edge is the same as the parameter Edge pointer.
 */
bool Edge::isSameEdge(Edge *otherEdge) {
    // initialize bool as true. If it fails any tests, it will be set to
    //	false.
    bool same = true;

    // if the first end point is not the same as both of the end points of the
    // other edge.
    // it is not the same edge
    if (endVertices[0] != otherEdge->destination()
            && endVertices[0] != otherEdge->origin()) {
        same = false;
    }

    // if the second end point is not the same as both of the end points of the
    // other edge.
    // it is not the same edge
    if (same && endVertices[1] != otherEdge->destination()
            && endVertices[1] != otherEdge->origin()) {
        same = false;
    }

    // if the lengths of the two edges been compared are not the same
    // it is not the same edge
    if (same && length() != otherEdge->length()) {
        same = false;
    }

    // return whether it is the same edge
    return same;
}

//*****************************************************************
//opposite
//this method returns the vertex that is opposite of the vertex
//on this edge that was passed in.
//@param otherVertex - the vertex to find the opposite of
//@return a pointer to the vertex opposite of the vertex passed in
Vertex* Edge::opposite(Vertex* otherVertex /* IN */) {
    //if the first vertex matches the one we passed in, we will
    //return the 2nd vertex (b/c we want the opposite)
    if (endVertices[0]->name() == otherVertex->name()) {
        return endVertices[1];
    }
    //otherwise the 1st vertex does not match the 2nd vertex
    //and we can return the 1st vertex (b/c it is opposite)
    else {
        return endVertices[0];
    }
}

/**
 * isDirected
 * Returns whether the edge is directed
 */
bool Edge::isDirected() const {
    return directed;
}

/**
 * hasEndpoints
 * Returns whether the edge consists of the two paramter vertices
 */
bool Edge::hasEndpoints(Vertex *vertexA, Vertex *vertexB) {
    // both vertices must be an endpoint of this edge
    return hasEndPoint(vertexA) && hasEndPoint(vertexB);
}
