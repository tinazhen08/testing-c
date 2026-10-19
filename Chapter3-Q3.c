#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void) {
    char isbn[100];
    int valid;
    int gs1, group, publisher, item, check;

    while (1) {
        valid = 1;

        printf("Enter ISBN (format: xxx-x-xxx-xxxxx-x): ");

        if (scanf("%99s", isbn) != 1) {
            return 1;
        }

        if (strlen(isbn) != 17) {
            valid = 0;
        }

        if (valid) {
            for (int i = 0; i < 17; i++) {
                if (i == 3 || i == 5 || i == 9 || i == 15) {
                    if (isbn[i] != '-') {
                        valid = 0;
                        break;
                    }
                } else {
                    if (!isdigit((unsigned char)isbn[i])) {
                        valid = 0;
                        break;
                    }
                }
            }
        }

        if (valid) {
            break;
        }

        printf("Invalid format! Please try again.\n\n");
    }

    sscanf(isbn, "%3d-%1d-%3d-%5d-%1d",
           &gs1, &group, &publisher, &item, &check);

    printf("\nGS1 prefix: %d\n", gs1);
    printf("Group identifier: %d\n", group);
    printf("Publisher code: %d\n", publisher);
    printf("Item number: %d\n", item);
    printf("Check digit: %d\n", check);

    return 0;
}