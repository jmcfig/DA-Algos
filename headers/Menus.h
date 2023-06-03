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


    /**
    @brief Runs problem 1 based on the loaded graph.
    The runProblem1() function first checks if a graph is loaded by calling the checkLoaded() function. If no graph is loaded, it redirects the user to the load graph menu.
    If a graph is loaded, it checks if the filename of the loaded graph contains the substring "toy_graphs" by using the find() function. If the substring is not found, it displays a warning message indicating that the graph may be too big for a brute force algorithm and asks the user if they still want to proceed. If the user chooses not to proceed, it redirects them to the start menu.
    If the user chooses to proceed or if the loaded graph is a toy graph, it measures the time taken to solve the TSP problem using a backtracking algorithm by capturing the clock value before and after the algorithm execution. It also stores the path of the TSP solution in a vector called tsp_path and the cost of the TSP solution in the variable cost.
    Finally, it calls the printPath() function to display the cost and the path of the TSP solution. It then redirects the user to the start menu.
    @note This function assumes that the graph and readCSV objects are member variables of the Menus class.
    @note The time complexity of the TSP problem solved by the backtracking algorithm in this function is exponential, O(2^n * n^2), where n is the number of vertices in the graph.
    @return void
    */
    void runProblem1();


    /**
    @brief Runs Problem 2.
    The runProblem2() function executes Problem 2. It first checks if a graph is loaded by calling the checkLoaded() function.
    After that, it measures the time taken to execute the tspApprox() function, which approximates the Traveling Salesman Problem (TSP) solution for the loaded graph. The resulting TSP path and its cost are stored in the tsp_path vector and cost variable, respectively.
    The time taken to execute the tspApprox() function is measured using the clock() function. The difference between the end and begin clock ticks represents the execution time.
    Finally, it calls the printPath() function to display the TSP path and cost, and then returns to the start menu by calling the startMenu() function.
    @note This function assumes that the graph object is a member variable of the Menus class.
    @note The time complexity of this function depends on the complexity of the tspApprox() function and the size of the loaded graph.
    @return void
    */
    void runProblem2();


    /**
    @brief Runs Problem 3.
    The runProblem3() function executes Problem 3. It first checks if a graph is loaded by calling the checkLoaded() function.
    As of now, Problem 3 is not implemented, and the function displays a message stating that it is not implemented yet.
    Finally, it returns to the start menu by calling the startMenu() function.
    @note This function assumes that the graph object is a member variable of the Menus class.
    @note The time complexity of this function is negligible since it only displays a message and returns to the start menu.
    @return void
    */
    void runProblem3();


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



private:
    Graph graph;
    ReadCSV readCSV;



};

#endif

