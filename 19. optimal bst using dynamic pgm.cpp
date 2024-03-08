#include <stdio.h>
#include <limits.h>
float sumOfProbabilities(float probabilities[], int i, int j) {
    float sum = 0;
    for (int k = i; k <= j; k++) {
        sum += probabilities[k];
    }
    return sum;
}
float optimalBST(float keys[], float probabilities[], int n) 
{
    float cost[n][n];
    for (int i = 0; i < n; i++) 
	{
        cost[i][i] = probabilities[i];
    }
    for (int cl = 2; cl <= n; cl++) {
        for (int i = 0; i <= n - cl + 1; i++) {
            int j = i + cl - 1;
            cost[i][j] = INT_MAX;
            for (int r = i; r <= j; r++) {
                float c = ((r > i) ? cost[i][r - 1] : 0) +
                          ((r < j) ? cost[r + 1][j] : 0) +
                          sumOfProbabilities(probabilities, i, j);
                if (c < cost[i][j]) {
                    cost[i][j] = c;
                }
            }
        }
    }
    return cost[0][n - 1];
}
int main() 
{
    int n;
    printf("Enter the number of keys: ");
    scanf("%d", &n);
    float keys[n];
    float probabilities[n];
    printf("Enter the keys and their respective probabilities:\n");
    for (int i = 0; i < n; i++) 
	{
        scanf("%f %f", &keys[i], &probabilities[i]);
    }
    float minCost = optimalBST(keys, probabilities, n);
    printf("Minimum cost of constructing an optimal BST: %f\n", minCost);
    return 0;
}
