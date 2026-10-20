#include <stdio.h>

int main(void) {
    int m, n, remainder;
    int items_read;

    while (1) {
        printf("Enter two integers in the format [x,y]: ");
        
        items_read = scanf(" [%d , %d]", &m, &n);

        if (items_read == 2) {
            break;
        }

        printf("Invalid format! Please try again.\n\n");
        while (getchar() != '\n'); 
    }

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }

    printf("Greatest common divisor: %d\n", m);

    return 0;
}
