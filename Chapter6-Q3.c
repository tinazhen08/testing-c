#include <stdio.h>

int main(void) {
    int num, denom, m, n, remainder;
    int items_read;

    while (1) {
        printf("Enter a fraction (num/denom): ");
        items_read = scanf("%d/%d", &num, &denom);

        if (items_read == 2 && denom != 0) {
            break;
        }

        if (items_read == 2 && denom == 0) {
            printf("Error: Denominator cannot be zero! Please try again.\n\n");
        } else {
            printf("Invalid format! Please use the 'x/y' format.\n\n");
        }

        while (getchar() != '\n');
    }

    m = num;
    n = denom;

    while (n != 0) {
        remainder = m % n;
        m = n;
        n = remainder;
    }
    
    int reduced_num = num / m;
    int reduced_denom = denom / m;

    if (reduced_denom < 0) {
        reduced_num = -reduced_num;
        reduced_denom = -reduced_denom;
    }

    printf("In lowest terms: %d/%d\n", reduced_num, reduced_denom);

    return 0;
}
