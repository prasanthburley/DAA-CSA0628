#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define NUM_CITIES 4
#define INF 999999

int min(int a, int b) {
    return (a < b) ? a : b;
}

int tsp(int graph[NUM_CITIES][NUM_CITIES], int mask, int pos, int dp[NUM_CITIES][1 << NUM_CITIES], int parent[NUM_CITIES][1 << NUM_CITIES]) {
    if (mask == (1 << NUM_CITIES) - 1) {
        return graph[pos][0];
    }

    if (dp[pos][mask] != -1) {
        return dp[pos][mask];
    }

    int ans = INF;
    int best_child = -1;

    for (int city = 0; city < NUM_CITIES; city++) {
        if ((mask & (1 << city)) == 0) {
            int newAns = graph[pos][city] + tsp(graph, mask | (1 << city), city, dp, parent);
            if (newAns < ans) {
                ans = newAns;
                best_child = city;
            }
        }
    }

    dp[pos][mask] = ans;
    parent[pos][mask] = best_child;
    return ans;
}

void printPath(int graph[NUM_CITIES][NUM_CITIES], int dp[NUM_CITIES][1 << NUM_CITIES], int parent[NUM_CITIES][1 << NUM_CITIES]) {
    printf("Minimum Cost: %d\n\n", tsp(graph, 1, 0, dp, parent));
    printf("Graph:\n");
    printf("   B\n");
    printf("   |\n");
    printf("   A\n");
    printf("  /\n");
    printf(" C\n");
    printf("/\n");
    printf("D");
}

int main() {
    int graph[NUM_CITIES][NUM_CITIES] = {
        {0, 29, 20, 21},
        {29, 0, 15, 12},
        {20, 15, 0, 19},
        {21, 12, 19, 0}
    };

    int dp[NUM_CITIES][1 << NUM_CITIES];
    int parent[NUM_CITIES][1 << NUM_CITIES];
    for (int i = 0; i < NUM_CITIES; i++) {
        for (int j = 0; j < (1 << NUM_CITIES); j++) {
            dp[i][j] = -1;
            parent[i][j] = -1;
        }
    }

    printPath(graph, dp, parent);

    return 0;
}
