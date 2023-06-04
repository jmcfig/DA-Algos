#ifndef MENUS
#define MENUS


#include "Graph.h"
#include "ReadCSV.h"

class Menus {
public:
    Menus();



    void startMenu();



    void graphMenu();



    void toyGraphsMenu();



    void realWorldGraphsMenu();



    void mediumGraphsMenu();



    void runProblem(int problem_number);





    void printPath(double cost, vector<Vertex*> path, double time);


    void checkLoaded();

    void checkPlausible();

private:
    Graph graph;
    ReadCSV readCSV;



};

#endif

