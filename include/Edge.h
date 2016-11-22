/*************************************************************************
 * AUTHOR	     : Steve Fajardo
 * STUDENT ID    : 832032
 * ASSIGNMENT #14: Djikstra & MST
 * CLASS	     : CS1D
 * SECTION       : MW 4:30 P.M.
 * DUE DATE      : 4/25/16
 ************************************************************************/

#ifndef EDGE_H_
#define EDGE_H_

// Declare but don't define Vertex, because the Vertex and Edge classes have
// members of the type of each other
class Vertex;

/*************************************************************************
 * Class Edge
 * This class is a representation of an edge between two vertices. It
 * includes the length of the edge.
 *************************************************************************/
class Edge {
public:
    /*************************************************************************
    * Constructors & Destructors
    *************************************************************************/
	/**
	 * Edge
	 * The constructor for Edge. It sets the both end points of the edge and
	 * the length of the edge. It also initializes the "visited" member to
	 * false. Visited is whether the edge has been visited.
	 */
    Edge(Vertex* originVertex, Vertex* destinationVertex, double newLength, bool isDirected = false);

	/**
	 * ~Edge
	 * This is the destructor for the Edge class.
	 */
	~Edge();

    /*************************************************************************
    * Mutators
    *************************************************************************/
	/**
	 * visit
	 * Sets the edge to have been visited, setting data member visited to true.
	 */
	void visit();

	/**
	 * reverse
	 * Reverses the endpoints of the edge, making the origin the destination
	 * vice-versa.
	 */
	void reverse();

    /*************************************************************************
    * Accessors
    *************************************************************************/
	/**
	 * length
	 * Returns the length of the edge.
	 */
	double length() const;


	/**
	 * hasEndPoint
	 * Returns whether the Vertex type parameter key is one of the edge's
	 * end points.
	 */
	bool hasEndPoint(Vertex *key) const;

	/**
	 * isVisited
	 * Returns whether the edge has been visited.
	 */
	bool isVisited() const;

	//*****************************************************************
	//opposite
	//this method returns the vertex that is opposite of the vertex
	//on this edge that was passed in.
	//@param otherVertex - the vertex to find the opposite of
	//@return a pointer to the vertex opposite of the vertex passed in
	Vertex* opposite(Vertex* otherVertex);

	/**
	 * endPointA
	 * Returns the head of the edge if directed, or just one endpoint if not
	 */
    Vertex* destination();

	/**
	 * endPointB
	 * Returns the second end point of the edge, as a Vertex type pointer.
	 */
    Vertex* origin();

	/**
	 * isSameEdge
	 * Returns whether this edge is the same as the parameter Edge pointer.
	 */
	bool isSameEdge(Edge *otherEdge);

	/**
	 * isDirected
	 * Returns whether the edge is directed
	 */
	bool isDirected() const;

	/**
	 * hasEndpoints
	 * Returns whether the edge consists of the two paramter vertices
	 */
	bool hasEndpoints(Vertex *vertexA, Vertex *vertexB);

private:
	Vertex* endVertices[2]; // the end point vertices of the edge
	double edgeLength; 		// the length of the edge
	bool visited;			// whether the edge has been visited
	bool directed;			// whether the edge is directed
};

#endif /* EDGE_H_ */
