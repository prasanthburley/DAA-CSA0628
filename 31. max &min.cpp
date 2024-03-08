#include <stdio.h>
int main() {
    int n;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    int numbers[n];
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    if (n == 0) {
        printf("The list is empty.\n");
        return 0;
    }
    int current_min = numbers[0];
    int current_max = numbers[0];
    int min_sequence[n]; 
    int max_sequence[n]; 
    int min_length = 1;
    int max_length = 1;
    for (int i = 1; i < n; i++) {
        if (numbers[i] < current_min) {
            current_min = numbers[i];
            min_sequence[0] = numbers[i];
            min_length = 1;
        } else if (numbers[i] == current_min) {
            min_sequence[min_length] = numbers[i];
            min_length++;
        }
        if (numbers[i] > current_max) {
            current_max = numbers[i];
            max_sequence[0] = numbers[i];
            max_length = 1;
        } else if (numbers[i] == current_max) {
            max_sequence[max_length] = numbers[i];
            max_length++;
        }
    }
    printf("Minimum Sequence: ");
    for (int i = 0; i < min_length; i++) {
        printf("%d ", min_sequence[i]);
    }
    printf("\nMinimum Value: %d\n", current_min);
    printf("Maximum Sequence: ");
    for (int i = 0; i < max_length; i++) {
        printf("%d ", max_sequence[i]);
    }
    printf("\nMaximum Value: %d\n", current_max);
    return 0;
}
