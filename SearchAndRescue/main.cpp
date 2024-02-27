#include <iostream>
#include "graph.hpp"
#include "grid_functions.cpp"

using namespace std;
int main()
{

    Graph g = createGrid(8);
    // Print the adjacency matrix
    int** matrix = g.getMatrix();
    //g.printMatrix();

    //g.printGraph();
    cout<<g.next(0,1);

    return 0;
}




