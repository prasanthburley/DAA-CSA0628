#include <stdio.h>
#define MAX 100
int set[MAX];
int subset[MAX];
int n; 
int targetSum;
int currentSum = 0;
void printSubset(int size) {
    printf("Subset: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", subset[i]);
    }
    printf("\n");
}
void findSubsets(int index, int size) {
    if (currentSum == targetSum) {
        printSubset(size);
        return;
    }
    if (index == n || currentSum > targetSum) {
        return;
    }
    subset[size] = set[index];
    currentSum += set[index];
    findSubsets(index + 1, size + 1);
    currentSum -= set[index];
    findSubsets(index + 1, size);
}
int main() {
    printf("Enter the number of elements in the set: ");
    scanf("%d", &n);
    printf("Enter the elements of the set:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &set[i]);
    }
    printf("Enter the target sum: ");
    scanf("%d", &targetSum);
    findSubsets(0, 0);
    return 0;
}
