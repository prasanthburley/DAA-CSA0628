#include <stdio.h>
#include <string.h>
#include <ctype.h>
int main() {
    char input[100];
    int num = 0;  
    printf("Enter an integer: ");
    fgets(input, sizeof(input), stdin);
    char *p = input;
    while (isspace((unsigned char)*p)) {
        p++;
    }
    for (int i = strlen(p) - 1; i >= 0 && isspace((unsigned char)p[i]); i--) {
        p[i] = '\0';
    }
    int i = 0;
    while (p[i] != '\0') {
        if (!isdigit(p[i])) {
            printf("Invalid input. Please enter a valid integer.\n");
            return 1;
        }
        i++;
    }
    if (sscanf(p, "%d", &num) != 1) {
        printf("Invalid input. Please enter a valid integer.\n");
        return 1;
    }
    int reversed = 0;
    int remainder;
    while (num != 0) {
        remainder = num % 10;
        reversed = reversed * 10 + remainder;
        num /= 10;
    }
    printf("Reversed number: %d\n", reversed);
    return 0;
}
