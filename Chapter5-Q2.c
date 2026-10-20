#include <stdio.h>

int main(void) {
    int hour, minute;
    char meridiem[3];
    while (1) {
        printf("Enter a 24-hour time (HH:MM): ");
        if (scanf("%2d:%2d", &hour, &minute) == 2) {
            if (hour >= 0 && hour < 24 && minute >= 0 && minute < 60) {
                break; 
            }
        }
        printf("Invalid input. Please enter a valid 24-hour time.\n");
        while (getchar() != '\n');
    }

    if (hour == 0) {
        hour = 12; 
        snprintf(meridiem, sizeof(meridiem), "AM");
    } else if (hour == 12) {
        snprintf(meridiem, sizeof(meridiem), "PM"); 
    } else if (hour > 12) {
        hour -= 12;
        snprintf(meridiem, sizeof(meridiem), "PM");
    } else {
        snprintf(meridiem, sizeof(meridiem), "AM");
    }

    printf("Equivalent 12-hour time: %d:%02d %s\n", hour, minute, meridiem);

    return 0;
}
