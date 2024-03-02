#include <iostream>
#include "grid.hpp"
#include <algorithm>

using namespace std;

// Helper function to remove Grid
void removeTilesById(vector<Tile>& Tiles, int idToRemove)
{
    // Check for each Tile
    for (int i = 0 ; i < Tiles.size()-1; i++)
    {
        // If corresponding Tile is found
        if (Tiles[i].getId() == idToRemove)
        {
            // Swap elements at start and end indices
            // Push the corresponding Tile to end of the vector
            Tile temp    = Tiles[i];
            Tiles[i]     = Tiles[i+1];
            Tiles[i+1]   = temp;

        }
    }
    // Delete the Tile from back
    Tiles.pop_back();
}

// ***** Tile Class *****

// Constructors
// Default constructor
Tile::Tile():id(0)
{}
// Constructor
Tile::Tile(int id, vector<int>& neighbors):id(id),neighbors(neighbors) {}

// the functions getId and getNeighbors.
int Tile::getId()
{
    return id;
}

vector<int>& Tile::getNeighbors()
{
    return neighbors;
}


// ***** Grid Class *****

// Constructor
Grid::Grid(int N):N(N) {}

//functions

Tile* Grid::getTile(int id)
{
    // For each Tile in Tiles
    for (Tile& Tile : tiles)
    {
        if (Tile.getId() == id) // If the Tile id is equal to id
        {
            return &Tile;
        }
    }
    return nullptr; // If the id is not exists
}

void Grid::addTile(int id, std::vector<int>& neighbors)
{
    bool FLAG_EXIST = true;
    int NeighborId;
    Tile* NeighborTile;
    // Create a new Tile
    Tile NewTile(id,neighbors);
    // Add Tile to Tiles vector
    tiles.push_back(NewTile);

    for (int i = 0; i<neighbors.size(); i++)
    {
        // Neighbor's Id
        NeighborId     = neighbors[i];
        // Get the neighbor
        NeighborTile   = getTile(NeighborId);
        // If the NeighborTile exists add Tile to its neighbors
        if(NeighborTile != NULL)
        {
            vector<int> NeighbOfNeigb = NeighborTile->getNeighbors(); // Neighbors vector of neighbor of Tile
            for (int n : NeighbOfNeigb)
            {
                if(n == id) // If the Tile already exists in neighbors of its neighbors, make the flag false
                    FLAG_EXIST = false;
            }
            if (FLAG_EXIST) // If the Tile does not exists in neighbors of its neighbors, add to its neighbors' neighbors
                NeighborTile->getNeighbors().push_back(id);
        }
    }
}

void Grid::removeTile(int id)

{
    // Check for each Tile
    for(Tile& Tile : tiles)
    {
        // Remove Tile from neighbors vector
        vector<int>& neighbors = Tile.getNeighbors();
        // Check each neighbor of Tile's neighbors
        for (int neighbor : neighbors)
        {
            // If removed Tile is found
            if(neighbor == id)
            {
                for (size_t j = 0; j < neighbors.size(); ++j)
                {
                    if (neighbors[j] == id)
                    {
                        neighbors.erase(neighbors.begin() + j);
                        break;
                    }
                }
            }

        }
    }
    // Remove Tile
    removeTilesById(tiles, id);
}
// Print Grid
void Grid::printGrid()
{
    for(Tile& Tile : tiles)
    {
        // Remove Tile from neighbors vector
        vector<int>& neighbors = Tile.getNeighbors();
        // Check each neighbor of Tile's neighbors
        cout<<"tile:" << Tile.getId() << "neig: " ;
        for (int neighbor : neighbors)
        {
            cout<< neighbor<<" ";

        }
        cout<< endl;
    }
}