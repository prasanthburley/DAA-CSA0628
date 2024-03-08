#include <stdio.h>
#include <stdlib.h>
#define MAX_ITEMS 100
void knapsackGreedy(int binCapacity, int items[], int n) {
    int currentBinWeight = 0;
    int currentBinIndex = 0;
    for (int i = 0; i < n; i++) {
        if (currentBinWeight + items[i] <= binCapacity) {
            currentBinWeight += items[i];
            printf("Item %d (Weight: %d) fits into Container %d (Total Weight: %d)\n", items[i], items[i], currentBinIndex, currentBinWeight);
        } else {
            currentBinIndex++;
            currentBinWeight = items[i];
            printf("Item %d (Weight: %d) starts a new Container %d (Total Weight: %d)\n", items[i], items[i], currentBinIndex, currentBinWeight);
        }
    }
    printf("Number of containers used: %d\n", currentBinIndex + 1);
}
int main() {
    int binCapacity;
    int n;
    int items[MAX_ITEMS];
    printf("Enter the container capacity: ");
    scanf("%d", &binCapacity);
    printf("Enter the number of items: ");
    scanf("%d", &n);
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &items[i]);
    }
    printf("\nGreedy Container Weight Allocations:\n");
    knapsackGreedy(binCapacity, items, n);
    return 0;
}
