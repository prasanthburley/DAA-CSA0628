#include <stdio.h>
#include <string.h>
int main() 
{
	char string1[50];
    int i, len;
    int flag = 0;
    printf("Enter a string: ");
    scanf("%s", &string1);
    len = strlen(string1);
    for (i = 0; i < len / 2; i++) {
        if (string1[i] != string1[len - i - 1]) {
            flag = 1;
            break;
        }
    }
    if (flag) {
        printf("%s is not a palindrome\n", string1);
    } else {
        printf("%s is a palindrome\n", string1);
    }
    return 0;
}