// By: Gonçalo Leão

#include "Graph.h"
#include "MutablePriorityQueue.h"

int Graph::getNumVertex() const {
    return vertexMap.size();
}

std::unordered_map<int, Vertex*> Graph::getVertexMap() const {
    return vertexMap;
}

/*
 * Auxiliary function to find a vertex with a given content.
 */
Vertex * Graph::findVertex(int id) const {
    auto it = vertexMap.find(id);
    if(it != vertexMap.end()){
        return it->second;
    }
    else{
        return nullptr;
    }
}

/*
 * Finds the index of the vertex with a given content.
 */
int Graph::findVertexIdx(const int &id) const {
    int i = 0;
    for (auto it = vertexSet.begin(); it !=  vertexSet.end(); it++, ++i)
        if ((*it)->getId() == id)
            return i;
    return -1;
}
/*
 *  Adds a vertex with a given content or info (in) to a graph (this).
 *  Returns true if successful, and false if a vertex with that content already exists.
 */
bool Graph::addVertex(int id) {
    if (findVertex(id) != nullptr)
        return false;
    auto *v = new Vertex(id);
    vertexSet.insert(v);
    vertexMap.insert({id,v});
    return true;
}

bool Graph::addVertex(int id, double longitude, double latitude){
    if(findVertex(id) != nullptr){
        return false;
    }
    auto *v = new Vertex(id,longitude,latitude);
    vertexSet.insert(v);
    vertexMap.insert({id,v});
    return true;
}


/*
 * Adds an edge to a graph (this), given the contents of the source and
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if the source or destination vertex does not exist.
 */

bool Graph::addEdge(int sourc, int dest, double w) {
    auto v1 = findVertex(sourc);
    auto v2 = findVertex(dest);
    if (v1 == nullptr || v2 == nullptr)
        return false;
    v1->addEdge(v2, w);
    return true;
}

