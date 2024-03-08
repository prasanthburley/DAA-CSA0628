#include <stdio.h>
#include <stdbool.h>
#define MAX_VERTICES 100
int graph[MAX_VERTICES][MAX_VERTICES];
int numVertices;
int numColors;
int solution[MAX_VERTICES];
bool isSafe(int v, int c) {
    for (int i = 0; i < numVertices; i++) {
        if (graph[v][i] && solution[i] == c) {
            return false;
        }
    }
    return true;
}
bool graphColoringUtil(int v) {
    if (v == numVertices) {
        printf("Possible Coloring: ");
        for (int i = 0; i < numVertices - 1; i++) {
            printf("c%d-", solution[i]);
        }
        printf("c%d\n", solution[numVertices - 1]);
        return false; 
    }
    for (int c = 1; c <= numColors; c++) {
        if (isSafe(v, c)) {
            solution[v] = c;
            graphColoringUtil(v + 1);
            solution[v] = 0; 
        }
    }
    return false;
}
void graphColoring() {
    for (int i = 0; i < numVertices; i++) {
        solution[i] = 0;
    }
    printf("All Possible Colorings:\n");
    graphColoringUtil(0);
}
int main() {
    printf("Enter the number of vertices: ");
    scanf("%d", &numVertices);
    printf("Enter the adjacency matrix:\n");
    for (int i = 0; i < numVertices; i++) {
        for (int j = 0; j < numVertices; j++) {
            scanf("%d", &graph[i][j]);
        }
    }
    printf("Enter the number of colors: ");
    scanf("%d", &numColors);
    graphColoring();
    return 0;
}
