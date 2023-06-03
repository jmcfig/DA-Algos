//
// Created by jmigu on 30/05/2023.
//

#include "../headers/ReadCSV.h"


ReadCSV::ReadCSV() {}

void ReadCSV::setFilename(const string &filename) {
    ReadCSV::filename = filename;
}

Graph ReadCSV::readGraph() {
    if(filename.find(".csv") != std::string::npos) return oneFileGraph();

    else return twoFilesGraph();
}

Graph ReadCSV::oneFileGraph() {
    Graph graph;

    ifstream file(filename);
    if (!file.is_open()) {
        cout << "File with path " << filename << " could not be opened.";
        return graph;
    }

    string line;
    if(filename.find("toy_graphs") != std::string::npos) getline(file, line);
    while (getline(file, line)) {

        Vertex *v1, *v2;

        stringstream ss(line); string s;
        vector<string> strings;

        while(getline(ss, s, ','))
            strings.push_back(s);

        int source = stoi(strings[0]);
        int dest = stoi(strings[1]);
        double distance = stod(strings[2]);

        if(strings.size()>3){
            string sourceLabel = strings[3];
            string destLabel = strings[4];
            v1 = new Vertex(source, sourceLabel);
            v2 = new Vertex(dest, destLabel);
        }
        else {
            v1 = new Vertex(source);
            v2 = new Vertex(dest);
        }
        graph.addVertex(v1);
        graph.addVertex(v2);
        graph.addBidirectionalEdge(source, dest, distance);
    }
    file.close();
    return graph;
}

Graph ReadCSV::twoFilesGraph() {
    Graph graph;

    ifstream nodesFile(filename + "/nodes.csv");
    ifstream edgesFile(filename + "/edges.csv");

    if (!nodesFile.is_open()) {
        cerr << "File with path " << filename << "/nodes.csv" << " could not be opened.";
        return graph;
    }

    if (!edgesFile.is_open()) {
        cerr << "File with path " << filename << "/edges.csv" << " could not be opened.";
        return graph;
    }


    string line;
    getline(nodesFile, line);
    while (getline(nodesFile, line)) {

        stringstream ss(line); string s;
        vector<string> strings;

        while(getline(ss, s, ','))
            strings.push_back(s);

        int id = stoi(strings[0]);
        double longitude = stof(strings[1]);
        double latitude = stof(strings[2]);

        Vertex* v = new Vertex(id, longitude, latitude);
        graph.addVertex(v);
    }

    getline(edgesFile, line);
    while (getline(edgesFile, line)) {
        stringstream ss(line); string s;
        vector<string> strings;

        while(getline(ss, s, ','))
            strings.push_back(s);

        int source = stoi(strings[0]);
        int dest = stoi(strings[1]);
        double distance = stod(strings[2]);

        graph.addBidirectionalEdge(source, dest, distance);
    }

    nodesFile.close();
    edgesFile.close();
    return graph;
}

const string &ReadCSV::getFilename() const {
    return filename;
}