bool
Graph::addBidirectionalEdge(int sourc,int dest,double w) {
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

void Graph::dfs(int vertex, const vector<int> &parent_, vector<bool> &visited, stack<int> &stack, vector<int> &path){
    visited[vertex] = true;
    stack.push(vertex);

    while(!stack.empty()){
        int top = stack.top();
        stack.pop();

        path.push_back(top);

        for(int adj = 0 ; adj < parent_.size(); adj++){
            if(parent_[adj] == top && !visited[adj]){
                visited[adj] = true;
                stack.push(adj);
            }
        }
    }
}

vector<pair<int,int>> Graph::prim(vector<int> &parent_){
    vector<double> weights(vertexMap.size(),numeric_limits<double>::max());
    vector<bool> inMST(vertexMap.size(),false);

    int start = 0;
    weights[start] = 0.0;

    for(int i = 0; i < vertexMap.size() -1; i++){
        int minW = minWeight(weights, inMST);
        inMST[minW] = true;

        for(auto edge: vertexMap[minW]->getAdj()){
            int v = edge->getDest()->getId();
            double weight = edge->getWeight();

            if(!inMST[v] && weight < weights[v]){
                parent_[v] = minW;
                weights[v] = weight;
            }
        }
    }

    vector<pair<int,int>> mst;

    for(int i = 1; i < vertexMap.size(); i++){
        mst.push_back(make_pair(parent_[i],i));
    }

    return mst;
}

int Graph::minWeight(vector<double> &weights,vector<bool> &inMST){
    double min = numeric_limits<double>::max();
    int minIndex = -1;

    for(int i = 0; i < weights.size(); i++){
        if(!inMST[i] && weights[i] < min){
            min = weights[i];
            minIndex = i;
        }
    }
    return minIndex;
}

//This function explores the graph starting from a certain vertex, updates the path, marks vertices as visited, and keeps track of the minimum cost.
// When all vertices have been visited, it checks and updates the minimum cost to complete the cycle.
void Graph::tsp_backtrack(vector<int> &path, vector<bool>& visited, double &min_cost, double costSoFar){
    if(path.size() == vertexSet.size()){
        int start_vertex = path.front();
        int last_vertex = path.back();
        for(Edge *edge: (vertexMap.find(last_vertex))->second->getAdj()){
            if(edge->getDest()->getId() == start_vertex){
                double cost = costSoFar + edge->getWeight();
                if(cost < min_cost){
                    min_cost = cost;
                }
                break;
            }

        }
        return;
    }

    int last_vertex = path.back();
    for(Edge *edge: (vertexMap.find(last_vertex))->second->getAdj()){
        if(!visited[edge->getDest()->getId()]){
            path.push_back(edge->getDest()->getId());
            visited[edge->getDest()->getId()] = true;

            tsp_backtrack(path,visited,min_cost,costSoFar + edge->getWeight());
            path.pop_back();
            visited[edge->getDest()->getId()] = false;
        }
    }
}

/*
 * Checks if any of v1's destination nodes is v2
 * destination vertices and the edge weight (w).
 * Returns true if successful, and false if v1 doesn't have v2 has destination node.
 */
bool Graph::haveEdge(int v1, int v2){
    int index;
    for(int i = 0; i < vertexMap.size(); i++){
        if(vertexMap[i]->getId() == v1){
            index = i;
        }
    }

    for(auto edge: vertexMap[index]->getAdj()){
        if(edge->getDest()->getId() == v2){
            return true;
        }
    }
    return false;
}

//This function computes the distance between two geographical points (given as latitude and longitude) using the Haversine formula.
//The result, given in meters, approximates the shortest distance over the Earth's surface.
double Graph::haversine(double lat1, double lon1, double lat2, double lon2){

    double lat1Rad = lat1 * M_PI /180;
    double lon1Rad = lon1 * M_PI /180;
    double lat2Rad = lat2 * M_PI /180;
    double lon2Rad = lon2 * M_PI /180;

    double latDiff = lat2Rad -lat1Rad;
    double lonDiff = lon2Rad -lon1Rad;

    double a = sin(latDiff/2.00) * sin(latDiff/2.00) + cos(lat1Rad) * cos(lat2Rad) * sin(lonDiff/2.00) * sin(lonDiff/2.00);

    double c = 2.00 * atan2(sqrt(a), sqrt(1-a));

    double distance = 6371000.0 * c;

    return distance;
}

//This function computes the cumulative distance of a path. For non-existing edges, it uses the Haversine formula to estimate the distance.
// The returned total includes the return distance to the path's starting vertex.
double Graph::totalDistance(const vector<int> &path){
    double total = 0.0;

    for(int i = 0; i < path.size() - 1; i++){
        int v1 = path[i];
        int v2 = path[i + 1];

        if(!haveEdge(v1,v2)){
            total += haversine(vertexMap[v1]->getLat(),vertexMap[v1]->getLon(),vertexMap[v2]->getLat(),vertexMap[v2]->getLon());
            continue;
        }
        for(auto edge: vertexMap[v1]->getAdj()){
            if(edge->getDest()->getId() == v2){
                total += edge->getWeight();
                break;
            }
        }
    }

    int final = path.back();
    if(!haveEdge(final,path[0])){
        total += haversine(vertexMap[final]->getLat(),vertexMap[final]->getLon(),vertexMap[path[0]]->getLat(),vertexMap[path[0]]->getLon());
    }else{
        for(auto edge: vertexMap[final]->getAdj()){
            if(edge->getDest()->getId() == path[0]){
                total += edge->getWeight();
                break;
            }
        }
    }

    return total;
}
//This function uses Prim's algorithm to create a minimum spanning tree, then performs a DFS to form a path.
// It computes and returns the total distance of the path. The path is also printed, starting and ending at vertex 0.
double Graph::triangularApproximation(){
    vector<int> parent_(vertexSet.size(),-1);
    prim(parent_);

    vector<bool> visited(vertexMap.size(),false);
    vector<int> path;
    stack<int> stack;
    dfs(0,parent_,visited,stack,path);

    for(int i = 0; i < path.size(); i++){
        cout << path[i] << " -> " ;
    }
    cout << "0" << endl;

    double total = totalDistance(path);

    return total;

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

Graph::Graph() {
    deleteMatrix(distMatrix, vertexSet.size());
    deleteMatrix(pathMatrix, vertexSet.size());
}

