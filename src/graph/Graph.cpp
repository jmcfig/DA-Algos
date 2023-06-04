
#include "../../headers/graph/Graph.h"

int Graph::getNumVertex() const {
    return vertexSet.size();
}

std::vector<Vertex *> Graph::getVertexSet() const {
    return vertexSet;
}


/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(const int &id) const {
    for (auto v : vertexSet)
        if (v->getId() == id)
            return v;
    return nullptr;
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    for (unsigned i = 0; i < vertexSet.size(); i++)
        if (vertexSet[i]->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(Vertex *v) {
    if (findVertex(v->getId()) != nullptr)
        return false;
    vertexSet.push_back(v);
    return true;
}

/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */
bool Graph::addEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

bool Graph::addBidirectionalEdge(const int &sourc, const int &dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    auto e1 = v1->addEdge(v2, w);
    auto e2 = v2->addEdge(v1, w);
    e1->setReverse(e2);
    e2->setReverse(e1);
    return true;
}

void deleteMatrix(int **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void deleteMatrix(double **m, int n) {
    if (m != nullptr) {
        for (int i = 0; i < n; i++)
            if (m[i] != nullptr)
                delete [] m[i];
        delete [] m;
    }
}

void Graph::tspBTRec(Vertex *curVertex, unsigned int curIndex, double curDist, std::vector<Vertex*> &curPath, double &minDist, std::vector<Vertex*> &path) {
    curVertex->setVisited(true); // Mark the current vertex as visited

    curPath[curIndex-1] = curVertex; // Update the current path with the current vertex

    // Check if all vertices have been visited (i.e., a complete tour)
    if(curIndex == vertexSet.size()) {
        curVertex->setVisited(false); // Reset for the next possible path

        Edge* edge = curVertex->getEdgeTo(curPath[0]);
        if(edge){
            curDist += edge->getWeight(); // Add the distance from the last vertex to the first vertex
            if(curDist < minDist) { // Check if the total distance is less than the minimum distance
                minDist = curDist;
                path = curPath;
            }
        }
        return;
    }

    // Try to move to the i-th vertex if the total distance does not exceed the best distance found and the vertex is not yet visited
    for(auto edge: curVertex->getAdj()) {
        Vertex* vertex = edge->getDest();

        if(!vertex->isVisited() && curDist + edge->getWeight() < minDist) { // Check if vertex is unvisited and total distance is less than minimum distance
            tspBTRec(vertex, curIndex+1, curDist + edge->getWeight(), curPath, minDist, path);
        }
    }

    curVertex->setVisited(false); // Reset for the next possible path
}

double Graph::tspBT(std::vector<Vertex*> &path) {
    std::vector<Vertex*> curPath(vertexSet.size()); // Dynamic memory allocation

    double minDist = INF;

    for(auto vertex: vertexSet) {
        vertex->setVisited(false);
    }

    // Assumes path starts at node 0
    tspBTRec(vertexSet[0], 1, 0.0, curPath, minDist, path);


    return minDist;
}


void Graph::dfs(Vertex* v, std::vector<Edge*> mst,  std::vector<Vertex*> &path){

    v->setVisited(true);
    path.push_back(v);
    for(Edge* e: mst){
        if(!e->getDest()->isVisited() && e->getOrig() == v){
            dfs( e->getDest(), mst, path);
        }
    }
}

std::vector<Edge*> Graph::prim(){

    std::vector<Edge*> mst;
    std::priority_queue<Edge*, std::vector<Edge*>, Edge::EdgeCompare> pq;


    Vertex* start = vertexSet[0];
    for(Edge* e : start->getAdj()){
        pq.push(e);
    }

    while(!pq.empty()){
        Edge* minEdge = pq.top();
        pq.pop();
        Vertex* dest = minEdge->getDest();

        // If the destination vertex is not in the MST
        if(!dest->isInMst()){
            dest->setInMst(true);
            mst.push_back(minEdge);

            for(Edge* e : dest->getAdj()){
                if(!e->getDest()->isInMst()){
                    pq.push(e);
                }
            }
        }
    }
    return mst;
}


double Graph::tspApprox(std::vector<Vertex*> &path){

    for(Vertex* v : vertexSet){
        v->setVisited(false);
        v->setInMst(false);
    }

    std::vector<Edge*> mst = prim();
    dfs(vertexSet[0],mst,path);


    double total = 0.0;

    for(int i = 0; i < path.size() - 1; i++){
        Vertex* v1 = path[i];
        Vertex* v2 = path[i + 1];

        if(!v1->hasEdgeTo(v2->getId())){
            total += haversine(v1,v2);
            continue;
        }
        for(auto edge: v1->getAdj()){
            if(edge->getDest() == v2){
                total += edge->getWeight();
                break;
            }
        }
    }

    Vertex* final = path.back();
    if(!final->hasEdgeTo(0)){
        total += haversine(final,path[0]);
    }else{
        for(auto edge: final->getAdj()){
            if(edge->getDest()->getId() == 0){
                total += edge->getWeight();
                break;
            }
        }
    }

    return total;
}

double Graph::haversine(Vertex *v1, Vertex *v2) {
    double lat1 = v1->getLatitude();
    double lon1 = v1->getLongitude();
    double lat2 = v2->getLatitude();
    double lon2 = v2->getLongitude();

    double dLat = (lat2 - lat1) * M_PI / 180.0;
    double dLon = (lon2 - lon1) * M_PI / 180.0;

    lat1 = lat1 * M_PI / 180.0;
    lat2 = lat2 * M_PI / 180.0;

    double a = pow(sin(dLat / 2), 2) + pow(sin(dLon / 2), 2) * cos(lat1) * cos(lat2);
    double c = 2 * asin(sqrt(a));

    return 6371.0 * c;
}

double Graph::tspNearestNeighbor(std::vector<Vertex *> &path) {

    for(Vertex* v : vertexSet)
        v->setVisited(false);

    Vertex* start = vertexSet[0];
    Vertex* curr = vertexSet[0];
    double distance = 0.0;

    nnRec(start,curr,path,distance);

    if(path.back()->hasEdgeTo(path[0]->getId()))
        distance += path.back()->getEdgeTo(path[0])->getWeight();
    else
        distance += haversine(path.back(),path[0]);

    return distance;
}


void Graph::nnRec(Vertex* &start, Vertex* &curr, std::vector<Vertex*>& path, double &distance){
    int visitedVertices = 0;
    for(Vertex *v: vertexSet)
        if(v->isVisited()) visitedVertices++;

    if(visitedVertices >= vertexSet.size())
        distance += haversine(curr, start);

    curr->setVisited(true);
    path.push_back(curr);

    Edge *minEdge = nullptr;
    double minWeight = std::numeric_limits<double>::max();
    for(auto e: curr->getAdj()){
        if(!e->getDest()->isVisited() && e->getWeight() < minWeight){
            minEdge = e;
            minWeight = e->getWeight();
        }
    }

    if(minEdge){
        distance += minWeight;
        curr = minEdge->getDest();
        nnRec(start, curr, path, distance);
    }
}


Graph::~Graph() {

}


