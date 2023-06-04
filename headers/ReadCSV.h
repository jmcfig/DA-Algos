#ifndef READ_CSV
#define READ_CSV

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>
#include "Graph.h"


using namespace std;

class ReadCSV {
public:
    ReadCSV();


    /**
    @brief Sets the filename for reading the CSV data.
    The setFilename() function sets the filename to be used for reading the CSV data.
    @param filename The name of the CSV file to be read.
    @note The time complexity of this function is constant, or O(1).
    @return void
    */
    void setFilename(const string &filename);

    void setFile(string filename);


    /**
    @brief Retrieves the filename associated with the ReadCSV object.
    The getFilename() function returns the filename associated with the ReadCSV object.
    @note The time complexity of this function is O(1).
    @return The filename associated with the ReadCSV object.
    */
    const string &getFilename() const;


    /**
    @brief Reads and constructs a graph from the specified CSV file(s).
    The readGraph() function reads and constructs a graph based on the specified CSV file(s).
    If the filename contains ".csv", it assumes a single file format and calls the oneFileGraph() function.
    Otherwise, it assumes a two-file format and calls the twoFilesGraph() function.
    @note The time complexity of this function depends on the specific implementation of oneFileGraph() and twoFilesGraph() functions.
    @return The constructed graph.
    */
    Graph readGraph();

    //aux functions


    /**
    @brief Constructs a graph from a single CSV file.
    The oneFileGraph() function constructs a graph by reading data from a single CSV file.
    The CSV file should contain lines representing edges between vertices, with each line containing the source vertex ID, destination vertex ID, and distance.
    If the CSV file includes additional columns, it considers them as labels for the vertices.
    @note The time complexity of this function depends on the size of the CSV file and the number of vertices and edges in the graph.
    @return The constructed graph.
    */
    Graph oneFileGraph();


    /**
    @brief Constructs a graph from two separate CSV files.
    The twoFilesGraph() function constructs a graph by reading data from two separate CSV files: nodes.csv and edges.csv.
    The nodes.csv file should contain lines representing vertices, with each line containing the vertex ID, longitude, and latitude.
    The edges.csv file should contain lines representing edges between vertices, with each line containing the source vertex ID, destination vertex ID, and distance.
    @note The time complexity of this function depends on the size of the CSV files and the number of vertices and edges in the graph.
    @return The constructed graph.
    */
    Graph twoFilesGraph();

private:
    std::string filename;
};


#endif