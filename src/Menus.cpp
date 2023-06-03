//
// Created by jmigu on 30/05/2023.
//

#include "../headers/Menus.h"

Menus::Menus(){}


void Menus::startMenu() {
    std::cout << "===========================================" << std::endl;
    std::cout << "Start Menu" << std::endl;
    std::cout << "1 - Problem 1" << std::endl;
    std::cout << "2 - Problem 2" << std::endl;
    std::cout << "3 - Problem 3" << std::endl;
    std::cout << "4 - Load/Change Graph" << std::endl;
    std::cout << "0 - Exit" << std::endl;
    std::cout << "Please select one of the previous options:" << std::endl;

    int option;
    std::cin >> option;

    switch(option){
        case 1:
            runProblem1();
            break;
        case 2:
            runProblem2();
            break;
        case 3:
            runProblem3();
            break;
        case 4:
            graphMenu();
            break;
        case 0:
            cout << "Exiting program..." << endl;
            exit(0);
        default:
            std::cout << "Invalid option, please try again." << std::endl;
            startMenu();
    }
}

void Menus::graphMenu() {

    std::cout << "===========================================" << std::endl;
    std::cout << "Load Graph" << std::endl;
    std::cout << "1 - Toy Graphs" << std::endl;
    std::cout << "2 - Medium Graphs" << std::endl;
    std::cout << "3 - Real World Graphs" << std::endl;
    std::cout << "0 - Start Menu" << std::endl;
    std::cout << "Please select one of the previous options:" << std::endl;

    int option;
    std::cin >> option;

    switch(option){
        case 1:
            toyGraphsMenu();
            break;
        case 2:
            mediumGraphsMenu();
            break;
        case 3:
            realWorldGraphsMenu();
            break;
        case 0:
            startMenu();
        default:
            std::cout << "Invalid option, please try again." << std::endl;
            graphMenu();
    }
}

void Menus::toyGraphsMenu() {
    string filename = "../data/toy_graphs/";

    std::cout << "===========================================" << std::endl;
    std::cout << "Toy Graphs" << std::endl;
    std::cout << "1 - Shipping" << std::endl;
    std::cout << "2 - Stadiums" << std::endl;
    std::cout << "3 - Tourism" << std::endl;
    std::cout << "0 - Graph Menu" << std::endl;
    std::cout << "Please select one of the previous options:" << std::endl;

    int option;
    std::cin >> option;

    switch(option){
        case 1:
            filename+= "shipping.csv";
            break;
        case 2:
            filename+= "stadiums.csv";
            break;
        case 3:
            filename+= "tourism.csv";
            break;
        case 0:
            graphMenu();
        default:
            std::cout << "Invalid option, please try again." << std::endl;
            toyGraphsMenu();
    }
    readCSV.setFilename(filename);
    clock_t begin = clock();
    graph = readCSV.readGraph();
    clock_t end = clock();
    cout << "Time to read graph: " << (double)(end-begin)/1000  << " seconds" << endl;
    startMenu();
}

void Menus::mediumGraphsMenu() {
    string filename = "../data/extra_fully_connected_graphs/";

    std::cout << "===========================================" << std::endl;
    std::cout << "Medium Graphs" << std::endl;
    std::cout << "1 - 25 Vertices" << std::endl;
    std::cout << "2 - 50 Vertices" << std::endl;
    std::cout << "3 - 75 Vertices" << std::endl;
    std::cout << "4 - 100 Vertices" << std::endl;
    std::cout << "5 - 200 Vertices" << std::endl;
    std::cout << "6 - 300 Vertices" << std::endl;
    std::cout << "7 - 400 Vertices" << std::endl;
    std::cout << "8 - 500 Vertices" << std::endl;
    std::cout << "9 - 600 Vertices" << std::endl;
    std::cout << "10 - 700 Vertices" << std::endl;
    std::cout << "11 - 800 Vertices" << std::endl;
    std::cout << "12 - 900 Vertices" << std::endl;
    std::cout << "0 - Graph Menu" << std::endl;
    std::cout << "Please select one of the previous options:" << std::endl;

    int option;
    std::cin >> option;

    switch(option){
        case 1:
            filename+="edges_25.csv";
            break;
        case 2:
            filename+="edges_50.csv";
            break;
        case 3:
            filename+="edges_75.csv";
            break;
        case 4:
            filename+="edges_100.csv";
            break;
        case 5:
            filename+="edges_200.csv";
            break;
        case 6:
            filename+="edges_300.csv";
            break;
        case 7:
            filename+="edges_400.csv";
            break;
        case 8:
            filename+="edges_500.csv";
            break;
        case 9:
            filename+="edges_600.csv";
            break;
        case 10:
            filename+="edges_700.csv";
            break;
        case 11:
            filename+="edges_800.csv";
            break;
        case 12:
            filename+="edges_900.csv";
            break;
        case 0:
            graphMenu();
        default:
            std::cout << "Invalid option, please try again." << std::endl;
            mediumGraphsMenu();
    }
    readCSV.setFilename(filename);
    clock_t begin = clock();
    graph = readCSV.readGraph();
    clock_t end = clock();
    cout << "Time to read graph: " << (double)(end-begin)/1000  << " seconds" << endl;
    startMenu();
}

