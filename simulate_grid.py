import numpy as np
import matplotlib.pyplot as plt

class Grids:
    def __init__(self):
        self.grid = np.array([
            [i for i in range(81, 89)],
            [i for i in range(71, 79)],
            [i for i in range(61, 69)],
            [i for i in range(51, 59)],
            [i for i in range(41, 49)],
            [i for i in range(31, 39)],
            [i for i in range(21, 29)],
            [i for i in range(11, 19)],
            [i for i in range(1, 9)],
        ])
        self.visited = np.zeros((9, 9))  # Initialize array to track visited nodes

    def plot_grid_with_path(self, paths):
        fig, ax = plt.subplots()

        grid_with_path = np.zeros((9, 9))
        plt.xticks(np.arange(9), ['1', '2', '3', '4', '5', '6','7','8','9'])
        plt.yticks(np.arange(9), ['1', '11', '21', '31', '41', '51', '61', '71', '81'])
        plt.xlabel('Column')
        plt.ylabel('Row')
        plt.title('Grid with Paths')
        plt.grid(color='white', linestyle='-', linewidth=1)

        for i in range(len(max(paths, key=len))):  # Iterate through maximum number of steps
            for path in paths:
                if i < len(path):
                    idx = path[i]
                    row = (idx - 1) // 10
                    col = (idx - 1) % 10
                    grid_with_path[row][col] = 2  # Mark current position as visited
                    self.visited[row][col] = 1  # Mark current position as visited

            ax.imshow(grid_with_path, cmap='gray', origin='lower', extent=[0, 9, 0, 9])
            
            # Show visited nodes in grid
            for row in range(9):
                for col in range(9):
                    if self.visited[row][col] == 1:
                        ax.text(col + 0.5, row + 0.5, '*', ha='center', va='center', color='cyan', fontsize=12)

            plt.pause(0.5)  # Pause for 0.5 seconds
            plt.draw()
            grid_with_path = np.zeros((9, 9))  # Reset grid to clear previous positions
        
        plt.show()
# Input string
input_string3 = "44 45 46 47 48 49 59 69 79 89 88 78 68 58 57 56 55 54 64 74 84 85 75 65 66 67 66 76 86 76 77 87"

# Convert input string to Python list
path3 = list(map(int, input_string3.split()))

# Define the paths
path1 = [1, 2, 3 ,13, 23, 33 ,43, 53 ,63 ,73 ,83 ,82, 72 ,62 ,52 ,42 ,32, 22 ,12 ,11, 21 ,31 ,41 ,51, 61 ,71, 81]
path2 = [4, 5, 6, 7, 8, 9, 19, 29, 39, 38, 28, 18, 17, 16, 15, 14, 15, 25, 35, 25, 26, 27, 26, 25, 24, 25, 26, 36, 36, 37]
# path3 = [44, 54, 55, 56, 57, 58, 59, 69, 79, 69, 68, 67, 66, 65, 64, 74, 84, 85, 75, 65, 55, 56, 46, 47, 48, 49, 48, 47, 57, 67, 77, 87,
#     77, 76, 86]

# Create an instance of the Grids class
grids = Grids()

# Plot the grid with the paths for all three regions
grids.plot_grid_with_path([path1, path2, path3])
