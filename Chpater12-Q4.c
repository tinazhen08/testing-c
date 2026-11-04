/* Simplify Programming Project 2(b) by taking advantage of the fact that an array name can
be used as a pointer. */

#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define MAX_LENGTH 100

int main(void) {
    char message[MAX_LENGTH];
    char ch;
    int length = 0;

    printf("Enter a message: ");

    while ((ch = getchar()) != '\n' && length < MAX_LENGTH) {
        if (isalpha(ch)) {
            *(message + length) = tolower(ch);
            length++;
        }
    }

    bool is_palindrome = true;

    for (int i = 0; i < length / 2; i++) {
        if (*(message + i) != *(message + length - 1 - i)) {
            is_palindrome = false;
            break;
        }
    }

    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}
