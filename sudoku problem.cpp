#include <stdio.h>
#include <stdbool.h>

#define N 9

// Function to print the Sudoku grid
void printGrid(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            printf("%2d ", grid[row][col]);
        }
        printf("\n");
    }
}

// Function to check if a number can be placed at the given position
bool isSafe(int grid[N][N], int row, int col, int num) {
    // Check if the number is already present in the row or column
    for (int i = 0; i < N; i++) {
        if (grid[row][i] == num || grid[i][col] == num) {
            return false;
        }
    }

    // Check if the number is already present in the 3x3 subgrid
    int startRow = row - row % 3;
    int startCol = col - col % 3;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (grid[i + startRow][j + startCol] == num) {
                return false;
            }
        }
    }

    return true;
}

// Recursive function to solve the Sudoku puzzle using backtracking
bool solveSudoku(int grid[N][N]) {
    for (int row = 0; row < N; row++) {
        for (int col = 0; col < N; col++) {
            // Find an empty cell
            if (grid[row][col] == 0) {
                // Try placing numbers from 1 to 9
                for (int num = 1; num <= 9; num++) {
                    if (isSafe(grid, row, col, num)) {
                        // If placing the number is safe, assign and recur
                        grid[row][col] = num;

                        if (solveSudoku(grid)) {
                            return true;  // Solution found
                        }

                        // If placing the number doesn't lead to a solution, backtrack
                        grid[row][col] = 0;
                    }
                }
                return false;  // No number can be placed here
            }
        }
    }

    return true;  // The Sudoku is solved
}

int main() {
	printf("My name is Arshdeep Kaur\n");
    printf("My Sap ID is 500107135\n");
    // Example Sudoku grid (0 represents empty cells)
    int grid[N][N] = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}
    };

    printf("Sudoku Puzzle:\n");
    printGrid(grid);

    if (solveSudoku(grid)) {
        printf("\nSudoku Solution:\n");
        printGrid(grid);
    } else {
        printf("\nNo solution exists.\n");
    }

    return 0;
}

