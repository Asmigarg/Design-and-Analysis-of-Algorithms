#include <stdio.h>
#include <stdbool.h>

#define V 4  // Number of vertices in the graph

void printSolution(int color[]) {
    printf("Vertex Colors:\n");
    for (int i = 0; i < V; i++) {
        printf("Vertex %d: Color %d\n", i, color[i]);
    }
}

// Check if it's safe to color the vertex with the given color
bool isSafe(int v, int graph[V][V], int color[], int c) {
    for (int i = 0; i < V; i++) {
        if (graph[v][i] && color[i] == c) {
            return false;
        }
    }
    return true;
}

// Recursive function to color vertices using backtracking
bool graphColoringUtil(int graph[V][V], int m, int color[], int v) {
    if (v == V) {
        // All vertices are colored, a solution is found
        printSolution(color);
        return true;
    }

    for (int c = 1; c <= m; c++) {
        if (isSafe(v, graph, color, c)) {
            color[v] = c;

            // Recur to color the next vertices
            if (graphColoringUtil(graph, m, color, v + 1)) {
                return true;  // Solution found
            }

            // If coloring with the current color doesn't lead to a solution,
            // backtrack by trying a different color
            color[v] = 0;
        }
    }

    return false;  // No solution found
}

// Function to color the graph using at most m colors
void graphColoring(int graph[V][V], int m) {
    int color[V];
    for (int i = 0; i < V; i++) {
        color[i] = 0;  // Initialize colors to 0
    }

    if (!graphColoringUtil(graph, m, color, 0)) {
        printf("Solution does not exist.\n");
    }
}

int main() {
	printf("My name is Arshdeep Kaur\n");
    printf("My Sap ID is 500107135\n");
    int graph[V][V] = {
        {0, 1, 1, 1},
        {1, 0, 1, 0},
        {1, 1, 0, 1},
        {1, 0, 1, 0}
    };
    int m = 3;  // Number of colors

    graphColoring(graph, m);

    return 0;
}

