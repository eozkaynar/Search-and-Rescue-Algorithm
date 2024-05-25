#ifndef GRID_HPP_INCLUDED
#define GRID_HPP_INCLUDED
#include <string>
#include <vector>

// Struct for output of calculatePath

struct Path{
    std::vector<int> path;
    int dead_tile;
};


// visiting status of Tile
enum class Visited {UNVISITED, VISITED};

class Tile
{
    private:

        int id;                     // number of grid
        std::vector<int> neighbors; // neighbor vector of one tile

    public:
        // Constructors
        Tile();
        Tile(int id, std::vector<int>& neighbors);
        // Return ID
        int getId();
        // Return neighbors
        std::vector<int>& getNeighbors();
        // Status of Tile: visited or unvisited
        Visited status;
        // Weight of the crossing this tile
        int weight = 0;
        // Return status
        int getStatus();
};

class Grid
{
    private:
        // Tiles of grid
        std::vector<Tile> tiles;

        // Edge number
        int N;

    public:

        // Constructors
        Grid();
        Grid(int N);

        // Visited status vector
        std::vector<int> unvisited_tiles;

        // Base Tiles
        std::vector<int> base_tiles = {0};

        // Tile functions
        void addTile(int id, std::vector<int>& neighbors);

        // add Obstacle (remove Tile due to infinity weight)
        void addObstacle(int id);

        // Return tile
        Tile* getTile(int id);

        // Print grid
        void printGrid();

        // Change tile status
        void changeTileStatus(int id,Visited status);

        // Get tile status
        int getTileStatus(int id);

        // Get length of tiles
        int getTileNumber();

        // Calculate shortest path
        Path calculatePath(int source, int destination);

        //Check the tile is in the grid
        bool isInSubgrid(int tile);

        // Integer vector of Tile's id's
        std::vector<int> Tiles_IDs_vector();
};


#endif // GRID_HPP_INCLUDED
