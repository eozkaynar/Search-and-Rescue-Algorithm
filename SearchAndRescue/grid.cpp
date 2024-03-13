#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <climits> // For INT_MAX

#include "grid.hpp"

using namespace std;

//**** HELPER FUNCTIONS ****//

// The function to get index value of key in the vector
int getTileIndex(vector<Tile> tiles, int key)
{
    int index = 0;
    for (Tile& tile : tiles)
    {
        if (tile.getId() == key) // If key is found
            return index;
        index++;
    }

    // If the element is not found
    return -1;
}

// Remove zeros function for the path finding algorithm
void removeZeros(vector<int>& v)
{
    for (auto it = v.begin(); it != v.end(); )
    {
        if (*it == 0)         // If iterator pointing's value is 0
            it = v.erase(it); // Delete zeros
        else
            it++;             // Increase the iterator pointing
    }
}

// Helper function to remove Grid

void removetilesById(std::vector<Tile>& tiles, int idToRemove) {
    // Find the position of the element to remove
   auto it = std::find_if(tiles.begin(), tiles.end(), [idToRemove](Tile& t) {
        return t.getId() == idToRemove;
    });;

    // Check if the element exists in the vector
    if (it != tiles.end()) {
        // Erase the element from the vector
        tiles.erase(it);
    }
}

// ***** Tile Class *****

// Constructors
// Default constructor
Tile::Tile():id(0)
{}
// Constructor
Tile::Tile(int id, vector<int>& neighbors):id(id),neighbors(neighbors) {}

// the functions getId, getStatus and getNeighbors.
int Tile::getId()
{
    return id;
}

int Tile::getStatus()
{
    if(status == Visited::VISITED)
        return 1;
    else
        return 0;
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
    // For each Tile in tiles
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
    // Add Tile to tiles vector
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

void Grid::addObstacle(int id)
{
    // Check for each Tile
    for(Tile& Tile : tiles){
        // Remove Tile from neighbors vector
        vector<int>& neighbors = Tile.getNeighbors();
        // Check each neighbor of Tile's neighbors
        for (int neighbor : neighbors){
            // If removed Tile is found
            if(neighbor == id){
                for (size_t j = 0; j < neighbors.size(); ++j)
                {
                    if (neighbors[j] == id){
                        neighbors.erase(neighbors.begin() + j);
                        break;
                    }
                }
            }
        }

    }
    for(Tile& Tile : tiles){
                // Remove Tile
        if(Tile.getId() == id)
            removetilesById(tiles, id);
    }

}

// Print Grid
void Grid::printGrid()
{
    for(Tile& Tile : tiles)
    {
        // Remove Tile from neighbors vector
        vector<int>& neighbors = Tile.getNeighbors();
        // Check each neighbor of Tile's neighbors
        cout<<"Tile: " << Tile.getId() << " " << "Neigbors: " ;
        for (int neighbor : neighbors)
        {
            cout<< neighbor<<" ";
        }
        cout<< endl;
    }
}
// Grid member function to change Tile visiting status
void Grid::changeTileStatus(int id,Visited status)
{
    int index = getTileIndex(tiles,id);
    Tile& t = tiles[index];
    t.status = status;

    for(Tile& Tile : tiles)
    {
        cout<<"Tile: " <<  Tile.getStatus()<< endl;
    }
}

// Get tile's status with id
int Grid::getTileStatus(int id)
{
    int index = getTileIndex(tiles,id);
    Tile& t = tiles[index];
    cout<<"Tile: " << id <<"Status: " <<t.getStatus()<< endl;
}

std::vector<int> Grid::calculatePath(int source, int destination)
{
    int numOftiles = tiles.size();

    // Queue to Dijkstra's algorithm
    std::queue<int> q;

    // Stack to get the path
    std::stack<int> PathStack;
    int dist[numOftiles+1];         // Distances

    std::vector<int> path(numOftiles + 1); // Path vector
    std::vector<int> prev(numOftiles + 1); // Previous tiles

    // Set all distances, previous tiles, and marks
    for (int i = 1; i <= numOftiles; i++) {
        dist[i] = INT_MAX;
        prev[i] = -1;
    }

    // Update source
    int source_ind = getTileIndex(tiles, source);
    dist[source_ind] = 0;

    // Insert the source Tile
    q.push(source);

    // Unweighted Dijkstra's algorithm
    while (!q.empty()) {
        // Front element of q
        int u = q.front();
        q.pop();

        // Find neighbors corresponding Tile
        int u_Tile = getTileIndex(tiles, u);
        std::vector<int> neighbors = tiles[u_Tile].getNeighbors();

        for (int i = 0; i < neighbors.size(); ++i)
        {
            int ind = getTileIndex(tiles, neighbors[i]);

            // If old distance is larger than new distance
            if (dist[ind] > dist[u_Tile] + 1)
            {
                dist[ind] = dist[u_Tile] + 1;    // Update the distance
                prev[ind] = u;                   // Update the previous Tile
                q.push(neighbors[i]);            // Insert Tile to queue
            }
        }
    }

    int vertex = getTileIndex(tiles, destination);

    // Insert the destination Tile to stack
    if ((prev[vertex] > 0) && (vertex != -1))
        PathStack.push(destination);
    else
    {
        // If Tile does not exist.
        std::cerr << "There is no path!" << std::endl;
        exit(1);
    }

    int max_Tile = INT_MIN;

    // Max Tile index
    // Find max Tile index to determine valid vertex range 1-max_ind
    for (auto Tile : tiles)
    {
        if (Tile.getId() > max_Tile)
            max_Tile = Tile.getId();
    }

    // Start with destination Tile and find its previous Tile of vertex
    while (true)  // Until source Tile is reached, find previous tiles from prev vector
    {
        vertex = prev[vertex];
        if ((vertex < 0) || (vertex > max_Tile)) // If vertex is not in the valid range
            break;
        PathStack.push(vertex); // Push the tiles to Path stack
        vertex = getTileIndex(tiles, vertex);
    }

    int i = 0;

    // Until the PathStack is empty
    while (!PathStack.empty())
    {
        path[i] = PathStack.top(); // Reverse PathStack to path
        PathStack.pop();
        i++;
    }

    // Remove zeros from path
    removeZeros(path);
    return path;
}
