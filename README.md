# Search-and-Rescue-Algorithm
Search and Rescue algorithm for mobile unit \ TechBatch

*Done:* 

* Graph structure is created.
* Grid is created.
* Neighbors vector is added.
* Tile status change function added.
* Add addObstacle (removeTile) function.
* Dijkstra's algorithm.
* Update tile's ids wrt to IR messages.

*TO DO:*

* Add an enum class for Base and target tiles.
* Grid partitioning.
* Partition search for one mu.
* Tile constructor default UNVISITED status(maybe?).
* Add an attribute to the tiles indicating whether it is in the range.
* Rescue algorithm.

*TO DO FOR SUBGRID AND SEARCH PARTITIONING:*

* Solve the problem of MUs movement to their subgrids without collision.
* Add gotoRange function for MUs that completing their search and are not in the range of base.
* Check Target information and consider both "target is found" and "target is not found."
* Make simulation to simulate search and movement algorithm.
