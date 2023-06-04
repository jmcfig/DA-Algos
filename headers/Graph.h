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
    @note The time complexity of this function is O(V)
    @param id The ID of the vertex to find.
    @return A pointer to the vertex with the specified ID, or nullptr if not found.
    */
    Vertex *findVertex(const int &id) const;




    /**
    @brief Adds a vertex to the graph.
    @param v A pointer to the vertex to be added.
    @return True if the vertex was added successfully, false if a vertex with the same ID already exists.
    @note The time complexity of this function is O(V)
   */
    bool addVertex(Vertex *v);

    /**
    @brief Adds an edge to the graph.
    @param sourc The ID of the source vertex.
    @param dest The ID of the destination vertex.
    @param w The weight of the edge.
    @note The time complexity of this function is O(V)
    @return True if the edge was added successfully, false if either the source or destination vertex does not exist.
    */
    bool addEdge(const int &sourc, const int &dest, double w);


    /**
    @brief Adds a bidirectional edge between two vertices in the graph.
    @param sourc The ID of the source vertex.
    @param dest The ID of the destination vertex.
    @param w The weight of the edge.
    @note The time complexity of this function is O(V)
    @return True if the bidirectional edge was added successfully, false if either source or destination vertex is not found.
    */
    bool addBidirectionalEdge(const int &sourc, const int &dest, double w);


    /**
    @brief Give the number of vertices in the graph.
    @note The time complexity of this function is O(1).
    @return The number of vertices in the graph.
    */
    int getNumVertex() const;


    /**
    @brief Give a vector containing all the vertices in the graph.
    @note The time complexity of this function is O(1).
    @return A vector containing all the vertices in the graph.
    */
    std::vector<Vertex *> getVertexSet() const;
    /**
     * @brief Call the tspBTRec function to find the shortest path in a graph using the Backtracking approach for the Traveling Salesman Problem (TSP).
     * @param path Reference to the vector representing the shortest path.
     * @return  The total distance of the shortest path.
     */
    double tspBT(std::vector<Vertex*> &path);
    /**
     * @brief Finds the shortest path in a graph using the Backtracking approach for the Traveling Salesman Problem (TSP).
     * @param curVertex Pointer to the current vertex being visited.
     * @param curIndex The index of the current vertex in the path.
     * @param curDist The current total distance of the path.
     * @param curPath Reference to the vector representing the current path.
     * @param minDist Reference to the minimum distance found so far.
     * @param path Reference to the vector representing the shortest path.
     * @note The complexity of this algorithm is O(V!).
     */
    void tspBTRec(Vertex *curVertex, unsigned int curIndex, double curDist, std::vector<Vertex*> &curPath, double &minDist, std::vector<Vertex*> &path);
    /**
     * @brief Calculates the Haversine distance between two vertices representing geographic coordinates.
     * @param v1 Pointer to the first vertex.
     * @param v2 Pointer to the first vertex.
     * @note The complexity of this algorithm is O(1).
     * @return The Haversine distance between the two vertices.
     */

    double haversine(Vertex *v1, Vertex *v2);
    /**
     * @brief Finds an approximate solution for the Traveling Salesman Problem (TSP) using a greedy algorithm.
     * @param path Reference to the vector representing the shortest path.
     * @note The complexity of this algorithm is O(E+v log V).
     * @return The total distance of the shortest path.
     */
    double tspApprox(std::vector<Vertex*> &path);
    /**
     * @brief Calculates the MST of the graph using Prim's algorithm.
     * @note The complexity of this algorithm is O(E+V log V).
     * @return A vector containing the edges of the MST.
     */
    std::vector<Edge*> prim();
    /**
     * @brief Performs a depth-first search (DFS) traversal on the minimum spanning tree (MST) of the graph.
     * @param v Pointer to the current vertex being visited.
     * @param mst Vector containing the edges of the MST.
     * @param path Reference to the vector representing the path.
     * @note The complexity of this algorithm is O(E+V).
     */
    void dfs(Vertex *v,std::vector<Edge *> mst,  std::vector<Vertex*> &path);
    /**
     * @brief Applies the Nearest Neighbor (NN) algorithm recursively to find a heuristic solution for the Traveling Salesman Problem (TSP).
     * @param start The starting vertex for the TSP tour.
     * @param curr The current vertex being visited in the recursion.
     * @param path A vector of vertices to store the TSP tour path.
     * @param distance The total distance of the TSP tour.
     * @note The complexity of this algorithm is O(V^2).
     */
    void nnRec(Vertex *&start, Vertex *&curr, std::vector<Vertex *> &path, double &distance);
    /**
     *  @brief Use the nnRec function to find a heuristic solution for the Traveling Salesman Problem (TSP).
     * @param path A vector of vertices to store the TSP tour path.
     * @note The complexity of this algorithm is O(V^2).
     * @return The total distance of the TSP tour.
     */
    double tspNearestNeighbor(std::vector<Vertex*> &path);


protected:
    std::vector<Vertex *> vertexSet;
    /**
     * @brief Finds the index of a vertex in the vertexSet vector.
     * @param id The id of the vertex to find.
     * @return The index of the vertex in the vertexSet vector, or -1 if not found.
     */
    int findVertexIdx(const int &id) const;
};
#endif