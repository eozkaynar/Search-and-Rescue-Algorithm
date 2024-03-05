#ifndef GRID_HPP_INCLUDED
#define GRID_HPP_INCLUDED
#include <string>
#include <vector>

// visiting status of node
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
        // Return status
        int getStatus();
};

class Grid
{
    private:
        // Tiles of grid
        std::vector<Tile> tiles;
        // Return tile
        Tile* getTile(int id);
        // Edge number
        int N;

    public:

        // Constructors
        Grid();
        Grid(int N);
        // Tile functions
        void addTile(int id, std::vector<int>& neighbors);

        // add Obstacle (remove Tile due to infinity weigth)
        void addObstacle(int id);

        // Print grid
        void printGrid();

        // Change tile status
        void changeTileStatus(int id,Visited status);

        // Get tile status
        int getTileStatus(int id);

        // Calculate shortest path
        std::vector<int> calculatePath(int source, int destination);
};

#endif // GRID_HPP_INCLUDED
