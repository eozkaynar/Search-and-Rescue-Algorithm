#include <iostream>
#include "graph.hpp"
#include "grid.hpp"
#include "grid_functions.hpp"


using namespace std;
int main()
{
    vector<int>path;
    Grid g(2);
    g = createSubGrid(2,6,2,3);
    g.printGrid();
    //g.changeTileStatus(1,Visited::VISITED);
    //g.getTileStatus(1);
    g.addObstacle(6);
    g.printGrid();




//
    path = g.calculatePath(1,81);

    for (int p : path)
        cout<<p<<endl;
    return 0;
}




