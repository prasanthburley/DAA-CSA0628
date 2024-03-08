#include <stdio.h>
int binomialCoefficient(int n, int k) {
    if (k == 0 || k == n) {
        return 1;
    } else {
        return binomialCoefficient(n - 1, k - 1) + binomialCoefficient(n - 1, k);
    }
}
int main() {
    int numRows;
    printf("Enter the number of rows for Pascal's Triangle: ");
    scanf("%d", &numRows);
    for (int i = 0; i < numRows; i++) {
        for (int j = 0; j < numRows - i - 1; j++) {
            printf(" ");
        }
        for (int j = 0; j <= i; j++) {
            printf("%d ", binomialCoefficient(i, j));
        }
        printf("\n");
    }
    return 0;
}
