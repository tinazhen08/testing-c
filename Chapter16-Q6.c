#include <stdio.h>

struct date {
    int month;
    int day;
    int year;
};

int compare_dates(struct date d1, struct date d2);

int main() {
    struct date date1, date2;

    printf("Enter first date (mm/dd/yy): ");
    scanf("%d/%d/%d", &date1.month, &date1.day, &date1.year);

    printf("Enter second date (mm/dd/yy): ");
    scanf("%d/%d/%d", &date2.month, &date2.day, &date2.year);

    int result = compare_dates(date1, date2);

    if (result < 0) {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", 
               date1.month, date1.day, date1.year, 
               date2.month, date2.day, date2.year);
    } else if (result > 0) {
        printf("%d/%d/%02d is earlier than %d/%d/%02d\n", 
               date2.month, date2.day, date2.year, 
               date1.month, date1.day, date1.year);
    } else {
        printf("Both dates are the same: %d/%d/%02d\n", 
               date1.month, date1.day, date1.year);
    }

    return 0;
}

int compare_dates(struct date d1, struct date d2) {
    if (d1.year < d2.year) return -1;
    if (d1.year > d2.year) return 1;

    if (d1.month < d2.month) return -1;
    if (d1.month > d2.month) return 1;

    if (d1.day < d2.day) return -1;
    if (d1.day > d2.day) return 1;

    return 0;
}

