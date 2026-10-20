#include <stdio.h>

int main(void) {
    int grade;
    char letter_grade;

    while (1) {
        printf("Enter numerical grade: ");
        if (scanf("%d", &grade) == 1) {
            if (grade >= 0 && grade <= 100) {
                break; 
            }
        }
        printf("Invalid input. Please enter a valid numerical grade between 0 and 100.\n");
        while (getchar() != '\n'); 
    }

    switch (grade / 10) {
        case 10:
        case 9:
            letter_grade = 'A';
            break;
        case 8:
            letter_grade = 'B';
            break;
        case 7:
            letter_grade = 'C';
            break;
        case 6:
            letter_grade = 'D';
            break;
        default:
            letter_grade = 'F';
            break;
    }

    printf("Letter grade: %c\n", letter_grade);

    return 0;
}