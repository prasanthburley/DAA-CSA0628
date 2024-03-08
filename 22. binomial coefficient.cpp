#include <stdio.h>
int binomialCoefficient(int n, int k) 
{
    int C[n + 1][k + 1];
    for (int i = 0; i <= n; i++) 
	{
        for (int j = 0; j <= i && j <= k; j++) 
		{
            if (j == 0 || j == i) 
			{
                C[i][j] = 1;
            } 
			else 
			{
                C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
            }
        }
    }
    return C[n][k];
}
int main() 
{
    int n, k;    
    printf("Enter values of n and k for C(n, k): ");
    scanf("%d %d", &n, &k);
    if (k < 0 || k > n) 
	{
        printf("Invalid input: k should be between 0 and n.\n");
    } 
	else 
	{
        int result = binomialCoefficient(n, k);
        printf("C(%d, %d) = %d\n", n, k, result);
    }
    return 0;
}
