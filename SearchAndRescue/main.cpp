#include <iostream>
#include "graph.hpp"
#include "grid.hpp"
#include "grid_functions.hpp"


using namespace std;
int main()
{
    vector<int>path;

    Grid g = createSubGrid(1,22,63,11);
    //g.printGrid();

//    g.getTileStatus(1);


    path = func(g,1);
    cout<<"+++++++"<<endl;
    for (int p: path)
        cout<<p<<endl;
    //path = g.calculatePath(1,83);
//
//    for (int t : g.unvisited_tiles)
//        cout<<t<<endl;

//    g.changeTileStatus(11,Visited::VISITED);

//    cout<<"+++++++++++"<<endl;
//    for (int t : g.unvisited_tiles)
//        cout<<t<<endl;

    return 0;
}




