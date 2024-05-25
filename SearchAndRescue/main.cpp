#include <iostream>
#include "graph.hpp"
#include "grid.hpp"
#include "grid_functions.hpp"


using namespace std;
int main()
{
    //Visited v = VISITED;
    Path p,p1;
    Tile * t;
    vector<int> path,path1;
    vector<int> x;

    int dead,dead1;

    Tile * ti;


    int Target1;
    int Target2;
    int Target3;

    int base1;
    int base2;
    int base3;

    int obs1    = 0;
    int obs2    = 86;
    int obs3    = 75;
    int Target  = 84;

    int your_turn = 2;
    int your_id   = 1;
    int finder    = 3;

    Grid gb = createSubGrid(0,obs1,obs2,obs3);
    Grid g1 = createSubGrid(1,obs1,obs2,obs3);
    Grid g2 = createSubGrid(2,obs1,obs2,obs3);
    Grid g3 = createSubGrid(3,obs1,obs2,obs3);

    base1   = g1.base_tiles[0];
    base2   = g2.base_tiles[0];
    base3   = g3.base_tiles[0];

    int current_location = base1;


    GetTargetTiles(finder,Target1, Target2, Target3, Target,gb,g1,g2,g3);
    cout<< Target1<<endl;
    cout<< Target2<<endl;
    cout<< Target3<<endl;

    g1.addObstacle(63);
    g1.addObstacle(53);
    vector<int> tiles = g1.Tiles_IDs_vector();
//    for (int t : tiles)
//        cout<<t<<endl;

    int a = findClosestElement(tiles,69);
    cout<<a<<endl;

    //p = TargetPath(your_turn,your_id, finder,current_location,base1,base2, base3, Target1, Target2, Target3,gb);
    //for (int u : p.path)
    //    cout<< u <<" ";

//
//    ti = gb.getTile(29);
//    gb.changeTileStatus(56,Visited::UNVISITED);
//    cout<< ti->weight << endl;
////
//
//
//    updateGrids(g1,g2,g3,dead); // update grid en baþta ve ilk functan sonra çağır
//
//    p = func(g1,1);
//    path = p.path;
//    dead = p.dead_tile;
//
//    if (dead1 != -1)
//        updateGrids(g1,g2,g3,dead);
//
//    gb.printGrid();
//
//    GoToTarget( Target1, Target2, Target3, Target,gb);
//
//    cout<<"Target 1: " <<Target1 <<endl;
//    cout<<"Target 2: " << Target2 <<endl;
//    cout<<"Target 3: " << Target3 <<endl;



    return 0;
}




