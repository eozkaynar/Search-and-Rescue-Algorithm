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
                        color = 'black'
                        if grid_with_path[row][col] == 2:  # If it's the current node
                            color = 'white'  # Change color for current node
                        ax.text(col + 0.5, row + 0.30, '*', ha='center', va='center', color=color, fontsize=25)

            # Highlight specific indexes in red
            red_indexes = [1, 2, 3, 11, 12, 13, 21, 22, 23, 31, 32, 33, 41, 42, 43, 51, 52, 53, 61, 62, 63, 71, 72, 73, 81, 82, 83]
            for idx in red_indexes:
                row = (idx - 1) // 10
                col = (idx - 1) % 10
                ax.add_patch(plt.Rectangle((col, row), 1, 1, color=(1.0, 0.5, 0.5)))

            # Highlight specific indexes in red
            blue_indexes = [4, 5, 6, 7, 8, 9, 14, 15, 16, 17, 18, 19, 24, 25, 26, 27, 28, 29, 34, 35, 36, 37, 38, 39]
            for idx in blue_indexes:
                row = (idx - 1) // 10
                col = (idx - 1) % 10
                ax.add_patch(plt.Rectangle((col, row), 1, 1, color=(0.25, 0.25, 1.0)))

            # Highlight specific indexes in red
            green_indexes = [44, 45, 46, 47, 48, 49, 54, 55, 56, 57, 58, 59, 64, 65, 66, 67, 68, 69,74, 75, 76, 77, 78, 79 ,84, 85, 86, 87, 88, 89]
            for idx in green_indexes:
                row = (idx - 1) // 10
                col = (idx - 1) % 10
                ax.add_patch(plt.Rectangle((col, row), 1, 1, color=(0.25, 0.75 ,0.25)))

            plt.pause(0.5)  # Pause for 0.5 seconds
            plt.draw()
            grid_with_path = np.zeros((9, 9))  # Reset grid to clear previous positions
        
        plt.show()

# Input string
input_string3 = "44 45 46 47 48 58 68 78 79 89 88 78 68 67 66 65 64 54 64 65 66 56 57 58 59 58 57 56 66 65 64 74 84 85 75 76 77 67 57 47 48 49 48 47 46 56 66 76 86"

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
