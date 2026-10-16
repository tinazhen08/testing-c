#include <stdio.h>

int main(void) {
    float x, result;

    printf("Enter a value for x: ");
    
    if (scanf("%f", &x) != 1) {
        printf("Invalid input.\n");
        return 1;
    }

    result = (3 * x * x * x * x * x) 
           + (2 * x * x * x * x) 
           - (5 * x * x * x) 
           - (x * x) 
           + (7 * x) 
           - 6;

    printf("The value of the polynomial is: %.4f\n", result);

    return 0;
}
