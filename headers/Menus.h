#ifndef MENUS
#define MENUS


#include "graph/Graph.h"
#include "ReadCSV.h"

class Menus {
public:
    Menus();


    /**
    @brief Displays the start menu and handles user input.
    The start menu presents several options to the user and waits for input.
    Based on the selected option, it calls the corresponding functions or displays an error message
    if an invalid option is selected. It also allows the user to exit the program.
    @note The time complexity of this function is O(1).
    @return void
    */
    void startMenu();


    /**
    @brief Displays the graph menu and handles user input for graph selection.
    The graph menu presents several options to the user for selecting a graph type.
    Based on the selected option, it calls the corresponding functions to further
    interact with the selected graph type. It also allows the user to return to the
    start menu or displays an error message if an invalid option is selected.
    @note The time complexity of this function is O(1).
    @return void
    */
    void graphMenu();


    /**
    @brief Displays the menu for selecting toy graphs and handles user input.
    The toy graphs menu presents several options to the user for selecting a toy graph.
    Based on the selected option, it sets the corresponding filename and reads the graph
    from the CSV file. It also allows the user to return to the start menu or displays an
    error message if an invalid option is selected. After reading the graph, it displays
    the time taken to read the graph and returns to the start menu.
    @note The time complexity of this function depends on the time complexity of reading the graph from the CSV file.
    @return void
    */
    void toyGraphsMenu();


    /**
    @brief Displays the menu for selecting real-world graphs and handles user input.
    The real-world graphs menu presents several options to the user for selecting a real-world graph.
    Based on the selected option, it sets the corresponding filename and reads the graph
    from the CSV file. It also allows the user to return to the start menu or displays an
    error message if an invalid option is selected. After reading the graph, it displays
    the time taken to read the graph and returns to the start menu.
    @note The time complexity of this function depends on the time complexity of reading the graph from the CSV file.
    @return void
    */
    void realWorldGraphsMenu();


    /**
    @brief Displays the menu for selecting medium graphs and handles user input.
    The medium graphs menu presents several options to the user for selecting a medium-sized graph.
    Based on the selected option, it sets the corresponding filename and reads the graph
    from the CSV file. It also allows the user to return to the start menu or displays an
    error message if an invalid option is selected. After reading the graph, it displays
    the time taken to read the graph and returns to the start menu.
    @note The time complexity of this function depends on the time complexity of reading the graph from the CSV file.
    @return void
    */
    void mediumGraphsMenu();



    void runProblem(int problem_number);




    /**
    @brief Prints the minimum cost path and algorithm execution time.
    The printPath() function displays the minimum cost, the corresponding path, and the algorithm execution time.
    @param cost The minimum cost of the path.
    @param path The vector containing the vertices in the minimum cost path.
    @param time The execution time of the algorithm in milliseconds.
    @note The time complexity of this function depends on the size of the path vector, which is O(n), where n is the number of vertices in the path.
    @return void
    */
    void printPath(double cost, vector<Vertex*> path, double time);


    /**
    @brief Checks if a graph is loaded and performs the necessary actions based on the result.
    The checkLoaded() function checks if a graph is loaded by calling the getNumVertex() function on the graph object. If the number of vertices in the graph is 0, it displays a message indicating that no graph is loaded and redirects the user to the load graph menu by calling the graphMenu() function.
    If a graph is loaded, it displays a message indicating that the graph is properly loaded and proceeds to run the problem.
    After performing the necessary actions, it outputs a newline character for formatting purposes.
    @note This function assumes that the graph object is a member variable of the Menus class.
    @note The time complexity of this function is O(1), as it performs a simple check on the number of vertices in the graph.
    @return void
    */
    void checkLoaded();

    void checkPlausible();

private:
    Graph graph;
    ReadCSV readCSV;



};

#endif

