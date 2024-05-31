#include <stdio.h>
#include <stdbool.h>

#define V 5  // Number of vertices in the graph

// Function to print the Hamiltonian Cycle
void printSolution(int path[V]) {
    printf("Hamiltonian Cycle: ");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);  // Complete the cycle
}

// Function to check if a vertex can be added to the Hamiltonian path
bool isSafe(int v, int graph[V][V], int path[], int pos) {
    // Check if the vertex can be added to the path
    if (!graph[path[pos - 1]][v])
        return false;

    // Check if the vertex is already included in the path
    for (int i = 0; i < pos; i++)
        if (path[i] == v)
            return false;

    return true;
}

// Recursive function to find Hamiltonian Cycle
bool hamiltonianCycleUtil(int graph[V][V], int path[], int pos) {
    // If all vertices are included in the path, check if it's a cycle
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1)
            return true;
        else
            return false;
    }

    // Try adding each vertex to the path
    for (int v = 1; v < V; v++) {
        if (isSafe(v, graph, path, pos)) {
            path[pos] = v;

            if (hamiltonianCycleUtil(graph, path, pos + 1))
                return true;

            path[pos] = -1;  // Backtrack
        }
    }

    return false;
}

// Function to find and print Hamiltonian Cycle
bool hamiltonianCycle(int graph[V][V]) {
    int path[V];
    for (int i = 0; i < V; i++)
        path[i] = -1;

    path[0] = 0;  // Start from the first vertex

    if (!hamiltonianCycleUtil(graph, path, 1)) {
        printf("No Hamiltonian Cycle exists.\n");
        return false;
    }

    printSolution(path);
    return true;
}

int main() {
    printf("My name is Arshdeep Kaur\n");
    printf("My Sap ID is 500107135\n");

    // Example graph adjacency matrix
    int graph[V][V] = {
        {0, 1, 0, 1, 0},
        {1, 0, 1, 1, 1},
        {0, 1, 0, 0, 1},
        {1, 1, 0, 0, 1},
        {0, 1, 1, 1, 0}
    };

    // Call the function to find and print Hamiltonian Cycle
    if (hamiltonianCycle(graph))
        printf("Hamiltonian Cycle found.\n");

    return 0;
}

