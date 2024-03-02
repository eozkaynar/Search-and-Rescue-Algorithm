#include <iostream>
#include "graph.hpp"
#include "grid.hpp"

using namespace std;
int main()
{
/*
    Graph g = createGrid(8);
    // Print the adjacency matrix
    int** matrix = g.getMatrix();
    //g.printMatrix();

    //g.printGraph();
    cout<<g.next(0,1);
*/
    int i = 2;
    Grid g(9);
    vector<int> n1 = {};
    vector<int> n2 = {1};
    vector<int> n3 = {1, 2};
    vector<int> n4 = {1, 2, 3};
    vector<int> n5 = {2};
    vector<int> n6 = {4, 5};
    vector<int> n7 = {5, 6};



    g.addTile(1, n1);
    g.addTile(2, n2);
    g.addTile(3, n3);
    g.addTile(4, n4);
    g.addTile(5, n5);
    g.addTile(6, n6);
    g.addTile(7, n7);

    g.printGrid();


    return 0;
}




