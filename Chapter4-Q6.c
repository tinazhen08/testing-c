#include <stdio.h>

int main(void) {
    char ean[13];
    int first_sum = 0, second_sum = 0;
    int total, adjusted_total, remainder, check_digit;

    while (1) {
        printf("Enter the first 12 digits of an EAN: ");
        
        if (scanf("%12s", ean) == 1) {
            
            int valid = 1;
            for (int i = 0; i < 12; i++) {
                if (ean[i] < '0' || ean[i] > '9' || ean[i] == '\0') {
                    valid = 0;
                    break;
                }
            }
            
            if (valid) {
                break; 
            }
        }

        printf("Invalid input. Please enter exactly 12 numeric digits.\n\n");
        while (getchar() != '\n'); 
    }

    for (int i = 0; i < 12; i++) {
        int digit = ean[i] - '0'; 
        
        if (i % 2 != 0) {
            first_sum += digit;
        } else {
            second_sum += digit;
        }
    }

    total = (first_sum * 3) + second_sum;
    adjusted_total = total - 1;
    remainder = adjusted_total % 10;
    check_digit = 9 - remainder;

    printf("Check digit: %d\n", check_digit);

    return 0;
}