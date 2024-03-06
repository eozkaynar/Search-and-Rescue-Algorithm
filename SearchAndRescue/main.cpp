#include <iostream>
#include "graph.hpp"
#include "grid.hpp"
#include "grid_functions.hpp"


using namespace std;
int main()
{
    vector<int>path;
    Grid g(2);
    g = createGrid(9);
   // g.printGrid();
    //g.changeTileStatus(1,Visited::VISITED);
    //g.getTileStatus(1);
    g.printGrid();

//
//    g.addObstacle(2);
//    g.addObstacle(8);
//
////
//    path = g.calculatePath(1,9);
//
//    for (int p : path)
//        cout<<p<<endl;
    return 0;
}




