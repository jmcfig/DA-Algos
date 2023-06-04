#ifndef VERTEX_EDGE
#define VERTEX_EDGE

#include <iostream>
#include <vector>
#include <queue>
#include <limits>
#include <algorithm>
#include "MutablePriorityQueue.h"

class Edge;

#define INF std::numeric_limits<double>::max()

/************************* Vertex  **************************/

class Vertex {
public:
    Vertex(int id);
    Vertex(int id, double latitude, double longitude); //used for real-world graph
    Vertex(int id, const std::string &label);

    bool operator<(Vertex & vertex) const; // // required by MutablePriorityQueue


    int getId() const;
    std::vector<Edge *> getAdj() const;
    bool isVisited() const;
    bool isProcessing() const;
    unsigned int getIndegree() const;
    double getDist() const;
    int getPath() const;

    bool isInMst() const;

    void setInMst(bool inMst);

    const std::string &getLabel() const;

    std::vector<Edge *> getIncoming() const;

    void setId(int info);
    void setVisited(bool visited);
    void setProcesssing(bool processing);
    void setIndegree(unsigned int indegree);
    void setDist(double dist);
    void setPath(int path);
    Edge * addEdge(Vertex *dest, double w);
    bool removeEdge(int destID);
    void removeOutgoingEdges();
    bool hasEdgeTo(int id) const;
    Edge* getEdgeTo(Vertex* vertex);

    double getLatitude() const;

    double getLongitude() const;


    friend class MutablePriorityQueue<Vertex>;

protected:
    int id;                // identifier
    std::vector<Edge *> adj;  // outgoing edges
    std::string label; //tourism only
    double latitude; //real world only
    double longitude; //real world only

    // auxiliary fields
    bool visited = false; // used by DFS, BFS, Prim ...
    bool processing = false; // used by isDAG (in addition to the visited attribute)
    bool inMST; // used by Prim
    unsigned int indegree; // used by topsort
    double dist = 0;
    int path = -1;

    std::vector<Edge *> incoming; // incoming edges

    int queueIndex = 0; 		// required by MutablePriorityQueue and UFDS

    void deleteEdge(Edge *edge);
};

/********************** Edge  ****************************/

class Edge {
public:
    Edge(Vertex *orig, Vertex *dest, double w);

    Vertex * getDest() const;
    double getWeight() const;
    bool isSelected() const;

    Vertex * getOrig() const;
    Edge *getReverse() const;
    double getFlow() const;

    bool isInMst() const;

    void setInMst(bool inMst);

    void setSelected(bool selected);
    void setReverse(Edge *reverse);
    void setFlow(double flow);

    class EdgeCompare{
    public:
        bool operator()(const Edge* e1, const Edge* e2) const{
            return e1->getWeight() > e2->getWeight();
        }
    };

    bool operator<(const Edge *rhs) const;

    bool operator>(const Edge *rhs) const;

    bool operator<=(const Edge *rhs) const;

    bool operator>=(const Edge *rhs) const;

protected:
    Vertex * dest; // destination vertex
    double weight; // edge weight, can also be used for capacity

    // auxiliary fields
    bool selected = false;
    bool inMST; // used by Prim

    // used for bidirectional edges
    Vertex *orig;
    Edge *reverse = nullptr;

    double flow; // for flow-related problems
};

#endif