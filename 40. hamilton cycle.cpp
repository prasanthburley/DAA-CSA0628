#include <stdio.h>
#include <stdbool.h>
#define MAX_V 10
void printSolution(int path[], int V);
bool isSafe(int v, int pos, int path[], int graph[MAX_V][MAX_V], int V);
bool hamiltonianCycleUtil(int graph[MAX_V][MAX_V], int path[], int pos, int V);
bool hamiltonianCycle(int graph[MAX_V][MAX_V], int V);
int main() {
    int V;
    printf("Enter the number of vertices: ");
    scanf("%d", &V);
    int graph[MAX_V][MAX_V];
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < V; i++) {
        for (int j = 0; j < V; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    if (hamiltonianCycle(graph, V)) {
        printf("A Hamiltonian cycle exists.\n");
    } else {
        printf("No Hamiltonian cycle exists.\n");
    }
    return 0;
}
void printSolution(int path[], int V) {
    printf("Hamiltonian cycle exists:\n");
    for (int i = 0; i < V; i++) {
        printf("%d ", path[i]);
    }
    printf("%d\n", path[0]);
}
bool isSafe(int v, int pos, int path[], int graph[MAX_V][MAX_V], int V) {
    if (graph[path[pos - 1]][v] == 0) {
        return false;
    }   
    for (int i = 0; i < pos; i++) {
        if (path[i] == v) {
            return false;
        }
    }
    return true;
}
bool hamiltonianCycleUtil(int graph[MAX_V][MAX_V], int path[], int pos, int V) {
    if (pos == V) {
        if (graph[path[pos - 1]][path[0]] == 1) {
            return true;
        } else {
            return false;
        }
    }
    for (int v = 1; v < V; v++) {
        if (isSafe(v, pos, path, graph, V)) {
            path[pos] = v;
            if (hamiltonianCycleUtil(graph, path, pos + 1, V)) {
                return true;
            }
            path[pos] = -1;
        }
    }
    return false;
}
bool hamiltonianCycle(int graph[MAX_V][MAX_V], int V) {
    int path[MAX_V];
    for (int i = 0; i < V; i++) {
        path[i] = -1;
    }
    
    path[0] = 0; 
    if (!hamiltonianCycleUtil(graph, path, 1, V)) {
        return false;
    }
    printSolution(path, V);
    return true;
}
