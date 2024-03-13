#ifndef GRID_FUNCTIONS_HPP_INCLUDED
#define GRID_FUNCTIONS_HPP_INCLUDED

#include <iostream>
#include "grid.hpp"

using namespace std;

Grid createGrid(int N, int M, int init_id)
{
    /*
        N: number of rows
        M: number of colums
        init_id: initial id of grid
    */

    //Define base 34 ekle

    // int base = 34;
    // Create N by M grid
    int node_number = N*M;

    Grid g(node_number);

    int k = init_id/10; // row number
    int l = init_id%10; // column number

    for (int i = k; i < N+k; i++){
        for (int j = l; j < M+l; j++){

            int id = i*10 + j;         // id of current tile

            if (j == l){              // First column
                if (i == k){          // First tile
                    vector<int> tile = {id+1,id+10};
                    g.addTile(id,tile);
                }
                else if (i == N+k-1){
                    vector<int> tile = {id+1,id-10};
                    g.addTile(id,tile);
                }
                else{
                    vector<int> tile = {id-10,id+1,id+10};
                    g.addTile(id,tile);
                }
            }
            else if(j == M+l-1){          // Last column
                if (i == k){
                    vector<int> tile = {id-1,id+10};
                    g.addTile(id,tile);
                }
                else if(i == N+k-1){
                    vector<int> tile = {id-1,id-10};
                    g.addTile(id,tile);
                }
                else{
                    vector<int> tile = {id-10,id-1,id+10};
                    g.addTile(id,tile);
                }
            }
            else{
                if(i == k)
                {
                    vector<int> tile = {id-1,id+1,id+10};
                    g.addTile(id,tile);
                }
                else if(i == N+k-1){
                    vector<int> tile = {id-10,id-1,id+1};
                    g.addTile(id,tile);
                }
                else{
                    vector<int> tile = {id-10,id-1,id+1,id+10};
                    g.addTile(id,tile);
                }
            }
        }
    }
    //g.addObstacle(base);
    return g;
}

// Subgrid partitioning algorithm
Grid createSubGrid(int sub_id,int obs1,int obs2,int obs3)
{

    int base = 34;
    /*
        sub_id : id for 3 different search area
        obs1   : id of first obstacle
        obs2   : id of second obstacle
        obs3   : id of third
        base   : id of base unit
    */
    Grid subGrid(0);
    switch (sub_id)
        {
            case 1:
                {
                subGrid = createGrid(9,3,1);
                break;
                }

            case 2:
                {
                subGrid = createGrid(4,6,4);
                break;
                }

            case 3:
                {
                subGrid = createGrid(5,6,44);
                break;
                }
            default:
                cout<<"Wrong subGrid"<<endl;
        }

//    subGrid.addObstacle(obs1);
//    subGrid.addObstacle(obs2);
//    subGrid.addObstacle(obs3);
//    //subGrid.addObstacle(34);


    return subGrid;

}

#endif // GRID_FUNCTIONS_HPP_INCLUDED
