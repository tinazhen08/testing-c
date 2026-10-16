#include <stdio.h>

int main(void) {
    int part1, part2, part3;
    int items_matched;

    while (1) {
        printf("Enter phone number [(xxx) xxx-xxxx]: ");
        
        items_matched = scanf("(%d) %d-%d", &part1, &part2, &part3);

        if (items_matched == 3) {
            break; 
        }
        printf("Invalid format. Please try again.\n");
        while (getchar() != '\n'); 
    }

    printf("You entered: %.3d.%.3d.%.4d\n", part1, part2, part3);

    return 0;
}