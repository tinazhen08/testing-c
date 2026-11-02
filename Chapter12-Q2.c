/* /* (a) Write a program that reads amessage, then checks whether it's a palindrome (the letters
in the message are the same from left to right as from right to left):
Enter a message: He lived as a devil, eh?
Palindrome
Enter a message: Madam, I am Adam.
Not a palindrome
Ignore all characters that aren't letters. Use integer variables to keep track of positions in the
array. */

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
            message[length] = tolower(ch);
            length++;
        }
    }

    int i = 0;
    int j = length - 1;
    bool is_palindrome = true;

    while (i < j) {
        if (message[i] != message[j]) {
            is_palindrome = false;
            break;
        }
        i++;
        j--;
    }

    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}


/* (b) Revise the program to use pointers instead of integers to keep track of positions in the
array. */
int main(void) {
    char message[MAX_LENGTH];
    char ch;
    char *p = message;

    printf("Enter a message: ");
    
    while ((ch = getchar()) != '\n' && p < message + MAX_LENGTH) {
        if (isalpha(ch)) {
            *p = tolower(ch);
            p++;
        }
    }

    char *left = message;     
    char *right = p - 1;       
    bool is_palindrome = true;

    while (left < right) {
        if (*left != *right) {
            is_palindrome = false;
            break;
        }
        left++;
        right--;
    }

    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}
