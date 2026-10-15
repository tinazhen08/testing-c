#include <stdio.h>

int main() {
    double subtotal;
    double taxRate = 0.05;

    printf("Enter the money amount ($): ");
    if (scanf("%lf", &subtotal) != 1) {
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    double total = subtotal * (1.0 + taxRate);
    
    printf("Total amount with 5%% tax: $%.2lf\n", total);

    return 0;
}
