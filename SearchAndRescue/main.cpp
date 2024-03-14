#include <iostream>
#include "graph.hpp"
#include "grid.hpp"
#include "grid_functions.hpp"


using namespace std;
int main()
{
    vector<int>path;
    Grid g(2);
    g = createSubGrid(3,44,57,58);
    g.printGrid();
    //g.changeTileStatus(1,Visited::VISITED);
    //g.getTileStatus(1);

    path = g.calculatePath(54,59);

    for (int p : path)
        cout<<p<<endl;

    // deneme yorum

    return 0;
}




