#ifndef GRAPH
#define GRAPH

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include <cmath>
#include <stack>
#include <float.h>
#include "MutablePriorityQueue.h"
#include "VertexEdge.h"

class Graph {
public:
    ~Graph();


    /*
    * Auxiliary function to find a vertex with a given ID.
    */
    /**
    @brief Finds a vertex in the graph by its ID.
    The findVertex() function searches for a vertex in the graph based on its ID.
    It iterates over the vertex set and returns the first vertex with a matching ID,
    or nullptr if no vertex is found.
    @note The time complexity of this function is O(|V|), where |V| is the number of vertices in the graph.
    @param id The ID of the vertex to find.
    @return A pointer to the vertex with the specified ID, or nullptr if not found.
    */
    Vertex *findVertex(const int &id) const;


    /*
     *  Adds a vertex with a given content or info (in) to a graph (this).
     *  Returns true if successful, and false if a vertex with that content already exists.
     */

    /**
    @brief Adds a vertex to the graph.
    The addVertex() function adds a vertex to the graph. It first checks if a vertex with the same ID already exists
    in the graph by calling the findVertex() function. If a vertex with the same ID is found, it returns false,
    indicating that the vertex was not added. Otherwise, it adds the vertex to the vertex set of the graph by
    pushing it into the vector. The function returns true to indicate that the vertex was added successfully.
    @param v A pointer to the vertex to be added.
    @return True if the vertex was added successfully, false if a vertex with the same ID already exists.
    @note The time complexity of this function is O(V), where V is the number of vertices in the graph,
    as it involves searching for a vertex in the vertex set.
   */
    bool addVertex(Vertex *v);

    /*
     * Adds an edge to a graph (this), given the contents of the source and
     * destination vertices and the edge weight (w).
     * Returns true if successful, and false if the source or destination vertex does not exist.
     */
    /**
    @brief Adds an edge to the graph.
    The addEdge() function adds an edge to the graph between two vertices with the specified IDs.
    It first checks if the source and destination vertices exist in the graph. If either of them does not exist,
    it returns false indicating that the edge was not added. Otherwise, it adds the edge from the source vertex
    to the destination vertex with the specified weight and returns true.
    @param sourc The ID of the source vertex.
    @param dest The ID of the destination vertex.
    @param w The weight of the edge.
    @return True if the edge was added successfully, false if either the source or destination vertex does not exist.
    @note The time complexity of this function is O(V), where V is the number of vertices in the graph,
    as it involves finding the source and destination vertices in the vertex set.
    */
    bool addEdge(const int &sourc, const int &dest, double w);


    /**
    @brief Adds a bidirectional edge between two vertices in the graph.
    The addBidirectionalEdge() function adds a bidirectional edge between two vertices in the graph. It first checks
    if both source and destination vertices exist in the graph by calling the findVertex() function. If either vertex
    is not found, it returns false, indicating that the edge was not added. Otherwise, it adds an edge from the source
    vertex to the destination vertex using the addEdge() function of the source vertex, and adds a reverse edge from
    the destination vertex to the source vertex using the addEdge() function of the destination vertex. The reverse
    edges are set using the setReverse() function to maintain bidirectionality. The function returns true to indicate
    that the bidirectional edge was added successfully.
    @param sourc The ID of the source vertex.
    @param dest The ID of the destination vertex.
    @param w The weight of the edge.
    @return True if the bidirectional edge was added successfully, false if either source or destination vertex is not found.
    @note The time complexity of this function is O(V), where V is the number of vertices in the graph,
    as it involves searching for both vertices in the vertex set.
    */
    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);


    /**
    @brief Returns the number of vertices in the graph.
    The getNumVertex() function returns the number of vertices in the graph.
    @note The time complexity of this function is O(1).
    @return The number of vertices in the graph.
    */
    int getNumVertex() const;


    /**
    @brief Returns a vector containing all the vertices in the graph.
    The getVertexSet() function returns a vector containing all the vertices
    in the graph. The order of the vertices in the vector is not guaranteed.
    @note The time complexity of this function is O(1).
    @return A vector containing all the vertices in the graph.
    */
    std::vector<Vertex *> getVertexSet() const;

    double tspBT(std::vector<Vertex*> &path);
    void tspBTRec(Vertex *curVertex, unsigned int curIndex, double curDist, std::vector<Vertex*> &curPath, double &minDist, std::vector<Vertex*> &path);


    double haversine(Vertex *v1, Vertex *v2);


    double tspApprox(std::vector<Vertex*> &path);
    std::vector<Edge*> prim();
    void dfs(Vertex *v,std::vector<Edge *> mst,  std::vector<Vertex*> &path);

    void nnRec(Vertex *&start, Vertex *&curr, std::vector<Vertex *> &path, double &distance);

    double tspNearestNeighbor(std::vector<Vertex*> &path);


protected:
    std::vector<Vertex *> vertexSet;    // vertex set





    /*
     * Finds the index of the vertex with a given content.
     */
    /**
    @brief Finds the index of a vertex in the graph by its ID.
    The findVertexIdx() function searches for a vertex in the graph based on its ID
    and returns the index of the vertex in the vertex set. It iterates over the vertex set
    and returns the index of the first vertex with a matching ID, or -1 if no vertex is found.
    @note The time complexity of this function is O(|V|), where |V| is the number of vertices in the graph.
    @param id The ID of the vertex to find.
    @return The index of the vertex with the specified ID, or -1 if not found.
    */
    int findVertexIdx(const int &id) const;



};


#endif