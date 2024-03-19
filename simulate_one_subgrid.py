import numpy as np
import matplotlib.pyplot as plt
import time

class Grids:
    def __init__(self):
        self.grid_1 = [
            [81, 82, 83],
            [71, 72, 73],
            [61, 62, 63],
            [51, 52, 53],
            [41, 42, 43],
            [31, 32, 33],
            [21, 22, 23],
            [11, 12, 13],
            [1, 2, 3]
        ]
        self.grid_2 = [
            [34, 35, 36, 37, 38, 39],
            [24, 25, 26, 27, 28, 29],
            [14, 15, 16, 17, 18, 19],
            [4, 5, 6, 7, 8, 9],
        ]
        self.grid_3 = [
            [84, 85, 86, 87, 88, 89],
            [74, 75, 76, 77, 78, 79],
            [64, 65, 66, 67, 68, 69],
            [54, 55, 56, 57, 58, 59],
            [44, 45, 46, 47, 48, 49],
        ]


    def plot_grid_with_path(self,path, grid):

        if grid == 1:
            fig, ax = plt.subplots()

            grid_with_path = np.zeros((9, 3))
            plt.xticks(np.arange(3), ['1', '2', '3'])
            plt.yticks(np.arange(9), ['1', '11', '21', '31', '41', '51', '61', '71', '81'])
            plt.xlabel('Column')
            plt.ylabel('Row')
            plt.title('Grid with Path')
            plt.grid(color='black', linestyle='-', linewidth=1)

            for idx in path:
                row = (idx - 1) // 10
                col = (idx - 1) % 10
                grid_with_path[row][col] = 2  # Mark current position as visited
                ax.imshow(grid_with_path, cmap='gray', origin='lower')
                plt.pause(0.5)  # Pause for 0.5 seconds
                plt.draw()
                grid_with_path[row][col] = 1  # Revert visited position to path
        elif grid == 3:
            
            fig, ax = plt.subplots()

            grid_with_path = np.zeros((5, 6))
            plt.xticks(np.arange(6), ['44', '45', '46', '47', '48', '49'])
            plt.yticks(np.arange(5), ['44', '54', '64', '74', '84'])
            plt.xlabel('Column')
            plt.ylabel('Row')
            plt.title('Grid with Path')
            plt.grid(color='black', linestyle='-', linewidth=1)

            for idx in path:
                row = (idx - 44) // 10
                col = (idx - 44) % 10
                grid_with_path[row][col] = 2  # Mark current position as visited
                ax.imshow(grid_with_path, cmap='gray', origin='lower')
                plt.pause(0.5)  # Pause for 0.5 seconds
                plt.draw()
                grid_with_path[row][col] = 1  # Revert visited position to path

        elif grid == 2:
            
            fig, ax = plt.subplots()

            grid_with_path = np.zeros((4, 6))
            plt.xticks(np.arange(6), ['4', '5', '6', '7', '8', '9'])
            plt.yticks(np.arange(4), ['4', '14', '24', '34'])
            plt.xlabel('Column')
            plt.ylabel('Row')
            plt.title('Grid with Path')
            plt.grid(color='black', linestyle='-', linewidth=1)

            for idx in path:
                row = (idx - 4) // 10
                col = (idx - 4) % 10
                grid_with_path[row][col] = 2  # Mark current position as visited
                ax.imshow(grid_with_path, cmap='gray', origin='lower')
                plt.pause(0.5)  # Pause for 0.5 seconds
                plt.draw()
                grid_with_path[row][col] = 1  # Revert visited position to path


# Example usage:
grids = Grids()

# Define the path
# path = [1, 2, 3, 13, 23, 33,43,53,63,73,83,82,72,62,52,42,32,22,12,11,21,31,41,51,61,71,81]

path3 = [
    44, 54, 55, 56, 57, 58, 59,
    69, 79, 69, 68, 67, 66, 65, 64,
    74, 84, 85, 75, 65, 55, 56,
    46, 47, 48, 49, 48, 47,
    57, 67, 77, 87, 88, 87,
    77, 76, 86
]

path2 = [
    4, 5, 6, 7, 8, 9,
    19, 29, 39,
    38, 28, 18, 17, 16, 15, 14,
    15, 25, 35,
    25, 26, 27,
    26, 25, 24, 25, 26,
    36, 36, 37
]

# Input string
input_string = "44 54 55 56 57 58 59 69 79 69 68 67 66 65 64 74 84 85 75 65 55 56 46 47 48 49 48 47 57 67 77 87 88 87 77 76 86"

# Convert input string to Python list
path = list(map(int, input_string.split()))

grids= Grids()
# Plot the grid with the path and visited tiles
grids.plot_grid_with_path(path,3)