void Menus::realWorldGraphsMenu() {
    string filename = "../data/real_world_graphs/";

    std::cout << "===========================================" << std::endl;
    std::cout << "Real World Graphs" << std::endl;
    std::cout << "1 - Graph 1" << std::endl;
    std::cout << "2 - Graph 2" << std::endl;
    std::cout << "3 - Graph 3" << std::endl;
    std::cout << "0 - Graph Menu" << std::endl;
    std::cout << "Please select one of the previous options:" << std::endl;

    int option;
    std::cin >> option;

    switch(option){
        case 1:
            filename+="graph1";
            break;
        case 2:
            filename+="graph2";
            break;
        case 3:
            filename+="graph3";
            break;
        case 0:
            graphMenu();
        default:
            std::cout << "Invalid option, please try again." << std::endl;
            realWorldGraphsMenu();
    }
    readCSV.setFilename(filename);
    clock_t begin = clock();
    graph = readCSV.readGraph();
    clock_t end = clock();
    cout << "Time to read graph: " << (double)(end-begin)/1000 << " seconds" << endl;
    startMenu();
}



void Menus::checkLoaded() {
    if(graph.getNumVertex() == 0) {
        cout << "No graph loaded, redirecting you to load graph menu." << endl;
        graphMenu();
    }
    else {
        cout << "Graph is properly loaded, running the problem..." << endl;
    }
    cout << endl;
}


void Menus::runProblem1() {

    checkLoaded();
    if(readCSV.getFilename().find("toy_graphs") == std::string::npos){
        cout << "This graph is too big for such a brute force algorithm, " << endl <<
                "and you should NOT run it as it is." << endl <<
                "It's advised, instead, to go for a toy graph." << endl <<
                "Would you like to do it anyways?(y/n)"<< endl;
        char option;
        cin >> option;
        if(toupper(option) == 'N') {
            startMenu();
        }
    }
    clock_t begin = clock();
    std::vector<Vertex *> tsp_path;
    double cost = graph.tspBT(tsp_path);
    clock_t end = clock();
    printPath(cost, tsp_path, end-begin);



    startMenu();
}

void Menus::runProblem2() {

    checkLoaded();

    clock_t begin = clock();
    std::vector<Vertex *> tsp_path;
    double cost = graph.tspApprox(tsp_path);
    clock_t end = clock();
    printPath(cost, tsp_path,end-begin);
    startMenu();

    startMenu();

}

void Menus::runProblem3() {

    checkLoaded();

    cout << "Not implemented yet." << endl;

    startMenu();

}

void Menus::printPath(double cost, std::vector<Vertex *> path, double time){
    cout << "The minimum cost is: " << cost << endl;
    std::cout << "The path for that value is: ";
    for (int i = 0; i < path.size(); i++) {
        cout << path[i]->getId();
        if(readCSV.getFilename().find("tourism") != std::string::npos) {
            cout << " (" << path[i]->getLabel() << ")";
        }
        cout  << (i == path.size() - 1 ? "\n" : " -> ");
    }
    cout << "The algorithm took " << (double)time/1000 << " seconds to run." << endl;
}

