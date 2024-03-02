#include <iostream>
#include "graph.hpp"
#include "grid.hpp"
#include "grid_functions.hpp"


using namespace std;
int main()
{

    Grid g(9);
    g = createGrid(9);
    g.printGrid();


    return 0;
}




