/*(a) Write a program that reads a message, then prints the reversal of the message:
Enter a message: Don't get mad, get even.
Reversal is: .neve teg, dam teg t'noD
Hint: Read the message one character at a time (using getchar) and store the characters in
an array. Stop reading when the array is full or the character read is'\n'.*/

#include <stdio.h>

#define MAX_SIZE 100

int main(void) {
    char message[MAX_SIZE];
    char ch;
    int i = 0;

    printf("Enter a message: ");

    while (i < MAX_SIZE && (ch = getchar()) != '\n') {
        message[i] = ch;
        i++;
    }

    printf("Reversal is: ");
    
    for (int j = i - 1; j >= 0; j--) {
        putchar(message[j]);
    }
    putchar('\n');

    return 0;
}

/* (b) Revise the program to use a pointer instead of an integer to keep track of the current
position in the array. */

int main(void) {
    char message[MAX_SIZE];
    char ch;
    char *p = message;

    printf("Enter a message: ");

    while (p < (message + MAX_SIZE) && (ch = getchar()) != '\n') {
        *p = ch;
        p++;
    }

    printf("Reversal is: ");
    
    while (p > message) {
        p--;
        putchar(*p);
    }
    putchar('\n');

    return 0;
}
