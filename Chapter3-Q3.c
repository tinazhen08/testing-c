#include <stdio.h>

int main(void) {
    int gs1, group, publisher, item, check;

    printf("Enter ISBN (format: xxx-x-xxx-xxxxx-x): ");
    while (scanf("%d-%d-%d-%d-%d", &gs1, &group, &publisher, &item, &check) != 5) {
        printf("Invalid format! Please try again.\n");
        
        while (getchar() != '\n'); 
        
        printf("\nEnter ISBN: ");
    }

    printf("\nGS1 prefix: %d\n", gs1);
    printf("Group identifier: %d\n", group);
    printf("Publisher code: %d\n", publisher);
    printf("Item number: %d\n", item);
    printf("Check digit: %d\n", check);

    return 0;
}
