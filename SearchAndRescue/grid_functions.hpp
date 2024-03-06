#ifndef GRID_FUNCTIONS_HPP_INCLUDED
#define GRID_FUNCTIONS_HPP_INCLUDED

#include <iostream>
#include "grid.hpp"

using namespace std;

Grid createGrid(int N)
{
    // Create N by N grid
    int node_number = N*N;

    Grid g(node_number);

    for (int i = 0; i < N; i++){
        for (int j = 1; j <= N; j++){

            int id = i*10 + j;         // id of current tile

            if (j == 1){              // First column
                if (i == 0){          // First tile
                    vector<int> tile = {id+1,id+10};
                    g.addTile(id,tile);
                }
                else if (i == N-1){
                    vector<int> tile = {id+1,id-10};
                    g.addTile(id,tile);
                }
                else{
                    vector<int> tile = {id-10,id+1,id+10};
                    g.addTile(id,tile);
                }
            }
            else if(j == 9){          // Last column
                if (i == 0){
                    vector<int> tile = {id-1,id+10};
                    g.addTile(id,tile);
                }
                else if(i == 8){
                    vector<int> tile = {id-1,id-10};
                    g.addTile(id,tile);
                }
                else{
                    vector<int> tile = {id-10,id-1,id+10};
                    g.addTile(id,tile);
                }
            }
            else{
                if(i == 0)
                {
                    vector<int> tile = {id-1,id+1,id+10};
                    g.addTile(id,tile);
                }
                else if(i == 8){
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
    return g;
}

#endif // GRID_FUNCTIONS_HPP_INCLUDED
