#include <stdio.h>

int main() {
    float subtotal;
    float taxRate = 0.05;

    printf("Enter the money amount: $ ");
    
    if (scanf("%f", &subtotal) != 1) { 
        printf("Invalid input. Please enter a valid number.\n");
        return 1;
    }

    float total = subtotal * (1.0 + taxRate);
    
    printf("Total amount with 5%% tax: $%.2f\n", total);

    return 0;
}
