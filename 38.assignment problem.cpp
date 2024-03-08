#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
void printAssignment(int *assignment, int n) {
    printf("Assignment: ");
    for (int i = 0; i < n; i++) {
        printf("Worker %d -> Job %d  ", i, assignment[i]);
    }
    printf("\n");
}
int calculateCost(int *assignment, int **costMatrix, int n) {
    int totalCost = 0;
    for (int i = 0; i < n; i++) {
        totalCost += costMatrix[i][assignment[i]];
    }
    return totalCost;
}
bool isFeasible(int *assignment, int job, int level, int n) {
    for (int i = 0; i < level; i++) {
        if (assignment[i] == job) {
            return false;
        }
    }
    return true;
}
void branchAndBound(int *assignment, int *assigned, int **costMatrix, int level, int n) {
    if (level == n) {
        printAssignment(assignment, n);
        return;
    }

    for (int j = 0; j < n; j++) {
        if (!assigned[j] && isFeasible(assignment, j, level, n)) {
            assignment[level] = j;
            assigned[j] = 1;
            branchAndBound(assignment, assigned, costMatrix, level + 1, n);
            assigned[j] = 0;
        }
    }
}
int main() {
    int n;
    printf("Enter the size of the cost matrix:");
    scanf("%d", &n);
    int **costMatrix = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++) {
        costMatrix[i] = (int *)malloc(n * sizeof(int));
    }
    printf("Enter the cost matrix:\n");
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &costMatrix[i][j]);
        }
    }
    int *assignment = (int *)malloc(n * sizeof(int));
    int *assigned = (int *)calloc(n, sizeof(int));
    printf("\nPossible Assignments:\n");
    branchAndBound(assignment, assigned, costMatrix, 0, n);
    for (int i = 0; i < n; i++) {
        free(costMatrix[i]);
    }
    free(costMatrix);
    free(assignment);
    free(assigned);
    return 0;
}