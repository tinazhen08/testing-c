/* (a) Write a program that reads amessage, then checks whether it's a palindrome (the letters
in the message are the same from left to right as from right to left):
Enter a message: He lived as a devil, eh?
Palindrome
Enter a message: Madam, I am Adam.
Not a palindrome
Ignore all characters that aren't letters. Use integer variables to keep track of positions in the
array.
(b) Revise the program to use pointers instead of integers to keep track of positions in the
array. */

#include <stdio.h>
#include <ctype.h>

int main(void) {
    char message[100];
    char *start, *end;
    int is_palindrome = 1;

    printf("Enter a message: ");
    fgets(message, sizeof(message), stdin);

    start = message;
    end = message;

    while (*end != '\0') {
        end++;
    }
    end--;

    while (start < end) {
        if (!isalpha(*start)) {
            start++;
            continue;
        }
        if (!isalpha(*end)) {
            end--;
            continue;
        }
        if (tolower(*start) != tolower(*end)) {
            is_palindrome = 0;
            break;
        }

        start++;
        end--;
    }

    if (is_palindrome) {
        printf("Palindrome\n");
    } else {
        printf("Not a palindrome\n");
    }

    return 0;
}
